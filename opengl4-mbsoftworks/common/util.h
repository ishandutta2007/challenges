#ifndef _UTIL_H_
#define _UTIL_H_

#define CHECK_GL()                                                             \
	{                                                                          \
		auto err = glGetError();                                               \
		if (err != 0)                                                          \
			fatal("%s:%d %s gl error: %d", __FILE__, __LINE__, __func__, err); \
	}

[[noreturn]] void fatal(const char *fmt, ...);

char *file2str(const char *name, size_t *size);

void hexdump(void *buf, size_t len);

char *stprint(const char *fmt, ...);

template <typename T>
T getle(void *b)
{
	T v = 0;

	auto p = (uint8_t *)b;
	for (ssize_t i = sizeof(T) - 1; i >= 0; i--)
		v = (v << 8) | p[i];
	return v;
}

template <typename T>
T getbe(void *b)
{
	T v = 0;

	auto p = (uint8_t *)b;
	for (size_t i = 0; i < sizeof(T); i++)
		v = (v << 8) | p[i];
	return v;
}

const auto getbe2 = getbe<uint16_t>;
const auto getbe4 = getbe<uint32_t>;
const auto getbe8 = getbe<uint64_t>;

const auto getle2 = getle<uint16_t>;
const auto getle4 = getle<uint32_t>;
const auto getle8 = getle<uint64_t>;

template <typename T>
T fgetle(FILE *fp)
{
	uint8_t buf[sizeof(T)];
	fread(buf, sizeof(buf), 1, fp);
	return getle<T>(buf);
}

template <typename T>
T fgetbe(FILE *fp)
{
	uint8_t buf[sizeof(T)];
	fread(buf, sizeof(buf), 1, fp);
	return getbe<T>(buf);
}

const auto fgetbe2 = fgetbe<uint16_t>;
const auto fgetbe4 = fgetbe<uint32_t>;
const auto fgetbe8 = fgetbe<uint64_t>;

const auto fgetle2 = fgetle<uint16_t>;
const auto fgetle4 = fgetle<uint32_t>;
const auto fgetle8 = fgetle<uint64_t>;

#endif
