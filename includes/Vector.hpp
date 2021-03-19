#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <stdexcept>

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
	typedef T value_type;

	typedef	size_t size_type;

private:
	T*				_array;
	size_t			_size;
	size_t			_capacity;
	allocator_type	_alloc;

public:
	
	explicit Vector (const allocator_type& alloc = allocator_type()): _array(0), _size(0), _capacity(0), _alloc(alloc) {}
	
	explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(0), _capacity(n), _alloc(alloc)
	{
		_array = alloc.allocate(_capacity);
		while (_size < n)
			_array[_size++] = val;
	}

	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _alloc(alloc)
	{constructor_prototype(first, last, alloc, typename ft::is_integral<InputIterator>::type());}

	Vector (const Vector& x) {*this = x;}


	~Vector(void)	 // a confirmer
	{
		this->clear();
		_alloc.deallocate(_array, _capacity);
	}


// ========  Iterators  ========

	iterator	begin(void)
	{return (iterator(_array));}
	const_iterator	begin(void) const
	{return (const_iterator(reinterpret_cast<const T*>(_array)));}

	iterator	end(void)
	{return (iterator(_array, _size));}
	const_iterator	end(void) const
	{return (const_iterator(reinterpret_cast<const T*>(_array), _size));}

	reverse_iterator	rbegin(void)
	{
		if (_size > 0)
			return reverse_iterator(_array, _size - 1);
		return (reverse_iterator(0));
	}
	const_reverse_iterator	rbegin(void) const
	{
		if (_size > 0)
			return const_reverse_iterator(reinterpret_cast<T*>(_array), _size - 1);
		return const_reverse_iterator(0);
	}

	reverse_iterator	rend(void)
	{return (reverse_iterator(_array, -1));}
	const_reverse_iterator	rend(void) const
	{return (const_reverse_iterator(reinterpret_cast<T*>(_array), -1)); }


// ========  Overload  ========

	Vector &	operator=(const Vector & x)
	{		
		this->clear();
		if (x._size > _capacity)
		{
			if (_array)
				_alloc.deallocate(_array, _capacity);
			_array = _alloc.allocate(x._capacity);
			_capacity = x._capacity;
		}
		_size = 0;
		while (_size < x._size)
		{
			_array[_size] = x._array[_size];
			_size++;
		}
		return (*this);
	}

// ========  Capacity  ========

	size_type	size(void) const {return _size;}

	size_type	max_size() const {return (std::numeric_limits<size_type>::max() / sizeof(T));}	// a confirmer

	void resize (size_type n, value_type val = value_type())
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

	size_type capacity() const {return _capacity;}

	bool	empty(void) const {return (_size == 0);} // size ou capacity ?

	void reserve (size_type n)
	{
		if (n <= _capacity)
			return ;
		Vector	temp(n);
		temp.assign(this->begin(), this->end());
		*this = temp;
	}


// ========  Element Access  ========

	T & operator[] (size_type n)
	{
		return _array[n];
	}

	const T & operator[] (size_type n) const
	{
		return reinterpret_cast<const T>(_array[n]);
	}

	T & at (size_type n)
	{
		if (n < _size)
			return _array[n];
		throw std::out_of_range("");				// a confirmer
	}

	const T & at (size_type n) const
	{
		if (n < _size)
			return reinterpret_cast<const T>(_array[n]);
		throw std::out_of_range("");				// a confirmer
	}


	T &	front(void)
	{
		if (_size)
			return _array[0];
		throw std::exception();
	}

	const T &	front(void) const
	{
		if (_size)
			return reinterpret_cast<const T>(_array[0]);
		throw std::exception();
	}

	T &	back(void)
	{
		if (_size)
			return _array[_size - 1];
		throw std::exception();
	}

	const T &	back(void) const
	{
		if (_size)
			return reinterpret_cast<const T>(_array[_size - 1]);
		throw std::exception();
	}


// ========  Modifiers  ========

//		----  Assign  ----

	void assign (size_type n, const value_type& val, int) {assign_prototype(n, val, int());}

	template <class InputIterator, class InputIterator2>
	void assign (InputIterator first, InputIterator2 last)
	{assign_prototype(first, last, typename ft::is_integral<InputIterator>::type());}

//		----  Push / Pop  ----

	void	push_back (const value_type & val)
	{
		if (!_array)
			this->initiate_first_elem(val);
		else if (_size < _capacity)
			_array[_size++] = val;
		else
		{
			Vector	temp(_capacity * 2);
			temp = *this;
			temp[_size] = val;
			*this = temp;
		}
	}

	void	pop_back(void)
	{
		if (!_size)
			return ;
		else
			this->erase(--(this->end()));
	}

//		----  Insert  ----

	iterator insert (iterator position, const value_type& val)	// a ajuster si position apres end
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return iterator(0);		// a confirmer
		this->drift(position, 1);
		_array[i] = val;		
		return (iterator(*this, i));
	}

	void insert (iterator position, size_type n, const value_type& val) {insert_prototype(position, n, val, int()); }

	template <class InputIterator, class InputIterator2>
	void insert (iterator position, InputIterator first, InputIterator2 last)
	{
		insert_prototype(position, first, last, typename ft::is_integral<InputIterator>::type());
	}

//		----  Erase  ----

	iterator erase (iterator position)		// a ajuster si position apres end
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		this->drift_left(position, 1);
		return (iterator(*this, i));
	}

	iterator erase (iterator first, iterator last)			// a ajuster si position apres end
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != first && i < _size)
		{
			it++;
			i++;
		}

		size_t	len = 0;
		while (it != last && i + len < _size)
		{
			it++;
			len++;
		}

		this->drift_left(first, len);
		return (iterator(*this, i));
	}

//		----  Swap  ----

	void swap (Vector& x)
	{
		T*				temp_array;
		size_t			temp_size;
		size_t			temp_capacity;

		x._array = _array;
		x._size = _size;
		x._capacity = _capacity;

		_array = temp_array;
		_size = temp_size;
		_capacity = temp_capacity;
	}


//		----  Clear  ----

	void clear() {this->erase(this->begin(), this->end());}	// a tester



// ************************************************************** //
// ************************************************************** //

private:

	void	initiate_first_elem(const value_type & val)
	{
		_array = _alloc.allocate(2);
		_array[0] = val;
		_capacity = 1;
		_size = 1;
	}

	void	drift_right(iterator position, size_t len)
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return ;
	
		Vector	temp(_size + len);
		size_t	index = 0;
		while (index < i)
		{
			temp[index] = _array[index];
			index++;
		}
		while (index < _size)
		{
			temp[index + len] = _array[index];
			index++;
		}
		*this = temp;
	}

	void	drift_left(iterator position, size_t len)
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return ;
		
		while (i + len < _size)
		{
			_array[i] = _array[i + len];
			i++;
		}
		while (i < _size)
			_array[i++] = T();
	}



// ========  Constructor - private  ========

	template <class InputIterator>
	void	constructor_prototype (InputIterator first, InputIterator last, const allocator_type& alloc, int)
	{
		_array = alloc.allocate(_capacity);
		while (_size < first)
			_array[_size++] = last;
	}

	template <class InputIterator>
	void	constructor_prototype (InputIterator first, InputIterator last, const allocator_type& alloc, void *)
	{
		InputIterator	temp;

		while (temp != last)
		{
			temp++;
			_capacity++;
		}
		_array = alloc.allocate(_capacity);
		while (first != last)
			_array[_size++] = *first++;
	}


// ========  Modifiers - private  ========

//		----  Assign  ----

	template <class InputIterator, class InputIterator2>
	void assign_prototype (InputIterator & first, InputIterator2 & last, int)
	{
		Vector	temp(first, last);
		*this = temp;
	}

	template <class InputIterator, class InputIterator2>
	void assign_prototype (InputIterator & first, InputIterator2 & last, void *)
	{
		Vector	temp(first, last);
		*this = temp;
	}


//		----  Insert  ----

	template <class InputIterator, class InputIterator2>
	void insert_prototype (iterator position, InputIterator first, InputIterator2 last, int)
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return ;
		this->drift_right(position, first);

		size_t	count = 0;
		while (first-- > 0)
			_array[i + count++] = last;
	}

	template <class InputIterator, class InputIterator2>
	void insert_prototype (iterator position, InputIterator first, InputIterator2 last, void *)
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		
		size_t	len = 0;
		iterator	temp = first;
		while (temp++ != last)
			len++;

		if (it != position)
			return ;
		this->drift_right(position, len);

		size_t	count = 0;
		while (first != last)
			_array[i + count++] = *first++;
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
