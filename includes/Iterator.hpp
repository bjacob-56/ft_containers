#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "List.hpp"

namespace ft
{

template <typename T, typename PointerType>
	class MyIterator
	{
		public:

			MyIterator(void): _ptr(0) {};
			MyIterator(PointerType ptr): _ptr(ptr) {};
			~MyIterator(void) {};

			MyIterator &	operator++(void)// pre increment
			{
				if (_ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			MyIterator	operator++(int)	// post increment
			{
				MyIterator	temp(*this);
				++(*this);
				return (temp);
			}
			MyIterator &	operator--(void)
			{
				if (_ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			MyIterator	operator--(int)
			{
				MyIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void) {return _ptr->value;}

			MyIterator & operator=(MyIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(MyIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(MyIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class MyConstIterator
	{
		public:

			MyConstIterator(void): _ptr(0) {};
			MyConstIterator(PointerType ptr): _ptr(ptr) {};
			~MyConstIterator(void) {};

			MyConstIterator &	operator++(void)// pre increment
			{
				if (_ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			MyConstIterator	operator++(int)	// post increment
			{
				MyConstIterator	temp(*this);
				++(*this);
				return (temp);
			}
			MyConstIterator &	operator--(void)
			{
				if (_ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			MyConstIterator	operator--(int)
			{
				MyConstIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void) {return _ptr->value;}

			MyConstIterator & operator=(MyConstIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(MyConstIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(MyConstIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		private:
			PointerType _ptr;
	};

template <typename T, typename PointerType>
	class MyReverseIterator
	{
		public:
			MyReverseIterator(void): _ptr(0) {};
			MyReverseIterator(PointerType ptr): _ptr(ptr) {};
			~MyReverseIterator(void) {};

			MyReverseIterator &	operator++(void)	// pre increment
			{
				if (_ptr->previous)
					_ptr = _ptr->previous;
				return (*this);
			}
			MyReverseIterator	operator++(int)	// post increment
			{
				MyReverseIterator	temp(*this);
				++(*this);
				return (temp);	// quel comportement apres end ?
			}
			MyReverseIterator &	operator--(void) // quel comportement avant begin ?
			{
				if (_ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			MyReverseIterator	operator--(int)
			{
				MyReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			T &	operator*(void) {return _ptr->value;}

			MyReverseIterator & operator=(MyReverseIterator const & rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			bool operator==(MyReverseIterator const & rhs) const {return (_ptr == rhs._ptr);}
			bool operator!=(MyReverseIterator const & rhs) const {return (_ptr != rhs._ptr);}
			bool operator==(PointerType const ptr) const {return (_ptr == ptr);}
			bool operator!=(PointerType const ptr) const {return (_ptr != ptr);}

		private:
			PointerType _ptr;
	};

}

#endif