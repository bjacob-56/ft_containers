#include "utils_main.hpp"

bool	is_even(const int & i) { return (i % 2 == 0); }
bool	are_factor_five(const int & i, const int & j) { return (i % 5 == 0 && j % 5 == 0); }
bool	same_abs(const int & i, const int & j) {return (i == j || i == -j);}
bool	is_greater(const int & i, const int & j) {return (i > j); }