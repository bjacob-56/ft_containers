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
	ft::List<int>	lst2;	
	
	lst.push_back(1);
	lst.push_back(-5);
	lst2.push_back(2);
	lst2.push_back(9);
	display_list(lst2, "lst2");
	lst.sort();
	display_list(lst, "lst");
	// lst.merge(lst2);
	display_list(lst, "lst");
	display_list(lst2, "lst2");

	return (0);
}
