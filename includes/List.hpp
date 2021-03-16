#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <limits>

# include "Iterator.hpp"

namespace ft
{

template <typename T>
class Node
{
	public:
		Node *	previous;
		Node *	next;
		T		value;

		Node(const T & val): previous(0), next(0), value(val) {}
		Node(Node *pr, Node *ne, const T & val): previous(pr), next(ne), value(val)
		{
			pr->next = this;
			ne->previous = this;
		}
		Node(): previous(0), next(0), value(T()) {}
	
	void	add_next(Node * node)
	{
		node->next = next;
		node->previous = this;
		next->previous = node;
		next = node;
	}

	void	add_previous(Node * node)
	{
		node->next = this;
		node->previous = previous;
		previous->next = node;
		previous = node;
	}
};


template <typename T>
class List
{
public:

	typedef MyIterator<T, Node<T> *> iterator;
	typedef MyIterator<const T, const Node<T> *> const_iterator;
	typedef MyReverseIterator<T, Node<T> *> reverse_iterator;
	typedef MyReverseIterator<const T, const  Node<T> *> const_reverse_iterator;

private:
	Node<T>	*_begin;
	Node<T>	*_end;
	Node<T>	*_rend;
	size_t	_size;

public:
	List(void): _begin(0), _end(0), _rend(0), _size(0) {}
	List(int nb, T const & content): _begin(0), _end(0), _rend(0), _size(0)
	{
		if (nb > 0)
		{
			this->initiate_first_elem(content);
			int i = 0;
			Node<T>	* save = _begin;
			while (++i < nb)
			{
				Node<T> * temp = new Node<T>(content);
				save->add_next(temp);
				save = temp;
			}
			_size = nb;
		}
	}

	List(List const & src): _begin(0), _end(0), _rend(0), _size(0) {*this = src;}

	List(List::iterator begin, List::iterator end): _begin(0), _end(0), _rend(0), _size(0)	// secu a mettre ?
	{								// template a ajouter ?
		if (begin != end)
		{
			this->initiate_first_elem(*begin);
			begin++;
			Node<T>	* save = _begin;
			while (begin != end)
			{
				Node<T> * temp = new Node<T>(*begin);
				save->add_next(temp);
				save = temp;
				begin++;
				_size++;
			}
		}
	}

	// std::list<int> first;                                // empty list of ints
  	// std::list<int> second (4,100);                       // four ints with value 100
  	// std::list<int> third (second.begin(),second.end());  // iterating through second
  	// std::list<int> fourth (third);

	~List(void) {this->clear();}

// ========  Iterators  ========

	// ------  Functions  ------
	// template <typename PointerType>
	// List::MyIterator<PointerType>	begin(void)
	// {
	// 	List::MyIterator<PointerType>	it(this);
	// 	return (it);
	// }
	iterator	begin(void)
	{
		Node<T> * node = _begin;

		iterator	it(node);
		return (it);
	}
	const_iterator	begin(void) const
	{
		const Node<T> * node = _begin;

		const_iterator	it(node);
		return (it);
	}

	iterator	end(void)
	{
		Node<T> * node = _end;

		iterator	it(node);
		return (it);
	}
	const_iterator	end(void) const
	{
		const Node<T> * node = _end;

		const_iterator	it(node);
		return (it);
	}

	reverse_iterator	rbegin(void)
	{
		Node<T> *	node = 0;
		
		if (_size > 0)
			node = _end->previous;
		reverse_iterator	rit(node);
		return (rit);
	}
	const_reverse_iterator	rbegin(void) const
	{
		const Node<T> *	node = 0;
		
		if (_size > 0)
			node = _end->previous;
		const_reverse_iterator	rit(node);
		return (rit);
	}

	reverse_iterator	rend(void)
	{
		Node<T> * node = _rend;

		reverse_iterator	rit(node);
		return (rit);
	}
	const_reverse_iterator	rend(void) const
	{
		const Node<T> * node = _rend;

		const_reverse_iterator	rit(node);
		return (rit);
	}


// ========  Overload  ========

	List &	operator=(List const & rhs)
	{
		this->clear();
		if (rhs.size() > 0)
		{
			const_iterator	begin = rhs.begin();
			const_iterator	end = rhs.end();
			this->initiate_first_elem(*begin);
			if (begin != end)
			{
				begin++;
				Node<T>	* save = _begin;
				while (begin != end)
				{
					Node<T> * temp = new Node<T>(*begin);
					save->add_next(temp);
					save = temp;
					begin++;
				}
			}
			_size = rhs.size();
		}
		return (*this);
	}

// ========  Capacity  ========

	bool	empty(void) const
	{
		if (!_size)
			return (true);
		return (false);
	}

	size_t	size(void) const {return (_size);}

	size_t	max_size() const {return std::numeric_limits<size_t>::max();} // utiliser size_t ici et pour size ?


// ========  Element Access  ========

	T &	front(void)	// besoin de faire la meme en const ?
	{
		if (this->size() > 0)
			return (_begin->value);
		return (T(0));
	}

	T &	back(void)
	{
		if (this->size() > 0)
			return (_end->previous->value);
		return (T(0));
	}


// ========  Modifiers  ========

//		----  Assign  ----

template <class InputIterator>
void assign (InputIterator first, InputIterator last)
{
	Node<T>	*	temp;
	InputIterator it = first;
	size_t		n = 0;

	while (it++ != last)
		n++;
	this->resize(n);
	temp = _begin;
	while (first != last)
	{
		temp->value = *first;
		first++;
		temp = temp->next;
	}
}

void assign (size_t n, const T& val)
{
	Node<T>	*	temp;

	this->resize(n);
	temp = _begin;
	while (temp != _end)
	{
		temp->value = val;
		temp = temp->next;
	}
}

//		----  Push / Pop  ----

	void	push_back (const T & val)
	{
		if (!_size)
			this->initiate_first_elem(val);
		else
		{
			Node<T> * temp = new Node<T>(val);
			_end->add_previous(temp);
			_size++;
		}
	}

	void	pop_back(void)
	{
		if (!_size)
			return ;
		else if (_size == 1)
			this->clear();
		else
		{
			this->erase(--(this->end()));
			_size--;
		}
	}

	void	push_front (const T & val)
	{
		if (!_size)
			this->initiate_first_elem(val);
		else
		{
			Node<T> * new_begin = new Node<T>(val);
			_rend->add_next(new_begin);
			_begin = new_begin;
			_size++;
		}
	}

	void	pop_front(void)
	{
		Node<T>	*	new_begin;
		
		if (!_size)
			return ;
		else if (_size == 1)
			this->clear();
		else
		{
			new_begin = _begin->next;
			this->erase((this->begin()));
			_begin = new_begin;
			_size--;
		}
	}

//		----  Insert  ----

iterator insert (iterator position, const T& val)
{
	Node<T>	*	temp = _begin;
	Node<T>	*	new_node = 0;

	while (position != temp && temp != _end)
		temp = temp->next;
	if (position == temp)
	{
		new_node = new Node<T>(val);
		temp->add_previous(new_node);
		_size++;
		if (position == _begin)
			_begin = new_node;
	}
	return (iterator(new_node));
}

void insert (iterator position, size_t n, const T& val)
{
	Node<T>	*	temp = _begin;
	Node<T>	*	new_node = 0;

	while (position != temp && temp != _end)
		temp = temp->next;
	if (position == temp)
	{
		while (n-- > 0)
		{
			new_node = new Node<T>(val);
			temp->add_previous(new_node);
			temp = new_node;
			_size++;
		}
		if (position == _begin)
			_begin = new_node;
	}
}

// template <class InputIterator>
// void insert (iterator position, InputIterator first, InputIterator last)	// garder template ?
void insert (iterator position, iterator first, iterator last)	// garder template ?
{
	Node<T>	*	temp = _begin;
	Node<T>	*	new_node = 0;

	while (position != temp && temp != _end)
		temp = temp->next;
	if (position == temp)
	{
		while (first != last)
		{
			new_node = new Node<T>(*(--last));
			temp->add_previous(new_node);
			temp = new_node;
			_size++;
		}
		if (position == _begin)
			_begin = new_node;
	}
}

//		----  Erase  ----

	iterator erase (iterator position)
	{
		Node<T>	*	temp = _begin;
		Node<T>	*	temp_del;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp && temp != _end)
		{
			temp_del = temp;
			temp = temp->next;
			temp_del->previous->next = temp;
			temp->previous = temp_del->previous;
			delete temp_del;
			_size--;
		}
		if (!_size)
		{
			this->clear();
			temp = 0;
		}
		return (iterator(temp));
	}

	iterator erase (iterator first, iterator last)
	{
		Node<T>	*	temp = _begin;
		Node<T>	*	temp_del;

		while (first != temp && temp != _end)
			temp = temp->next;
		if (first == temp && temp != _end)
		{
			while (last != temp && temp != _end)
			{
				temp_del = temp;
				temp = temp->next;
				temp_del->previous->next = temp;
				temp->previous = temp_del->previous;
				delete temp_del;
				_size--;
			}
		}
		if (!_size)
		{
			this->clear();
			temp = 0;
		}
		return (iterator(temp));
	}

//		----  Swap  ----

	void swap (List& x)
	{
		Node<T> * temp_begin = x._begin;
		Node<T> * temp_end = x._end;
		Node<T> * temp_rend = x._rend;
		size_t	temp_size = x._size;

		x._begin = _begin;
		x._end = _end;
		x._rend = _rend;
		x._size = _size;

		_begin = temp_begin;
		_end = temp_end;
		_rend = temp_rend;
		_size = temp_size;
	}

//		----  Resize  ----

void resize (size_t n, T val = T())	// c++11 ?
{
	if (!n)
	{
		this->clear();
		return ;
	}
	while (_size > n)
		erase(--this->end());
	while (_size < n)
		this->push_back(val);
}

//		----  Clear  ----

void clear()
{
	Node<T>	* node = _begin;

	if (_size > 0)
	{
		while (node != _end)
		{
			node = node->next;
			delete node->previous;
		}
		delete _end;
		delete _rend;
	}
	_begin = 0;
	_end = 0;
	_rend = 0;
	_size = 0;
}

// ************************************************************** //
// ************************************************************** //

private:

	void	initiate_first_elem(const T & val)
	{
		_end = new Node<T>();
		_rend = new Node<T>();
		_begin = new Node<T>(_rend, _end, val);
		_size = 1;
	}

};

template <typename T>
void swap (List<T>& x, List<T>& y) {x.swap(y);}

}

#endif
