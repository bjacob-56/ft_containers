#ifndef STACK_HPP
# define STACK_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <utility>
# include <deque>

# include "Iterator.hpp"
# include "Is_integral.hpp"

namespace ft
{

template < class T, class Container = std::deque<T> >
class Stack: protected Container
{
public:
	typedef T value_type;
	typedef Container container_type;

	typedef	size_t size_type;

private:
	container_type	_cont;

public:
	explicit Stack(const container_type& ctnr = container_type()): _cont (ctnr) {}

	~Stack(void) 
	{
		while (this->size())
			this->pop();
	}

// ========  Capacity  ========

	bool	empty(void) const {return _cont.empty();}

	size_type	size(void) const {return _cont.size();}


// ========  Element Access  ========

	value_type &	top(void) {return _cont.back();}

	const value_type &	top(void) const {return _cont.back();}



// ========  Modifiers  ========

//		----  Push  ----

	void push (const value_type& val) {_cont.push_back(val);}

//		----  Pop  ----

	void pop() {_cont.pop_back();}

// ========  Comparison  ========

bool operator== (const Stack<T,Container>& rhs)
{return (_cont == rhs._cont);}

bool operator!= (const Stack<T,Container>& rhs)
{return (_cont != rhs._cont);}

bool operator<  (const Stack<T,Container>& rhs)
{return (_cont < rhs._cont);}

bool operator<= (const Stack<T,Container>& rhs)
{return (_cont <= rhs._cont);}

bool operator>  (const Stack<T,Container>& rhs)
{return (_cont > rhs._cont);}

bool operator>= (const Stack<T,Container>& rhs)
{return (_cont >= rhs._cont);}

};

}

#endif
