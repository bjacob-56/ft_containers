#ifndef UTILS_MAIN_HPP
# define UTILS_MAIN_HPP

extern int	print_value;
extern int	print_error;

extern int	nb_OK;
extern int	nb_KO;

# include "../includes/Iterator.hpp"
# include "../includes/List.hpp"
# include "../includes/Vector.hpp"
# include "../includes/Map.hpp"
# include "../includes/Queue.hpp"

# include <list>
# include <vector>
# include <map>
# include <queue>
# include <stack>
# include <string>
# include <utility>
# include <iostream>
# include <sstream>

# define PRINT_VALUE 0
# define PRINT_ERROR 0

bool	is_even(const int & i);
bool	are_factor_five(const int & i, const int & j);
bool	same_abs(const int & i, const int & j);
bool	is_greater(const int & i, const int & j);
bool	is_greaters(const std::string & i, const std::string & j);
bool	has_length_3(const std::string & i);
bool	same_length(const std::string & i, const std::string & j);

void	list_check_constructors();
void	list_check_constructors_string();
void	list_check_iterators();
void	list_check_capacity();
void	list_check_element_access();
void	list_check_modifiers();
void	list_check_modifiers_string();
void	list_check_operations();
void	list_check_operations_string();
void	list_check_comparison();
void	list_check_comparison_string();

void	vector_check_constructors();
void	vector_check_constructors_string();
void	vector_check_iterators();
void	vector_check_capacity();
void	vector_check_element_access();
void	vector_check_modifiers();
void	vector_check_modifiers_string();
void	vector_check_comparison();
void	vector_check_comparison_string();

void	map_check_constructors();
void	map_check_constructors_string();
void	map_check_iterators();
void	map_check_capacity();
void	map_check_element_access();
void	map_check_modifiers();
void	map_check_modifiers_string();
void	map_check_operations();
void	map_check_operations_const();
void	map_check_operations_string();
void	map_check_observers();
void	map_check_observers_string();

void	queue_check_constructor();
void	queue_check_capacity();
void	queue_check_element_access();
void	queue_check_comparison();


#endif