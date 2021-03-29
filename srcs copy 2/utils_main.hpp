#ifndef UTILS_MAIN_HPP
# define UTILS_MAIN_HPP

// int	print_value;
// int	print_error;

// int	nb_OK;
// int	nb_KO;

# include "../includes/Iterator.hpp"
# include "../includes/List.hpp"
# include "../includes/Vector.hpp"
# include "../includes/Map.hpp"
# include "../includes/Queue.hpp"
# include "../includes/Stack.hpp"

# include <list>
# include <vector>
# include <map>
# include <queue>
# include <stack>
# include <string>
# include <utility>
# include <iostream>
# include <sstream>

// # define PRINT_VALUE 0
// # define PRINT_ERROR 0

bool	is_even(const int & i);
bool	are_factor_five(const int & i, const int & j);
bool	same_abs(const int & i, const int & j);
bool	is_greater(const int & i, const int & j);
bool	is_greaters(const std::string & i, const std::string & j);
bool	has_length_3(const std::string & i);
bool	same_length(const std::string & i, const std::string & j);

void	list_check_constructors(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_constructors_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_iterators(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_modifiers(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_modifiers_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_operations(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_operations_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_comparison(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	list_check_comparison_string(int print_value, int print_error, int *nb_OK, int *nb_KO);

void	vector_check_constructors(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_constructors_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_iterators(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_modifiers(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_modifiers_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_comparison(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	vector_check_comparison_string(int print_value, int print_error, int *nb_OK, int *nb_KO);

void	map_check_constructors(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_constructors_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_iterators(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_modifiers(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_modifiers_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_operations(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_operations_const(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_operations_string(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_observers(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	map_check_observers_string(int print_value, int print_error, int *nb_OK, int *nb_KO);

void	queue_check_constructor(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	queue_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	queue_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	queue_check_comparison(int print_value, int print_error, int *nb_OK, int *nb_KO);

void	stack_check_constructor(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	stack_check_capacity(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	stack_check_element_access(int print_value, int print_error, int *nb_OK, int *nb_KO);
void	stack_check_comparison(int print_value, int print_error, int *nb_OK, int *nb_KO);


#endif