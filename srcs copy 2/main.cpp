#include "utils_main.hpp"

	// int	print_value = 0;
	// int	print_error = 0;

	// int	nb_OK = 0;
	// int	nb_KO = 0;

void	test_list(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m================ LIST ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	list_check_constructors(print_value, print_error, nb_OK, nb_KO);
	list_check_constructors_string(print_value, print_error, nb_OK, nb_KO);
	list_check_iterators(print_value, print_error, nb_OK, nb_KO);
	list_check_capacity(print_value, print_error, nb_OK, nb_KO);
	list_check_element_access(print_value, print_error, nb_OK, nb_KO);
	list_check_modifiers(print_value, print_error, nb_OK, nb_KO);
	list_check_modifiers_string(print_value, print_error, nb_OK, nb_KO);
	list_check_operations(print_value, print_error, nb_OK, nb_KO);
	list_check_operations_string(print_value, print_error, nb_OK, nb_KO);
	list_check_comparison(print_value, print_error, nb_OK, nb_KO);
	list_check_comparison_string(print_value, print_error, nb_OK, nb_KO);
}

void	test_vector(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m============== VECTOR ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	vector_check_constructors(print_value, print_error, nb_OK, nb_KO);
	vector_check_constructors_string(print_value, print_error, nb_OK, nb_KO);
	vector_check_iterators(print_value, print_error, nb_OK, nb_KO);
	vector_check_capacity(print_value, print_error, nb_OK, nb_KO);
	vector_check_element_access(print_value, print_error, nb_OK, nb_KO);
	vector_check_modifiers(print_value, print_error, nb_OK, nb_KO);
	vector_check_modifiers_string(print_value, print_error, nb_OK, nb_KO);
	vector_check_comparison(print_value, print_error, nb_OK, nb_KO);
	vector_check_comparison_string(print_value, print_error, nb_OK, nb_KO);
}

void	test_map(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m================ MAP ================\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	map_check_constructors(print_value, print_error, nb_OK, nb_KO);
	map_check_constructors_string(print_value, print_error, nb_OK, nb_KO);
	map_check_iterators(print_value, print_error, nb_OK, nb_KO);
	map_check_capacity(print_value, print_error, nb_OK, nb_KO);
	map_check_element_access(print_value, print_error, nb_OK, nb_KO);
	map_check_modifiers(print_value, print_error, nb_OK, nb_KO);
	map_check_modifiers_string(print_value, print_error, nb_OK, nb_KO);
	map_check_operations(print_value, print_error, nb_OK, nb_KO);
	map_check_operations_const(print_value, print_error, nb_OK, nb_KO);
	map_check_operations_string(print_value, print_error, nb_OK, nb_KO);
	map_check_observers(print_value, print_error, nb_OK, nb_KO);
	map_check_observers_string(print_value, print_error, nb_OK, nb_KO);
}

void	test_queue(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== QUEUE ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	queue_check_constructor(print_value, print_error, nb_OK, nb_KO);
	queue_check_capacity(print_value, print_error, nb_OK, nb_KO);
	queue_check_element_access(print_value, print_error, nb_OK, nb_KO);
	queue_check_comparison(print_value, print_error, nb_OK, nb_KO);
}

void	test_stack(int print_value, int print_error, int *nb_OK, int *nb_KO)
{
	std::cout << "\033[1;36m\n\n=====================================\033[0m\n";
	std::cout << "\033[1;36m=============== STACK ===============\033[0m\n";
	std::cout << "\033[1;36m=====================================\033[0m\n";

	stack_check_constructor(print_value, print_error, nb_OK, nb_KO);
	stack_check_capacity(print_value, print_error, nb_OK, nb_KO);
	stack_check_element_access(print_value, print_error, nb_OK, nb_KO);
	stack_check_comparison(print_value, print_error, nb_OK, nb_KO);
}

void	print_total(int nb_OK, int nb_KO)
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

	int	print_value = 0;
	int	print_error = 0;

	int	nb_OK = 0;
	int	nb_KO = 0;

	if (argc >= 2)
		str_test = std::string(argv[1]);

	if (argc == 3 && std::string(argv[2]) == "1")
		print_value = 1;
	if (argc == 3 && std::string(argv[2]) == "2")
		print_error = 1;

	if (argc == 1 || str_test == "list" || str_test == "all")
		test_list(print_value, print_error, &nb_OK, &nb_KO);
	if (argc == 1 || str_test == "vector" || str_test == "all")
		test_vector(print_value, print_error, &nb_OK, &nb_KO);
	if (argc == 1 || str_test == "map" || str_test == "all")
		test_map(print_value, print_error, &nb_OK, &nb_KO);
	if (argc == 1 || str_test == "queue" || str_test == "all")
		test_queue(print_value, print_error, &nb_OK, &nb_KO);
	if (argc == 1 || str_test == "stack" || str_test == "all")
		test_stack(print_value, print_error, &nb_OK, &nb_KO);

	print_total(nb_OK, nb_KO);	

	
	return 0;
}
