#include "utils_main.hpp"

template <typename T, typename Container>
void	clear(ft::Stack<T, Container> myLst)
{
	while (myLst.size())
		myLst.pop();
}

template <typename T, typename Container>
void	clear(std::stack<T, Container> myLst)
{
	while (myLst.size())
		myLst.pop();
}

template <typename T, typename Container1, typename Container2 >
void	check_stack(ft::Stack<T, Container1> myLst, std::stack<T, Container2> realLst)
{
	std::stringstream ss_ft;
	std::stringstream ss_std;

	ss_ft << "[";
	while (myLst.size())
	{
		ss_ft << myLst.top();
		myLst.pop();
		if (myLst.size())
			ss_ft << ", ";
	}
	ss_ft << "]\n";

	ss_std << "[";
	while (realLst.size())
	{
		ss_std << realLst.top();
		realLst.pop();
		if (realLst.size())
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


void	stack_check_constructor(void)
{
	std::cout << "\033[1;36m\n===== Constructors =====\033[0m\n";

	ft::Vector<int>		lstF;
	std::vector<int>	lstS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	ft::Stack<int, ft::Vector<int> >	queF;
	std::stack<int, std::vector<int> >	queS;
	check_stack(queF, queS);

	ft::Stack<int, ft::Vector<int> >	queF2(lstF);
	std::stack<int, std::vector<int> >	queS2(lstS);
	check_stack(queF2, queS2);

	std::cout << "\n";
}

void	stack_check_capacity(void)
{
	std::cout << "\033[1;36m\n===== Capacity =====\033[0m\n";

	ft::Vector<int>		lstF;
	std::vector<int>	lstS;

	size_t	valF;
	size_t	valS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	ft::Stack<int, ft::Vector<int> >	queF;
	std::stack<int, std::vector<int> >	queS;
	check_stack(queF, queS);

	valF = queF.empty();
	valS = queS.empty();
	check_value(valF, valS);

	valF = queF.size();
	valS = queS.size();
	check_value(valF, valS);

	ft::Stack<int, ft::Vector<int> >	queF2(lstF);
	std::stack<int, std::vector<int> >	queS2(lstS);
	check_stack(queF2, queS2);

	valF = queF2.empty();
	valS = queS2.empty();
	check_value(valF, valS);

	valF = queF2.size();
	valS = queS2.size();
	check_value(valF, valS);

	std::cout << "\n";
}


void	stack_check_element_access(void)
{
	std::cout << "\033[1;36m\n===== Element access =====\033[0m\n";

	ft::Vector<int>	lstF;
	std::vector<int>	lstS;

	size_t	valF;
	size_t	valS;

	lstF.push_back(1);
	lstF.push_back(2);
	lstF.push_back(3);
	lstS.push_back(1);
	lstS.push_back(2);
	lstS.push_back(3);

	ft::Stack<int, ft::Vector<int> >			queF2(lstF);
	std::stack<int, std::vector<int> >	queS2(lstS);

	valF = queF2.top();
	valS = queS2.top();
	check_value(valF, valS);

	const int	cvalF2 = queF2.top();
	const int	cvalS2 = queS2.top();
	check_value(cvalF2, cvalS2);

	queF2.push(4);
	queS2.push(4);

	queF2.pop();
	queS2.pop();

	valF = queF2.top();
	valS = queS2.top();
	check_value(valF, valS);

	std::cout << "\n";
}

void	stack_check_comparison(void)
{
	std::cout << "\033[1;36m\n===== Comparison =====\033[0m\n";

	std::cout << "  ---  ==  ---\n";
	ft::Vector<int>	lstF;
	std::vector<int>	lstS;

	ft::Stack<int, ft::Vector<int> >		queF(lstF);
	std::stack<int, std::vector<int> >	queS(lstS);

	ft::Stack<int, ft::Vector<int> >		queF2(lstF);
	std::stack<int, std::vector<int> >	queS2(lstS);

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
	check_value(valF, valS);


	check_stack(queF, queS);
	check_stack(queF2, queS2);

	queF2.push(6);
	queS2.push(6);
	valF = (queF == queF2);
	valS = (queS == queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF == queF2);
	valS = (queS == queS2);
	check_value(valF, valS);

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
	check_value(valF, valS);

	queF2.push(6);
	queS2.push(6);
	valF = (queF != queF2);
	valS = (queS != queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF != queF2);
	valS = (queS != queS2);
	check_value(valF, valS);

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
	check_value(valF, valS);

	queF2.push(6);
	queS2.push(6);
	valF = (queF > queF2);
	valS = (queS > queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF > queF2);
	valS = (queS > queS2);
	check_value(valF, valS);

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
	check_value(valF, valS);

	queF2.push(6);
	queS2.push(6);
	valF = (queF < queF2);
	valS = (queS < queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF < queF2);
	valS = (queS < queS2);
	check_value(valF, valS);

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
	check_value(valF, valS);

	queF2.push(6);
	queS2.push(6);
	valF = (queF >= queF2);
	valS = (queS >= queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF >= queF2);
	valS = (queS >= queS2);
	check_value(valF, valS);

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
	check_value(valF, valS);

	queF2.push(6);
	queS2.push(6);
	valF = (queF <= queF2);
	valS = (queS <= queS2);
	check_value(valF, valS);

	queF2.pop();
	queS2.pop();
	queF2.push(4);
	queS2.push(4);
	valF = (queF <= queF2);
	valS = (queS <= queS2);
	check_value(valF, valS);

	std::cout << "\n";

}

