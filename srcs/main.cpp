#include "utils_main.hpp"

	int print_value = 0;
	int print_error = 0;

	int nb_OK = 0;
	int nb_KO = 0;

void	test_list()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m================ LIST ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	list_check_constructors();
	list_check_constructors_string();
	list_check_iterators();
	list_check_capacity();
	list_check_element_access();
	list_check_modifiers();
	list_check_modifiers_string();
	list_check_operations();
	list_check_operations_string();
	list_check_comparison();
	list_check_comparison_string();
}

void	test_vector()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m============== VECTOR ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	vector_check_constructors();
	vector_check_constructors_string();
	vector_check_iterators();
	vector_check_capacity();
	vector_check_element_access();
	vector_check_modifiers();
	vector_check_modifiers_string();
	vector_check_comparison();
	vector_check_comparison_string();
}

void	test_map()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m================ MAP ================\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	map_check_constructors();
	map_check_constructors_string();
	map_check_iterators();
	map_check_capacity();
	map_check_element_access();
	map_check_modifiers();
	map_check_modifiers_string();
	map_check_operations();
	map_check_operations_const();
	map_check_operations_string();
	map_check_observers();
	map_check_observers_string();
}

void	test_queue()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== QUEUE ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	queue_check_constructor();
	queue_check_capacity();
	queue_check_element_access();
	queue_check_comparison();
}

void	test_stack()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== STACK ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	stack_check_constructor();
	stack_check_capacity();
	stack_check_element_access();
	stack_check_comparison();
}

void	print_total()
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== Total ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	std::cout << "\033[1;32mNb test OK : " << nb_OK << "/" << nb_OK + nb_KO << "\n\033[0m";
	if (nb_KO)
		std::cout << "\033[1;31mNb test KO : " << nb_KO << "/" << nb_OK + nb_KO << "\n\033[0m";
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	std::string str_test;

	// int	print_value = 0;
	// int	print_error = 0;

	// int	nb_OK = 0;
	// int	nb_KO = 0;

	if (argc >= 2)
		str_test = std::string(argv[1]);

	if (argc == 3 && std::string(argv[2]) == "1")
		print_value = 1;
	if (argc == 3 && std::string(argv[2]) == "2")
		print_error = 1;

	if (argc == 1 || str_test == "list" || str_test == "all")
		test_list();
	if (argc == 1 || str_test == "vector" || str_test == "all")
		test_vector();
	if (argc == 1 || str_test == "map" || str_test == "all")
		test_map();
	if (argc == 1 || str_test == "queue" || str_test == "all")
		test_queue();
	if (argc == 1 || str_test == "stack" || str_test == "all")
		test_stack();

	print_total();	

	
	return 0;
}
