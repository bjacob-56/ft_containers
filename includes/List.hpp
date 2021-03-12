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

	typedef MyIterator<List *> iterator;
	typedef MyIterator<const List *> const_iterator;
	typedef MyReverseIterator<List *> reverse_iterator;
	typedef MyReverseIterator<const List *> const_reverse_iterator;

	List(void): _previous(0), _next(0), _content(0) {}
	List(int nb, T const & content): _previous(0), _next(0), _content(0)
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
				save = temp;
			}
		}
	}

	List(List const & src): _previous(0), _next(0), _content(0) {*this = src;}

	List(List::iterator begin, List::iterator end): _previous(0), _next(0), _content(0)	// secu a mettre ?
	{
		this->initiate_first_elem((*begin)->getContent());
		if (begin != end)
		{
			begin++;
			List	* save;
			save = this;
			while (begin != end)
			{
				List * temp = new List((*begin)->getContent());
				save->add_next(temp);
				save = temp;
				begin++;
			}
		}
	}

	// std::list<int> first;                                // empty list of ints
  	// std::list<int> second (4,100);                       // four ints with value 100
  	// std::list<int> third (second.begin(),second.end());  // iterating through second
  	// std::list<int> fourth (third);

	~List(void) {this->delete_list();}

// ========  Iterators  ========

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
	const_iterator	end(void) const
	{
		const List * lst;

		lst = this;
		while (lst->getNext())
			lst = lst->getNext();
		const_iterator	it(lst);
		return (it);
	}

	reverse_iterator	rbegin(void)
	{
		iterator	it = this->end();
		reverse_iterator	rit((*(--it)));
		return (rit);
	}
	const_reverse_iterator	rbegin(void) const
	{
		const_iterator	it = this->end();
		const_reverse_iterator	rit((*(--it)));
		return (rit);
	}

	reverse_iterator	rend(void)
	{
		iterator	it = this->begin();
		reverse_iterator	rit((*(--it)));
		return (rit);
	}
	const_reverse_iterator	rend(void) const
	{
		const_iterator	it = this->begin();
		const_reverse_iterator	rit((*(--it)));
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
		this->delete_list();
		if (rhs.size() > 0)
		{
			const_iterator	begin = rhs.begin();
			const_iterator	end = rhs.end();
			this->initiate_first_elem((*begin)->getContent());
			if (begin != end)
			{
				begin++;
				List	* save;
				save = this;
				while (begin != end)
				{
					List * temp = new List((*begin)->getContent());
					save->add_next(temp);
					save = temp;
					begin++;
				}
			}
		}
		else	
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
		const_iterator	it = this->begin();
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

	void	delete_list(void)
	{
		if (_previous)
		{
			_previous->setNext(0);
			delete _previous;
		}
		if (_next)
		{
			_next->setPrevious(0);
			delete _next;
		}
	}

};

}

#endif
