#include "../includes/List.hpp"
# include "../includes/Iterator.hpp"

int main(void)
{
	ft::List<int>	lst;

	std::cout << "size = " << lst.size() << "\n";

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	std::cout << "size = " << lst.size() << "\n";

// -------- Iterator --------
	ft::List<int>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "content = " << (*it++)->getContent() << "\n";

std::cout << "\n\n";

// -------- reverse Iterator --------
	const ft::List<int>	lstc(lst);

	ft::List<int>::const_reverse_iterator	rit = lstc.rbegin();
	// rit = lst.rbegin();
	while (rit != lstc.rend())
		std::cout << "reverse_content = " << (*rit++)->getContent() << "\n";

	rit--;
	rit--;
	std::cout << "reverse_content -- -- = " << (*rit)->getContent() << "\n";

	return (0);
}
