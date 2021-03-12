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

	ft::List<int>::iterator	it;
	it = lst.begin();
	while (it != lst.end())
		std::cout << "content = " << (*it++)->getContent() << "\n";

	it--;
	it--;
	std::cout << "content -- -- = " << (*it)->getContent() << "\n";

	return (0);
}