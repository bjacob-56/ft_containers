#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>

# include "Iterator.hpp"
# include "Is_integral.hpp"

namespace ft
{

template <typename T, class Alloc = std::allocator<T> >
class Vector
{
public:

	typedef VectorIterator<T> iterator;
	typedef VectorConstIterator<const T> const_iterator;
	typedef VectorReverseIterator<T> reverse_iterator;
	typedef VectorConstReverseIterator<const T> const_reverse_iterator;
	
	typedef typename std::allocator<T> allocator_type;

	typedef	size_t size_type;

private:
	T*				_array;
	size_t			_size;
	size_t			_capacity;
	allocator_type	_alloc;

public:
	explicit Vector(const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc) {}
	explicit Vector(size_t n, const T& val = T(), const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc)
	{
		this->initiate_first_elem(val);
		size_t i = 0;
		Array<T>	* save = _begin;
		while (++i < n)
		{
			Array<T> * temp = new Array<T>(val);
			save->add_next(temp);
			save = temp;
		}
		_size = n;
	}

	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _begin(0), _end(0), _rend(0), _size(0), _alloc(alloc)
	{								// template a tester
		constructor_prototype(first, last, typename ft::is_integral<InputIterator>::type());
	}

	Vector(const Vector& x): _begin(0), _end(0), _rend(0), _size(0) {*this = x;}

	~Vector(void) {this->clear();}


// ========  Iterators  ========

	iterator	begin(void)
	{return (iterator(_begin));}
	const_iterator	begin(void) const
	{return (const_iterator(reinterpret_cast<Array<const T> *>(_begin)));}

	iterator	end(void)
	{return (iterator(_end));}
	const_iterator	end(void) const
	{return (const_iterator(reinterpret_cast<Array<const T> *>(_end)));}

	reverse_iterator	rbegin(void)
	{		
		if (_size > 0)
			return reverse_iterator(_end->previous);
		return (reverse_iterator(0));
	}
	const_reverse_iterator	rbegin(void) const
	{
		if (_size > 0)
			return const_reverse_iterator(reinterpret_cast<Array<const T> *>(_end->previous));
		return const_reverse_iterator(0);
	}

	reverse_iterator	rend(void)
	{return (reverse_iterator(_rend));}
	const_reverse_iterator	rend(void) const
	{return (const_reverse_iterator(reinterpret_cast<Array<const T> *>(_rend))); }


// ========  Overload  ========

	Vector &	operator=(const Vector & x)
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
				Array<T>	* save = _begin;
				while (begin != end)
				{
					Array<T> * temp = new Array<T>(*begin);
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

	bool	empty(void) const
	{
		if (!_size)
			return (true);
		return (false);
	}

	size_type	size(void) const {return (_size);}

	size_type	max_size() const {return (std::numeric_limits<size_type>::max() / sizeof(Array<T>));}


// ========  Element Access  ========

	T &	front(void)
	{
		if (_begin)
			return (_begin->value);
		throw std::exception();
	}

	const T &	front(void) const
	{
		if (_begin)
			return (_begin->value);
		throw std::exception();
	}

	T &	back(void)
	{
		if (_end)
			return (_end->previous->value);
		throw std::exception();
	}

	const T &	back(void) const
	{
		if (_end)
			return (_end->previous->value);
		throw std::exception();
	}


// ========  Modifiers  ========

//		----  Assign  ----

	void assign (size_type n, const T& val, int) { assign_prototype(n, val, int());}

	template <class InputIterator, class InputIterator2>
	void assign (InputIterator first, InputIterator2 last)
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
			Array<T> * temp = new Array<T>(val);
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
			Array<T> * new_begin = new Array<T>(val);
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
		Array<T>	*	temp = _begin;
		Array<T>	*	new_Array = 0;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp)
		{
			new_Array = new Array<T>(val);
			temp->add_previous(new_Array);
			_size++;
			if (position == _begin)
				_begin = new_Array;
		}
		return (iterator(new_Array));
	}

	void insert (iterator position, size_type n, const T& val) { insert_prototype(position, n, val, int()); }

	template <class InputIterator, class InputIterator2>
	void insert (iterator position, InputIterator first, InputIterator2 last)
	{
		insert_prototype(position, first, last, typename ft::is_integral<InputIterator>::type());
	}

//		----  Erase  ----

	iterator erase (iterator position)
	{
		Array<T>	*	temp = _begin;
		Array<T>	*	temp_del;

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
		Array<T>	*	temp = _begin;
		Array<T>	*	temp_del;

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

	void swap (Vector& x)
	{
		Array<T> * temp_begin = x._begin;
		Array<T> * temp_end = x._end;
		Array<T> * temp_rend = x._rend;
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
		Array<T>	* Array = _begin;

		if (_size > 0)
		{
			while (Array != _end)
			{
				Array = Array->next;
				delete Array->previous;
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


	void splice (iterator position, Vector& x)
	{
		this->insert(position, x.begin(), x.end());
		x.clear();
	}

	void splice (iterator position, Vector& x, iterator i)
	{
		this->insert(position, *i);
		x.erase(i);
	}

	void splice (iterator position, Vector& x, iterator first, iterator last)
	{
		this->insert(position, first, last);
		x.erase(first, last);
	}

//		----  Remove  ----

	void remove (const T& val)
	{
		Vector::iterator	begin(_begin);
		Vector::iterator	end(_end);

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
		Vector::iterator	begin(_begin);
		Vector::iterator	end(_end);

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
		Vector::iterator	begin(_begin);
		Vector::iterator	begin_previous(_begin);
		Vector::iterator	end(_end);

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
		Vector::iterator	begin(_begin);
		Vector::iterator	begin_previous(_begin);
		Vector::iterator	end(_end);

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

	void merge (Vector& x)
	{
		if (!this->is_sorted_up() || !x.is_sorted_up())
			return ;
		Vector::iterator	it = x.begin();
		Vector::iterator	ite = x.end();
		Vector::iterator	it_temp;
		Vector::iterator	itt = this->begin();
		Vector::iterator	itte = this->end();
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
	void merge (Vector& x, Compare comp)
	{
		if (!this->is_sorted_comp(comp) || !x.is_sorted_comp(comp))
			return ;
		Vector::iterator	it = x.begin();
		Vector::iterator	ite = x.end();
		Vector::iterator	it_temp;
		Vector::iterator	itt = this->begin();
		Vector::iterator	itte = this->end();
		while (it != ite)
		{
			while (itt != itte &&
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
		Array<T> * temp = _begin->next;
		while (temp != _end)
		{
			if (temp->previous->value > temp->value)
			{
				if (temp->previous == _begin)
					_begin = temp;
				temp->previous->swap_following_Arrays(temp);
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
		Array<T> * temp;
		Array<T> * temp_bis;
		Array<T> * begin = _begin;

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
		Array<T> * temp = _begin;
		Array<T> * begin_previous = _begin->previous;
		Array<T> * temp_previous;
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
		_end = new Array<T>();
		_rend = new Array<T>();
		_begin = new Array<T>(_rend, _end, val);
		_size = 1;
	}

	int is_sorted_up()
	{
		if (_size < 2)
			return 1;
		Vector::iterator	begin(_begin);
		Vector::iterator	begin_previous(_begin);
		Vector::iterator	end(_end);
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
		Vector::iterator	begin(_begin);
		Vector::iterator	begin_previous(_begin);
		Vector::iterator	end(_end);
		begin++;
		while (begin != end)
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
		Array<T>	* save = _begin;
		while (++i < first)
		{
			Array<T> * temp = new Array<T>(last);
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
			Array<T> * temp;
			this->initiate_first_elem(*first);
			first++;
			Array<T>	* save = _begin;
			while (first != last)
			{
				temp = new Array<T>(*first);
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
		Array<T>	*	temp;

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
		Array<T>	*	temp;
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
		Array<T>	*	temp = _begin;
		Array<T>	*	new_Array = 0;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp)
		{
			while (first-- > 0)
			{
				new_Array = new Array<T>(last);
				temp->add_previous(new_Array);
				temp = new_Array;
				_size++;
			}
			if (position == _begin)
				_begin = new_Array;
		}
	}

	template <class InputIterator, class InputIterator2>
	void insert_prototype (iterator position, InputIterator first, InputIterator2 last, void *)
	{
		Array<T>	*	temp = _begin;
		Array<T>	*	new_Array = 0;

		while (position != temp && temp != _end)
			temp = temp->next;
		if (position == temp)
		{
			while (first != last)
			{
				new_Array = new Array<T>(*(--last));
				temp->add_previous(new_Array);
				temp = new_Array;
				_size++;
			}
			if (position == _begin)
				_begin = new_Array;
		}
	}

};



// ========  Comparison  ========

template <typename T, class Alloc>
bool operator== (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	if (!lhs.size())
		return true;
	typename ft::Vector<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::Vector<T, Alloc>::const_iterator		it2 = rhs.begin();
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
bool operator!= (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {return !(lhs == rhs);}

template <typename T, class Alloc>
bool operator< (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
{
	if (!lhs.size() && rhs.size())
		return true;
	if (lhs.size() && !rhs.size())
		return false;
	typename ft::Vector<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::Vector<T, Alloc>::const_iterator		it2 = rhs.begin();
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
bool operator> (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
{
	if (lhs.size() && !rhs.size())
		return true;
	if (!lhs.size() && rhs.size())
		return false;
	typename ft::Vector<T, Alloc>::const_iterator		it1 = lhs.begin();
	typename ft::Vector<T, Alloc>::const_iterator		it2 = rhs.begin();
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
bool operator<= (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {return !(lhs > rhs);}

template <class T, class Alloc>
bool operator>= (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {return !(lhs < rhs);}



template <typename T, class Alloc>
void swap (Vector<T, Alloc>& x, Vector<T, Alloc>& y) {x.swap(y);}

}

#endif
