#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <limits>

# include "Iterator.hpp"

namespace ft
{

template <typename T>
class Node
{
	public:
		Node *	previous;
		Node *	next;
		T		value;

		Node(const T & val): previous(0), next(0), value(val) {}
		Node(Node *pr, Node *ne, const T & val): previous(pr), next(ne), value(val) {}
		Node(): previous(0), next(0), value(T()) {}
	
	void	add_next(Node * node)
	{
		node->next = next;
		node->previous = this;
		next->previous = node;
		next = node;
	}

	void	add_previous(Node * node)
	{
		node->next = this;
		node->previous = previous;
		previous->next = node;
		previous = node;
	}
};


template <typename T>
class List
{
public:

	typedef MyIterator<T, Node<T> *> iterator;
	typedef MyIterator<const T, const Node<T> *> const_iterator;
	typedef MyReverseIterator<T, Node<T> *> reverse_iterator;
	typedef MyReverseIterator<const T, const  Node<T> *> const_reverse_iterator;

private:
	Node<T>	*_begin;
	Node<T>	*_end;
	Node<T>	*_rend;
	size_t	_size;

public:
	List(void): _begin(0), _end(0), _rend(0), _size(0) {}
	List(int nb, T const & content): _begin(0), _end(0), _rend(0), _size(0)
	{
		if (nb > 0)
		{
			this->initiate_first_elem(content);
			int i = 0;
			Node<T>	* save = _begin;
			while (++i < nb)
			{
				Node<T> * temp = new Node<T>(	content);
				save->next = temp;
				save = temp;
			}
			save->next = _end;
			_size = nb;
		}
	}

	List(List const & src): _begin(0), _end(0), _rend(0), _size(0) {*this = src;}

	List(List::iterator begin, List::iterator end): _begin(0), _end(0), _rend(0), _size(0)	// secu a mettre ?
	{
		this->initiate_first_elem(*begin);
		if (begin != end)
		{
			begin++;
			Node<T>	* save = _begin;
			while (begin != end)
			{
				Node<T> * temp = new Node<T>(*begin);
				save->next = temp;
				save = temp;
				begin++;
			}
			save->next = _end;
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
		Node<T> * node = _begin;

		iterator	it(node);
		return (it);
	}
	const_iterator	begin(void) const
	{
		const Node<T> * node = _begin;

		const_iterator	it(node);
		return (it);
	}

	iterator	end(void)
	{
		Node<T> * node = _end;

		iterator	it(node);
		return (it);
	}
	const_iterator	end(void) const
	{
		const Node<T> * node = _end;

		const_iterator	it(node);
		return (it);
	}

	reverse_iterator	rbegin(void)
	{
		Node<T> *	node = 0;
		
		if (_size > 0)
			node = _end->previous;
		reverse_iterator	rit(node);
		return (rit);
	}
	const_reverse_iterator	rbegin(void) const
	{
		const Node<T> *	node = 0;
		
		if (_size > 0)
			node = _end->previous;
		const_reverse_iterator	rit(node);
		return (rit);
	}

	reverse_iterator	rend(void)
	{
		Node<T> * node = _rend;

		reverse_iterator	rit(node);
		return (rit);
	}
	const_reverse_iterator	rend(void) const
	{
		const Node<T> * node = _rend;

		const_reverse_iterator	rit(node);
		return (rit);
	}


// ========  Overload  ========

	List &	operator=(List const & rhs)
	{
		this->delete_list();
		if (rhs.size() > 0)
		{
			const_iterator	begin = rhs.begin();
			const_iterator	end = rhs.end();
			this->initiate_first_elem(*begin);
			if (begin != end)
			{
				begin++;
				Node<T>	* save = _begin;
				while (begin != end)
				{
					Node<T> * temp = new Node<T>(*begin);
					save->next = temp;
					save = temp;
					begin++;
				}
				save->next = _end;
			}
		}
		// else	
		// 	_content = rhs.getContent();
		return (*this);
	}

// ========  Capacity  ========

	bool	empty(void) const
	{
		if (!_size)
			return (true);
		return (false);
	}

	size_t	size(void) const {return (_size);}

	size_t	max_size() const {return std::numeric_limits<size_t>::max();} // utiliser size_t ici et pour size ?


// ========  Element Access  ========

	T &	front(void)	// besoin de faire la meme en const ?
	{
		if (this->size() > 0)
			return (_begin->value);	// possible d'appeler en milieu de list ?
		return (T(0));
	}					// reference sur list ou content ?

	T &	back(void)
	{
		if (this->size() > 0)
			return (_end->previous->value);
		return (T(0));
	}


// ========  Modifiers  ========

// void assign (int n, const T & val);							// a faire
// void assign (List::iterator first, List::iterator last);	// a faire

	void	push_back (const T & val)
	{
		if (!_size)
			this->initiate_first_elem(val);
		else
		{
			Node<T> * temp = new Node<T>(	val);
			_end->add_previous(temp);
		}
	}

	void	pop_back(void)
	{
		if (!_size)
			return ;
		else if (_size == 1)
			this->delete_list();
		else
			this->erase(--(this->end()));
	}

	void	push_front (const T & val)
	{
		if (!_size)
			this->initiate_first_elem(val);
		else
		{
			Node<T> * temp = new Node<T>(	val);
			_rend->add_next(temp);
		}
	}

	void	pop_front(void)
	{
		if (!_size)
			return ;
		else if (_size == 1)
			this->delete_list();
		else
			this->erase((this->begin()));
	}

	iterator erase (iterator position)	// range of iterator a gerer
	{
		Node<T>	*	temp = _begin;
		while (iterator(temp) != position && temp != _end)
			temp = temp->next;
		if (iterator(temp) == position && temp != _end)
		{
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			temp = temp->next;
			delete temp->previous;
		}
		return (iterator(temp));
	}





// ************************************************************** //
// ************************************************************** //

private:

	void	initiate_first_elem(const T & val)
	{
		_end = new Node<T>();
		_rend = new Node<T>();
		_begin = new Node<T>(_rend, _end, val);
	}

	void	delete_list(void)
	{
		Node<T>	* node = _begin;

		if (_size > 0)
		{
			while (node != _end)
			{
				node = node->next;
				delete node->previous;
			}
			delete _end;
			delete _rend;
			_size = 0;
		}
	}


};

}

#endif
