#include "utils_main.hpp"

template <typename T>
std::stringstream stream_list(ft::List<T> & lst)
{
	std::stringstream ss;

	typename ft::List<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		ss << "> " << *(it++) << "\n";
	ss << "\n";
	return (ss);
}

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
std::stringstream	stream_real_list(std::list<T> & lst)
{
	std::stringstream ss;

	typename std::list<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		ss << "> " << *(it++) << "\n";
	ss << "\n";
	return (ss);
}

template <typename T>
void	display_real_list(std::list<T> & lst)
{
	typename std::list<T>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "> " << *(it++) << "\n";
	std::cout << "\n";
}

template <typename T>
void	check_list(ft::List<T> & myLst, std::list<T> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::iterator	itF;
	itF = myLst.begin();
	while (itF != myLst.end())
		ss_ft << "> " << *(itF++) << "\n";
	ss_ft << "\n";
	
	typename std::list<T>::iterator	itS;
	itS = realLst.begin();
	while (itS != realLst.end())
		ss_std << "> " << *(itS++) << "\n";
	ss_std << "\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
		std::cout << "\033[1;32mOK \033[0m";
	else
		std::cout << "\033[1;31mKO \033[0m";
}



int main(void)
{
	ft::List<int>	lstF;
	std::list<int>	lstS;

	check_list(lstF, lstS);

	lstF.push_back(42);
	lstS.push_back(42);
	check_list(lstF, lstS);

	std::cout << "\n";

	return 0;
}