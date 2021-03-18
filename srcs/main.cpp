#include "../includes/List.hpp"
#include "../includes/Iterator.hpp"

#include <list>

template <typename T>
void	display_list(ft::List<T> & lst, std::string title)
{
	if (title != "")
		std::cout << "... " << title << " ...\n";
	typename ft::List<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "> " << *(it++) << "\n";
	std::cout << "\n";
}

template <typename T>
void	reverse_display_list(ft::List<T> & lst)
{
	// ft::List<T>::const_reverse_iterator	rit;
	typename ft::List<T>::reverse_iterator	rit = lst.rbegin();

	while (rit != lst.rend())
		std::cout << "> " << *(rit++) << "\n";
	std::cout << "\n";
}

template <typename T>
void	display_real_list(std::list<T> & lst, std::string title)
{
	if (title != "")
		std::cout << "... " << title << " ...\n";
	typename std::list<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "> " << *(it++) << "\n";
	std::cout << "\n";
}








int main(void)
{
	ft::List<int>	lst;

// -------- push_back --------
std::cout << "\n-------- push_back --------\n";
	std::cout << "size = " << lst.size() << "\n";
	std::cout << "is_empty = " << lst.empty() << "\n";
	
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::cout << "size = " << lst.size() << "\n";
	std::cout << "is_empty = " << lst.empty() << "\n";

// -------- Iterator --------
std::cout << "\n-------- Iterator --------\n";

	display_list(lst, "lst");
	lst.pop_back();
	display_list(lst, "lst");
	lst.pop_front();
	display_list(lst, "lst");
	lst.push_front(-5);
	display_list(lst, "lst");

// -------- reverse Iterator --------
std::cout << "\n-------- reverse Iterator --------\n";
	ft::List<int>	lstc(lst);
	// display_list(lstc);
	reverse_display_list(lstc);

// -------- Constructors --------
std::cout << "\n-------- Constructor - (nb 5, val 42) --------\n";

	ft::List<int>	lst2(5, 42);

	display_list(lst2, "lst2");

std::cout << "\n-------- Constructor - (begin, end) --------\n";
	ft::List<int>::iterator	itb = lst.begin();
	ft::List<int>::iterator	ite = lst.end();
	itb++;
	ite--;
	ft::List<int>	lst3(itb, ite);

	display_list(lst3, "lst3");

	lst3 = lst;
	display_list(lst, "lst");
	// lst.erase(--itb, ++ite);
	lst.erase(itb, ite);
	display_list(lst, "lst");
	lst = lst3;
	display_list(lst, "lst");


// -------- Swap --------
std::cout << "\n-------- Swap --------\n";

	display_list(lst3, "lst3");
	display_list(lst2, "lst2");
	lst3.swap(lst2);
	display_list(lst3, "lst3");
	display_list(lst2, "lst2");

// -------- Insert --------
std::cout << "\n-------- Insert --------\n";
	ft::List<int>::iterator	it3 = lst3.begin();
	lst3.insert(it3, 3, -42);
	it3++;
	it3++;
	lst3.insert(it3, -1);
	display_list(lst3, "lst3");

	ft::List<int>::iterator	it2 = lst2.begin();
	ft::List<int>::iterator	ite2 = lst2.end();
	it3 = lst3.begin();
	ite2--;
	lst3.insert(it3, it2, ite2);
	display_list(lst3, "lst3");

// -------- Resize --------
std::cout << "\n-------- Resize --------\n";
	std::cout << "size lst3 = " << lst3.size() << "\n";
	lst3.resize(5);
	display_list(lst3, "lst3");
	lst3.resize(7);
	display_list(lst3, "lst3");
	lst3.resize(10, 56);
	display_list(lst3, "lst3");
	lst3.resize(0);
	display_list(lst3, "lst3");

	lst3.resize(5, 7);
	display_list(lst3, "lst3");
	lst3.clear();
	display_list(lst3, "lst3");

// -------- Assign --------
std::cout << "\n-------- Assign --------\n";

	lst3.assign(3, 9);			// Template function a gerer
	display_list(lst3, "lst3");

	itb = lst.begin();
	ite = lst.end();
	itb++;
	lst3.assign(itb, ite);
	display_list(lst3, "lst3");




// ===========  OPERATIONS  ===========
std::cout << "\n===========  OPERATIONS  ===========\n";

	lst.clear();
	lst2.clear();
	lst3.clear();
	lstc.clear();

	lst.assign(5, 42);
	display_list(lst, "lst");

	lst2.assign(2, 1);
	display_list(lst2, "lst2");

	lst3.push_back(-100);
	lst3.push_back(-5);
	lst3.push_back(0);
	lst3.push_back(5);
	lst3.push_back(100);
	display_list(lst3, "lst3");

// -------- Splice --------
std::cout << "\n-------- Splice --------\n";
	itb = lst.begin();
	ite = --lst.end();
	// ite = lst.end();
	// lst.erase(itb, --ite);
	// display_list(lst, "lst");


	ft::List<int>::iterator	itb3 = ++lst3.begin();
	lst3.splice(itb3, lst, itb, ite);
	lst3.splice(itb3, lst2);
	display_list(lst3, "lst3");

// -------- Remove --------
std::cout << "\n-------- Remove --------\n";

// -------- Remove_if --------
std::cout << "\n-------- Remove_if --------\n";

// -------- Unique --------
std::cout << "\n-------- Unique --------\n";

// -------- Merge --------
std::cout << "\n-------- Merge --------\n";

// -------- Sort --------
std::cout << "\n-------- Sort --------\n";

// -------- Reverse --------
std::cout << "\n-------- Reverse --------\n";


// =========== List (real) ===========
std::cout << "\n=========== List (real) ===========\n";

	std::list<int> real_l;

	// real_l.assign(-2147483647, 9);

	display_real_list(real_l, "real_l");


	// lstc.~List();
	// lst3.~List();
	// lst2.~List();
	// lst.~List();


	return (0);
}
