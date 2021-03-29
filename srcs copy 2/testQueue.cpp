#include "utils_main.hpp"

template <typename T, typename Container>
void	clear(ft::Queue<T, Container> myLst)
{
	while (myLst.size())
		myLst.pop();
}

template <typename T, typename Container>
void	clear(std::queue<T, Container> myLst)
{
	while (myLst.size())
		myLst.pop();
}

template <typename T, typename Container1, typename Container2 >
void	check_queue(ft::Queue<T, Container1> myLst, std::queue<T, Container2> realLst, int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	ss_ft << "[";
	while (myLst.size())
	{
		ss_ft << myLst.front();
		myLst.pop();
		if (myLst.size())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	ss_std << "[";
	while (realLst.size())
	{
		ss_std << realLst.front();
		realLst.pop();
		if (realLst.size())
			ss_std << ", ";
	}
	ss_std << "]\n";

	if (!ss_std.str().compare(ss_ft.str()))
	{
		std::cout << "\033[1;32mOK \033[0m";
		(*nb_OK)++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		(*nb_KO)++;
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
static void	check_value(T & valF, T & valS, int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	if (valF == valS)
	{
		std::cout << "\033[1;32mOK \033[0m";
		(*nb_OK)++;
	}
	else
	{
		std::cout << "\033[1;31mKO \033[0m";
		(*nb_KO)++;
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


void	queue_check_constructor(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n===== Constructors =====\033[0m\n";

	ft::List<int>	lstF;
	std::list<int>	lstS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	ft::Queue<int, ft::List<int> >		queF;
	std::queue<int, std::list<int> >	queS;
	check_queue(queF, queS, print_value, print_error, nb_OK, nb_KO);

	ft::Queue<int, ft::List<int> >			queF2(lstF);
	std::queue<int, std::list<int> >	queS2(lstS);
	check_queue(queF2, queS2, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n";
}

void	queue_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

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

	ft::Queue<int, ft::List<int> >		queF;
	std::queue<int, std::list<int> >	queS;
	check_queue(queF, queS, print_value, print_error, nb_OK, nb_KO);

	valF = queF.empty();
	valS = queS.empty();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	valF = queF.size();
	valS = queS.size();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	ft::Queue<int, ft::List<int> >			queF2(lstF);
	std::queue<int, std::list<int> >	queS2(lstS);
	check_queue(queF2, queS2, print_value, print_error, nb_OK, nb_KO);

	valF = queF2.empty();
	valS = queS2.empty();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	valF = queF2.size();
	valS = queS2.size();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n";
}


void	queue_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO)
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

	ft::Queue<int, ft::List<int> >			queF2(lstF);
	std::queue<int, std::list<int> >	queS2(lstS);

	valF = queF2.front();
	valS = queS2.front();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	const int		cvalF = queF2.front();
	const int		cvalS = queS2.front();
	check_value(cvalF, cvalS, print_value, print_error, nb_OK, nb_KO);

	valF = queF2.back();
	valS = queS2.back();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	const int	cvalF2 = queF2.back();
	const int	cvalS2 = queS2.back();
	check_value(cvalF2, cvalS2, print_value, print_error, nb_OK, nb_KO);

	queF2.push(4);
	queS2.push(4);

	queF2.pop();
	queS2.pop();

	valF = queF2.front();
	valS = queS2.front();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	valF = queF2.back();
	valS = queS2.back();
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n";
}

void	queue_check_comparison(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n===== Comparison =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::List<int>	lstF;
	std::list<int>	lstS;

	ft::Queue<int, ft::List<int> >		queF(lstF);
	std::queue<int, std::list<int> >	queS(lstS);

	ft::Queue<int, ft::List<int> >		queF2(lstF);
	std::queue<int, std::list<int> >	queS2(lstS);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	bool	valF;
	bool	valS;

	valF = (queF == queF2);
	valS = (queS == queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);


	check_queue(queF, queS, print_value, print_error, nb_OK, nb_KO);
	check_queue(queF2, queS2, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF == queF2);
	valS = (queS == queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF == queF2);
	valS = (queS == queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n  ---  !=  ---\n";
	clear(queF);
	clear(queF2);
	clear(queS);
	clear(queS2);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	valF = (queF != queF2);
	valS = (queS != queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF != queF2);
	valS = (queS != queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF != queF2);
	valS = (queS != queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n  ---  >  ---\n";
	clear(queF);
	clear(queF2);
	clear(queS);
	clear(queS2);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	valF = (queF > queF2);
	valS = (queS > queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF > queF2);
	valS = (queS > queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF > queF2);
	valS = (queS > queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n  ---  <  ---\n";
	clear(queF);
	clear(queF2);
	clear(queS);
	clear(queS2);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	valF = (queF < queF2);
	valS = (queS < queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF < queF2);
	valS = (queS < queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF < queF2);
	valS = (queS < queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n  ---  >=  ---\n";
	clear(queF);
	clear(queF2);
	clear(queS);
	clear(queS2);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	valF = (queF >= queF2);
	valS = (queS >= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF >= queF2);
	valS = (queS >= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF >= queF2);
	valS = (queS >= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n  ---  <=  ---\n";
	clear(queF);
	clear(queF2);
	clear(queS);
	clear(queS2);

	queF.push(1);
	queF.push(5);
	queF.push(4);

	queF2.push(1);
	queF2.push(5);

	queS.push(1);
	queS.push(5);
	queS.push(4);

	queS2.push(1);
	queS2.push(5);

	valF = (queF <= queF2);
	valS = (queS <= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.push(6);
	queS2.push(6);
	valF = (queF <= queF2);
	valS = (queS <= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF <= queF2);
	valS = (queS <= queS2);
	check_value(valF, valS, print_value, print_error, nb_OK, nb_KO);

	std::cout << "\n";

}

