#include "../includes/List.hpp"
#include "../includes/Iterator.hpp"

template <typename T>
void	display_list(ft::List<T> & lst)
{
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

	display_list(lst);
	lst.pop_back();
	display_list(lst);
	lst.pop_front();
	display_list(lst);
	lst.push_front(0);
	display_list(lst);

// -------- reverse Iterator --------
std::cout << "\n-------- reverse Iterator --------\n";
	ft::List<int>	lstc(lst);

	reverse_display_list(lstc);

// -------- Constructors --------
std::cout << "\n-------- Constructor - (nb 5, val 42) --------\n";

	ft::List<int>	lst2(5, 42);

	display_list(lst2);

std::cout << "\n-------- Constructor - (begin, end) --------\n";
	ft::List<int>::iterator	itb = lst.begin();
	ft::List<int>::iterator	ite = lst.end();
	itb++;
	ite--;
	ft::List<int>	lst3(itb, ite);

	display_list(lst3);

	return (0);
}
