#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>

# include "Iterator.hpp"
# include "Is_integral.hpp"

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

	void	swap_nodes(Node * node)
	{
		Node *	temp_previous = previous;
		Node *	temp_next = next;

		previous = node->previous;
		next = node->next;
		node->previous = temp_previous;
		node->next = temp_next;
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

	typedef	size_t size_type;

private:
	Node<T>	*_begin;
	Node<T>	*_end;
	Node<T>	*_rend;
	size_t	_size;

public:
	explicit List(void): _begin(0), _end(0), _rend(0), _size(0) {}
	explicit List(size_t n, const T& val = T()): _begin(0), _end(0), _rend(0), _size(0)
	{
		this->initiate_first_elem(val);
		size_t i = 0;
		Node<T>	* save = _begin;
		while (++i < n)
		{
			Node<T> * temp = new Node<T>(val);
			save->add_next(temp);
			save = temp;
		}
		_size = n;
	}

	List(const List& x): _begin(0), _end(0), _rend(0), _size(0) {*this = x;}

	template <class InputIterator>
	List (InputIterator first, InputIterator last): _begin(0), _end(0), _rend(0), _size(0)
	{								// template a tester
		constructor_prototype(first, last, typename ft::is_integral<InputIterator>::type());
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

	List &	operator=(const List & x)
	{
		this->clear();
		if (x.size() > 0)
		{
			const_iterator	begin = x.begin();
			const_iterator	end = x.end();
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
			_size = x.size();
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

	size_t	max_size() const {return std::numeric_limits<size_t>::max();}


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

	void assign (size_type n, const T& val, int) { assign_prototype(n, val, int());}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		assign_prototype(first, last, typename ft::is_integral<InputIterator>::type());
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

	void insert (iterator position, size_type n, const T& val) { insert_prototype(position, n, val, int()); }

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last)
	{
		insert_prototype(position, first, last, typename ft::is_integral<InputIterator>::type());
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

	void resize (size_type n, T val = T())
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



// ========  Operations  ========

//		----  Splice  ----


	void splice (iterator position, List& x)
	{
		this->insert(position, x.begin(), x.end());
		x.clear();
	}

	void splice (iterator position, List& x, iterator i)
	{
		this->insert(position, *i);
		x.erase(i);
	}

	void splice (iterator position, List& x, iterator first, iterator last)
	{
		this->insert(position, first, last);
		x.erase(first, last);
	}

//		----  Remove  ----

	void remove (const T& val)	// test sur list vide
	{
		List::iterator	begin(_begin);
		List::iterator	end(_end);

		while (begin != end)
		{
			if (*begin == val)
				begin = this->erase(begin);
			else
				begin++;
		}
	}

//		----  Remove_if  ----

	template <class Predicate>
	void remove_if (Predicate pred)
	{
		List::iterator	begin(_begin);
		List::iterator	end(_end);

		while (begin != end)
		{
			if (pred(*begin) == true)
				begin = this->erase(begin);
			else
				begin++;
		}
	}

//		----  Unique  ----

	void unique()
	{
		List::iterator	begin(_begin);
		List::iterator	begin_previous(_begin);
		List::iterator	end(_end);

		if (_size > 1)
		{
			begin++;
			while (begin != end)
			{
				if (*begin == *(begin_previous))
					begin = this->erase(begin);
				else
				{
					begin++;
					begin_previous++;
				}
			}
		}
	}

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred)
	{
		List::iterator	begin(_begin);
		List::iterator	begin_previous(_begin);
		List::iterator	end(_end);

		if (_size > 1)
		{
			begin++;
			while (begin != end)
			{
				if (binary_pred(*begin) == binary_pred(*(begin_previous)))
					begin = this->erase(begin);
				else
				{
					begin++;
					begin_previous++;
				}
			}
		}
	}

//		----  Merge  ----

	void merge (List& x)
	{
		if (!this->is_sorted_up() || !x.is_sorted_up())
			return ;
		List::iterator	it = x.begin();
		List::iterator	ite = x.end();
		List::iterator	it_temp;
		List::iterator	itt = this->begin();
		List::iterator	itte = this->end();
		while (it != ite)
		{
			while (itt != itte && *itt < *it)
				itt++;
			it_temp = ++it;
			this->splice(itt, x, --it);
			it = it_temp;
		}
		x.clear();
	}

	template <class Compare>
	void merge (List& x, Compare comp)
	{
		if (!this->is_sorted_up() || !x.is_sorted_up())
			return ;
		List::iterator	it = x.begin();
		List::iterator	ite = x.end();
		List::iterator	it_temp;
		List::iterator	itt = this->begin();
		List::iterator	itte = this->end();
		while (it != ite)
		{
			while (itt != itte && comp(*itt, *it) == true)
				itt++;
			it_temp = ++it;
			this->splice(itt, x, --it);
			it = it_temp;
		}
		x.clear();
	}

//		----  Sort  ----

	void sort()
	{
		if (_size < 2)
			return ;
		Node<T> * temp = _begin->next;
		while (temp != _end)
		{
			if (temp->previous->value > temp->value)
			{
				if (temp->previous == _begin)
					_begin = temp;
				temp->swap_nodes(temp->previous);
				temp = _begin->next;
			}
			else
				temp = temp->next;
		}
	}
	
	template <class Compare>
	void sort (Compare comp)
	{
		if (_size < 2)
			return ;
		Node<T> * temp = _begin->next;
		while (temp != _end)
		{
			if (comp(temp->previous->value, temp->value) == false)
			{
				if (temp->previous == _begin)
					_begin = temp;
				temp->swap_nodes(temp->previous);
				temp = _begin->next;
			}
			else
				temp = temp->next;
		}	
	}

//		----  Reverse  ----

	void reverse()
	{
		if (_size < 2)
			return ;
		Node<T> * temp = _begin;
		Node<T> * begin_previous = _begin->previous;
		Node<T> * temp_previous;
		while (temp != _end)
		{
			temp_previous = temp->previous;
			temp->previous = temp->next;
			temp->next = temp_previous;
			temp = temp->previous;
		}
		_begin->next = _end;
		_end->previous->previous = begin_previous;
		begin_previous->next = _end->previous;
		_end->previous = _begin;
		_begin = begin_previous->next;
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

	int is_sorted_up()
	{
		if (_size < 2)
			return 1;
		List::iterator	begin(_begin);
		List::iterator	begin_previous(_begin);
		List::iterator	end(_end);
		begin++;
		while (begin != end)
		{
			if (*begin < *(begin_previous))
				return 0;
			else
			{
				begin++;
				begin_previous++;
			}
		}
		return 1;
	}

	// int is_sorted_down()
	// {
	// 	if (_size < 2)
	// 		return 1;
	// 	List::iterator	begin(_begin);
	// 	List::iterator	begin_previous(_begin);
	// 	List::iterator	end(_end);
	// 	begin++;
	// 	while (begin != end)
	// 	{
	// 		if (*begin > *(begin_previous))
	// 			return 0;
	// 		else
	// 		{
	// 			begin++;
	// 			begin_previous++;
	// 		}
	// 	}
	// 	return 1;
	// }

	// int	is_sorted()
	// {
	// 	if (!this->is_sorted_up() && !this->is_sorted_down())
	// 		return 0;
	// 	return 1;
	// }

// ========  Constructor - private  ========

	template <class InputIterator>
	void constructor_prototype (InputIterator first, InputIterator last, int)
	{
		this->initiate_first_elem(last);
		int i = 0;
		Node<T>	* save = _begin;
		while (++i < first)
		{
			Node<T> * temp = new Node<T>(last);
			save->add_next(temp);
			save = temp;
		}
		_size = first;
	}

	template <class InputIterator>
	void	constructor_prototype (InputIterator first, InputIterator last, void *)
	{
		if (first != last)
		{
			Node<T> * temp;
			this->initiate_first_elem(*first);
			first++;
			Node<T>	* save = _begin;
			while (first != last)
			{
				temp = new Node<T>(*first);
				save->add_next(temp);
				save = temp;
				first++;
				_size++;
			}
		}
	}


// ========  Modifiers - private  ========

//		----  Assign  ----

	template <class InputIterator>
	void assign_prototype (InputIterator & first, InputIterator & last, int)
	{
		Node<T>	*	temp;

		this->resize(first);
		temp = _begin;
		while (temp != _end)
		{
			temp->value = last;
			temp = temp->next;
		}
	}

	template <class InputIterator>
	void assign_prototype (InputIterator & first, InputIterator & last, void *)
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


//		----  Insert  ----

	template <class InputIterator>
	void insert_prototype (iterator position, InputIterator first, InputIterator last, int)
	{
		Node<T>	*	temp = _begin;
		Node<T>	*	new_node = 0;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp)
		{
			while (first-- > 0)
			{
				new_node = new Node<T>(last);
				temp->add_previous(new_node);
				temp = new_node;
				_size++;
			}
			if (position == _begin)
				_begin = new_node;
		}
	}

	template <class InputIterator>
	void insert_prototype (iterator position, InputIterator first, InputIterator last, void *)
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

};



template <typename T>
void swap (List<T>& x, List<T>& y) {x.swap(y);}

}

#endif
