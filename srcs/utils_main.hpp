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

bool	is_even(const int & i);
bool	is_factor_five(const int & i);
bool	same_abs(const int & i, const int & j);
bool	is_greater(const int & i, const int & j);
