#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "List.hpp"
#include "Vector.hpp"

namespace ft
{

// **********************************************************************************
// ************************************   LIST   ************************************
// **********************************************************************************

template <typename T, typename PointerType>
	class ListIterator
	{
		public:

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

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class ListConstIterator
	{
		public:

			ListConstIterator(void): _ptr(0) {};
			ListConstIterator(PointerType ptr): _ptr(ptr) {};
			ListConstIterator(const ListConstIterator & src): _ptr(src._ptr) {};
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

			T &	operator*(void) {return _ptr->value;}
			T *	operator->(void) {return &(_ptr->value);}

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
				return (temp);	// quel comportement apres end ?
			}
			ListReverseIterator &	operator--(void) // quel comportement avant begin ?
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

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class ListConstReverseIterator
	{
		public:
			ListConstReverseIterator(void): _ptr(0) {};
			ListConstReverseIterator(PointerType ptr): _ptr(ptr) {};
			ListConstReverseIterator(const ListConstReverseIterator & src): _ptr(src._ptr) {};
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
				return (temp);	// quel comportement apres end ?
			}
			ListConstReverseIterator &	operator--(void) // quel comportement avant begin ?
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

			T &	operator*(void) {return _ptr->value;}
			T *	operator->(void) {return &(_ptr->value);}

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
	class VectorIterator
	{
		public:

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

			T &	operator*(void) {return _array[_index];}
			T *	operator->(void) {return &(_array[_index]);}

			VectorIterator & operator=(VectorIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}

			bool operator==(VectorIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}

		private:
			size_t		_index;
			size_t		_size;
			T*			_array;
	};

template <typename T>
	class VectorConstIterator
	{
		public:

			VectorConstIterator(void): _index(0), _size(0), _array(0) {};
			VectorConstIterator(T* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorConstIterator(const VectorConstIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
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

			T &	operator*(void) {return _array[_index];}
			T *	operator->(void) {return &(_array[_index]);}

			VectorConstIterator & operator=(VectorConstIterator const & rhs)
			{
				_index = rhs._index;
				_size = rhs._size;
				_array = rhs._array;
				return (*this);
			}

			bool operator==(VectorConstIterator const & rhs) const {return (_index == rhs._index && _size == rhs._size && _array == rhs._array);}
			bool operator!=(VectorConstIterator const & rhs) const {return (_index != rhs._index || _size != rhs._size || _array != rhs._array);}

		private:
			size_t		_index;
			size_t		_size;
			T*			_array;
	};

template <typename T>
	class VectorReverseIterator
	{
		public:

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
				if (_index < _size - 1)
					_index++;
				return (*this);
			}
			VectorReverseIterator	operator--(int)
			{
				VectorReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void)
			{
				if (_index > 0)
					return _array[_index];
				return _array[0];
			}
			T *	operator->(void)
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

		private:
			int		_index;
			size_t		_size;
			T*			_array;
	};

template <typename T>
	class VectorConstReverseIterator
	{
		public:

			VectorConstReverseIterator(void): _index(0), _size(0), _array(0) {};
			VectorConstReverseIterator(T* array, size_t size, size_t index = 0): _index(index), _size(size), _array(array) {};
			VectorConstReverseIterator(const VectorConstReverseIterator & src): _index(src._index), _size(src._size), _array(src._array) {};
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
				if (_index < _size - 1)
					_index++;
				return (*this);
			}
			VectorConstReverseIterator	operator--(int)
			{
				VectorConstReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void)
			{
				if (_index > 0)
					return _array[_index];
				return _array[0];
			}
			T *	operator->(void)
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

		private:
			int		_index;
			size_t		_size;
			T*			_array;
	};

}

#endif