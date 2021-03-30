#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <cstddef>

# include "Iterator.hpp"
# include "Is_integral.hpp"

namespace ft
{

	template <typename T, typename PointerType>
	class ListIterator;

	template <typename T, typename PointerType>
	class ListConstIterator;

	template <typename T, typename PointerType>
	class ListReverseIterator;

	template <typename T, typename PointerType>
	class ListConstReverseIterator;

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

	void	move_to_previous(Node * node)
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		this->add_previous(node);
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

template <typename T, class Alloc = std::allocator<T> >
class List
{
public:
	typedef T value_type;
	typedef Alloc allocator_type;

	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;

	typedef ListIterator<T, Node<T> *> iterator;
	typedef ListConstIterator<T, Node<const T> *> const_iterator;
	typedef ListReverseIterator<T, Node<T> *> reverse_iterator;
	typedef ListConstReverseIterator<T,  Node<const T> *> const_reverse_iterator;
	
	typedef std::ptrdiff_t difference_type;
	typedef	size_t size_type;

protected:
	Node<T>	*_begin;
	Node<T>	*_end;
	Node<T>	*_rend;
	size_t	_size;
	allocator_type	_alloc;

public:
	explicit List(const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc) {}
	explicit List(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc)
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

	template <class InputIterator>
	List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc)
	{constructor_prototype(first, last, typename ft::is_integral<InputIterator>::type());}

	List(const List& x): _begin(0), _end(0), _rend(0), _size(0) {*this = x;}

	virtual ~List(void) {this->clear();}


// ========  Iterators  ========

	iterator	begin(void)
	{return (iterator(_begin));}
	const_iterator	begin(void) const
	{return (const_iterator(reinterpret_cast<Node<const T> *>(_begin)));}

	iterator	end(void)
	{return (iterator(_end));}
	const_iterator	end(void) const
	{return (const_iterator(reinterpret_cast<Node<const T> *>(_end)));}

	reverse_iterator	rbegin(void)
	{		
		if (_size > 0)
			return reverse_iterator(_end->previous);
		return (reverse_iterator(0));
	}
	const_reverse_iterator	rbegin(void) const
	{
		if (_size > 0)
			return const_reverse_iterator(reinterpret_cast<Node<const T> *>(_end->previous));
		return const_reverse_iterator(0);
	}

	reverse_iterator	rend(void)
	{return (reverse_iterator(_rend));}
	const_reverse_iterator	rend(void) const
	{return (const_reverse_iterator(reinterpret_cast<Node<const T> *>(_rend))); }


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
			_alloc = x._alloc;
		}
		return (*this);
	}

// ========  Capacity  ========

	bool	empty(void) const {return (_size == 0);}

	size_type	size(void) const {return (_size);}

	size_type	max_size() const {return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));}


// ========  Element Access  ========

	reference	front(void)
	{
		if (_begin)
			return (_begin->value);
		throw std::exception();
	}

	const_reference	front(void) const
	{
		if (_begin)
			return (_begin->value);
		throw std::exception();
	}

	reference	back(void)
	{
		if (_end)
			return (_end->previous->value);
		throw std::exception();
	}

	const_reference	back(void) const
	{
		if (_end)
			return (_end->previous->value);
		throw std::exception();
	}


// ========  Modifiers  ========

//		----  Assign  ----

	void assign (size_type n, const value_type& val, int) { assign_prototype(n, val, int());}

	template <class InputIterator, class InputIterator2>
	void assign (InputIterator first, InputIterator2 last)
	{
		assign_prototype(first, last, typename ft::is_integral<InputIterator>::type());
	}

//		----  Push / Pop  ----

	void	push_back (const value_type & val)
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

	void	push_front (const value_type & val)
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

	iterator insert (iterator position, const value_type& val)
	{
		Node<T>	*	temp = _begin;
		Node<T>	*	new_node = 0;

		if (this->empty())
		{
			this->initiate_first_elem(val);
			return (this->begin());
		}
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

	void insert (iterator position, size_type n, const value_type& val) {insert_prototype(position, n, val, int()); }

	template <class InputIterator, class InputIterator2>
	void insert (iterator position, InputIterator first, InputIterator2 last)
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

	void resize (size_type n, value_type val = T())
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
		x.erase(x.begin(), x.end());
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

	void remove (const value_type& val)
	{
		List::iterator	begin = this->begin();

		while (begin != this->end())
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
		List::iterator	begin = this->begin();

		while (begin != this->end())
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
			while (begin != this->end())
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
			while (begin != this->end())
			{
				if (binary_pred(*begin_previous, *begin) == true) 
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
		while (it != ite)
		{
			while (itt != this->end() && *itt < *it)
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
		List::iterator	it = x.begin();
		List::iterator	ite = x.end();
		List::iterator	it_temp;
		List::iterator	itt = this->begin();
		while (it != ite)
		{
			while (itt != this->end() &&
				comp(*itt, *it) == true &&
				comp(*it, *itt) == false)
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
		Node<T> * temp;
		Node<T> * temp_bis;
		Node<T> * begin = _begin;

		while (begin != _end->previous)
		{
			temp = begin->next;
			temp_bis = begin;
			while (temp != _end)
			{
				if (comp(temp->value, temp_bis->value) == true &&
				(temp_bis == begin || comp(temp_bis->value, temp->value) == false))
					temp_bis = temp;
				temp = temp->next;
			}
			if (temp_bis != begin)
			{					
				if (begin == _begin)
					_begin = temp_bis;
				if (temp_bis == _end->previous)
					_end->previous = temp_bis->previous;
				begin->move_to_previous(temp_bis);
				if (comp(temp_bis->value, begin->value) == true &&
					comp(begin->value, temp_bis->value) == true)
					begin = begin->next;
			}
			else
				begin = begin->next;
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

protected:

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
		begin++;
		while (begin != this->end())
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
		begin++;
		while (begin != this->end())
		{
			if (comp(*begin, *begin_previous) == true &&
				comp(*begin_previous, *begin) == false &&
				*begin != *begin_previous)
				return 0;
			else
			{
				begin++;
				begin_previous++;
			}
		}
		return 1;
	}


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

	template <class InputIterator, class InputIterator2>
	void assign_prototype (InputIterator & first, InputIterator2 & last, int)
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

	template <class InputIterator, class InputIterator2>
	void assign_prototype (InputIterator & first, InputIterator2 & last, void *)
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

	template <class InputIterator, class InputIterator2>
	void insert_prototype (iterator position, InputIterator first, InputIterator2 last, int)
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

	template <class InputIterator, class InputIterator2>
	void insert_prototype (iterator position, InputIterator first, InputIterator2 last, void *)
	{
		Node<T>	*	temp = _begin;
		Node<T>	*	new_node = 0;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp)
		{
			while (first != last)
			{

				if (!_size)
				{
					initiate_first_elem(*(--last));
					temp = _begin;
					position = _begin;
				}
				else
				{
				new_node = new Node<T>(*(--last));

				
				temp->add_previous(new_node);
				temp = new_node;
				_size++;
				}
			}
			if (position == _begin)
				_begin = temp;
		}
	}

public:
	// ========  Comparison  ========
	
	bool operator== (const List& rhs)
	{
		if (this->size() != rhs.size())
			return false;
		if (!this->size())
			return true;
		const_iterator		it1 = this->begin();
		const_iterator		it2 = rhs.begin();
		while (it1 != this->end() && it2 != rhs.end())
		{
			if (*it1++ != *it2++)
				return false;
		}
		if (it1 == this->end() && it2 == rhs.end())
			return true;
		return false;
	}
	
	bool operator!= (const List& rhs) {return !((*this) == rhs);}
	
	bool operator< (const List& rhs)
	{
		if (!this->size() && rhs.size())
			return true;
		if (this->size() && !rhs.size())
			return false;
		const_iterator		it1 = this->begin();
		const_iterator		it2 = rhs.begin();
		while (it1 != this->end() && it2 != rhs.end() && *it1 == *it2)
		{
			it1++;
			it2++;
		}
		if (it2 == rhs.end())
			return false;
		if (it1 == this->end())
			return true;
		if (*it1 < *it2)
			return true;
		return false;
	}
	
	bool operator> (const List& rhs)
	{
		if (this->size() && !rhs.size())
			return true;
		if (!this->size() && rhs.size())
			return false;
		const_iterator		it1 = this->begin();
		const_iterator		it2 = rhs.begin();
		while (it1 != this->end() && it2 != rhs.end() && *it1 == *it2)
		{
			it1++;
			it2++;
		}
		if (it1 == this->end())
			return false;
		if (it2 == rhs.end())
			return true;
		if (*it1 > *it2)
			return true;
		return false;
}

bool operator<= (const List& rhs) {return !((*this) > rhs);}

bool operator>= (const List& rhs) {return !((*this) < rhs);}

};



// ========  Comparison  ========

template <typename T, class Alloc>
bool operator== (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	if (!lhs.size())
		return true;
	typename ft::List<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::List<T, Alloc>::const_iterator		it2 = rhs.begin();
	while (it1 != lhs.end() && it2 != rhs.end())
	{
		if (*it1++ != *it2++)
			return false;
	}
	if (it1 == lhs.end() && it2 == rhs.end())
		return true;
	return false;
}

template <typename T, class Alloc>
bool operator!= (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs) {return !(lhs == rhs);}

template <typename T, class Alloc>
bool operator< (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
{
	if (!lhs.size() && rhs.size())
		return true;
	if (lhs.size() && !rhs.size())
		return false;
	typename ft::List<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::List<T, Alloc>::const_iterator		it2 = rhs.begin();
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

template <typename T, class Alloc>
bool operator> (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
{
	if (lhs.size() && !rhs.size())
		return true;
	if (!lhs.size() && rhs.size())
		return false;
	typename ft::List<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::List<T, Alloc>::const_iterator		it2 = rhs.begin();
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

template <typename T, class Alloc>
bool operator<= (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs) {return !(lhs > rhs);}

template <class T, class Alloc>
bool operator>= (const List<T, Alloc>& lhs, const List<T, Alloc>& rhs) {return !(lhs < rhs);}



template <typename T, class Alloc>
void swap (List<T, Alloc>& x, List<T, Alloc>& y) {x.swap(y);}

}

#endif
