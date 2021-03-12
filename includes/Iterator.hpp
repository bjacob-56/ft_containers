#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{

template <typename PointerType>
	class MyIterator
	{
		public:

			MyIterator(void): _ptr(0) {};
			MyIterator(PointerType ptr): _ptr(ptr) {};
			~MyIterator(void) {};

			PointerType getPtr(void) const {return _ptr;}

			MyIterator &	operator++(void)	// pre increment
			{
				_ptr = _ptr->getNext();
				return (*this);
			}
			MyIterator	operator++(int)	// post increment
			{
				MyIterator	temp(*this);
				++(*this);
				return (temp);	// quel comportement apres end ?
			}
			MyIterator &	operator--(void) // quel comportement avant begin ?
			{
				_ptr = _ptr->getPrevious();
				return (*this);
			}
			MyIterator	operator--(int)
			{
				MyIterator	temp(*this);
				--(*this);
				return (temp);
			}

			PointerType	operator*(void) {return _ptr;}

			MyIterator & operator=(MyIterator const & rhs)
			{
				_ptr = rhs.getPtr();
				return (*this);
			}

			bool operator==(MyIterator const & rhs) const {return (_ptr == rhs.getPtr());}
			bool operator!=(MyIterator const & rhs) const {return (_ptr != rhs.getPtr());}

		private:
			PointerType _ptr;
	};

template <typename PointerType>
	class MyReverseIterator
	{
		public:
			MyReverseIterator(void): _ptr(0) {};
			MyReverseIterator(PointerType ptr): _ptr(ptr) {};
			~MyReverseIterator(void) {};

			PointerType getPtr(void) const {return _ptr;}

			MyReverseIterator &	operator++(void)	// pre increment
			{
				_ptr = _ptr->getPrevious();
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
				_ptr = _ptr->getNext();
				return (*this);
			}
			MyReverseIterator	operator--(int)
			{
				MyReverseIterator	temp(*this);
				--(*this);
				return (temp);
			}

			PointerType	operator*(void) {return _ptr;}

			MyReverseIterator & operator=(MyReverseIterator const & rhs)
			{
				_ptr = rhs.getPtr();
				return (*this);
			}

			bool operator==(MyReverseIterator const & rhs) const {return (_ptr == rhs.getPtr());}
			bool operator!=(MyReverseIterator const & rhs) const {return (_ptr != rhs.getPtr());}

		private:
			PointerType _ptr;
	};

}

#endif