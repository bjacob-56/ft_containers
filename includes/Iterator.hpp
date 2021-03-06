#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "List.hpp"
#include "Vector.hpp"

namespace ft
{

// **********************************************************************************
// ************************************   LIST   ************************************
// **********************************************************************************

template <typename T>
class Node;

template <typename T, typename PointerType>
	class ListIterator
	{
		public:
			typedef T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef T*   pointer;
    		typedef T& reference;
    		typedef std::bidirectional_iterator_tag  iterator_category;

			ListIterator(void): _ptr(0) {};
			ListIterator(PointerType ptr): _ptr(ptr) {};
			ListIterator(const ListIterator & src): _ptr(src._ptr) {};
			~ListIterator(void) {};

			ListIterator &	operator++(void)// pre increment
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			ListIterator	operator++(int)	// post increment
			{
				ListIterator	temp(*this);
				++(*this);
				return (temp);
			}
			ListIterator &	operator--(void)
			{
				if (_ptr && _ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			ListIterator	operator--(int)
			{
				ListIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void) {return _ptr->value;}
			T *	operator->(void) {return &(_ptr->value);}

			ListIterator & operator=(ListIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(ListIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(ListIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		protected:
			PointerType getPtr(void) const {return _ptr;}

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class ListConstIterator: protected ListIterator<T, Node< T > *>
	{
		public:
			typedef const T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef const T*   pointer;
    		typedef const T& reference;
    		typedef std::bidirectional_iterator_tag  iterator_category;

			ListConstIterator(void): _ptr(0) {};
			ListConstIterator(PointerType ptr): _ptr(ptr) {};
			ListConstIterator(const ListConstIterator & src): _ptr(src._ptr) {};
			ListConstIterator(const ListIterator<T, Node<T> *> & src): _ptr(reinterpret_cast<ft::Node<const T> *>(reinterpret_cast< const ListConstIterator &>(src).getPtr())) {};
			~ListConstIterator(void) {};

			ListConstIterator &	operator++(void)// pre increment
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			ListConstIterator	operator++(int)	// post increment
			{
				ListConstIterator	temp(*this);
				++(*this);
				return (temp);
			}
			ListConstIterator &	operator--(void)
			{
				if (_ptr && _ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			ListConstIterator	operator--(int)
			{
				ListConstIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void) {return _ptr->value;}
			value_type *	operator->(void) {return &(_ptr->value);}

			ListConstIterator & operator=(ListConstIterator & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(ListConstIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(ListConstIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		private:
			PointerType _ptr;
	};


template <typename T, typename PointerType>
	class ListReverseIterator
	{
		public:
			typedef T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef T*   pointer;
    		typedef T& reference;
    		typedef std::bidirectional_iterator_tag  iterator_category;

			ListReverseIterator(void): _ptr(0) {};
			ListReverseIterator(PointerType ptr): _ptr(ptr) {};
			ListReverseIterator(const ListReverseIterator & src): _ptr(src._ptr) {};
			~ListReverseIterator(void) {};

			ListReverseIterator &	operator++(void)	// pre increment
			{
				if (_ptr && _ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			ListReverseIterator	operator++(int)	// post increment
			{
				ListReverseIterator	temp(*this);
				++(*this);
				return (temp);
			}
			ListReverseIterator &	operator--(void)
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			ListReverseIterator	operator--(int)
			{
				ListReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void) {return _ptr->value;}
			T *	operator->(void) {return &(_ptr->value);}

			ListReverseIterator & operator=(ListReverseIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(ListReverseIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(ListReverseIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		protected:
			PointerType getPtr(void) const {return _ptr;}

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class ListConstReverseIterator: protected ListReverseIterator<T, Node< T > *>
	{
		public:
			typedef const T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef const T*   pointer;
    		typedef const T& reference;
    		typedef std::bidirectional_iterator_tag  iterator_category;

			ListConstReverseIterator(void): _ptr(0) {};
			ListConstReverseIterator(PointerType ptr): _ptr(ptr) {};
			ListConstReverseIterator(const ListConstReverseIterator & src): _ptr(src._ptr) {};
			ListConstReverseIterator(const ListReverseIterator<T, Node<T> *> & src): _ptr(reinterpret_cast<ft::Node<const T> *>(reinterpret_cast< const ListConstReverseIterator &>(src).getPtr())) {};




			~ListConstReverseIterator(void) {};

			ListConstReverseIterator &	operator++(void)	// pre increment
			{
				if (_ptr && _ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			ListConstReverseIterator	operator++(int)	// post increment
			{
				ListConstReverseIterator	temp(*this);
				++(*this);
				return (temp);
			}
			ListConstReverseIterator &	operator--(void)
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			ListConstReverseIterator	operator--(int)
			{
				ListConstReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void) {return _ptr->value;}
			value_type *	operator->(void) {return &(_ptr->value);}

			ListConstReverseIterator & operator=(ListConstReverseIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(ListConstReverseIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(ListConstReverseIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		private:
			PointerType _ptr;
	};



// **********************************************************************************
// ***********************************   VECTOR   ***********************************
// **********************************************************************************

	template <typename T>
	class VectorIterator;
	template <typename T>
	class VectorConstIterator;
	template <typename T>
	class VectorReverseIterator;
	template <typename T>
	class VectorConstReverseIterator;

	template <typename T>
	class VectorIterator
	{
		public:
			typedef T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef T*   pointer;
    		typedef T& reference;
    		typedef std::random_access_iterator_tag  iterator_category;

			VectorIterator(void): _index(0), _size(0), _array(0) {};
			VectorIterator(T* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorIterator(const VectorIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
			~VectorIterator(void) {};

			VectorIterator &	operator++(void) // pre increment
			{
				if (_index < _size)
					_index++;
				return (*this);
			}
			VectorIterator	operator++(int)	// post increment
			{
				VectorIterator	temp(*this);
				++(*this);
				return (temp);
			}
			VectorIterator &	operator--(void)
			{
				if (_index > 0)
					_index--;
				return (*this);
			}
			VectorIterator	operator--(int)
			{
				VectorIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void) {return _array[_index];}
			value_type *	operator->(void) {return &(_array[_index]);}

			VectorIterator & operator=(VectorIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}


			bool operator==(VectorIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}


			VectorIterator	operator+(difference_type n)
			{
				VectorIterator	res(*this);
				if (_index + n <= _size)
					res._index += n;
				return (res);
			}

			VectorIterator	operator-(difference_type n)
			{
				VectorIterator	res(*this);
				if (_index - n >= 0)
					res._index -= n;
				return (res);
			}

			VectorIterator &	operator+=(difference_type n)
			{
				while (n-- > 0)
					((*this)++);
				return (*this);
			}

			VectorIterator &	operator-=(difference_type n)
			{
				while (n-- > 0)
					((*this)--);
				return (*this);
			}

			difference_type	operator-(VectorIterator & rhs)
			{
				if (_size == rhs._size && _array == rhs._array)
					return (_index - rhs._index);
				return (0);
			}


			bool operator<(VectorIterator const & rhs) const {return (_index < rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>(VectorIterator const & rhs) const {return (_index > rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator<=(VectorIterator const & rhs) const {return (_index <= rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>=(VectorIterator const & rhs) const {return (_index >= rhs._index && _size == rhs._size && _array == rhs._array);}

			T &	operator[](difference_type n) {return *(*this + n);}


			template <typename U>
			friend bool operator==(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator==(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);

			template <typename U>
			friend bool operator<(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator<(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);

		protected:
			size_t		_index;
			size_t		_size;
			value_type*			_array;

			size_t getIndex(void) const {return _index;}
			size_t getSize(void) const {return _size;}
			value_type* getArray(void) const {return _array;}
	};

	

	template <typename T>
	VectorIterator<T> &	operator+(std::ptrdiff_t n, VectorIterator<T> & it) {return it + n;}

template <typename T>
	class VectorConstIterator: protected VectorIterator<T>
	{
		public:
			typedef const T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef const value_type*   pointer;
    		typedef const value_type& reference;
    		typedef std::random_access_iterator_tag  iterator_category;

			VectorConstIterator(void): _index(0), _size(0), _array(0) {};
			VectorConstIterator(value_type* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorConstIterator(const VectorConstIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
			VectorConstIterator(const VectorIterator<T> & src):	_index(reinterpret_cast<const VectorConstIterator &>(src).getIndex()),
																_size(reinterpret_cast<const VectorConstIterator &>(src).getSize()),
																_array(reinterpret_cast<const VectorConstIterator &>(src).getArray()) {};
			~VectorConstIterator(void) {};

			VectorConstIterator &	operator++(void) // pre increment
			{
				if (_index < _size)
					_index++;
				return (*this);
			}
			VectorConstIterator	operator++(int)	// post increment
			{
				VectorConstIterator	temp(*this);
				++(*this);
				return (temp);
			}
			VectorConstIterator &	operator--(void)
			{
				if (_index > 0)
					_index--;
				return (*this);
			}
			VectorConstIterator	operator--(int)
			{
				VectorConstIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void) {return _array[_index];}
			value_type *	operator->(void) {return &(_array[_index]);}

			VectorConstIterator & operator=(VectorConstIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}

			
			bool operator==(VectorConstIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorConstIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}
		

			VectorConstIterator	operator+(difference_type n)
			{
				VectorConstIterator	res(*this);
				if (_index + n <= _size)
					res._index += n;
				return (res);
			}

			VectorConstIterator	operator-(difference_type n)
			{
				VectorConstIterator	res(*this);
				if (_index - n >= 0)
					res._index -= n;
				return (res);
			}

			VectorConstIterator &	operator+=(difference_type n)
			{
				while (n-- > 0)
					((*this)++);
				return (*this);
			}

			VectorConstIterator &	operator-=(difference_type n)
			{
				while (n-- > 0)
					((*this)--);
				return (*this);
			}

			difference_type	operator-(VectorConstIterator & rhs)
			{
				if (_size == rhs._size && _array == rhs._array)
					return (_index - rhs._index);
				return (0);
			}

			bool operator<(VectorConstIterator const & rhs) const {return (_index < rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>(VectorConstIterator const & rhs) const {return (_index > rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator<=(VectorConstIterator const & rhs) const {return (_index <= rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>=(VectorConstIterator const & rhs) const {return (_index >= rhs._index && _size == rhs._size && _array == rhs._array);}

			T &	operator[](difference_type n) {return *(*this + n);}


			template <typename U>
			friend bool operator==(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator==(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);

			template <typename U>
			friend bool operator<(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator<(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs);


		private:
			size_t		_index;
			size_t		_size;
			value_type *			_array;
	};

	template <typename T>
	VectorConstIterator<T> &	operator+(std::ptrdiff_t n, VectorConstIterator<T> & it) {return it + n;}

	template <typename U>
	bool operator==(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return (lhs._index == rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator==(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return (lhs._index == rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator!=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return !(lhs == rhs);}
	template <typename U>
	bool operator!=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return !(lhs == rhs);}

	template <typename U>
	bool operator<(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return (lhs._index < rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator<(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return (lhs._index < rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator>(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return (lhs._index > rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator>(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return (lhs._index > rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator<=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return !(lhs > rhs);}
	template <typename U>
	bool operator<=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return !(lhs > rhs);}
	template <typename U>
	bool operator>=(VectorIterator<U> const & lhs, VectorConstIterator<U> const & rhs) {return !(lhs < rhs);}
	template <typename U>
	bool operator>=(VectorConstIterator<U> const & lhs, VectorIterator<U> const & rhs) {return !(lhs < rhs);}



template <typename T>
	class VectorReverseIterator
	{
		public:
			typedef T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef T*   pointer;
    		typedef T& reference;
    		typedef std::random_access_iterator_tag  iterator_category;

			VectorReverseIterator(void): _index(0), _size(0), _array(0) {};
			VectorReverseIterator(T* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorReverseIterator(const VectorReverseIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
			~VectorReverseIterator(void) {};

			VectorReverseIterator &	operator++(void) // pre increment
			{
				if (_index > -1)
					_index--;
				return (*this);
			}
			VectorReverseIterator	operator++(int)	// post increment
			{
				VectorReverseIterator	temp(*this);
				++(*this);
				return (temp);
			}
			VectorReverseIterator &	operator--(void)
			{
				if (_index < static_cast<int>(_size) - 1)
					_index++;
				return (*this);
			}
			VectorReverseIterator	operator--(int)
			{
				VectorReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void)
			{
				if (_index > 0)
					return _array[_index];
				return _array[0];
			}
			value_type *	operator->(void)
			{
				if (_index > 0)
					return &(_array[_index]);
				return &(_array[0]);
			}


			VectorReverseIterator & operator=(VectorReverseIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}

			bool operator==(VectorReverseIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorReverseIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}


			VectorReverseIterator	operator+(difference_type n)
			{
				VectorReverseIterator	res(*this);
				if (_index - n >= 0)
					res._index -= n;
				return (res);
			}

			VectorReverseIterator	operator-(difference_type n)
			{
				VectorReverseIterator	res(*this);
				if (_index + n <= static_cast<int>(_size))
					res._index += n;
				return (res);
			}

			VectorReverseIterator &	operator+=(difference_type n)
			{
				while (n-- > 0)
					((*this)++);
				return (*this);
			}

			VectorReverseIterator &	operator-=(difference_type n)
			{
				while (n-- > 0)
					((*this)--);
				return (*this);
			}

			difference_type	operator-(VectorReverseIterator & rhs)
			{
				if (_size == rhs._size && _array == rhs._array)
					return (rhs._index - _index);
				return (0);
			}

			int	index_base(void) {return (_index - 1);}

			bool operator<(VectorReverseIterator const & rhs) const {return (_index > rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>(VectorReverseIterator const & rhs) const {return (_index < rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator<=(VectorReverseIterator const & rhs) const {return (_index >= rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>=(VectorReverseIterator const & rhs) const {return (_index <= rhs._index && _size == rhs._size && _array == rhs._array);}

			T &	operator[](difference_type n) {return *(*this + n);}


			template <typename U>
			friend bool operator==(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator==(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);

			template <typename U>
			friend bool operator<(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);


		protected:
			int		_index;
			size_t		_size;
			value_type*			_array;

			int getIndex(void) const {return _index;}
			size_t getSize(void) const {return _size;}
			value_type* getArray(void) const {return _array;}
	};

	template <typename T>
	VectorReverseIterator<T> &	operator+(std::ptrdiff_t n, VectorReverseIterator<T> & it) {return it + n;}

	template <typename T>
	class VectorConstReverseIterator: protected VectorReverseIterator<T>
	{
		public:
			typedef const T         value_type;
    		typedef std::ptrdiff_t  difference_type;
    		typedef value_type *   pointer;
    		typedef value_type & reference;
    		typedef std::random_access_iterator_tag  iterator_category;

			VectorConstReverseIterator(void): _index(0), _size(0), _array(0) {};
			VectorConstReverseIterator(value_type* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorConstReverseIterator(const VectorConstReverseIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
			VectorConstReverseIterator(const VectorReverseIterator<T> & src):	_index(reinterpret_cast<const VectorConstReverseIterator &>(src).getIndex()),
																				_size(reinterpret_cast<const VectorConstReverseIterator &>(src).getSize()),
																				_array(reinterpret_cast<const VectorConstReverseIterator &>(src).getArray()) {};
			~VectorConstReverseIterator(void) {};

			VectorConstReverseIterator &	operator++(void) // pre increment
			{
				if (_index > -1)
					_index--;
				return (*this);
			}
			VectorConstReverseIterator	operator++(int)	// post increment
			{
				VectorConstReverseIterator	temp(*this);
				++(*this);
				return (temp);
			}
			VectorConstReverseIterator &	operator--(void)
			{
				if (_index < static_cast<int>(_size) - 1)
					_index++;
				return (*this);
			}
			VectorConstReverseIterator	operator--(int)
			{
				VectorConstReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			value_type &	operator*(void)
			{
				if (_index > 0)
					return _array[_index];
				return _array[0];
			}
			value_type *	operator->(void)
			{
				if (_index > 0)
					return &(_array[_index]);
				return &(_array[0]);
			}

			VectorConstReverseIterator & operator=(VectorConstReverseIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}

			bool operator==(VectorConstReverseIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorConstReverseIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}


			VectorConstReverseIterator	operator+(difference_type n)
			{
				VectorConstReverseIterator	res(*this);
				if (_index - n >= 0)
					res._index -= n;
				return (res);
			}

			VectorConstReverseIterator	operator-(difference_type n)
			{
				VectorConstReverseIterator	res(*this);
				if (_index + n <= static_cast<int>(_size))
					res._index += n;
				return (res);
			}

			VectorConstReverseIterator &	operator+=(difference_type n)
			{
				while (n-- > 0)
					((*this)++);
				return (*this);
			}

			VectorConstReverseIterator &	operator-=(difference_type n)
			{
				while (n-- > 0)
					((*this)--);
				return (*this);
			}

			difference_type	operator-(VectorConstReverseIterator & rhs)
			{
				if (_size == rhs._size && _array == rhs._array)
					return (rhs._index - _index);
				return (0);
			}

			bool operator<(VectorConstReverseIterator const & rhs) const {return (_index > rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>(VectorConstReverseIterator const & rhs) const {return (_index < rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator<=(VectorConstReverseIterator const & rhs) const {return (_index >= rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator>=(VectorConstReverseIterator const & rhs) const {return (_index <= rhs._index && _size == rhs._size && _array == rhs._array);}

			T &	operator[](difference_type n) {return *(*this + n);}


			template <typename U>
			friend bool operator==(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator==(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator!=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);

			template <typename U>
			friend bool operator<(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator<=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs);
			template <typename U>
			friend bool operator>=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs);

		private:
			int		_index;
			size_t		_size;
			value_type*			_array;
	};

	template <typename U>
	bool operator==(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return (lhs._index == rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator==(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return (lhs._index == rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator!=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return !(lhs == rhs);}
	template <typename U>
	bool operator!=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return !(lhs == rhs);}

	template <typename U>
	bool operator<(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return (lhs._index > rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator<(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return (lhs._index > rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator>(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return (lhs._index < rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator>(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return (lhs._index < rhs._index && lhs._size == rhs._size && lhs._array == rhs._array);}
	template <typename U>
	bool operator<=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return !(lhs > rhs);}
	template <typename U>
	bool operator<=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return !(lhs > rhs);}
	template <typename U>
	bool operator>=(VectorReverseIterator<U> const & lhs, VectorConstReverseIterator<U> const & rhs) {return !(lhs < rhs);}
	template <typename U>
	bool operator>=(VectorConstReverseIterator<U> const & lhs, VectorReverseIterator<U> const & rhs) {return !(lhs < rhs);}

	template <typename T>
	VectorConstReverseIterator<T> &	operator+(std::ptrdiff_t n, VectorConstReverseIterator<T> & it) {return it + n;}


}

#endif