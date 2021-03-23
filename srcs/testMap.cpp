#include "utils_main.hpp"

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
void	check_map(ft::Map< Key, T, Compare, Alloc> & myMap, std::map< Key, T, Compare, Alloc> & realMap, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::iterator	itF = myMap.begin();
	ss_ft << "[";
	while (itF != myMap.end())
	{
		// ss_ft << stream_pair(*(itF++));
		ss_ft << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itF != myMap.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::iterator	itS = realMap.begin();
	ss_std << "[";
	while (itS != realMap.end())
	{
		// ss_std << stream_pair(*(itS++));
		ss_std << "(" << (*itS).first << "," << (*itS).second << ")";
		if (++itS != realMap.end())
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
		myMap.clear();
		realMap.clear();
	}
}

template < class Key, class T, class Compare, class Alloc >
void	check_map_const(const ft::Map< Key, T, Compare, Alloc> & myMap, const std::map< Key, T, Compare, Alloc> & realMap)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::const_iterator	itF = myMap.begin();
	ss_ft << "[";
	while (itF != myMap.end())
	{
		// ss_ft << stream_pair(*(itF++));
		ss_ft << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itF != myMap.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::const_iterator	itS = realMap.begin();
	ss_std << "[";
	while (itS != realMap.end())
	{
		// ss_std << stream_pair(*(itS++));
		ss_std << "(" << (*itS).first << "," << (*itS).second << ")";
		if (++itS != realMap.end())
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
void	check_map_reverse(ft::Map< Key, T, Compare, Alloc> & myMap, std::map< Key, T, Compare, Alloc> & realMap, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::reverse_iterator	itF = myMap.rbegin();
	ss_ft << "[";
	while (itF != myMap.rend())
	{
		// ss_ft << stream_pair(*(itF++));
		ss_ft << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itF != myMap.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::reverse_iterator	itS = realMap.rbegin();
	ss_std << "[";
	while (itS != realMap.rend())
	{
		// ss_std << stream_pair(*(itS++));
		ss_std << "(" << (*itS).first << "," << (*itS).second << ")";
		if (++itS != realMap.rend())
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
		myMap.clear();
		realMap.clear();
	}
}


template < class Key, class T, class Compare, class Alloc >
void	check_map_const_reverse(const ft::Map< Key, T, Compare, Alloc> & myMap, const std::map< Key, T, Compare, Alloc> & realMap)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Map< Key, T>::const_reverse_iterator	itF = myMap.rbegin();
	ss_ft << "[";
	while (itF != myMap.rend())
	{
		// ss_ft << stream_pair(*(itF++));
		ss_ft << "(" << (*itF).first << "," << (*itF).second << ")";
		if (++itF != myMap.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::map< Key, T>::const_reverse_iterator	itS = realMap.rbegin();
	ss_std << "[";
	while (itS != realMap.rend())
	{
		// ss_std << stream_pair(*(itS++));
		ss_std << "(" << (*itS).first << "," << (*itS).second << ")";
		if (++itS != realMap.rend())
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
static void	check_value(T & valF, T & valS)
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


void	map_check_constructors(void)
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

	ft::Map<const int, std::string>::iterator	itbF = ++mpF.begin();
	ft::Map<const int, std::string>::iterator	iteF = mpF.end();
	std::map<const int, std::string>::iterator	itbS = ++mpS.begin();
	std::map<const int, std::string>::iterator	iteS = mpS.end();

	ft::Map<const int, std::string>		mpF2(itbF, iteF);
	std::map<const int, std::string>	mpS2(itbS, iteS);
	check_map(mpF2, mpS2);

	ft::Map<const int, std::string>		mpF4(mpF2);
	std::map<const int, std::string>	mpS4(mpS2);
	check_map(mpF4, mpS4);

	mpF = mpF4;
	mpS2 = mpS4;
	check_map(mpF, mpS2);

	std::cout << "\n";
}

void	map_check_constructors_string(void)
{
	std::cout << "\033[1;36m\n===== Constructors string =====\033[0m\n";

	ft::Map<const std::string, std::string>	mpF;
	std::map<const std::string, std::string>	mpS;
	check_map(mpF, mpS);

	mpF.insert(std::pair<const std::string, std::string>("key3", "val3"));
	mpF.insert(std::pair<const std::string, std::string>("key1", "val1"));
	mpF.insert(std::pair<const std::string, std::string>("key2", "val2"));
	mpF.insert(std::pair<const std::string, std::string>("key4", "val4"));
	mpS.insert(std::pair<const std::string, std::string>("key3", "val3"));
	mpS.insert(std::pair<const std::string, std::string>("key1", "val1"));
	mpS.insert(std::pair<const std::string, std::string>("key2", "val2"));
	mpS.insert(std::pair<const std::string, std::string>("key4", "val4"));

	// display_map(mpF);
	// display_real_map(mpS);

	ft::Map<const std::string, std::string>::iterator	itbF = ++mpF.begin();
	ft::Map<const std::string, std::string>::iterator	iteF = mpF.end();
	std::map<const std::string, std::string>::iterator	itbS = ++mpS.begin();
	std::map<const std::string, std::string>::iterator	iteS = mpS.end();

	ft::Map<const std::string, std::string>		mpF2(itbF, iteF);
	std::map<const std::string, std::string>	mpS2(itbS, iteS);
	check_map(mpF2, mpS2);

	ft::Map<const std::string, std::string>		mpF4(mpF2);
	std::map<const std::string, std::string>	mpS4(mpS2);
	check_map(mpF4, mpS4);

	mpF = mpF4;
	mpS2 = mpS4;
	check_map(mpF, mpS2);

	std::cout << "\n";
}


void	map_check_iterators(void)
{
	std::cout << "\033[1;36m\n===== Iterators =====\033[0m\n";

	ft::Map<int, std::string>	mpF;
	std::map<int, std::string>	mpS;

	mpF.insert(std::pair<int, std::string>(3, "3"));
	mpF.insert(std::pair<int, std::string>(1, "1"));
	mpF.insert(std::pair<int, std::string>(2, "2"));
	mpF.insert(std::pair<int, std::string>(4, "4"));
	mpS.insert(std::pair<int, std::string>(3, "3"));
	mpS.insert(std::pair<int, std::string>(1, "1"));
	mpS.insert(std::pair<int, std::string>(2, "2"));
	mpS.insert(std::pair<int, std::string>(4, "4"));

	check_map	(mpF, mpS);
	check_map_const(mpF, mpS);
	check_map_reverse(mpF, mpS);
	check_map_const_reverse(mpF, mpS);

	std::cout << "\n";
}

void	map_check_capacity(void)
{
	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

	ft::Map<const std::string, std::string>	mpF;
	std::map<const std::string, std::string>	mpS;

	size_t	valF;
	size_t	valS;

	valF = mpF.max_size();
	valS = mpS.max_size();
	check_value(valF, valS);

	valF = mpF.empty();
	valS = mpS.empty();
	check_value(valF, valS);
	valF = mpF.size();
	valS = mpS.size();
	check_value(valF, valS);


	mpF.insert(std::pair<const std::string, std::string>("key3", "val3"));
	mpF.insert(std::pair<const std::string, std::string>("key1", "val1"));
	mpF.insert(std::pair<const std::string, std::string>("key2", "val2"));
	mpF.insert(std::pair<const std::string, std::string>("key4", "val4"));
	mpS.insert(std::pair<const std::string, std::string>("key3", "val3"));
	mpS.insert(std::pair<const std::string, std::string>("key1", "val1"));
	mpS.insert(std::pair<const std::string, std::string>("key2", "val2"));
	mpS.insert(std::pair<const std::string, std::string>("key4", "val4"));

	valF = mpF.empty();
	valS = mpS.empty();
	check_value(valF, valS);

	valF = mpF.size();
	valS = mpS.size();
	check_value(valF, valS);

	std::cout << "\n";
}

void	map_check_element_access(void)
{
	std::cout << "\033[1;36m\n===== Element access =====\033[0m\n";

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

	std::string	valF;
	std::string	valS;

	valF = mpF[2];
	valS = mpS[2];
	check_value(valF, valS);

	const std::string		cvalF = mpF[4];
	const std::string		cvalS = mpS[4];
	check_value(cvalF, cvalS);

	const std::string	cvalF2 = mpF[1];
	const std::string	cvalS2 = mpS[1];
	check_value(cvalF2, cvalS2);

	valF = mpF[5];
	valS = mpS[5];
	check_value(valF, valS);

	std::cout << "\n";
}

void	map_check_modifiers(void)
{
	std::cout << "\033[1;36m\n===== Modifiers =====\033[0m\n";

	ft::Map<const int, std::string>		mpF;
	std::map<const int, std::string>	mpS;

	std::cout << "\n  --- Insert ---\n";

	
	mpF.insert(std::pair<const int, std::string>(3, "3-"));
	mpF.insert(std::pair<const int, std::string>(1, "1-"));
	mpF.insert(std::pair<const int, std::string>(9, "9-"));
	mpF.insert(std::pair<const int, std::string>(6, "6-"));
	mpS.insert(std::pair<const int, std::string>(3, "3-"));
	mpS.insert(std::pair<const int, std::string>(1, "1-"));
	mpS.insert(std::pair<const int, std::string>(9, "9-"));
	mpS.insert(std::pair<const int, std::string>(6, "6-"));

	ft::Map<const int, std::string>::iterator		itbF = ++mpF.begin();
	std::map<const int, std::string>::iterator	itbS = ++mpS.begin();

	mpF.insert(itbF, std::pair<const int, std::string>(5, "5-"));
	mpS.insert(itbS, std::pair<const int, std::string>(5, "5-"));
	check_map(mpF, mpS);

	ft::Map<const int, std::string>		mpF2;
	std::map<const int, std::string>	mpS2;

	mpF2.insert(std::pair<const int, std::string>(8, "8-"));
	mpF2.insert(std::pair<const int, std::string>(4, "4-"));
	mpF2.insert(std::pair<const int, std::string>(2, "2-"));
	mpS2.insert(std::pair<const int, std::string>(8, "8-"));
	mpS2.insert(std::pair<const int, std::string>(4, "4-"));
	mpS2.insert(std::pair<const int, std::string>(2, "2-"));

	ft::Map<const int, std::string>::iterator		itbF2 = mpF2.begin();
	std::map<const int, std::string>::iterator	itbS2 = mpS2.begin();
	ft::Map<const int, std::string>::iterator		iteF2 = mpF2.end();
	std::map<const int, std::string>::iterator	iteS2 = mpS2.end();

	mpF.insert(itbF2, iteF2);
	mpS.insert(itbS2, iteS2);
	check_map(mpF, mpS);

	std::cout << "\n  --- Erase ---\n";

	itbF = ++mpF.begin();
	itbS = ++mpS.begin();
	ft::Map<const int, std::string>::iterator		iteF = --mpF.end();
	std::map<const int, std::string>::iterator	iteS = --mpS.end();

	mpF.erase(itbF);
	mpS.erase(itbS);
	check_map(mpF, mpS);

	itbF = ++mpF.begin();
	itbS = ++mpS.begin();

	for(int i = 0; i < 3; i++)
	{
		iteF--;
		iteS--;
	}

	mpF.erase(itbF, iteF);
	mpS.erase(itbS, iteS);
	check_map(mpF, mpS);

	size_t	valF;
	size_t	valS;

	valF = mpF.erase(15);
	valS = mpS.erase(15);
	check_map(mpF, mpS);
	check_value(valF, valS);

	valF = mpF.erase(6);
	valS = mpS.erase(6);
	check_map(mpF, mpS);
	check_value(valF, valS);

	std::cout << "\n  --- Swap ---\n";
	mpF.swap(mpF2);
	mpS.swap(mpS2);
	check_map(mpF, mpS);
	check_map(mpF2, mpS2);

	std::cout << "\n  --- Clear ---\n";
	mpF.clear();
	mpF2.clear();
	mpS.clear();
	mpS2.clear();
	check_map(mpF, mpS);
	check_map(mpF2, mpS2);

	std::cout << "\n";
}

void	map_check_modifiers_string(void)
{
	std::cout << "\033[1;36m\n===== Modifiers string =====\033[0m\n";

	ft::Map<const std::string, std::string>		mpF;
	std::map<const std::string, std::string>	mpS;

	std::cout << "\n  --- Insert ---\n";

	
	mpF.insert(std::pair<const std::string, std::string>("3", "3-"));
	mpF.insert(std::pair<const std::string, std::string>("1", "1-"));
	mpF.insert(std::pair<const std::string, std::string>("9", "9-"));
	mpF.insert(std::pair<const std::string, std::string>("6", "6-"));
	mpS.insert(std::pair<const std::string, std::string>("3", "3-"));
	mpS.insert(std::pair<const std::string, std::string>("1", "1-"));
	mpS.insert(std::pair<const std::string, std::string>("9", "9-"));
	mpS.insert(std::pair<const std::string, std::string>("6", "6-"));

	ft::Map<const std::string, std::string>::iterator		itbF = ++mpF.begin();
	std::map<const std::string, std::string>::iterator	itbS = ++mpS.begin();

	mpF.insert(itbF, std::pair<const std::string, std::string>("5", "5-"));
	mpS.insert(itbS, std::pair<const std::string, std::string>("5", "5-"));
	check_map(mpF, mpS);

	ft::Map<const std::string, std::string>		mpF2;
	std::map<const std::string, std::string>	mpS2;

	mpF2.insert(std::pair<const std::string, std::string>("8", "8-"));
	mpF2.insert(std::pair<const std::string, std::string>("4", "4-"));
	mpF2.insert(std::pair<const std::string, std::string>("2", "2-"));
	mpS2.insert(std::pair<const std::string, std::string>("8", "8-"));
	mpS2.insert(std::pair<const std::string, std::string>("4", "4-"));
	mpS2.insert(std::pair<const std::string, std::string>("2", "2-"));

	ft::Map<const std::string, std::string>::iterator		itbF2 = mpF2.begin();
	std::map<const std::string, std::string>::iterator	itbS2 = mpS2.begin();
	ft::Map<const std::string, std::string>::iterator		iteF2 = mpF2.end();
	std::map<const std::string, std::string>::iterator	iteS2 = mpS2.end();

	mpF.insert(itbF2, iteF2);
	mpS.insert(itbS2, iteS2);
	check_map(mpF, mpS);

	std::cout << "\n  --- Erase ---\n";

	itbF = ++mpF.begin();
	itbS = ++mpS.begin();
	ft::Map<const std::string, std::string>::iterator		iteF = --mpF.end();
	std::map<const std::string, std::string>::iterator	iteS = --mpS.end();

	mpF.erase(itbF);
	mpS.erase(itbS);
	check_map(mpF, mpS);

	itbF = ++mpF.begin();
	itbS = ++mpS.begin();

	for(int i = 0; i < 3; i++)
	{
		iteF--;
		iteS--;
	}

	mpF.erase(itbF, iteF);
	mpS.erase(itbS, iteS);
	check_map(mpF, mpS);

	size_t	valF;
	size_t	valS;

	valF = mpF.erase("15");
	valS = mpS.erase("15");
	check_map(mpF, mpS);
	check_value(valF, valS);

	valF = mpF.erase("6");
	valS = mpS.erase("6");
	check_map(mpF, mpS);
	check_value(valF, valS);

	std::cout << "\n  --- Swap ---\n";
	mpF.swap(mpF2);
	mpS.swap(mpS2);
	check_map(mpF, mpS);
	check_map(mpF2, mpS2);

	std::cout << "\n  --- Clear ---\n";
	mpF.clear();
	mpF2.clear();
	mpS.clear();
	mpS2.clear();
	check_map(mpF, mpS);
	check_map(mpF2, mpS2);

	std::cout << "\n";
}

void	map_check_operations(void)
{
	std::cout << "\033[1;36m\n===== Operations =====\033[0m\n";

	std::cout << "  --- Find ---\n";
	
	ft::Map<const int, std::string>		mpF;
	std::map<const int, std::string>	mpS;
	
	mpF.insert(std::pair<const int, std::string>(3, "3-"));
	mpF.insert(std::pair<const int, std::string>(1, "1-"));
	mpF.insert(std::pair<const int, std::string>(9, "9-"));
	mpF.insert(std::pair<const int, std::string>(6, "6-"));
	mpS.insert(std::pair<const int, std::string>(3, "3-"));
	mpS.insert(std::pair<const int, std::string>(1, "1-"));
	mpS.insert(std::pair<const int, std::string>(9, "9-"));
	mpS.insert(std::pair<const int, std::string>(6, "6-"));

	check_map(mpF, mpS);

	ft::Map<const int, std::string>::iterator	itF;
	std::map<const int, std::string>::iterator	itS;

	ft::Map<const int, std::string>::const_iterator		citF;
	std::map<const int, std::string>::const_iterator	citS;

	size_t	valF;
	size_t	valS;

	itF = mpF.find(3);
	itS = mpS.find(3);
	check_value((*itF).second, (*itS).second);

	itF = mpF.find(5);
	itS = mpS.find(5);
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Count ---\n";

	valF = mpF.count(9);
	valS = mpS.count(9);
	check_value(valF, valS);

	valF = mpF.count(42);
	valS = mpS.count(42);
	check_value(valF, valS);

	std::cout << "\n  --- Lower_bound ---\n";

	itF = mpF.lower_bound(5);
	itS = mpS.lower_bound(5);
	check_value((*itF).second, (*itS).second);

	itF = mpF.lower_bound(-42);
	itS = mpS.lower_bound(-42);
	check_value((*itF).second, (*itS).second);

	itF = mpF.lower_bound(42);
	itS = mpS.lower_bound(42);
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Upper_bound ---\n";
	
	itF = mpF.upper_bound(5);
	itS = mpS.upper_bound(5);
	check_value((*itF).second, (*itS).second);

	itF = mpF.upper_bound(-42);
	itS = mpS.upper_bound(-42);
	check_value((*itF).second, (*itS).second);


	itF = mpF.upper_bound(42);
	itS = mpS.upper_bound(42);
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Equal_range ---\n";

	std::pair<ft::Map<const int, std::string>::iterator,ft::Map<const int, std::string>::iterator> paF;
	std::pair<std::map<const int, std::string>::iterator,std::map<const int, std::string>::iterator> paS;

	paF = mpF.equal_range(6);
	paS = mpS.equal_range(6);
	check_value((*(paF.first)).second, (*(paS.first)).second);

	paF = mpF.equal_range(-42);
	paS = mpS.equal_range(-42);
	valF = (paF.first == mpF.end());
	valS = (paS.first == mpS.end());
	check_value(valF, valS);
}

void	map_check_operations_const (void)
{
	std::cout << "\033[1;36m\n===== Operations const =====\033[0m\n";

	std::cout << "  --- Find ---\n";
	
	ft::Map<const int, std::string>		mpF;
	std::map<const int, std::string>	mpS;
	
	mpF.insert(std::pair<const int, std::string>(3, "3-"));
	mpF.insert(std::pair<const int, std::string>(1, "1-"));
	mpF.insert(std::pair<const int, std::string>(9, "9-"));
	mpF.insert(std::pair<const int, std::string>(6, "6-"));
	mpS.insert(std::pair<const int, std::string>(3, "3-"));
	mpS.insert(std::pair<const int, std::string>(1, "1-"));
	mpS.insert(std::pair<const int, std::string>(9, "9-"));
	mpS.insert(std::pair<const int, std::string>(6, "6-"));

	const ft::Map<const int, std::string>	cmpF = mpF;
	const std::map<const int, std::string>	cmpS = mpS;

	check_map_const(cmpF, mpS);

	ft::Map<const int, std::string>::const_iterator		itF = cmpF.find(3);
	std::map<const int, std::string>::const_iterator	itS = cmpS.find(3);

	size_t	valF;
	size_t	valS;

	check_value((*itF).second, (*itS).second);

	ft::Map<const int, std::string>::const_iterator		itF2 = cmpF.find(5);
	std::map<const int, std::string>::const_iterator	itS2 = cmpS.find(5);
	valF = (itF2 == cmpF.end());
	valS = (itS2 == cmpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Count ---\n";

	valF = cmpF.count(9);
	valS = cmpS.count(9);
	check_value(valF, valS);

	valF = cmpF.count(42);
	valS = cmpS.count(42);
	check_value(valF, valS);

	std::cout << "\n  --- Lower_bound ---\n";

	ft::Map<const int, std::string>::const_iterator		itF3 = cmpF.lower_bound(5);
	std::map<const int, std::string>::const_iterator	itS3 = cmpS.lower_bound(5);
	check_value((*itF3).second, (*itS3).second);

	ft::Map<const int, std::string>::const_iterator		itF4 = cmpF.lower_bound(-42);
	std::map<const int, std::string>::const_iterator	itS4 = cmpS.lower_bound(-42);
	check_value((*itF4).second, (*itS4).second);

	ft::Map<const int, std::string>::const_iterator		itF5 = cmpF.lower_bound(42);
	std::map<const int, std::string>::const_iterator	itS5 = cmpS.lower_bound(42);
	valF = (itF5 == cmpF.end());
	valS = (itS5 == cmpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Upper_bound ---\n";
	
	ft::Map<const int, std::string>::const_iterator		itF6 = cmpF.upper_bound(5);
	std::map<const int, std::string>::const_iterator	itS6 = cmpS.upper_bound(5);
	check_value((*itF6).second, (*itS6).second);

	ft::Map<const int, std::string>::const_iterator		itF7 = cmpF.upper_bound(-42);
	std::map<const int, std::string>::const_iterator	itS7 = cmpS.upper_bound(-42);
	check_value((*itF7).second, (*itS7).second);

	ft::Map<const int, std::string>::const_iterator		itF8 = cmpF.upper_bound(42);
	std::map<const int, std::string>::const_iterator	itS8 = cmpS.upper_bound(42);
	valF = (itF8 == cmpF.end());
	valS = (itS8 == cmpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Equal_range ---\n";

	std::pair<ft::Map<const int, std::string>::const_iterator,ft::Map<const int, std::string>::const_iterator> paF = cmpF.equal_range(6);
	std::pair<std::map<const int, std::string>::const_iterator,std::map<const int, std::string>::const_iterator> paS = cmpS.equal_range(6);
	check_value((*(paF.first)).second, (*(paS.first)).second);

	std::pair<ft::Map<const int, std::string>::const_iterator,ft::Map<const int, std::string>::const_iterator> paF2 = cmpF.equal_range(-42);
	std::pair<std::map<const int, std::string>::const_iterator,std::map<const int, std::string>::const_iterator> paS2 = cmpS.equal_range(-42);
	valF = (paF2.first == cmpF.end());
	valS = (paS2.first == cmpS.end());
	check_value(valF, valS);

}

void	map_check_operations_string(void)
{

	std::cout << "\033[1;36m\n===== Operations string =====\033[0m\n";

	std::cout << "  --- Find ---\n";
	
	ft::Map<const std::string, std::string>		mpF;
	std::map<const std::string, std::string>	mpS;
	
	mpF.insert(std::pair<const std::string, std::string>("3", "3-"));
	mpF.insert(std::pair<const std::string, std::string>("1", "1-"));
	mpF.insert(std::pair<const std::string, std::string>("9", "9-"));
	mpF.insert(std::pair<const std::string, std::string>("6", "6-"));
	mpS.insert(std::pair<const std::string, std::string>("3", "3-"));
	mpS.insert(std::pair<const std::string, std::string>("1", "1-"));
	mpS.insert(std::pair<const std::string, std::string>("9", "9-"));
	mpS.insert(std::pair<const std::string, std::string>("6", "6-"));

	check_map(mpF, mpS);

	ft::Map<const std::string, std::string>::iterator	itF;
	std::map<const std::string, std::string>::iterator	itS;

	ft::Map<const std::string, std::string>::const_iterator		citF;
	std::map<const std::string, std::string>::const_iterator	citS;

	size_t	valF;
	size_t	valS;

	itF = mpF.find("3");
	itS = mpS.find("3");
	check_value((*itF).second, (*itS).second);

	itF = mpF.find("5");
	itS = mpS.find("5");
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Count ---\n";

	valF = mpF.count("9");
	valS = mpS.count("9");
	check_value(valF, valS);

	valF = mpF.count("42");
	valS = mpS.count("42");
	check_value(valF, valS);

	std::cout << "\n  --- Lower_bound ---\n";

	itF = mpF.lower_bound("5");
	itS = mpS.lower_bound("5");
	check_value((*itF).second, (*itS).second);

	itF = mpF.lower_bound("-42");
	itS = mpS.lower_bound("-42");
	check_value((*itF).second, (*itS).second);

	itF = mpF.lower_bound("42");
	itS = mpS.lower_bound("42");
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Upper_bound ---\n";
	
	itF = mpF.upper_bound("5");
	itS = mpS.upper_bound("5");
	check_value((*itF).second, (*itS).second);

	itF = mpF.upper_bound("-42");
	itS = mpS.upper_bound("-42");
	check_value((*itF).second, (*itS).second);


	itF = mpF.upper_bound("42");
	itS = mpS.upper_bound("42");
	valF = (itF == mpF.end());
	valS = (itS == mpS.end());
	check_value(valF, valS);

	std::cout << "\n  --- Equal_range ---\n";

	std::pair<ft::Map<const std::string, std::string>::iterator,ft::Map<const std::string, std::string>::iterator> paF;
	std::pair<std::map<const std::string, std::string>::iterator,std::map<const std::string, std::string>::iterator> paS;

	paF = mpF.equal_range("6");
	paS = mpS.equal_range("6");
	check_value((*(paF.first)).second, (*(paS.first)).second);

	paF = mpF.equal_range("-42");
	paS = mpS.equal_range("-42");
	valF = (paF.first == mpF.end());
	valS = (paS.first == mpS.end());
	check_value(valF, valS);

}

void	map_check_observers(void)
{
	std::cout << "\033[1;36m\n===== Observers =====\033[0m\n";

	
	ft::Map<const int, std::string>		mpF;
	std::map<const int, std::string>	mpS;

	std::cout << "  --- Key_comp ---\n";

	size_t	valF;
	size_t	valS;

	valF = mpF.key_comp()(9, 42);
	valS = mpS.key_comp()(9, 42);
	check_value(valF, valS);

	valF = mpF.key_comp()(9, 9);
	valS = mpS.key_comp()(9, 9);
	check_value(valF, valS);

	valF = mpF.key_comp()(42, 9);
	valS = mpS.key_comp()(42, 9);
	check_value(valF, valS);


	std::cout << "  --- Value_comp ---\n";

	std::pair<const int, std::string> paF1(3, "3-");
	std::pair<const int, std::string> paF2(9, "9-");

	valF = mpF.value_comp()(paF1, paF2);
	valS = mpS.value_comp()(paF1, paF2);
	check_value(valF, valS);

	valF = mpF.value_comp()(paF1, paF1);
	valS = mpS.value_comp()(paF1, paF1);
	check_value(valF, valS);

	valF = mpF.value_comp()(paF2, paF1);
	valS = mpS.value_comp()(paF2, paF1);
	check_value(valF, valS);

	std::cout << "\n";

}

void	map_check_observers_string(void)
{
	std::cout << "\033[1;36m\n===== Observers string =====\033[0m\n";

	
	ft::Map<const std::string, std::string>		mpF;
	std::map<const std::string, std::string>	mpS;

	std::cout << "  --- Key_comp ---\n";

	size_t	valF;
	size_t	valS;

	valF = mpF.key_comp()("9", "42");
	valS = mpS.key_comp()("9", "42");
	check_value(valF, valS);

	valF = mpF.key_comp()("9", "9");
	valS = mpS.key_comp()("9", "9");
	check_value(valF, valS);

	valF = mpF.key_comp()("42", "9");
	valS = mpS.key_comp()("42", "9");
	check_value(valF, valS);


	std::cout << "  --- Value_comp ---\n";

	std::pair<const std::string, std::string> paF1("3", "3-");
	std::pair<const std::string, std::string> paF2("9", "9-");

	valF = mpF.value_comp()(paF1, paF2);
	valS = mpS.value_comp()(paF1, paF2);
	check_value(valF, valS);

	valF = mpF.value_comp()(paF1, paF1);
	valS = mpS.value_comp()(paF1, paF1);
	check_value(valF, valS);

	valF = mpF.value_comp()(paF2, paF1);
	valS = mpS.value_comp()(paF2, paF1);
	check_value(valF, valS);

	std::cout << "\n";

}
