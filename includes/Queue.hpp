#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <utility>
# include <deque>

# include "Iterator.hpp"
# include "Is_integral.hpp"
# include "List.hpp"

namespace ft
{

template < class T, class Container = std::deque<T> >
class Queue: protected Container
{
public:
	typedef T value_type;
	typedef Container container_type;

	typedef ListIterator<value_type, Node<value_type> *> iterator;
	typedef ListConstIterator<const value_type, Node<const value_type> *> const_iterator;
	typedef ListReverseIterator<value_type, Node<value_type> *> reverse_iterator;
	typedef ListConstReverseIterator<const value_type,  Node<const value_type> *> const_reverse_iterator;

	typedef	size_t size_type;

private:
	container_type	_cont;

public:
	explicit Queue(const container_type& ctnr = container_type()): _cont (ctnr) {}

	~Queue(void) 
	{
		while (this->size())
			this->pop();
	}

// ========  Capacity  ========

	bool	empty(void) const {return _cont.empty();}

	size_type	size(void) const {return _cont.size();}


// ========  Element Access  ========

	value_type &	front(void)	{return _cont.front();}

	const value_type &	front(void) const {return _cont.front();}

	value_type &	back(void) {return _cont.back();}

	const value_type &	back(void) const {return _cont.back();}



// ========  Modifiers  ========

//		----  Push  ----

	void push (const value_type& val) {_cont.push_back(val);}

//		----  Pop  ----

	void pop() {_cont.pop_front();}

// ========  Comparison  ========

bool operator== (const Queue<T,Container>& rhs)
{return (_cont == rhs._cont);}

bool operator!= (const Queue<T,Container>& rhs)
{return (_cont != rhs._cont);}

bool operator<  (const Queue<T,Container>& rhs)
{return (_cont < rhs._cont);}

bool operator<= (const Queue<T,Container>& rhs)
{return (_cont <= rhs._cont);}

bool operator>  (const Queue<T,Container>& rhs)
{return (_cont > rhs._cont);}

bool operator>= (const Queue<T,Container>& rhs)
{return (_cont >= rhs._cont);}

};

}

#endif
