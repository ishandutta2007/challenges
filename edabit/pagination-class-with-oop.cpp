/*

Your task is to create a class to handle paginated content in a website. A pagination is used to divide long lists of content in a series of pages.

The pagination class will accept 2 parameters:

    items (default: []): An array of contents to paginate.

    pageSize (default: 10): The amount of items to show in each page.

So for example we could initialize our pagination like this:

const alphabetArray = "abcdefghijklmnopqrstuvwxyz".split("");

const p = new Pagination(alphabetArray, 4);

And then use the method getVisibleItems to show the contents of the paginated array.

console.log(p.getVisibleItems()); // ["a", "b", "c", "d"]

You will have to implement various methods to go through the pages such as:

    prevPage
    nextPage
    firstPage
    lastPage
    goToPage

Here's a continuation of the example above using nextPage and lastPage:

p.nextPage();

console.log(p.getVisibleItems());
// ["e", "f", "g", "h"]

p.lastPage();

console.log(p.getVisibleItems());
// ["y", "z"]

Notes

    You don't have to use ES6 class if you don't want to
    The second argument (pageSize) could be a float, in that case just convert it to an int (this is also the case for the goToPage method)
    The methods used to change page should be chainable, so you can call them one after the other like this: p.nextPage().nextPage();
    Please remove the comments I provided before publishing your solution.

*/

#include <cassert>
#include <cinttypes>
#include <vector>
#include <string>

using namespace std;

template <typename T>
struct Pagination
{
	vector<T> items;
	ssize_t currentPage;
	ssize_t totalPages;
	ssize_t pageSize;

	Pagination(vector<T> items = vector<T>(), ssize_t pageSize = 10)
		: items(items), pageSize(pageSize)
	{
		assert(pageSize != 0);
		totalPages = items.size() / pageSize;
		if (items.size() % pageSize)
			totalPages++;
		if (totalPages == 0)
			totalPages++;
		currentPage = 1;
	}

	Pagination &prevPage()
	{
		return goToPage(currentPage - 1);
	}

	Pagination &nextPage()
	{
		return goToPage(currentPage + 1);
	}

	Pagination &firstPage()
	{
		return goToPage(1);
	}

	Pagination &lastPage()
	{
		return goToPage(totalPages);
	}

	Pagination &goToPage(ssize_t page)
	{
		if (page <= 0)
			page = 1;
		if (page > totalPages)
			page = totalPages;
		currentPage = page;
		return *this;
	}

	vector<T> getVisibleItems()
	{
		vector<T> list;
		for (ssize_t i = 0; i < pageSize; i++)
		{
			ssize_t j = (currentPage - 1) * pageSize + i;
			if ((size_t)j >= items.size())
				break;
			list.push_back(items[j]);
		}
		return list;
	}
};

void testDefaults()
{
	Pagination<int> p;
	assert(p.pageSize == 10);
	assert(p.items.size() == 0);
}

void testTotalPages()
{
	Pagination<string> p1(vector<string>(0), 10);
	Pagination<string> p2(vector<string>(1), 10);
	Pagination<string> p3(vector<string>(10), 10);
	Pagination<string> p4(vector<string>(11), 10);

	assert(p1.totalPages == 1);
	assert(p2.totalPages == 1);
	assert(p3.totalPages == 1);
	assert(p4.totalPages == 2);
}

void testCurrentPage()
{
	Pagination<string> p1(vector<string>(0), 10);
	Pagination<string> p2(vector<string>(1), 10);
	Pagination<string> p3(vector<string>(10), 10);
	Pagination<string> p4(vector<string>(11), 10);

	assert(p1.currentPage == 1);
	assert(p2.currentPage == 1);
	assert(p3.currentPage == 1);
	assert(p4.currentPage == 1);
}

void testChangePage()
{
	Pagination<string> p(vector<string>(69), 5);
	assert(p.nextPage().currentPage == 2);
	assert(p.lastPage().currentPage == 14);
	assert(p.nextPage().currentPage == 14);
	assert(p.prevPage().currentPage == 13);
	assert(p.firstPage().currentPage == 1);
	assert(p.goToPage(99).currentPage == 14);
	assert(p.goToPage(4).currentPage == 4);
	assert(p.goToPage(-99).currentPage == 1);
}

void testVisibleItems()
{
	Pagination<int> p({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 5);
	vector<int> v1 = { 0, 1, 2, 3, 4 };
	vector<int> v2 = { 5, 6, 7, 8, 9 };
	vector<int> v3 = { 10 };
	assert(p.getVisibleItems() == v1);
	assert(p.nextPage().getVisibleItems() == v2);
	assert(p.nextPage().getVisibleItems() == v3);
}

int main()
{
	testDefaults();
	testTotalPages();
	testCurrentPage();
	testChangePage();
	testVisibleItems();
	return 0;
}
