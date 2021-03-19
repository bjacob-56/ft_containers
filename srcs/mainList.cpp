#include "utils_main.hpp"

int	print_value = 0;
int	print_error = 0;

int	nb_OK = 0;
int	nb_KO = 0;


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
	ss_ft << "[";
	while (itF != myLst.end())
	{
		ss_ft << *(itF++);
		if (itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::list<T>::iterator	itS = realLst.begin();
	ss_std << "[";
	while (itS != realLst.end())
	{
		ss_std << *(itS++);
		if (itS != realLst.end())
			ss_std << ", ";
	}
	ss_std << "]\n";

	if (!ss_std.str().compare(ss_ft.str()))
	{
		std::cout << "\033[1;32mOK \033[0m";
		nb_OK++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		nb_KO++;
	}

	if (print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
	if (print_error && ss_std.str().compare(ss_ft.str()) && !print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}

	if (clearFlag)
	{
		myLst.clear();
		realLst.clear();
	}
}

template <typename T>
void	check_list_const(const ft::List<T> & myLst, const std::list<T> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::const_iterator	itF = myLst.begin();
	ss_ft << "[";
	while (itF != myLst.end())
	{
		ss_ft << *(itF++);
		if (itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::list<T>::const_iterator	itS = realLst.begin();
	ss_std << "[";
	while (itS != realLst.end())
	{
		ss_std << *(itS++);
		if (itS != realLst.end())
			ss_std << ", ";
	}
	ss_std << "]\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
	{
		std::cout << "\033[1;32mOK \033[0m";
		nb_OK++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		nb_KO++;
	}

	if (print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
	if (print_error && ss_std.str().compare(ss_ft.str()) && !print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
}

template <typename T>
void	check_list_reverse(ft::List<T> & myLst, std::list<T> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << *(itF++);
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::list<T>::reverse_iterator	itS = realLst.rbegin();
	ss_std << "[";
	while (itS != realLst.rend())
	{
		ss_std << *(itS++);
		if (itS != realLst.rend())
			ss_std << ", ";
	}
	ss_std << "]\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
	{
		std::cout << "\033[1;32mOK \033[0m";
		nb_OK++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		nb_KO++;
	}

	if (print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
	if (print_error && ss_std.str().compare(ss_ft.str()) && !print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}

	if (clearFlag)
	{
		myLst.clear();
		realLst.clear();
	}
}


template <typename T>
void	check_list_const_reverse(const ft::List<T> & myLst, const std::list<T> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::List<T>::const_reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << *(itF++);
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::list<T>::const_reverse_iterator	itS = realLst.rbegin();
	ss_std << "[";
	while (itS != realLst.rend())
	{
		ss_std << *(itS++);
		if (itS != realLst.rend())
			ss_std << ", ";
	}
	ss_std << "]\n";
	
	if (!ss_std.str().compare(ss_ft.str()))
	{
		std::cout << "\033[1;32mOK \033[0m";
		nb_OK++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		nb_KO++;
	}

	if (print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
	if (print_error && ss_std.str().compare(ss_ft.str()) && !print_value)
	{
		std::cout << "\n";
		std::cout << ss_ft.str();
		std::cout << ss_std.str();
	}
}

template <typename T>
void	check_value(T & valF, T & valS)
{
	if (valF == valS)
	{
		std::cout << "\033[1;32mOK \033[0m";
		nb_OK++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		nb_KO++;
	}

	if (print_value)
	{
		std::cout << "\n";
		std::cout << "valF = " << valF << "\n";
		std::cout << "valS = " << valS << "\n";
	}
	if (print_error && valF != valS && !print_value)
	{
		std::cout << "\n";
		std::cout << "valF = " << valF << "\n";
		std::cout << "valS = " << valS << "\n";
	}

}

// ************************************************************* //
// ************************************************************* //


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

void	check_constructors_string(void)
{
	std::cout << "\033[1;36m\n===== Constructors string =====\033[0m\n";

	ft::List<std::string>	lstF;
	std::list<std::string>	lstS;
	check_list(lstF, lstS);

	ft::List<std::string>	lstF2(5, "test");
	std::list<std::string>	lstS2(5, "test");
	check_list(lstF2, lstS2);

	ft::List<std::string>::iterator		itbF = lstF2.begin()++;
	ft::List<std::string>::iterator		iteF = lstF2.end();
	std::list<std::string>::iterator	itbS = lstS2.begin()++;
	std::list<std::string>::iterator	iteS = lstS2.end();

	ft::List<std::string>	lstF3(itbF, iteF);
	std::list<std::string>	lstS3(itbS, iteS);
	check_list(lstF3, lstS3);

	ft::List<std::string>	lstF4(lstF3);
	std::list<std::string>	lstS4(lstS3);
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
	// ft::List<int>	lstF2;
	std::list<int>	lstS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	check_list	(lstF, lstS);
	check_list_const(lstF, lstS);
	check_list_reverse(lstF, lstS);
	check_list_const_reverse(lstF, lstS);

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

	int		valF;
	int		valS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	valF = lstF.front();
	valS = lstS.front();
	check_value(valF, valS);

	const int		cvalF = lstF.front();
	const int		cvalS = lstS.front();
	check_value(cvalF, cvalS);

	valF = lstF.back();
	valS = lstS.back();
	check_value(valF, valS);

	const int	cvalF2 = lstF.back();
	const int	cvalS2 = lstS.back();
	check_value(cvalF2, cvalS2);

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

	swap(lstF, lstF2);
	swap(lstS, lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Resize ---\n";
	lstF2.resize(0);
	lstS2.resize(0);
	check_list(lstF2, lstS2);
	
	lstF2.resize(12, -42);
	lstS2.resize(12, -42);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Clear ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n";
}

void	check_modifiers_string(void)
{
	std::cout << "\033[1;36m\n===== Modifiers string =====\033[0m\n";

	std::cout << "  --- Assign ---\n";
	ft::List<std::string>	lstF;
	std::list<std::string>	lstS;

	lstF.assign(5, "test");
	lstS.assign(5, "test");
	check_list(lstF, lstS);

	ft::List<std::string>	lstF2;
	std::list<std::string>	lstS2;

	ft::List<std::string>::iterator		itbF = lstF.begin()++;
	ft::List<std::string>::iterator		iteF = lstF.end()--;
	std::list<std::string>::iterator	itbS = lstS.begin()++;
	std::list<std::string>::iterator	iteS = lstS.end()--;
	
	lstF.assign(itbF, iteF);
	lstS.assign(itbS, iteS);
	check_list(lstF2, lstS2, 1);

	std::cout << "\n  --- Push/Pop_Front/Back ---\n";

	lstF2.push_front("bla");
	lstF2.push_front("tree");
	lstS2.push_front("bla");
	lstS2.push_front("tree");
	check_list(lstF2, lstS2);

	lstF2.push_back("What is this?");
	lstF2.push_back("Yellow Sub");
	lstS2.push_back("What is this?");
	lstS2.push_back("Yellow Sub");
	check_list(lstF2, lstS2);

	lstF2.pop_front();
	lstS2.pop_front();
	check_list(lstF2, lstS2);

	lstF2.pop_back();
	lstS2.pop_back();
	check_list(lstF2, lstS2);


	std::cout << "\n  --- Insert ---\n";

	ft::List<std::string>::iterator		itbF2 = ++lstF2.begin();
	std::list<std::string>::iterator	itbS2 = ++lstS2.begin();

	itbF2 = lstF2.insert(itbF2, "42");
	itbS2 = lstS2.insert(itbS2, "42");
	check_list(lstF2, lstS2);

	lstF2.insert(itbF2, 5, "Ab64");
	lstS2.insert(itbS2, 5, "Ab64");
	check_list(lstF2, lstS2);

	lstF2.insert(itbF2, itbF, iteF);
	lstS2.insert(itbS2, itbS, iteS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Erase ---\n";
	itbF2 = lstF2.erase(--itbF2);
	itbS2 = lstS2.erase(--itbS2);
	check_list(lstF2, lstS2);

	ft::List<std::string>::iterator		iteF2 = --lstF2.end();
	std::list<std::string>::iterator	iteS2 = --lstS2.end();

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

	swap(lstF, lstF2);
	swap(lstS, lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Resize ---\n";
	lstF2.resize(0);
	lstS2.resize(0);
	check_list(lstF2, lstS2);
	
	lstF2.resize(12, "new str");
	lstS2.resize(12, "new str");
	check_list(lstF2, lstS2);

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

	std::cout << "\n  --- Remove/Remove_if ---\n";

	ft::List<int>	lstF3;
	std::list<int>	lstS3;

	lstF3.remove(2);
	lstS3.remove(2);
	check_list(lstF3, lstS3);

	lstF.push_back(2);
	lstS.push_back(2);
	lstF.remove(2);
	lstS.remove(2);
	check_list(lstF, lstS);

	lstF.remove(2);
	lstS.remove(2);
	check_list(lstF, lstS);

	lstF.remove_if(is_even);
	lstS.remove_if(is_even);
	check_list(lstF, lstS);

	std::cout << "\n  --- Unique ---\n";

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

	std::cout << "\n  --- Merge ---\n";
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

	std::cout << "\n  --- Sort ---\n";

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

	std::cout << "\n  --- Reverse ---\n";

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

}

void	check_operations_string(void)
{
	std::cout << "\033[1;36m\n===== Operations String =====\033[0m\n";

	std::cout << "  --- Splice ---\n";
	ft::List<std::string>	lstF;
	std::list<std::string>	lstS;

	ft::List<std::string>	lstF2;
	std::list<std::string>	lstS2;

	lstF.push_back("test");
	lstF.push_back("bla");
	lstF.push_back("tree");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("test");
	lstS.push_back("bla");
	lstS.push_back("tree");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	ft::List<std::string>::iterator		itbF = ++lstF.begin();
	std::list<std::string>::iterator	itbS = ++lstS.begin();

	lstF.splice(itbF, lstF2);
	lstS.splice(itbS, lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF2.push_back("abce");
	lstF2.push_back("abcf");
	lstF2.push_back("abcg");
	lstF2.push_back("abch");
	lstF2.push_back("abci");

	lstS2.push_back("abce");
	lstS2.push_back("abcf");
	lstS2.push_back("abcg");
	lstS2.push_back("abch");
	lstS2.push_back("abci");

	lstF.splice(lstF.end(), lstF2, ++lstF2.begin());
	lstS.splice(lstS.end(), lstS2, ++lstS2.begin());
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF.splice(lstF.end(), lstF2, ++lstF2.begin(), --lstF2.end());
	lstS.splice(lstS.end(), lstS2, ++lstS2.begin(), --lstS2.end());
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Remove/Remove_if ---\n";

	ft::List<std::string>	lstF3;
	std::list<std::string>	lstS3;

	lstF3.remove("abc");
	lstS3.remove("abc");
	check_list(lstF3, lstS3);

	lstF.push_back("abc");
	lstS.push_back("abc");
	lstF.remove("abc");
	lstS.remove("abc");
	check_list(lstF, lstS);

	lstF.remove("abc");
	lstS.remove("abc");
	check_list(lstF, lstS);

	lstF.remove_if(has_length_3);
	lstS.remove_if(has_length_3);
	check_list(lstF, lstS);

	std::cout << "\n  --- Unique ---\n";

	lstF.push_front("bcd");
	lstF.push_front("bcd");
	lstS.push_front("bcd");
	lstS.push_front("bcd");
	lstF.push_front("bbb");
	lstF.push_front("bbb");
	lstS.push_front("bbb");
	lstS.push_front("bbb");
	lstF.push_front("bcc");
	lstF.push_front("bcc");
	lstS.push_front("bcc");
	lstS.push_front("bcc");
	lstF.unique();
	lstS.unique();
	check_list(lstF, lstS);

	lstF.unique(same_length);
	lstS.unique(same_length);
	check_list(lstF, lstS);

	std::cout << "\n  --- Merge ---\n";
	lstF.merge(lstF2);
	lstS.merge(lstS2);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	lstF2.push_back("abcg");
	lstF2.push_back("abch");
	lstF2.push_back("abce");

	lstS2.push_back("abcg");
	lstS2.push_back("abch");
	lstS2.push_back("abce");

	lstF.reverse();
	lstS.reverse();
	check_list(lstF, lstS);


	lstF.merge(lstF2, same_length);
	lstS.merge(lstS2, same_length);
	check_list(lstF, lstS);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Sort ---\n";

	lstF2.push_back("hello");
	lstF2.push_back("Hello");
	lstF2.push_back("Hola");
	lstF2.push_back("hola");

	lstS2.push_back("hello");
	lstS2.push_back("Hello");
	lstS2.push_back("Hola");
	lstS2.push_back("hola");

	lstF2.sort();
	lstS2.sort();
	check_list(lstF2, lstS2);

	lstF2.clear();
	lstS2.clear();

	lstF2.push_back("Hello");
	lstF2.push_back("Hello1");
	lstF2.push_back("Hello2");
	lstF2.push_back("hello");
	lstF2.push_back("Hola");
	lstF2.push_back("hola");
	lstF2.push_back("hellO");

	lstS2.push_back("Hello");
	lstS2.push_back("Hello1");
	lstS2.push_back("Hello2");
	lstS2.push_back("hello");
	lstS2.push_back("Hola");
	lstS2.push_back("hola");
	lstS2.push_back("hellO");

	lstF2.sort(same_length);
	lstS2.sort(same_length);
	check_list(lstF2, lstS2);

	lstF2.sort(is_greaters);
	lstS2.sort(is_greaters);
	check_list(lstF2, lstS2);

	std::cout << "\n  --- Reverse ---\n";

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

	lstF2.reverse();
	lstS2.reverse();
	check_list(lstF2, lstS2);

}

void	check_comparison(void)
{
	std::cout << "\033[1;36m\n===== Comparison =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::List<int>	lstF;
	std::list<int>	lstS;

	ft::List<int>	lstF2;
	std::list<int>	lstS2;

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	bool	valF;
	bool	valS;

	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  !=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back(1);
	lstF.push_back(5);
	lstF.push_back(4);

	lstF2.push_back(1);
	lstF2.push_back(5);

	lstS.push_back(1);
	lstS.push_back(5);
	lstS.push_back(4);

	lstS2.push_back(1);
	lstS2.push_back(5);

	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	lstF2.push_back(6);
	lstS2.push_back(6);
	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back(4);
	lstS2.push_back(4);
	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	std::cout << "\n";

}

void	check_comparison_string(void)
{
	std::cout << "\033[1;36m\n===== Comparison string =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::List<std::string>	lstF;
	std::list<std::string>	lstS;

	ft::List<std::string>	lstF2;
	std::list<std::string>	lstS2;

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	bool	valF;
	bool	valS;

	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF == lstF2);
	valS = (lstS == lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  !=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF != lstF2);
	valS = (lstS != lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF > lstF2);
	valS = (lstS > lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF < lstF2);
	valS = (lstS < lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF >= lstF2);
	valS = (lstS >= lstS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <=  ---\n";
	lstF.clear();
	lstF2.clear();
	lstS.clear();
	lstS2.clear();

	lstF.push_back("abc");
	lstF.push_back("abcd");
	lstF.push_back("abce");

	lstF2.push_back("abc");
	lstF2.push_back("abcd");

	lstS.push_back("abc");
	lstS.push_back("abcd");
	lstS.push_back("abce");

	lstS2.push_back("abc");
	lstS2.push_back("abcd");

	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	lstF2.push_back("ab");
	lstS2.push_back("ab");
	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	lstF2.pop_back();
	lstS2.pop_back();
	lstF2.push_back("abce");
	lstS2.push_back("abce");
	valF = (lstF <= lstF2);
	valS = (lstS <= lstS2);
	check_value(valF, valS);

	std::cout << "\n";

}

int main(int argc, char **argv)
{
	if (argc == 2 && *(argv[1]) == '1')
		print_value = 1;
	if (argc == 2 && *(argv[1]) == '2')
		print_error = 1;

	check_constructors();
	check_constructors_string();
	check_iterators();
	check_capacity();
	check_element_access();
	check_modifiers();
	check_modifiers_string();
	check_operations();
	check_operations_string();
	check_comparison();
	check_comparison_string();

	std::cout << "\033[1;36m\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== Total ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	std::cout << "\033[1;32mNb test OK : " << nb_OK << "/" << nb_OK + nb_KO << "\n\033[0m";
	if (nb_KO)
		std::cout << "\033[1;31mNb test KO : " << nb_KO << "/" << nb_OK + nb_KO << "\n\033[0m";
	std::cout << "\n";


	return 0;
}
