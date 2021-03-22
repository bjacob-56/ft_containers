#include "utils_main.hpp"

int	print_value = 0;
int	print_error = 0;

int	nb_OK = 0;
int	nb_KO = 0;

template <typename Key, typename T>
std::stringstream	stream_pair(std::pair<Key, T> p)
{
	std::stringstream ss;

	ss << "(" << p.first << "," << p.second << ")";
	return (ss);
}

// template <typename T>
// std::stringstream stream_map(ft::Map< Key, T> & mp)
// {
// 	std::stringstream ss;

// 	typename ft::Map< Key, T>::iterator	it;
// 	it = mp.begin();
// 	while (it != mp.end())
// 		ss << "> " << *(it++) << "\n";
// 	ss << "\n";
// 	return (ss);
// }

template <typename T, typename Key>
void	display_map(ft::Map< Key, T> & mp)
{
	typename ft::Map< Key, T>::iterator	it;
	it = mp.begin();
	std::cout << "[";
	while (it != mp.end())
	{
		std::cout << "(" << (*it).first << "," << (*it).second << ")";
		if (++it != mp.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

// template <typename T>
// void	reverse_display_map(ft::Map< Key, T> & mp)
// {
// 	typename ft::Map< Key, T>::reverse_iterator	rit = mp.rbegin();

// 	while (rit != mp.rend())
// 		std::cout << "> " << *(rit++) << "\n";
// 	std::cout << "\n";
// }

// template <typename T>
// std::stringstream	stream_real_map(std::map< Key, T> & mp)
// {
// 	std::stringstream ss;

// 	typename std::map< Key, T>::iterator	it;
// 	it = mp.begin();
// 	while (it != mp.end())
// 		ss << "> " << *(it++) << "\n";
// 	ss << "\n";
// 	return (ss);
// }

template <typename T, typename Key>
void	display_real_map(std::map< Key, T> & mp)
{
	typename std::map< Key, T>::iterator	it;
	it = mp.begin();
	std::cout << "[";
	while (it != mp.end())
	{
		std::cout << "(" << (*it).first << "," << (*it).second << ")";
		if (++it != mp.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

template < class Key, class T, class Compare, class Alloc >
void	check_map(ft::Map< Key, T, Compare, Alloc> & myLst, std::map< Key, T, Compare, Alloc> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::iterator	itF = myLst.begin();
	ss_ft << "[";
	while (itF != myLst.end())
	{
		// ss_ft << stream_pair(*(itF++));
		ss_ft << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::iterator	itS = realLst.begin();
	ss_std << "[";
	while (itS != realLst.end())
	{
		// ss_std << stream_pair(*(itS++));
		ss_std << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itS != realLst.end())
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

template < class Key, class T, class Compare, class Alloc >
void	check_map_const(const ft::Map< Key, T, Compare, Alloc> & myLst, const std::map< Key, T, Compare, Alloc> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::const_iterator	itF = myLst.begin();
	ss_ft << "[";
	while (itF != myLst.end())
	{
		ss_ft << stream_pair(*(itF++));
		if (itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::const_iterator	itS = realLst.begin();
	ss_std << "[";
	while (itS != realLst.end())
	{
		ss_std << stream_pair(*(itS++));
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

template < class Key, class T, class Compare, class Alloc >
void	check_map_reverse(ft::Map< Key, T, Compare, Alloc> & myLst, std::map< Key, T, Compare, Alloc> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << stream_pair(*(itF++));
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::reverse_iterator	itS = realLst.rbegin();
	ss_std << "[";
	while (itS != realLst.rend())
	{
		ss_std << stream_pair(*(itS++));
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


template < class Key, class T, class Compare, class Alloc >
void	check_map_const_reverse(const ft::Map< Key, T, Compare, Alloc> & myLst, const std::map< Key, T, Compare, Alloc> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::const_reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << stream_pair(*(itF++));
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::const_reverse_iterator	itS = realLst.rbegin();
	ss_std << "[";
	while (itS != realLst.rend())
	{
		ss_std << stream_pair(*(itS++));
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

	ft::Map<const int, std::string>	mpF;
	std::map<const int, std::string>	mpS;
	check_map(mpF, mpS);

	mpF.insert(std::pair<const int, std::string>(3, "3-"));
	mpF.insert(std::pair<const int, std::string>(1, "1-"));
	mpF.insert(std::pair<const int, std::string>(2, "2-"));
	mpF.insert(std::pair<const int, std::string>(4, "4-"));
	mpS.insert(std::pair<const int, std::string>(3, "3-"));
	mpS.insert(std::pair<const int, std::string>(1, "1-"));
	mpS.insert(std::pair<const int, std::string>(2, "2-"));
	mpS.insert(std::pair<const int, std::string>(4, "4-"));

	// display_map(mpF);
	// display_real_map(mpS);

	ft::Map<const int, std::string>::iterator		itbF = mpF.begin()++;
	ft::Map<const int, std::string>::iterator		iteF = mpF.end();
	std::map<const int, std::string>::iterator	itbS = mpS.begin()++;
	std::map<const int, std::string>::iterator	iteS = mpS.end();

	ft::Map<const int, std::string>		mpF2(itbF, iteF);
	std::map<const int, std::string>	mpS2(itbS, iteS);
	check_map(mpF2, mpS2);

	// display_map(mpF2);
	// display_real_map(mpS2);

	ft::Map<const int, std::string>		mpF4(mpF2);
	std::map<const int, std::string>	mpS4(mpS2);
	check_map(mpF4, mpS4);

	mpF = mpF4;
	mpS2 = mpS4;
	check_map(mpF, mpS2);

	std::cout << "\n";
}

// void	check_constructors_string(void)
// {
// 	std::cout << "\033[1;36m\n===== Constructors string =====\033[0m\n";

// 	ft::Map<std::string>	mpF;
// 	std::map<std::string>	mpS;
// 	check_map(mpF, mpS);

// 	ft::Map<std::string>	mpF2(5, "test");
// 	std::map<std::string>	mpS2(5, "test");
// 	check_map(mpF2, mpS2);

// 	ft::Map<std::string>::iterator		itbF = mpF2.begin()++;
// 	ft::Map<std::string>::iterator		iteF = mpF2.end();
// 	std::map<std::string>::iterator	itbS = mpS2.begin()++;
// 	std::map<std::string>::iterator	iteS = mpS2.end();

// 	ft::Map<std::string>	mpF3(itbF, iteF);
// 	std::map<std::string>	mpS3(itbS, iteS);
// 	check_map(mpF3, mpS3);

// 	ft::Map<std::string>	mpF4(mpF3);
// 	std::map<std::string>	mpS4(mpS3);
// 	check_map(mpF4, mpS4);

// 	mpF = mpF4;
// 	mpS2 = mpS4;
// 	check_map(mpF, mpS2);

// 	std::cout << "\n";
// }


// void	check_iterators(void)
// {
// 	std::cout << "\033[1;36m\n===== Iterators =====\033[0m\n";

// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	mpF.insert(std::pair<int, std::string>(3, "3"));
// 	mpF.insert(std::pair<int, std::string>(1, "1"));
// 	mpF.insert(std::pair<int, std::string>(2, "2"));
// 	mpF.insert(std::pair<int, std::string>(4, "4"));
// 	mpS.insert(std::pair<int, std::string>(3, "3"));
// 	mpS.insert(std::pair<int, std::string>(1, "1"));
// 	mpS.insert(std::pair<int, std::string>(2, "2"));
// 	mpS.insert(std::pair<int, std::string>(4, "4"));

// 	check_map	(mpF, mpS);
// 	check_map_const(mpF, mpS);
// 	check_map_reverse(mpF, mpS);
// 	check_map_const_reverse(mpF, mpS);

// 	std::cout << "\n";
// }

// void	check_capacity(void)
// {
// 	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	size_t	valF;
// 	size_t	valS;

// 	valF = mpF.max_size();
// 	valS = mpS.max_size();
// 	check_value(valF, valS);

// 	valF = mpF.empty();
// 	valS = mpS.empty();
// 	check_value(valF, valS);
// 	valF = mpF.size();
// 	valS = mpS.size();
// 	check_value(valF, valS);

// 	mpF.push_back(1);
// 	mpF.push_back(2);
// 	mpF.push_back(3);
// 	mpS.push_back(1);
// 	mpS.push_back(2);
// 	mpS.push_back(3);

// 	valF = mpF.empty();
// 	valS = mpS.empty();
// 	check_value(valF, valS);

// 	valF = mpF.size();
// 	valS = mpS.size();
// 	check_value(valF, valS);

// 	std::cout << "\n";
// }

// void	check_element_access(void)
// {
// 	std::cout << "\033[1;36m\n===== Element access =====\033[0m\n";

// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	int		valF;
// 	int		valS;

// 	mpF.push_back(1);
// 	mpF.push_back(2);
// 	mpF.push_back(3);
// 	mpS.push_back(1);
// 	mpS.push_back(2);
// 	mpS.push_back(3);

// 	valF = mpF.front();
// 	valS = mpS.front();
// 	check_value(valF, valS);

// 	const int		cvalF = mpF.front();
// 	const int		cvalS = mpS.front();
// 	check_value(cvalF, cvalS);

// 	valF = mpF.back();
// 	valS = mpS.back();
// 	check_value(valF, valS);

// 	const int	cvalF2 = mpF.back();
// 	const int	cvalS2 = mpS.back();
// 	check_value(cvalF2, cvalS2);

// 	std::cout << "\n";
// }

// void	check_modifiers(void)
// {
// 	std::cout << "\033[1;36m\n===== Modifiers =====\033[0m\n";

// 	std::cout << "  --- Assign ---\n";
// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	mpF.assign(5, 42);
// 	mpS.assign(5, 42);
// 	check_map(mpF, mpS);

// 	ft::Map<int, std::string>	mpF2;
// 	std::map<int, std::string>	mpS2;

// 	ft::Map<int, std::string>::iterator		itbF = mpF.begin()++;
// 	ft::Map<int, std::string>::iterator		iteF = mpF.end()--;
// 	std::map<int, std::string>::iterator	itbS = mpS.begin()++;
// 	std::map<int, std::string>::iterator	iteS = mpS.end()--;
	
// 	mpF.assign(itbF, iteF);
// 	mpS.assign(itbS, iteS);
// 	check_map(mpF2, mpS2, 1);

// 	std::cout << "\n  --- Push/Pop_Front/Back ---\n";

// 	mpF2.push_front(2);
// 	mpF2.push_front(1);
// 	mpS2.push_front(2);
// 	mpS2.push_front(1);
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back(3);
// 	mpF2.push_back(5);
// 	mpS2.push_back(3);
// 	mpS2.push_back(5);
// 	check_map(mpF2, mpS2);

// 	mpF2.pop_front();
// 	mpS2.pop_front();
// 	check_map(mpF2, mpS2);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	check_map(mpF2, mpS2);


// 	std::cout << "\n  --- Insert ---\n";

// 	ft::Map<int, std::string>::iterator		itbF2 = ++mpF2.begin();
// 	std::map<int, std::string>::iterator	itbS2 = ++mpS2.begin();

// 	itbF2 = mpF2.insert(itbF2, 56);
// 	itbS2 = mpS2.insert(itbS2, 56);
// 	check_map(mpF2, mpS2);

// 	mpF2.insert(itbF2, 5, 93);
// 	mpS2.insert(itbS2, 5, 93);
// 	check_map(mpF2, mpS2);

// 	mpF2.insert(itbF2, itbF, iteF);
// 	mpS2.insert(itbS2, itbS, iteS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Erase ---\n";
// 	itbF2 = mpF2.erase(--itbF2);
// 	itbS2 = mpS2.erase(--itbS2);
// 	check_map(mpF2, mpS2);

// 	ft::Map<int, std::string>::iterator		iteF2 = --mpF2.end();
// 	std::map<int, std::string>::iterator	iteS2 = --mpS2.end();

// 	itbF2 = ++mpF2.begin();
// 	itbS2 = ++mpS2.begin();

// 	mpF2.erase(itbF2, iteF2);
// 	mpS2.erase(itbS2, iteS2);
// 	check_map(mpF2, mpS2);


// 	std::cout << "\n  --- Swap ---\n";
// 	mpF.swap(mpF2);
// 	mpS.swap(mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	swap(mpF, mpF2);
// 	swap(mpS, mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Resize ---\n";
// 	mpF2.resize(0);
// 	mpS2.resize(0);
// 	check_map(mpF2, mpS2);
	
// 	mpF2.resize(12, -42);
// 	mpS2.resize(12, -42);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Clear ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n";
// }

// void	check_modifiers_string(void)
// {
// 	std::cout << "\033[1;36m\n===== Modifiers string =====\033[0m\n";

// 	std::cout << "  --- Assign ---\n";
// 	ft::Map<std::string>	mpF;
// 	std::map<std::string>	mpS;

// 	mpF.assign(5, "test");
// 	mpS.assign(5, "test");
// 	check_map(mpF, mpS);

// 	ft::Map<std::string>	mpF2;
// 	std::map<std::string>	mpS2;

// 	ft::Map<std::string>::iterator		itbF = mpF.begin()++;
// 	ft::Map<std::string>::iterator		iteF = mpF.end()--;
// 	std::map<std::string>::iterator	itbS = mpS.begin()++;
// 	std::map<std::string>::iterator	iteS = mpS.end()--;
	
// 	mpF.assign(itbF, iteF);
// 	mpS.assign(itbS, iteS);
// 	check_map(mpF2, mpS2, 1);

// 	std::cout << "\n  --- Push/Pop_Front/Back ---\n";

// 	mpF2.push_front("bla");
// 	mpF2.push_front("tree");
// 	mpS2.push_front("bla");
// 	mpS2.push_front("tree");
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back("What is this?");
// 	mpF2.push_back("Yellow Sub");
// 	mpS2.push_back("What is this?");
// 	mpS2.push_back("Yellow Sub");
// 	check_map(mpF2, mpS2);

// 	mpF2.pop_front();
// 	mpS2.pop_front();
// 	check_map(mpF2, mpS2);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	check_map(mpF2, mpS2);


// 	std::cout << "\n  --- Insert ---\n";

// 	ft::Map<std::string>::iterator		itbF2 = ++mpF2.begin();
// 	std::map<std::string>::iterator	itbS2 = ++mpS2.begin();

// 	itbF2 = mpF2.insert(itbF2, "42");
// 	itbS2 = mpS2.insert(itbS2, "42");
// 	check_map(mpF2, mpS2);

// 	mpF2.insert(itbF2, 5, "Ab64");
// 	mpS2.insert(itbS2, 5, "Ab64");
// 	check_map(mpF2, mpS2);

// 	mpF2.insert(itbF2, itbF, iteF);
// 	mpS2.insert(itbS2, itbS, iteS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Erase ---\n";
// 	itbF2 = mpF2.erase(--itbF2);
// 	itbS2 = mpS2.erase(--itbS2);
// 	check_map(mpF2, mpS2);

// 	ft::Map<std::string>::iterator		iteF2 = --mpF2.end();
// 	std::map<std::string>::iterator	iteS2 = --mpS2.end();

// 	itbF2 = ++mpF2.begin();
// 	itbS2 = ++mpS2.begin();

// 	mpF2.erase(itbF2, iteF2);
// 	mpS2.erase(itbS2, iteS2);
// 	check_map(mpF2, mpS2);


// 	std::cout << "\n  --- Swap ---\n";
// 	mpF.swap(mpF2);
// 	mpS.swap(mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	swap(mpF, mpF2);
// 	swap(mpS, mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Resize ---\n";
// 	mpF2.resize(0);
// 	mpS2.resize(0);
// 	check_map(mpF2, mpS2);
	
// 	mpF2.resize(12, "new str");
// 	mpS2.resize(12, "new str");
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Clear ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n";
// }

// void	check_operations(void)
// {
// 	std::cout << "\033[1;36m\n===== Operations =====\033[0m\n";

// 	std::cout << "  --- Splice ---\n";
// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	ft::Map<int, std::string>	mpF2;
// 	std::map<int, std::string>	mpS2;

// 	mpF.push_back(1);
// 	mpF.push_back(4);
// 	mpF.push_back(5);

// 	mpF2.push_back(2);
// 	mpF2.push_back(3);

// 	mpS.push_back(1);
// 	mpS.push_back(4);
// 	mpS.push_back(5);

// 	mpS2.push_back(2);
// 	mpS2.push_back(3);

// 	ft::Map<int, std::string>::iterator		itbF = ++mpF.begin();
// 	std::map<int, std::string>::iterator	itbS = ++mpS.begin();

// 	mpF.splice(itbF, mpF2);
// 	mpS.splice(itbS, mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back(6);
// 	mpF2.push_back(7);
// 	mpF2.push_back(8);
// 	mpF2.push_back(9);
// 	mpF2.push_back(10);

// 	mpS2.push_back(6);
// 	mpS2.push_back(7);
// 	mpS2.push_back(8);
// 	mpS2.push_back(9);
// 	mpS2.push_back(10);

// 	mpF.splice(mpF.end(), mpF2, ++mpF2.begin());
// 	mpS.splice(mpS.end(), mpS2, ++mpS2.begin());
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF.splice(mpF.end(), mpF2, ++mpF2.begin(), --mpF2.end());
// 	mpS.splice(mpS.end(), mpS2, ++mpS2.begin(), --mpS2.end());
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Remove/Remove_if ---\n";

// 	ft::Map<int, std::string>	mpF3;
// 	std::map<int, std::string>	mpS3;

// 	mpF3.remove(2);
// 	mpS3.remove(2);
// 	check_map(mpF3, mpS3);

// 	mpF.push_back(2);
// 	mpS.push_back(2);
// 	mpF.remove(2);
// 	mpS.remove(2);
// 	check_map(mpF, mpS);

// 	mpF.remove(2);
// 	mpS.remove(2);
// 	check_map(mpF, mpS);

// 	mpF.remove_if(is_even);
// 	mpS.remove_if(is_even);
// 	check_map(mpF, mpS);

// 	std::cout << "\n  --- Unique ---\n";

// 	mpF.push_front(10);
// 	mpF.push_front(10);
// 	mpS.push_front(10);
// 	mpS.push_front(10);
// 	mpF.push_front(-5);
// 	mpF.push_front(-5);
// 	mpS.push_front(-5);
// 	mpS.push_front(-5);
// 	mpF.push_front(-10);
// 	mpF.push_front(-10);
// 	mpS.push_front(-10);
// 	mpS.push_front(-10);
// 	mpF.unique();
// 	mpS.unique();
// 	check_map(mpF, mpS);

// 	mpF.unique(are_factor_five);
// 	mpS.unique(are_factor_five);
// 	check_map(mpF, mpS);

// 	std::cout << "\n  --- Merge ---\n";
// 	mpF.merge(mpF2);
// 	mpS.merge(mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back(8);
// 	mpF2.push_back(4);
// 	mpF2.push_back(2);

// 	mpS2.push_back(8);
// 	mpS2.push_back(4);
// 	mpS2.push_back(2);

// 	mpF.reverse();
// 	mpS.reverse();
// 	mpF.merge(mpF2, is_greater);
// 	mpS.merge(mpS2, is_greater);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Sort ---\n";

// 	mpF2.push_back(100);
// 	mpF2.push_back(-22);
// 	mpF2.push_back(9);
// 	mpF2.push_back(-42);
// 	mpF2.push_back(56);
// 	mpF2.push_back(9);
// 	mpF2.push_back(93);

// 	mpS2.push_back(100);
// 	mpS2.push_back(-22);
// 	mpS2.push_back(9);
// 	mpS2.push_back(-42);
// 	mpS2.push_back(56);
// 	mpS2.push_back(9);
// 	mpS2.push_back(93);

// 	mpF2.sort();
// 	mpS2.sort();
// 	check_map(mpF2, mpS2);

// 	mpF2.clear();
// 	mpS2.clear();

// 	mpF2.push_back(100);
// 	mpF2.push_back(-22);
// 	mpF2.push_back(9);
// 	mpF2.push_back(-42);
// 	mpF2.push_back(56);
// 	mpF2.push_back(9);
// 	mpF2.push_back(93);

// 	mpS2.push_back(100);
// 	mpS2.push_back(-22);
// 	mpS2.push_back(9);
// 	mpS2.push_back(-42);
// 	mpS2.push_back(56);
// 	mpS2.push_back(9);
// 	mpS2.push_back(93);

// 	mpF2.sort(is_greater);
// 	mpS2.sort(is_greater);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Reverse ---\n";

// 	mpF2.reverse();
// 	mpS2.reverse();
// 	check_map(mpF2, mpS2);

// 	mpF2.reverse();
// 	mpS2.reverse();
// 	check_map(mpF2, mpS2);

// }

// void	check_operations_string(void)
// {
// 	std::cout << "\033[1;36m\n===== Operations String =====\033[0m\n";

// 	std::cout << "  --- Splice ---\n";
// 	ft::Map<std::string>	mpF;
// 	std::map<std::string>	mpS;

// 	ft::Map<std::string>	mpF2;
// 	std::map<std::string>	mpS2;

// 	mpF.push_back("test");
// 	mpF.push_back("bla");
// 	mpF.push_back("tree");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("test");
// 	mpS.push_back("bla");
// 	mpS.push_back("tree");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	ft::Map<std::string>::iterator		itbF = ++mpF.begin();
// 	std::map<std::string>::iterator	itbS = ++mpS.begin();

// 	mpF.splice(itbF, mpF2);
// 	mpS.splice(itbS, mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back("abce");
// 	mpF2.push_back("abcf");
// 	mpF2.push_back("abcg");
// 	mpF2.push_back("abch");
// 	mpF2.push_back("abci");

// 	mpS2.push_back("abce");
// 	mpS2.push_back("abcf");
// 	mpS2.push_back("abcg");
// 	mpS2.push_back("abch");
// 	mpS2.push_back("abci");

// 	mpF.splice(mpF.end(), mpF2, ++mpF2.begin());
// 	mpS.splice(mpS.end(), mpS2, ++mpS2.begin());
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF.splice(mpF.end(), mpF2, ++mpF2.begin(), --mpF2.end());
// 	mpS.splice(mpS.end(), mpS2, ++mpS2.begin(), --mpS2.end());
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Remove/Remove_if ---\n";

// 	ft::Map<std::string>	mpF3;
// 	std::map<std::string>	mpS3;

// 	mpF3.remove("abc");
// 	mpS3.remove("abc");
// 	check_map(mpF3, mpS3);

// 	mpF.push_back("abc");
// 	mpS.push_back("abc");
// 	mpF.remove("abc");
// 	mpS.remove("abc");
// 	check_map(mpF, mpS);

// 	mpF.remove("abc");
// 	mpS.remove("abc");
// 	check_map(mpF, mpS);

// 	mpF.remove_if(has_length_3);
// 	mpS.remove_if(has_length_3);
// 	check_map(mpF, mpS);

// 	std::cout << "\n  --- Unique ---\n";

// 	mpF.push_front("bcd");
// 	mpF.push_front("bcd");
// 	mpS.push_front("bcd");
// 	mpS.push_front("bcd");
// 	mpF.push_front("bbb");
// 	mpF.push_front("bbb");
// 	mpS.push_front("bbb");
// 	mpS.push_front("bbb");
// 	mpF.push_front("bcc");
// 	mpF.push_front("bcc");
// 	mpS.push_front("bcc");
// 	mpS.push_front("bcc");
// 	mpF.unique();
// 	mpS.unique();
// 	check_map(mpF, mpS);

// 	mpF.unique(same_length);
// 	mpS.unique(same_length);
// 	check_map(mpF, mpS);

// 	std::cout << "\n  --- Merge ---\n";
// 	mpF.merge(mpF2);
// 	mpS.merge(mpS2);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	mpF2.push_back("abcg");
// 	mpF2.push_back("abch");
// 	mpF2.push_back("abce");

// 	mpS2.push_back("abcg");
// 	mpS2.push_back("abch");
// 	mpS2.push_back("abce");

// 	mpF.reverse();
// 	mpS.reverse();
// 	check_map(mpF, mpS);


// 	mpF.merge(mpF2, same_length);
// 	mpS.merge(mpS2, same_length);
// 	check_map(mpF, mpS);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Sort ---\n";

// 	mpF2.push_back("hello");
// 	mpF2.push_back("Hello");
// 	mpF2.push_back("Hola");
// 	mpF2.push_back("hola");

// 	mpS2.push_back("hello");
// 	mpS2.push_back("Hello");
// 	mpS2.push_back("Hola");
// 	mpS2.push_back("hola");

// 	mpF2.sort();
// 	mpS2.sort();
// 	check_map(mpF2, mpS2);

// 	mpF2.clear();
// 	mpS2.clear();

// 	mpF2.push_back("Hello");
// 	mpF2.push_back("Hello1");
// 	mpF2.push_back("Hello2");
// 	mpF2.push_back("hello");
// 	mpF2.push_back("Hola");
// 	mpF2.push_back("hola");
// 	mpF2.push_back("hellO");

// 	mpS2.push_back("Hello");
// 	mpS2.push_back("Hello1");
// 	mpS2.push_back("Hello2");
// 	mpS2.push_back("hello");
// 	mpS2.push_back("Hola");
// 	mpS2.push_back("hola");
// 	mpS2.push_back("hellO");

// 	mpF2.sort(same_length);
// 	mpS2.sort(same_length);
// 	check_map(mpF2, mpS2);

// 	mpF2.sort(is_greaters);
// 	mpS2.sort(is_greaters);
// 	check_map(mpF2, mpS2);

// 	std::cout << "\n  --- Reverse ---\n";

// 	mpF2.reverse();
// 	mpS2.reverse();
// 	check_map(mpF2, mpS2);

// 	mpF2.reverse();
// 	mpS2.reverse();
// 	check_map(mpF2, mpS2);

// }

// void	check_comparison(void)
// {
// 	std::cout << "\033[1;36m\n===== Comparison =====\033[0m\n";

// 	std::cout << "  ---  ==  ---\n";
// 	ft::Map<int, std::string>	mpF;
// 	std::map<int, std::string>	mpS;

// 	ft::Map<int, std::string>	mpF2;
// 	std::map<int, std::string>	mpS2;

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	bool	valF;
// 	bool	valS;

// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  !=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  >  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  <  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  >=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  <=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back(1);
// 	mpF.push_back(5);
// 	mpF.push_back(4);

// 	mpF2.push_back(1);
// 	mpF2.push_back(5);

// 	mpS.push_back(1);
// 	mpS.push_back(5);
// 	mpS.push_back(4);

// 	mpS2.push_back(1);
// 	mpS2.push_back(5);

// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back(6);
// 	mpS2.push_back(6);
// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back(4);
// 	mpS2.push_back(4);
// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n";

// }

// void	check_comparison_string(void)
// {
// 	std::cout << "\033[1;36m\n===== Comparison string =====\033[0m\n";

// 	std::cout << "  ---  ==  ---\n";
// 	ft::Map<std::string>	mpF;
// 	std::map<std::string>	mpS;

// 	ft::Map<std::string>	mpF2;
// 	std::map<std::string>	mpS2;

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	bool	valF;
// 	bool	valS;

// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF == mpF2);
// 	valS = (mpS == mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  !=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF != mpF2);
// 	valS = (mpS != mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  >  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF > mpF2);
// 	valS = (mpS > mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  <  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF < mpF2);
// 	valS = (mpS < mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  >=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF >= mpF2);
// 	valS = (mpS >= mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n  ---  <=  ---\n";
// 	mpF.clear();
// 	mpF2.clear();
// 	mpS.clear();
// 	mpS2.clear();

// 	mpF.push_back("abc");
// 	mpF.push_back("abcd");
// 	mpF.push_back("abce");

// 	mpF2.push_back("abc");
// 	mpF2.push_back("abcd");

// 	mpS.push_back("abc");
// 	mpS.push_back("abcd");
// 	mpS.push_back("abce");

// 	mpS2.push_back("abc");
// 	mpS2.push_back("abcd");

// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	mpF2.push_back("ab");
// 	mpS2.push_back("ab");
// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	mpF2.pop_back();
// 	mpS2.pop_back();
// 	mpF2.push_back("abce");
// 	mpS2.push_back("abce");
// 	valF = (mpF <= mpF2);
// 	valS = (mpS <= mpS2);
// 	check_value(valF, valS);

// 	std::cout << "\n";

// }

int main(int argc, char **argv)
{
	if (argc == 2 && *(argv[1]) == '1')
		print_value = 1;
	if (argc == 2 && *(argv[1]) == '2')
		print_error = 1;

	check_constructors();
	// check_constructors_string();
	// check_iterators();
	// check_capacity();
	// check_element_access();
	// check_modifiers();
	// check_modifiers_string();
	// check_operations();
	// check_operations_string();
	// check_comparison();
	// check_comparison_string();

	std::cout << "\033[1;36m\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== Total ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	std::cout << "\033[1;32mNb test OK : " << nb_OK << "/" << nb_OK + nb_KO << "\n\033[0m";
	if (nb_KO)
		std::cout << "\033[1;31mNb test KO : " << nb_KO << "/" << nb_OK + nb_KO << "\n\033[0m";
	std::cout << "\n";


	return 0;
}
