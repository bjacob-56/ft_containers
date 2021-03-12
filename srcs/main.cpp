#include "../includes/List.hpp"
#include "../includes/Iterator.hpp"

template <typename T>
void	display_list(ft::List<T> & lst)
{
	typename ft::List<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "> " << (*it++)->getContent() << "\n";
}

template <typename T>
void	reverse_display_list(const ft::List<T> & lst)
{
	typename ft::List<T>::const_reverse_iterator	rit;
	rit = lst.rbegin();
	while (rit != lst.rend())
		std::cout << "> " << (*rit++)->getContent() << "\n";
}

int main(void)
{
	ft::List<int>	lst;

// -------- push_back --------
std::cout << "\n-------- push_back --------\n";
	std::cout << "size = " << lst.size() << "\n";

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	std::cout << "size = " << lst.size() << "\n";

// -------- Iterator --------
std::cout << "\n\n-------- Iterator --------\n";

	display_list(lst);

// -------- reverse Iterator --------
std::cout << "\n\n-------- reverse Iterator --------\n";
	const ft::List<int>	lstc(lst);

	reverse_display_list(lstc);

// -------- Constructors --------
std::cout << "\n\n-------- Constructor - (nb 5, val 42) --------\n";

	ft::List<int>	lst2(5, 42);

	display_list(lst2);

std::cout << "\n\n-------- Constructor - (begin, end) --------\n";
	ft::List<int>::iterator	itb = lst.begin();
	ft::List<int>::iterator	ite = lst.end();
	itb++;
	ite--;
	ft::List<int>	lst3(itb, ite);

	display_list(lst3);

	return (0);
}
