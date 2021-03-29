#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <stdexcept>
# include <memory>

# include "Iterator.hpp"
# include "Is_integral.hpp"

namespace ft
{
	template <typename T>
	class VectorIterator;

	template <typename T>
	class VectorConstIterator;

	template <typename T>
	class VectorReverseIterator;

	template <typename T>
	class VectorConstReverseIterator;

template <typename T, class Alloc = std::allocator<T> >
class Vector
{
public:
	typedef T value_type;
	typedef Alloc allocator_type;

	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	
	typedef VectorIterator<T> iterator;
	typedef VectorConstIterator<T> const_iterator;
	typedef VectorReverseIterator<T> reverse_iterator;
	typedef VectorConstReverseIterator<T> const_reverse_iterator;
	
	typedef std::ptrdiff_t difference_type;
	typedef	size_t size_type;

private:
	T *				_array;
	size_t			_size;
	size_t			_capacity;
	allocator_type	_alloc;

public:
	
	explicit Vector (const allocator_type& alloc = allocator_type()): _array(NULL), _size(0), _capacity(0), _alloc(alloc) {}
	
	explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _array(NULL), _size(0), _capacity(0), _alloc(alloc)
	{
		// _capacity = find_next_power2(n);
		_capacity = n;
		_array = _alloc.allocate(_capacity);
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
		while (_size < n)
			_array[_size++] = val;
	}

	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _array(NULL), _size(0), _capacity(0), _alloc(alloc)
	{constructor_prototype(first, last, typename ft::is_integral<InputIterator>::type());}

	Vector (const Vector& x): _array(NULL), _size(0), _capacity(0), _alloc(allocator_type())
	{*this = x;}


	~Vector(void)
	{
		this->clear();
		_alloc.deallocate(_array, _capacity);
	}


// ========  Iterators  ========

	iterator	begin(void)
	{return (iterator(_array, _size));}
	const_iterator	begin(void) const
	{return (const_iterator(reinterpret_cast< const T* >(_array), _size));}

	iterator	end(void)
	{return (iterator(_array, _size, _size));}
	const_iterator	end(void) const
	{return (const_iterator(reinterpret_cast< const T* >(_array), _size, _size));}

	reverse_iterator	rbegin(void)
	{
		if (_size > 0)
			return reverse_iterator(_array, _size, _size - 1);
		return (reverse_iterator());
	}
	const_reverse_iterator	rbegin(void) const
	{
		if (_size > 0)
			return const_reverse_iterator(reinterpret_cast< const T* >(_array), _size, _size - 1);
		return const_reverse_iterator();
	}

	reverse_iterator	rend(void)
	{
		if (_size > 0)
			return (reverse_iterator(_array, _size, -1));
		return (reverse_iterator());
	}
	const_reverse_iterator	rend(void) const
	{
		if (_size > 0)
			return (const_reverse_iterator(reinterpret_cast< const T* >(_array), _size, -1));
		return (const_reverse_iterator());
	}


// ========  Overload  ========

	Vector &	operator=(const Vector & x)
	{
		this->clear();
		if (_array)
			_alloc.deallocate(_array, _capacity);
		_capacity = std::max(_capacity, find_next_power2(x._size));
		_array = _alloc.allocate(_capacity);
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
		while (_size < x._size)
		{
			_array[_size] = x._array[_size];
			_size++;
		}
		while (_size < _capacity)
			_array[_size++] = T();
		_size = x._size;
		return (*this);
	}

// ========  Capacity  ========

	size_type	size(void) const {return _size;}

	size_type	max_size() const {return (std::numeric_limits<size_type>::max() / sizeof(T));}

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

	bool	empty(void) const {return (_size == 0);}

	void reserve (size_type n)
	{
		if (n <= _capacity)
			return ;
		Vector	temp(*this);
		_alloc.deallocate(_array, _capacity);
		_capacity = n;
		_array = _alloc.allocate(_capacity);
		_size = 0;
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
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
		throw std::out_of_range("");
	}

	const T & at (size_type n) const
	{
		if (n < _size)
			return reinterpret_cast<const T>(_array[n]);
		throw std::out_of_range("");
	}


	reference	front(void)
	{
		if (_size)
			return _array[0];
		throw std::exception();
	}

	const_reference	front(void) const
	{
		if (_size)
			return reinterpret_cast<const T>(_array[0]);
		throw std::exception();
	}

	reference	back(void)
	{
		if (_size)
			return _array[_size - 1];
		throw std::exception();
	}

	const_reference	back(void) const
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
		if (_array == NULL)
			this->initiate_first_elem(val);
		else if (_size < _capacity)
			_array[_size++] = val;
		else
		{
			Vector temp(_capacity + 1);

			temp = *this;
			temp.push_back(val);

			*this = temp;
		}
	}

	void	pop_back(void)
	{
		if (!_size)
			return ;
		iterator ite = this->end();
		ite--;
		this->erase(ite);
	}

//		----  Insert  ----

	iterator insert (iterator position, const value_type& val)
	{
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return iterator();
		this->drift_right(position, 1);
		_array[i] = val;		
		return (iterator(_array, _size, i));
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
		iterator	it = this->begin();
		size_t	i = 0;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		this->drift_left(position, 1);
		return (iterator(_array, _size, i));
	}

	iterator erase (iterator first, iterator last)
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
		return (iterator(_array, _size, i));
	}

//		----  Swap  ----

	void swap (Vector& x)
	{
		T*				temp_array = x._array;
		size_t			temp_size = x._size;
		size_t			temp_capacity = x._capacity;

		x._array = _array;
		x._size = _size;
		x._capacity = _capacity;

		_array = temp_array;
		_size = temp_size;
		_capacity = temp_capacity;
	}


//		----  Clear  ----

	void clear() {this->erase(this->begin(), this->end());}



// ************************************************************** //
// ************************************************************** //

private:

	void	initiate_first_elem(const value_type & val)
	{

		_capacity = 1;
		_array = _alloc.allocate(_capacity);
		_size = 0;
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
		_array[_size++] = val;
	}

	void	drift_right(iterator & position, size_t len)
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

	void	drift_left(iterator & position, size_t len)
	{
		iterator	it = this->begin();
		size_t	i = 0;
		size_t	size_temp = _size;

		while (it != position && i < _size)
		{
			it++;
			i++;
		}
		if (it != position)
			return ;
		while (i + len < size_temp)
		{
			_array[i] = _array[i + len];
			i++;
		}
		while (i < size_temp)
		{
			_array[i++] = T();
			_size--;
		}
	}

	size_t	copy_array(T** array_dest, size_t dest_len, T* array_src, size_t src_len, allocator_type alloc)
	{
		size_t capacity = dest_len;

		while (capacity < src_len)
		{
			alloc.deallocate(*array_dest, capacity);
			capacity *= 2;
			*array_dest = alloc.allocate(capacity);
			for (size_t i = 0 ; i < _capacity ; i++)
				_alloc.construct(*array_dest + i, T());
		}
		for (size_t i = 0 ; i < src_len ; i++)
			(*array_dest)[i] = array_src[i];
		return (capacity);
	}


// ========  Constructor - private  ========

	template <class InputIterator>
	void	constructor_prototype (InputIterator first, InputIterator last, int)
	{
		// _capacity = find_next_power2(first);
		_capacity = first;
		_array = _alloc.allocate(_capacity);
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
		while (first-- > 0)
			_array[_size++] = last;
	}

	template <class InputIterator>
	void	constructor_prototype (InputIterator first, InputIterator last, void *)
	{
		InputIterator	temp = first;

		while (temp != last)
		{
			temp++;
			_capacity++;
		}
		// _capacity = find_next_power2(_capacity);
		_array = _alloc.allocate(_capacity);
		while (_size < _capacity)
			_alloc.construct(_array + _size++, T());
		_size = 0;
		while (first != last)
			_array[_size++] = *(first++);
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
		InputIterator	temp = first;
		while (temp++ != last)
			len++;

		if (it != position)
			return ;
		this->drift_right(position, len);

		size_t	count = 0;
		while (first != last)
			_array[i + count++] = *first++;
	}

	size_t find_next_power2(size_t capacity)
	{
		size_t res = 1;
		while (res < capacity)
			res *= 2;
		return (res);		
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
