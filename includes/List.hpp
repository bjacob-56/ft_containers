#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <limits>

# include "Iterator.hpp"

namespace ft
{

template <typename T>
class List
{
public:
	List(void): _previous(0), _next(0), _content(0) {}
	List(int nb, T const & content): List()	// a faire
	{
		if (nb > 0)
		{
			this->initiate_first_elem(content);
			int i = 0;
			List	* save;
			save = this;
			while (++i < nb)
			{
				List * temp = new List(content);
				save->add_next(temp);
				// temp.setNext(save->getNext());
				// save->setNext(&temp);
				// temp.setPrevious(save);
				save = temp;
			}
		}
	}

	List(List const & src)
	{
		*this = src;
		return (*this);
	}

	// std::list<int> first;                                // empty list of ints
  	// std::list<int> second (4,100);                       // four ints with value 100
  	// std::list<int> third (second.begin(),second.end());  // iterating through second
  	// std::list<int> fourth (third); 

	~List(void)
	{
		if (this->size() > 0)
		{
			// il faut tout delete
		}
	}

// ========  Iterators  ========

	// ------  Class  ------

	typedef MyIterator<List *> iterator;
	typedef MyIterator<const List *> const_iterator;

	// List(List::iterator begin, List::iterator end)	// a faire
	// {

	// }

	class reverse_iterator
	{
		public:

			reverse_iterator(void): _ptr(0) {};
			reverse_iterator(List * lst): _ptr(lst) {};
			~reverse_iterator(void);

			List * getPtr(void) {return _ptr;}

			reverse_iterator &	operator++(void)	// pre increment
			{
				this->ptr = this->_ptr->_previous;
				return (*this);
			}
			reverse_iterator	operator++(int)	// post increment
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
			reverse_iterator	operator--(int)
			{
				reverse_iterator	temp = *this
				--(*this);
				return (temp);
			}

			reverse_iterator	operator*(void) {return _ptr;}

		private:
			List * _ptr;
	};

	// ------  Functions  ------
	// template <typename PointerType>
	// List::MyIterator<PointerType>	begin(void)
	// {
	// 	List::MyIterator<PointerType>	it(this);
	// 	return (it);
	// }

	iterator	begin(void)
	{
		iterator	it(this);
		return (it);
	}

	const_iterator	begin(void) const
	{
		const_iterator	it(this);
		return (it);
	}


	iterator	end(void)
	{
		List * lst;

		lst = this;
		while (lst->getNext())
			lst = lst->getNext();
		iterator	it(lst);
		return (it);
	}

	// MyIterator<const List *>	end(void) const
	const_iterator	end(void) const
	{
		const List * lst;

		lst = this;
		while (lst->getNext())
			lst = lst->getNext();
		const_iterator	it(lst);
		return (it);
	}





	List::reverse_iterator	& rbegin(void)
	{
		List * lst;
		List::iterator	it = this->end();

		List::reverse_iterator	rit((*(--it)));
		return (rit);
	}

	List::reverse_iterator	& rend(void)
	{
		List * lst;
		List::iterator	it = this->begin();

		List::reverse_iterator	rit((*(--it))); // elem avant begin a bien definir
		return (rit);
	}

// ========  Getters  ========

	List	* getPrevious(void) const {return _previous;}
	List	* getNext(void) const {return _next;}
	T		getContent(void) const {return _content;}


// ========  Setters  ========

	void	setPrevious(List* pr) {_previous = pr;}
	void	setNext(List* ne) {_next = ne;}
	void	setContent(T co) {_content = co;}


// ========  Overload  ========

	List &	operator=(List const & rhs)
	{
		_previous = rhs.getPrevious();
		_next = rhs.getNext();
		_content = rhs.getContent();
		return (*this);
	}

// ========  Capacity  ========

	bool	empty(void) const
	{
		if (!this->next)
			return (true);
		return (false);
	}

	int	size(void) const
	{
		int count = 0;
		// const_iterator	it = this->begin();	// iterator bien trouvé ?
		const_iterator	it;
		it = this->begin();
		while (it++ != this->end())
			count++;
		return (count);
	}

	int	max_size() const {return std::numeric_limits<int>::max();} // utiliser size_type ici et pour size ?


// ========  Element Access  ========

	List &	front(void)	// besoin de faire la meme en const ?
	{
		if (this->size() > 0)
			return *(this->begin());
		return (*this);
	}					// reference sur list ou content ?

	List &	back(void)
	{
		if (this->size() > 0)
		{
			iterator	ite = this->end();
			return (**(--ite));
		}
		return (*this);
	}


// ========  Modifiers  ========

// void assign (int n, const T & val);							// a faire
// void assign (List::iterator first, List::iterator last);	// a faire

	void push_back (const T & val)
	{
		if (!this->_next)
			this->initiate_first_elem(val);
		else
		{
			List * temp = new List(val);
			this->back().add_next(temp);
		}
	}

private:
	List *	_previous;
	List *	_next;
	T		_content;

	List(const T & val): _previous(0), _next(0), _content(val) {}

	void	initiate_first_elem(const T & val)
	{
		List *before = new List();
		List *after = new List();
		after->setPrevious(this);
		this->setNext(after);
		this->setPrevious(before);
		before->setNext(this);
		this->setContent(val);
	}

	void	add_next(List * lst)
	{
		lst->setNext(this->getNext());
		this->getNext()->setPrevious(lst);
		this->setNext(lst);
		lst->setPrevious(this);
	}

};

}

#endif
