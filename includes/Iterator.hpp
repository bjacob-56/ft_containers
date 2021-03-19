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
				if (_ptr->next)
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
				if (_ptr->previous)
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
				if (_ptr->next)
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
				if (_ptr->previous)
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
				if (_ptr->previous)
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
				if (_ptr->next)
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
				if (_ptr->previous)
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
				if (_ptr->next)
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

			VectorIterator(void): _index(0), _vector(0) {};
			VectorIterator(size_t index, Vector<T> vector): _index(index), _vector(vector) {};
			VectorIterator(const VectorIterator & src): _index(src._index), _vector(src.vector) {};
			~VectorIterator(void) {};

			VectorIterator &	operator++(void) // pre increment
			{
				if (_index < _vector.capacity() - 1)
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

			T &	operator*(void) {return _vector[_index];}

			VectorIterator & operator=(VectorIterator const & rhs)
			{
				_index = rhs._index;
				_vector = rhs._vector;
				return (*this);
			}

			bool operator==(VectorIterator const & rhs) const {return (_index == rhs._index && _vector == rhs._vector);}
			bool operator!=(VectorIterator const & rhs) const {return (_index != rhs._index || _vector != rhs._vector);}
			// bool operator==(PointerType const ptr) const {return (_index == ptr);}
			// bool operator!=(PointerType const ptr) const {return (_index != ptr);}

		private:
			size_t		_index;
			Vector<T>	_vector;
	};



}

#endif