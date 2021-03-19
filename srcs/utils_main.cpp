#include "utils_main.hpp"

bool	is_even(const int & i) { return (i % 2 == 0); }
bool	are_factor_five(const int & i, const int & j) { return (i % 5 == 0 && j % 5 == 0); }
bool	same_abs(const int & i, const int & j) {return (i == j || i == -j);}
bool	is_greater(const int & i, const int & j) {return (i > j); }
bool	is_greaters(const std::string & i, const std::string & j) {return (i > j); }
bool	has_length_3(const std::string & i) { return (i.length() == 3); }
bool	same_length(const std::string & i, const std::string & j) {return (i.length() == j.length());}