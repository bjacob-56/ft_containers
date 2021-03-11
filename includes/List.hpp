#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream> 

// namespace ft
// {

template <typename T>
class List
{
public:
	List(void): _previous(0), _next(0), _content(0) {}
	List(int nb, T content): List()
	{ _content = content; }
	List(List::iterator begin, List::iterator end);
	List(List const & src);

	~List(void) {}

// ========  Iterators  ========

	// ------  Class  ------

	class iterator
	{
		public:

			iterator(void): _ptr(0) {};
			iterator(List * lst): _ptr(lst) {};
			~iterator(void);

			getPtr(void) {return _ptr;}

			iterator &	operator++(void)	// pre increment
			{
				this->ptr = this->_ptr->_next;
				return (*this);
			}
			iterator	operator++(int i)	// post increment
			{
				iterator	temp = *this
				++(*this);
				return (temp);	// quel comportement apres end ?
			}
			iterator &	operator--(void) // quel comportement avant begin ?
			{
				this->ptr = this->_ptr->_previous;
				return (*this);
			}
			iterator	operator--(int i)
			{
				iterator	temp = *this
				--(*this);
				return (temp);
			}

			iterator	operator*(void) {return _ptr;}

		private:
			List * _ptr;
	}

	class reverse_iterator
	{
		public:

			reverse_iterator(void): _ptr(0) {};
			reverse_iterator(List * lst): _ptr(lst) {};
			~reverse_iterator(void);

			getPtr(void) {return _ptr;}

			reverse_iterator &	operator++(void)	// pre increment
			{
				this->ptr = this->_ptr->_previous;
				return (*this);
			}
			reverse_iterator	operator++(int i)	// post increment
			{
				reverse_iterator	temp = *this
				++(*this);
				return (temp);
			}
			reverse_iterator &	operator--(void)
			{
				this->ptr = this->_ptr->_next;
				return (*this);
			}
			reverse_iterator	operator--(int i)
			{
				reverse_iterator	temp = *this
				--(*this);
				return (temp);
			}

			reverse_iterator	operator*(void) {return _ptr;}

		private:
			List * _ptr;
	}

	// ------  Functions  ------

	List::iterator	& begin(void)
	{
		List::iterator	it(this);
		return (it);
	}

	List::iterator	& end(void)
	{
		List * lst;

		lst = this;
		while (lst->getNext())
			lst = lst->getNext();
		List::iterator	it(lst);
		return (it);
	}

	List::reverse_iterator	& rbegin(void)
	{
		List * lst;
		List::iterator	it = this->end();

		List::reverse_iterator	rit((*(--it));
		return (rit);
	}

	List::reverse_iterator	& rend(void)
	{
		List * lst;
		List::iterator	it = this->begin();

		List::reverse_iterator	rit((*(--it)); // elem avant begin a bien definir
		return (rit);
	}

// ========  Getters  ========

	List	* getPrevious(void) {return _previous;}
	List	* getNext(void) {return _next;}
	List	* getContent(void) {return _content;}

	List &	operator=(List const & rhs)
	{
		_previous = rhs.getPrevious();
		_next = rhs.getNext();
		_content = rhs.getContent();
		return (*this);
	}

	// std::list<int> first;                                // empty list of ints
  	// std::list<int> second (4,100);                       // four ints with value 100
  	// std::list<int> third (second.begin(),second.end());  // iterating through second
  	// std::list<int> fourth (third); 

private:
	List *	_previous;
	List *	_next;
	<T>		_content;

};

// }

#endif
