// Write a routine bfree that will free an arbitrary block p of n characters
// into the free list maintained by malloc and free. By using bfree, a user can
// add a static or external array to the free list at any time.

#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>

typedef union Header Header;

union Header {
	struct {
		Header *ptr;
		size_t size;
	};
	max_align_t align;
};

static Header base;
static Header *freep;
static size_t maxalloc;

void *xmalloc(size_t);
void xfree(void *);

#define NALLOC 1024
#define MAXBYTES SSIZE_MAX

static Header *
morecore(size_t nu)
{
	Header *up;
	void *cp;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (void *)-1)
		return NULL;
	up = cp;
	up->size = nu;
	if (up->size > maxalloc)
		maxalloc = up->size;
	xfree(up + 1);
	return freep;
}

void *
xmalloc(size_t size)
{
	Header *p, *prevp;
	size_t nunits;

	if (size > MAXBYTES) {
		fprintf(stderr, "alloc: can't allocate more than %zu bytes\n", MAXBYTES);
		return NULL;
	}

	nunits = (size + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {
		base.ptr = freep = prevp = &base;
		base.size = 0;
	}

	for (p = prevp->ptr;; prevp = p, p = p->ptr) {
		if (p->size >= nunits) {
			if (p->size == nunits)
				prevp->ptr = p->ptr;
			else {
				p->size -= nunits;
				p += p->size;
				p->size = nunits;
			}

			freep = prevp;
			return p + 1;
		}

		if (p == freep) {
			if ((p = morecore(nunits)) == NULL)
				break;
		}
	}

	return NULL;
}

void
xfree(void *ptr)
{
	Header *bp, *p;

	if (ptr == NULL)
		return;

	bp = (Header *)ptr - 1;
	if (bp->size == 0 || bp->size > maxalloc) {
		fprintf(stderr, "free: can't free %zu units\n", bp->size);
		return;
	}

	for (p = freep; !(bp > p && bp < p->ptr); p = p->ptr) {
		if (p >= p->ptr && (bp > p || bp < p->ptr))
			break;
	}
	if (bp + bp->size == p->ptr) {
		bp->size += p->ptr->size;
		bp->ptr = p->ptr->ptr;
	} else
		bp->ptr = p->ptr;

	if (p + p->size == bp) {
		p->size += bp->size;
		p->ptr = bp->ptr;
	} else
		p->ptr = bp;
	freep = p;
}

size_t
bfree(void *p, size_t n)
{
	Header *hp;

	if (n < sizeof(Header))
		return 0;
	hp = p;
	hp->size = n / sizeof(Header);
	xfree(hp + 1);
	return hp->size;
}

int
main(void)
{
	void *p;

	p = xmalloc(32);
	bfree(p, 32);
	return 0;
}
