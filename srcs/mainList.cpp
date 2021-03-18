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
void	display_list(ft::List<T> & lst)
{
	typename ft::List<T>::iterator	it;
	it = lst.begin();
	std::cout << "[";
	while (it != lst.end())
	{
		std::cout << "" << *(it++);
		if (it != lst.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
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
	std::cout << "[";
	while (it != lst.end())
	{
		std::cout << "" << *(it++);
		if (it != lst.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

template <typename T>
void	check_list(ft::List<T> & myLst, std::list<T> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::iterator	itF = myLst.begin();
	while (itF != myLst.end())
		ss_ft << "> " << *(itF++) << "\n";
	ss_ft << "\n";
	
	typename std::list<T>::iterator	itS = realLst.begin();
	while (itS != realLst.end())
		ss_std << "> " << *(itS++) << "\n";
	ss_std << "\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
		std::cout << "\033[1;32mOK \033[0m";
	else
		std::cout << "\033[1;31mKO \033[0m";

	if (PRINT_VALUE)
	{
		std::cout << "\n";
		display_list(myLst);
		display_real_list(realLst);
	}
	if (PRINT_ERROR && ss_std.str().compare(ss_ft.str()) && !PRINT_VALUE)
	{
		std::cout << "\n";
		display_list(myLst);
		display_real_list(realLst);
	}

	if (clearFlag)
	{
		myLst.clear();
		realLst.clear();
	}
}

// template <typename T>
// void	check_list_const(ft::List<T> & myLst, std::list<T> & realLst, int clearFlag = 0)
// {
// 	std::stringstream ss_ft;
// 	std::stringstream ss_std;

// 	// typename ft::List<T>::iterator	itF = myLst.begin();
// 	typename ft::List<T>::const_iterator	itF = myLst.begin();
// 	while (itF != myLst.end())
// 		ss_ft << "> " << *(itF++) << "\n";
// 	ss_ft << "\n";
	
// 	typename std::list<T>::const_iterator	itS = realLst.begin();
// 	while (itS != realLst.end())
// 		ss_std << "> " << *(itS++) << "\n";
// 	ss_std << "\n";
	
// 	if (!ss_std.str().compare(ss_ft.str()))
// 		std::cout << "\033[1;32mCOK \033[0m";
// 	else
// 		std::cout << "\033[1;31mCKO \033[0m";

// 	if (clearFlag)
// 	{
// 		myLst.clear();
// 		realLst.clear();
// 	}
// }

template <typename T>
void	check_list_reverse(ft::List<T> & myLst, std::list<T> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::reverse_iterator	itF = myLst.rbegin();
	while (itF != myLst.rend())
		ss_ft << "> " << *(itF++) << "\n";
	ss_ft << "\n";
	
	typename std::list<T>::reverse_iterator	itS = realLst.rbegin();
	while (itS != realLst.rend())
		ss_std << "> " << *(itS++) << "\n";
	ss_std << "\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
		std::cout << "\033[1;32mROK \033[0m";
	else
		std::cout << "\033[1;31mRKO \033[0m";

	if (clearFlag)
	{
		myLst.clear();
		realLst.clear();
	}
}

template <typename T>
void	check_value(T & valF, T & valS)
{
	if (valF == valS)
		std::cout << "\033[1;32mOK \033[0m";
	else
		std::cout << "\033[1;31mKO \033[0m";

	if (PRINT_VALUE)
	{
		std::cout << "\nvalF = " << valF << "\n";
		std::cout << "valS = " << valS << "\n";
	}
	if (PRINT_ERROR && valF != valS && !PRINT_VALUE)
	{
		std::cout << "\nvalF = " << valF << "\n";
		std::cout << "valS = " << valS << "\n";
	}
}

void	check_constructors(void)
{
	std::cout << "\033[1;36m\n===== Constructors =====\033[0m\n";

	ft::List<int>	lstF;
	std::list<int>	lstS;
	check_list(lstF, lstS);

	ft::List<int>	lstF2(5, 42);
	std::list<int>	lstS2(5, 42);
	check_list(lstF2, lstS2);

	ft::List<int>::iterator		itbF = lstF2.begin()++;
	ft::List<int>::iterator		iteF = lstF2.end();
	std::list<int>::iterator	itbS = lstS2.begin()++;
	std::list<int>::iterator	iteS = lstS2.end();

	ft::List<int>	lstF3(itbF, iteF);
	std::list<int>	lstS3(itbS, iteS);
	check_list(lstF3, lstS3);

	ft::List<int>	lstF4(lstF3);
	std::list<int>	lstS4(lstS3);
	check_list(lstF4, lstS4);

	lstF = lstF4;
	lstS2 = lstS4;
	check_list(lstF, lstS2);

	std::cout << "\n";
}


void	check_iterators(void)
{
	std::cout << "\033[1;36m\n===== Iterators =====\033[0m\n";

	ft::List<int>	lstF;
	std::list<int>	lstS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	check_list	(lstF, lstS);
	// check_list_const(lstF, lstS);
	check_list_reverse(lstF, lstS);
	// check_list_const_reverse(lstF, lstS);

	std::cout << "\n";
}

void	check_capacity(void)
{
	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

	ft::List<int>	lstF;
	std::list<int>	lstS;

	size_t	valF;
	size_t	valS;

	valF = lstF.max_size();
	valS = lstS.max_size();
	check_value(valF, valS);

	valF = lstF.empty();
	valS = lstS.empty();
	check_value(valF, valS);
	valF = lstF.size();
	valS = lstS.size();
	check_value(valF, valS);

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	valF = lstF.empty();
	valS = lstS.empty();
	check_value(valF, valS);

	valF = lstF.size();
	valS = lstS.size();
	check_value(valF, valS);

	std::cout << "\n";
}

void	check_element_access(void)
{
	std::cout << "\033[1;36m\n===== Element access =====\033[0m\n";

	ft::List<int>	lstF;
	std::list<int>	lstS;

	size_t	valF;
	size_t	valS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	valF = lstF.front();
	valS = lstS.front();
	check_value(valF, valS);

	valF = lstF.back();
	valS = lstS.back();
	check_value(valF, valS);

	std::cout << "\n";
}

void	check_modifiers(void)
{
	std::cout << "\033[1;36m\n===== Modifiers =====\033[0m\n";

	std::cout << "  --- Assign ---\n";
	ft::List<int>	lstF;
	std::list<int>	lstS;

	lstF.assign(5, 42);
	lstS.assign(5, 42);
	check_list(lstF, lstS);

	ft::List<int>	lstF2;
	std::list<int>	lstS2;

	ft::List<int>::iterator		itbF = lstF.begin()++;
	ft::List<int>::iterator		iteF = lstF.end()--;
	std::list<int>::iterator	itbS = lstS.begin()++;
	std::list<int>::iterator	iteS = lstS.end()--;
	
	lstF.assign(itbF, iteF);
	lstS.assign(itbS, iteS);
	check_list(lstF2, lstS2, 1);

	std::cout << "\n  --- Push/Pop_Front/Back ---\n";

	lstF2.push_front(2);
	lstF2.push_front(1);
	lstS2.push_front(2);
	lstS2.push_front(1);
	check_list(lstF2, lstS2);

	lstF2.push_back(3);
	lstF2.push_back(5);
	lstS2.push_back(3);
	lstS2.push_back(5);
	check_list(lstF2, lstS2);

	lstF2.pop_front();
	lstS2.pop_front();
	check_list(lstF2, lstS2);

	lstF2.pop_back();
	lstS2.pop_back();
	check_list(lstF2, lstS2);


	std::cout << "\n  --- Insert ---\n";

	ft::List<int>::iterator		itbF2 = ++lstF2.begin();
	std::list<int>::iterator	itbS2 = ++lstS2.begin();

	itbF2 = lstF2.insert(itbF2, 56);
	itbS2 = lstS2.insert(itbS2, 56);
	check_list(lstF2, lstS2);

	lstF2.insert(itbF2, 5, 93);
	lstS2.insert(itbS2, 5, 93);
	check_list(lstF2, lstS2);

	lstF2.insert(itbF2, itbF, iteF);
	lstS2.insert(itbS2, itbS, iteS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Erase ---\n";
	itbF2 = lstF2.erase(--itbF2);
	itbS2 = lstS2.erase(--itbS2);
	check_list(lstF2, lstS2);

	ft::List<int>::iterator		iteF2 = --lstF2.end();
	std::list<int>::iterator	iteS2 = --lstS2.end();

	itbF2 = ++lstF2.begin();
	itbS2 = ++lstS2.begin();

	lstF2.erase(itbF2, iteF2);
	lstS2.erase(itbS2, iteS2);
	check_list(lstF2, lstS2);


	std::cout << "\n  --- Swap ---\n";
	lstF.swap(lstF2);
	lstS.swap(lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Resize ---\n";
	lstF.resize(0);
	lstS.resize(0);
	check_list(lstF, lstS);
	
	lstF.resize(12, -42);
	lstS.resize(12, -42);
	check_list(lstF, lstS);

	std::cout << "\n  --- Clear ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n";
}

void	check_operations(void)
{
	std::cout << "\033[1;36m\n===== Operations =====\033[0m\n";

	std::cout << "  --- Splice ---\n";
	ft::List<int>	lstF;
	std::list<int>	lstS;

	ft::List<int>	lstF2;
	std::list<int>	lstS2;

	lstF.push_back(1);
	lstF.push_back(4);
	lstF.push_back(5);

	lstF2.push_back(2);
	lstF2.push_back(3);

	lstS.push_back(1);
	lstS.push_back(4);
	lstS.push_back(5);

	lstS2.push_back(2);
	lstS2.push_back(3);

	ft::List<int>::iterator		itbF = ++lstF.begin();
	std::list<int>::iterator	itbS = ++lstS.begin();

	lstF.splice(itbF, lstF2);
	lstS.splice(itbS, lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF2.push_back(6);
	lstF2.push_back(7);
	lstF2.push_back(8);
	lstF2.push_back(9);
	lstF2.push_back(10);

	lstS2.push_back(6);
	lstS2.push_back(7);
	lstS2.push_back(8);
	lstS2.push_back(9);
	lstS2.push_back(10);

	lstF.splice(lstF.end(), lstF2, ++lstF2.begin());
	lstS.splice(lstS.end(), lstS2, ++lstS2.begin());
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF.splice(lstF.end(), lstF2, ++lstF2.begin(), --lstF2.end());
	lstS.splice(lstS.end(), lstS2, ++lstS2.begin(), --lstS2.end());
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "  --- Remove/Remove_if ---\n";

	lstF.push_back(2);
	lstS.push_back(2);
	lstF.remove(2);
	lstS.remove(2);
	check_list(lstF, lstS);

	lstF.remove_if(is_even);
	lstS.remove_if(is_even);
	check_list(lstF, lstS);

	std::cout << "  --- Unique ---\n";

	lstF.push_front(10);
	lstF.push_front(10);
	lstS.push_front(10);
	lstS.push_front(10);
	lstF.push_front(-5);
	lstF.push_front(-5);
	lstS.push_front(-5);
	lstS.push_front(-5);
	lstF.push_front(-10);
	lstF.push_front(-10);
	lstS.push_front(-10);
	lstS.push_front(-10);
	lstF.unique();
	lstS.unique();
	check_list(lstF, lstS);

	lstF.unique(are_factor_five);
	lstS.unique(are_factor_five);
	check_list(lstF, lstS);

	std::cout << "  --- Merge ---\n";
	lstF.merge(lstF2);
	lstS.merge(lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF2.push_back(8);
	lstF2.push_back(4);
	lstF2.push_back(2);

	lstS2.push_back(8);
	lstS2.push_back(4);
	lstS2.push_back(2);

	lstF.reverse();
	lstS.reverse();
	lstF.merge(lstF2, is_greater);
	lstS.merge(lstS2, is_greater);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "  --- Sort ---\n";

	lstF2.push_back(100);
	lstF2.push_back(-22);
	lstF2.push_back(9);
	lstF2.push_back(-42);
	lstF2.push_back(56);
	lstF2.push_back(9);
	lstF2.push_back(93);

	lstS2.push_back(100);
	lstS2.push_back(-22);
	lstS2.push_back(9);
	lstS2.push_back(-42);
	lstS2.push_back(56);
	lstS2.push_back(9);
	lstS2.push_back(93);

	lstF2.sort();
	lstS2.sort();
	check_list(lstF2, lstS2);

	lstF2.clear();
	lstS2.clear();

	lstF2.push_back(100);
	lstF2.push_back(-22);
	lstF2.push_back(9);
	lstF2.push_back(-42);
	lstF2.push_back(56);
	lstF2.push_back(9);
	lstF2.push_back(93);

	lstS2.push_back(100);
	lstS2.push_back(-22);
	lstS2.push_back(9);
	lstS2.push_back(-42);
	lstS2.push_back(56);
	lstS2.push_back(9);
	lstS2.push_back(93);

	lstF2.sort(is_greater);
	lstS2.sort(is_greater);
	check_list(lstF2, lstS2);

	std::cout << "  --- Reverse ---\n";

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

}

int main(void)
{
	check_constructors();
	check_iterators();
	check_capacity();
	check_element_access();
	check_modifiers();
	check_operations();

	return 0;
}