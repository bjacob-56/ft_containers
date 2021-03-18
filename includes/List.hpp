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

		Node(): previous(0), next(0), value(T()) {}
		Node(const T & val): previous(0), next(0), value(val) {}
		Node(Node *pr, Node *ne, const T & val): previous(pr), next(ne), value(val)
		{
			pr->next = this;
			ne->previous = this;
		}
		~Node() {}
	
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

	void	swap_following_nodes(Node * node_next)
	{
		Node * next_next = node_next->next;
		Node * previous_current = previous;
		
		next = node_next->next;
		node_next->previous = previous;
		previous = node_next;
		node_next->next = this;
		next_next->previous = this;
		previous_current->next = node_next;
	}
};


template <typename T>
class List
{
public:

	typedef MyIterator<T, Node<T> *> iterator;
	typedef MyConstIterator<const T, Node<const T> *> const_iterator;
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
		// const Node<T> * node = _begin;
		Node<const T> * node = reinterpret_cast<Node<const T> *>(_begin);

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
		// const Node<T> * node = _end;
		Node<const T> * node = reinterpret_cast<Node<const T> *>(_end);

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

	size_type	size(void) const {return (_size);}

	size_type	max_size() const {return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));}


// ========  Element Access  ========

	T &	front(void)
	{
		if (_begin)
			return (_begin->value);
		throw std::exception();
	}	// besoin de faire la meme en const ?

	T &	back(void)
	{
		if (_end)
			return (_end->previous->value);
		throw std::exception();
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
			this->erase(--(this->end()));
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
		if (!_size)
			return ;
		else if (_size == 1)
			this->clear();
		else
			this->erase((this->begin()));
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
			if (_begin == temp_del)
				_begin = temp;
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
				if (_begin == temp_del)
					_begin = temp;
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
		else
		{
			if (_end)
				delete _end;
			if (_rend)
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
				if (binary_pred(*begin, *begin_previous) == true)
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
		if (!this->is_sorted_comp(comp) || !x.is_sorted_comp(comp))
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
				temp->previous->swap_following_nodes(temp);
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
			if (comp(temp->previous->value, temp->value) == false && temp->previous->value != temp->value)
			{
				if (temp->previous == _begin)
					_begin = temp;
				temp->previous->swap_following_nodes(temp);
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

	template <class Compare>
	int is_sorted_comp(Compare comp)
	{
		if (_size < 2)
			return 1;
		List::iterator	begin(_begin);
		List::iterator	begin_previous(_begin);
		List::iterator	end(_end);
		begin++;
		while (begin != end)
		{
			if (comp(*begin, *begin_previous) == true)
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



// ========  Comparison  ========

template <class T>
bool operator== (const List<T>& lhs, const List<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	if (!lhs.size())
		return true;
	ft::List<int>::const_iterator		it1 = lhs.begin();
	ft::List<int>::const_iterator		it2 = rhs.begin();
	while (it1 != lhs.end() && it2 != rhs.end())
	{
		if (*it1++ != *it2++)
			return false;
	}
	if (it1 == lhs.end() && it2 == rhs.end())
		return true;
	return false;
}

template <class T>
bool operator!= (const List<T>& lhs, const List<T>& rhs) {return !(lhs == rhs);}

template <class T>
bool operator< (const List<T>& lhs, const List<T>& rhs)
{
	if (!lhs.size() && rhs.size())
		return true;
	if (lhs.size() && !rhs.size())
		return false;
	ft::List<int>::const_iterator		it1 = lhs.begin();
	ft::List<int>::const_iterator		it2 = rhs.begin();
	while (it1 != lhs.end() && it2 != rhs.end() && *it1 == *it2)
	{
		it1++;
		it2++;
	}
	if (it2 == rhs.end())
		return false;
	if (it1 == lhs.end())
		return true;
	if (*it1 < *it2)
		return true;
	return false;
}

template <class T>
bool operator> (const List<T>& lhs, const List<T>& rhs)
{
	if (lhs.size() && !rhs.size())
		return true;
	if (!lhs.size() && rhs.size())
		return false;
	ft::List<int>::const_iterator		it1 = lhs.begin();
	ft::List<int>::const_iterator		it2 = rhs.begin();
	while (it1 != lhs.end() && it2 != rhs.end() && *it1 == *it2)
	{
		it1++;
		it2++;
	}
	if (it1 == lhs.end())
		return false;
	if (it2 == rhs.end())
		return true;
	if (*it1 > *it2)
		return true;
	return false;
}

template <class T>
bool operator<= (const List<T>& lhs, const List<T>& rhs) {return !(lhs > rhs);}

template <class T>
bool operator>= (const List<T>& lhs, const List<T>& rhs) {return !(lhs < rhs);}



template <typename T>
void swap (List<T>& x, List<T>& y) {x.swap(y);}

}

#endif
