#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "utility"

namespace ft
{

template< class T >
struct is_integral { typedef void * type; };


template <>
struct is_integral<bool> { typedef int type; };

template <>
struct is_integral<char> { typedef int type; };

template <>
struct is_integral<signed char> { typedef int type; };

template <>
struct is_integral<unsigned char> { typedef int type; };

template <>
struct is_integral<wchar_t> { typedef int type; };

template <>
struct is_integral<short> { typedef int type; };

template <>
struct is_integral<int> { typedef int type; };

template <>
struct is_integral<long> { typedef int type; };

template <>
struct is_integral<long long> { typedef int type; };

template <>
struct is_integral<unsigned short> { typedef int type; };

template <>
struct is_integral<unsigned int> { typedef int type; };

template <>
struct is_integral<unsigned long> { typedef int type; };

template <>
struct is_integral<unsigned long long> { typedef int type; };

}


#endif