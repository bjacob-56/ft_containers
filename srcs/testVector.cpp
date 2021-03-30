#include "utils_main.hpp"

template <typename T>
std::stringstream stream_vector(ft::Vector<T> & vect)
{
	std::stringstream ss;

	typename ft::Vector<T>::iterator	it;
	it = vect.begin();
	while (it != vect.end())
		ss << "> " << *(it++) << "\n";
	ss << "\n";
	return (ss);
}

template <typename T>
void	display_vector(ft::Vector<T> & vect)
{
	typename ft::Vector<T>::iterator	it;
	it = vect.begin();
	std::cout << "[";
	while (it != vect.end())
	{
		std::cout << "" << *(it++);
		if (it != vect.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

template <typename T>
void	reverse_display_vector(ft::Vector<T> & vect)
{
	typename ft::Vector<T>::reverse_iterator	rit = vect.rbegin();

	while (rit != vect.rend())
		std::cout << "> " << *(rit++) << "\n";
	std::cout << "\n";
}

template <typename T>
std::stringstream	stream_real_vector(std::vector<T> & vect)
{
	std::stringstream ss;

	typename std::vector<T>::iterator	it;
	it = vect.begin();
	while (it != vect.end())
		ss << "> " << *(it++) << "\n";
	ss << "\n";
	return (ss);
}

template <typename T>
void	display_real_vector(std::vector<T> & vect)
{
	typename std::vector<T>::iterator	it;
	it = vect.begin();
	std::cout << "[";
	while (it != vect.end())
	{
		std::cout << "" << *(it++);
		if (it != vect.end())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

template <typename T>
void	check_vector(ft::Vector<T> & myLst, std::vector<T> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Vector<T>::iterator	itF = myLst.begin();
	ss_ft << "[";
	while (itF != myLst.end())
	{
		ss_ft << *(itF++);
		if (itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	typename std::vector<T>::iterator	itS = realLst.begin();
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
void	check_vector_const(const ft::Vector<T> & myLst, const std::vector<T> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Vector<T>::const_iterator	itF = myLst.begin();
	ss_ft << "[";
	while (itF != myLst.end())
	{
		ss_ft << *(itF++);
		if (itF != myLst.end())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::vector<T>::const_iterator	itS = realLst.begin();
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
void	check_vector_reverse(ft::Vector<T> & myLst, std::vector<T> & realLst, int clearFlag = 0)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Vector<T>::reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << *(itF++);
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::vector<T>::reverse_iterator	itS = realLst.rbegin();
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
void	check_vector_const_reverse(const ft::Vector<T> & myLst, const std::vector<T> & realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	typename ft::Vector<T>::const_reverse_iterator	itF = myLst.rbegin();
	ss_ft << "[";
	while (itF != myLst.rend())
	{
		ss_ft << *(itF++);
		if (itF != myLst.rend())
			ss_ft << ", ";
	}
	ss_ft << "]\n";
	
	typename std::vector<T>::const_reverse_iterator	itS = realLst.rbegin();
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


void	vector_check_constructors(void)
{
	std::cout << "\033[1;36m\n===== Constructors =====\033[0m\n";

	ft::Vector<int>	vectF;
	std::vector<int>	vectS;
	check_vector(vectF, vectS);

	ft::Vector<int>	vectF2(5, 42);
	std::vector<int>	vectS2(5, 42);
	check_vector(vectF2, vectS2);

	ft::Vector<int>::iterator		itbF = vectF2.begin()++;
	ft::Vector<int>::iterator		iteF = vectF2.end();
	std::vector<int>::iterator	itbS = vectS2.begin()++;
	std::vector<int>::iterator	iteS = vectS2.end();

	ft::Vector<int>	vectF3(itbF, iteF);
	std::vector<int>	vectS3(itbS, iteS);
	check_vector(vectF3, vectS3);

	ft::Vector<int>	vectF4(vectF3);
	std::vector<int>	vectS4(vectS3);
	check_vector(vectF4, vectS4);

	vectF = vectF4;
	vectS2 = vectS4;
	check_vector(vectF, vectS2);

	std::cout << "\n";
}

void	vector_check_constructors_string(void)
{
	std::cout << "\033[1;36m\n===== Constructors string =====\033[0m\n";

	ft::Vector<std::string>	vectF;
	std::vector<std::string>	vectS;
	check_vector(vectF, vectS);


	ft::Vector<std::string>	vectF2(5, "test");
	std::vector<std::string>	vectS2(5, "test");
	check_vector(vectF2, vectS2);

	ft::Vector<std::string>::iterator		itbF = vectF2.begin()++;
	ft::Vector<std::string>::iterator		iteF = vectF2.end();
	std::vector<std::string>::iterator	itbS = vectS2.begin()++;
	std::vector<std::string>::iterator	iteS = vectS2.end();

	ft::Vector<std::string>	vectF3(itbF, iteF);
	std::vector<std::string>	vectS3(itbS, iteS);
	check_vector(vectF3, vectS3);

	ft::Vector<std::string>	vectF4(vectF3);
	std::vector<std::string>	vectS4(vectS3);
	check_vector(vectF4, vectS4);

	vectF = vectF4;
	vectS2 = vectS4;
	check_vector(vectF, vectS2);

	std::cout << "\n";
}


void	vector_check_iterators(void)
{
	std::cout << "\033[1;36m\n===== Iterators =====\033[0m\n";

	ft::Vector<std::string>	vectF;
	std::vector<std::string>	vectS;

	vectF.push_back("a");
	vectF.push_back("ab");



	vectF.push_back("abcde");
	vectS.push_back("a");
	vectS.push_back("ab");
	vectS.push_back("abcde");

	check_vector (vectF, vectS);
	check_vector_const(vectF, vectS);
	check_vector_reverse(vectF, vectS);
	check_vector_const_reverse(vectF, vectS);

	ft::Vector<std::string>::iterator		itbF = ++vectF.begin();
	ft::Vector<std::string>::iterator		iteF = --vectF.end();
	std::vector<std::string>::iterator	itbS = ++vectS.begin();
	std::vector<std::string>::iterator	iteS = --vectS.end();

	size_t	valF;
	size_t	valS;

	valF = itbF->length();
	valS = itbS->length();
	check_value(valF, valS);

	valF = iteF->length();
	valS = iteS->length();
	check_value(valF, valS);

	std::cout << "\n";
}

void	vector_check_capacity(void)
{
	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

	ft::Vector<int>	vectF;
	std::vector<int>	vectS;

	size_t	valF;
	size_t	valS;

	valF = vectF.max_size();
	valS = vectS.max_size();
	check_value(valF, valS);

	valF = vectF.empty();
	valS = vectS.empty();
	check_value(valF, valS);
	valF = vectF.size();
	valS = vectS.size();
	check_value(valF, valS);

	vectF.push_back(1);
	vectF.push_back(2);
	vectF.push_back(3);
	vectS.push_back(1);
	vectS.push_back(2);
	vectS.push_back(3);

	valF = vectF.empty();
	valS = vectS.empty();
	check_value(valF, valS);

	valF = vectF.size();
	valS = vectS.size();
	check_value(valF, valS);

	std::cout << "\n";
}

void	vector_check_element_access(void)
{
	std::cout << "\033[1;36m\n===== Element access =====\033[0m\n";

	ft::Vector<int>	vectF;
	std::vector<int>	vectS;

	int		valF;
	int		valS;

	vectF.push_back(1);
	vectF.push_back(2);
	vectF.push_back(3);
	vectS.push_back(1);
	vectS.push_back(2);
	vectS.push_back(3);

	valF = vectF.front();
	valS = vectS.front();
	check_value(valF, valS);

	const int		cvalF = vectF.front();
	const int		cvalS = vectS.front();
	check_value(cvalF, cvalS);

	valF = vectF.back();
	valS = vectS.back();
	check_value(valF, valS);

	const int	cvalF2 = vectF.back();
	const int	cvalS2 = vectS.back();
	check_value(cvalF2, cvalS2);

	std::cout << "\n";
}

void	vector_check_modifiers(void)
{
	std::cout << "\033[1;36m\n===== Modifiers =====\033[0m\n";

	std::cout << "  --- Assign ---\n";
	ft::Vector<int>	vectF;
	std::vector<int>	vectS;

	vectF.assign(5, 42);
	vectS.assign(5, 42);
	check_vector(vectF, vectS);

	ft::Vector<int>	vectF2;
	std::vector<int>	vectS2;

	ft::Vector<int>::iterator		itbF = ++vectF.begin();
	ft::Vector<int>::iterator		iteF = --vectF.end();
	std::vector<int>::iterator	itbS = ++vectS.begin();
	std::vector<int>::iterator	iteS = --vectS.end();
	
	vectF.assign(itbF, iteF);
	vectS.assign(itbS, iteS);
	check_vector(vectF2, vectS2, 1);

	std::cout << "\n  --- Push/Pop_Back ---\n";


	vectF2.push_back(3);
	vectF2.push_back(5);
	vectS2.push_back(3);
	vectS2.push_back(5);
	check_vector(vectF2, vectS2);


	vectF2.pop_back();
	vectS2.pop_back();
	check_vector(vectF2, vectS2);


	std::cout << "\n  --- Insert ---\n";

	ft::Vector<int>::iterator		itbF2 = ++vectF2.begin();
	std::vector<int>::iterator	itbS2 = ++vectS2.begin();


	itbF2 = vectF2.insert(itbF2, 56);
	itbS2 = vectS2.insert(itbS2, 56);
	check_vector(vectF2, vectS2);

	vectF2.insert(itbF2, 5, 93);
	vectS2.insert(itbS2, 5, 93);
	check_vector(vectF2, vectS2);

	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();

	itbF = vectF.begin();
	itbS = vectS.begin();
	iteF = vectF.end();
	iteS = vectS.end();

	vectF2.insert(itbF2, itbF, iteF);
	vectS2.insert(itbS2, itbS, iteS);
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Erase ---\n";

	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();

	itbF2 = vectF2.erase(--itbF2);
	itbS2 = vectS2.erase(--itbS2);
	check_vector(vectF2, vectS2);

	ft::Vector<int>::iterator		iteF2 = --vectF2.end();
	std::vector<int>::iterator	iteS2 = --vectS2.end();

	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();

	vectF2.erase(itbF2, iteF2);
	vectS2.erase(itbS2, iteS2);
	check_vector(vectF2, vectS2);


	std::cout << "\n  --- Swap ---\n";
	vectF.swap(vectF2);
	vectS.swap(vectS2);
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	swap(vectF, vectF2);
	swap(vectS, vectS2);
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Resize ---\n";
	vectF2.resize(0);
	vectS2.resize(0);
	check_vector(vectF2, vectS2);
	
	vectF2.resize(12, -42);
	vectS2.resize(12, -42);
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Clear ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	std::cout << "\n";
}

void	vector_check_modifiers_string(void)
{
	std::cout << "\033[1;36m\n===== Modifiers string =====\033[0m\n";

	std::cout << "  --- Assign ---\n";
	ft::Vector<std::string>	vectF;
	std::vector<std::string>	vectS;

	// std::string str = "test";
	// vectF.assign(5, str);
	vectF.assign(5, "test");
	vectS.assign(5, "test");
	check_vector(vectF, vectS);
	

	ft::Vector<std::string>	vectF2;
	std::vector<std::string>	vectS2;

	ft::Vector<std::string>::iterator		itbF = vectF.begin()++;
	ft::Vector<std::string>::iterator		iteF = vectF.end()--;
	std::vector<std::string>::iterator	itbS = vectS.begin()++;
	std::vector<std::string>::iterator	iteS = vectS.end()--;

	vectF.assign(itbF, iteF);
	vectS.assign(itbS, iteS);
	check_vector(vectF2, vectS2, 1);

	std::cout << "\n  --- Push/Pop_Back ---\n";

	vectF2.push_back("What is this?");
	vectF2.push_back("Yellow Sub");
	vectS2.push_back("What is this?");
	vectS2.push_back("Yellow Sub");
	check_vector(vectF2, vectS2);

	vectF2.pop_back();
	vectS2.pop_back();
	check_vector(vectF2, vectS2);


	std::cout << "\n  --- Insert ---\n";

	ft::Vector<std::string>::iterator		itbF2 = ++vectF2.begin();
	std::vector<std::string>::iterator	itbS2 = ++vectS2.begin();

	itbF2 = vectF2.insert(itbF2, "42");
	itbS2 = vectS2.insert(itbS2, "42");
	check_vector(vectF2, vectS2);

	vectF2.insert(itbF2, 5, "Ab64");
	vectS2.insert(itbS2, 5, "Ab64");
	check_vector(vectF2, vectS2);

	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();

	itbF = vectF.begin();
	itbS = vectS.begin();
	iteF = vectF.end();
	iteS = vectS.end();

	vectF2.insert(itbF2, itbF, iteF);
	vectS2.insert(itbS2, itbS, iteS);
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Erase ---\n";
	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();
	
	itbF2 = vectF2.erase(--itbF2);
	itbS2 = vectS2.erase(--itbS2);
	check_vector(vectF2, vectS2);

	ft::Vector<std::string>::iterator		iteF2 = --vectF2.end();
	std::vector<std::string>::iterator	iteS2 = --vectS2.end();

	itbF2 = ++vectF2.begin();
	itbS2 = ++vectS2.begin();

	vectF2.erase(itbF2, iteF2);
	vectS2.erase(itbS2, iteS2);
	check_vector(vectF2, vectS2);


	std::cout << "\n  --- Swap ---\n";
	vectF.swap(vectF2);
	vectS.swap(vectS2);
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	swap(vectF, vectF2);
	swap(vectS, vectS2);
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Resize ---\n";
	vectF2.resize(0);
	vectS2.resize(0);
	check_vector(vectF2, vectS2);
	
	vectF2.resize(12, "new str");
	vectS2.resize(12, "new str");
	check_vector(vectF2, vectS2);

	std::cout << "\n  --- Clear ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();
	check_vector(vectF, vectS);
	check_vector(vectF2, vectS2);

	std::cout << "\n";
}


void	vector_check_comparison(void)
{
	std::cout << "\033[1;36m\n===== Comparison =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::Vector<int>	vectF;
	std::vector<int>	vectS;

	ft::Vector<int>	vectF2;
	std::vector<int>	vectS2;

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	bool	valF;
	bool	valS;

	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  !=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back(1);
	vectF.push_back(5);
	vectF.push_back(4);

	vectF2.push_back(1);
	vectF2.push_back(5);

	vectS.push_back(1);
	vectS.push_back(5);
	vectS.push_back(4);

	vectS2.push_back(1);
	vectS2.push_back(5);

	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);

	vectF2.push_back(6);
	vectS2.push_back(6);
	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back(4);
	vectS2.push_back(4);
	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);

	std::cout << "\n";

}

void	vector_check_comparison_string(void)
{
	std::cout << "\033[1;36m\n===== Comparison string =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::Vector<std::string>	vectF;
	std::vector<std::string>	vectS;

	ft::Vector<std::string>	vectF2;
	std::vector<std::string>	vectS2;

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	bool	valF;
	bool	valS;

	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF == vectF2);
	valS = (vectS == vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  !=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF != vectF2);
	valS = (vectS != vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF > vectF2);
	valS = (vectS > vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF < vectF2);
	valS = (vectS < vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  >=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF >= vectF2);
	valS = (vectS >= vectS2);
	check_value(valF, valS);

	std::cout << "\n  ---  <=  ---\n";
	vectF.clear();
	vectF2.clear();
	vectS.clear();
	vectS2.clear();

	vectF.push_back("abc");
	vectF.push_back("abcd");
	vectF.push_back("abce");

	vectF2.push_back("abc");
	vectF2.push_back("abcd");

	vectS.push_back("abc");
	vectS.push_back("abcd");
	vectS.push_back("abce");

	vectS2.push_back("abc");
	vectS2.push_back("abcd");

	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);

	vectF2.push_back("ab");
	vectS2.push_back("ab");
	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);

	vectF2.pop_back();
	vectS2.pop_back();
	vectF2.push_back("abce");
	vectS2.push_back("abce");
	valF = (vectF <= vectF2);
	valS = (vectS <= vectS2);
	check_value(valF, valS);


    // ft::Vector<int> v1;

	// bool bool1;

	// v1.push_back(1);
    // bool1 = v1.size() == 1;
	// std::cout << "bool1 = " << bool1 << "\n";
    // bool1 = v1.capacity() >= 1;
	// std::cout << "bool1 = " << bool1 << "\n";
    // bool1 = v1[0] == 1;
	// std::cout << "bool1 = " << bool1 << "\n";

    // v1.push_back(2);
    // bool1 = v1.size() == 2;
	// std::cout << "bool1 = " << bool1 << "\n";
    // bool1 = v1.capacity() >= 2;
	// std::cout << "bool1 = " << bool1 << "\n";
    // bool1 = v1[0] == 1;
	// std::cout << "bool1 = " << bool1 << "\n";
    // bool1 = v1[1] == 2;
	// std::cout << "bool1 = " << bool1 << "\n";

	// ft::Vector< ft::Vector<char*> > v4_copied;
	// ft::Vector< ft::Vector<char*> > v4(v4_copied);
    // std::cout << "capacities = " << v4.capacity()<< " and " << v4_copied.capacity()<< "\n";
    // // ASSERT(v4.empty() == v4_copied.empty());
    // ASSERT(v4.size() == v4_copied.size());
    // ASSERT(v4.capacity() == v4_copied.capacity());


    // std::string                     arr2[3] = {"bonjour", "je", "suis"};
    // ft::Vector<std::string>         v2_duplicated(arr2, arr2 + 3);
    // std::vector<std::string>         rv2_duplicated(arr2, arr2 + 3);

	// ft::Vector<std::string> v2(10, "zzz");
	// std::vector<std::string> rv2(10, "zzz");
    // v2 = v2_duplicated;
    // rv2 = rv2_duplicated;
    // std::cout << "capacities = " << v2.capacity()<< " and " << v2_duplicated.capacity()<< "\n";
    // std::cout << "real capacities = " << rv2.capacity()<< " and " << rv2_duplicated.capacity()<< "\n";

	// std::cout << "real -> " << (rv2.begin() < rv2.end()) << "\n";
	// std::cout << "ft -> " << (v2.begin() < v2.end()) << "\n";

	// ft::Vector<std::string>::const_iterator		itF = --v2.end();
	// ft::Vector<std::string>::iterator		itF2 = --v2.end();
	// ft::Vector<std::string>::reverse_iterator		itF3 = v2.rbegin();

	// std::vector<std::string>::const_iterator		itR = --rv2.end();
	// std::vector<std::string>::iterator		itR2 = --rv2.end();
	// // std::vector<std::string>::reverse_iterator		itR3 = rv2.rbegin();

	// // std::cout << "real -> " << (rv2.rbegin() > rv2.rend()) << "\n";
	// // std::cout << "ft -> " << (v2.rbegin() > v2.rend()) << "\n";

	// std::cout << "real1 -> " << (itF == itF2) << " - " << (itR == itR2) << "\n";
	// std::cout << "real1 -> " << (itF > itF2) << " - " << (itR > itR2) << "\n";
	// // std::cout << "real2 -> " << (itF == itF3) << " - " << (itR == itR3) << "\n";
	// // std::cout << "real3 -> " << (itF == ++itF3) << " - " << (itR == ++itR3) << "\n";
	// // std::cout << "real4 -> " << (itF > itF3) << " - " << (itR > itR3) << "\n";

	// std::cout << "test -> " << (1 == 1) << "\n";
	// std::cout << "test -> " << (2 > 3) << "\n";




	int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::Vector<int>                 v1_copied(arr1, arr1 + 5);
    std::vector<int>                 rv1_copied(arr1, arr1 + 5);

    ft::Vector<int> v1(v1_copied);
    std::vector<int> rv1(rv1_copied);
  
    std::cout << v1.capacity() << " - " << v1_copied.capacity() << "\n";
    std::cout << rv1.capacity() << " - " << rv1_copied.capacity() << "\n";


	std::cout << "\n";

}
