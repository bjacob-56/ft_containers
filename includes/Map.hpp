#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <limits>
# include <exception>
# include <utility>

# include "Iterator.hpp"
# include "Is_integral.hpp"
# include "List.hpp"

namespace ft
{

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           >
class Map: protected List< std::pair<const Key,T>, Alloc>
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;

	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;

	typedef ListIterator<value_type, Node<value_type> *> iterator;
	typedef ListConstIterator<value_type, Node<const value_type> *> const_iterator;
	typedef ListReverseIterator<value_type, Node<value_type> *> reverse_iterator;
	typedef ListConstReverseIterator<value_type,  Node<const value_type> *> const_reverse_iterator;

	typedef std::ptrdiff_t difference_type;
	typedef	size_t size_type;

	typedef List< std::pair<const Key,T>, Alloc> Lst;


	class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			public:
				value_compare(key_compare comp) : _comp(comp) {}
				bool operator()(const value_type &lhs, const value_type &rhs) const { return _comp(lhs.first, rhs.first); }	

			private:
				key_compare _comp;
		};

private:
	key_compare	_comp;

public:
	explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
		Lst(alloc) {_comp = comp;}

	template <class InputIterator>
	Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
		Lst(first, last, alloc)
		{
			_comp = comp;
			this->sort();
		}

	Map(const Map& x): Lst(x)
		{_comp = x._comp;}

	~Map(void) {this->clear();}

// ========  Iterators  ========

	iterator	begin(void) {return this->Lst::begin();}
	const_iterator	begin(void) const {return this->Lst::begin();}

	iterator	end(void) {return this->Lst::end();}
	const_iterator	end(void) const {return this->Lst::end();}

	reverse_iterator	rbegin(void) {return this->Lst::rbegin();}
	const_reverse_iterator	rbegin(void) const {return this->Lst::rbegin();}

	reverse_iterator	rend(void) {return this->Lst::rend();}
	const_reverse_iterator	rend(void) const {return this->Lst::rend();}

// ========  Overload  ========

	Map &	operator=(const Map & x)
	{
		this->Lst::operator=(x);
		_comp = x._comp;
		return (*this);
	}

// ========  Capacity  ========

	bool	empty(void) const {return this->Lst::empty();}

	size_type	size(void) const {return this->Lst::size();}

	size_type	max_size() const {return std::numeric_limits<size_type>::max() / (sizeof(Node<std::pair<const Key,T> >) + 2 * sizeof(void*));}


// ========  Element Access  ========

	mapped_type& operator[] (const key_type& k)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if ((*it).first == k)
				return (*it).second;
			it++;
		}
		return (*it).second;
	}



// ========  Modifiers  ========

//		----  Insert  ----

	std::pair<iterator,bool> insert (const value_type& val)
	{
		
		if (!this->_size)
			this->initiate_first_elem(val);
		
		iterator it = this->find(val.first);
		if (it != this->end())
			return std::pair<iterator,bool>(it, false);
		
		it = this->lower_bound(val.first);
		it = this->Lst::insert(it, val);
		return (std::pair<iterator,bool>(it, true));
	}

	iterator insert (iterator position, const value_type& val)
	{return insert_prototype(position, val, int());}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{insert_prototype(first, last, typename ft::is_integral<InputIterator>::type());}

//		----  Erase  ----

	void erase (iterator position) {this->Lst::erase(position);}

	size_type erase (const key_type& k)
	{
		iterator it = this->find(k);
		if (it == this->end())
			return 0;
		this->erase(it);
		return 1;
	}

	void erase (iterator first, iterator last) {this->Lst::erase(first, last);}

//		----  Swap  ----

	void swap (Map& x) {this->Lst::swap(x);}

//		----  Clear  ----

	void clear() {this->Lst::clear();}


// ========  Observers  ========

//		----  Key_comp  ----

key_compare key_comp() const {return _comp;}

//		----  Value_comp  ----

value_compare value_comp() const {return value_compare(_comp);}


// ========  Operations  ========

//		----  Find  ----

	iterator find (const key_type& k)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if (!_comp((*it).first, k) && !_comp(k, (*it).first))
				return it;
			it++;
		}
		return it;
	}
	
	const_iterator find (const key_type& k) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if (!_comp((*it).first, k) && !_comp(k, (*it).first))
				return it;
			it++;
		}
		return it;
	}

//		----  Count  ----

	size_type count (const key_type& k) const {return (this->find(k) != this->end());}

//		----  Lower_bound  ----

	iterator lower_bound (const key_type& k)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if (!_comp((*it).first, k))
				return it;
			it++;
		}
		return it;
	}

	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if (!_comp((*it).first, k))
				return it;
			it++;
		}
		return it;
	}



//		----  Upper_bound  ----

	iterator upper_bound (const key_type& k)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return it;
			it++;
		}
		return it;
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return it;
			it++;
		}
		return it;
	}

//		----  Equal_range  ----

	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite && !_comp(k, (*it).first))
		{
			if (!_comp((*it).first, k) && !_comp(k, (*it).first))
			{
				const_iterator	itr = it++;
				return std::pair<const_iterator,const_iterator>(itr, it);
			}
			it++;
		}
		return std::pair<const_iterator,const_iterator>(it, it);
	}
	
	std::pair<iterator,iterator>	equal_range (const key_type& k)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite && !_comp(k, (*it).first))
		{
			if (!_comp((*it).first, k) && !_comp(k, (*it).first))
			{
				ite = it++;
				return std::pair<iterator,iterator>(ite, it);
			}
			it++;
		}
		return std::pair<iterator,iterator>(it, it);
	}


// ************************************************************** //
// ************************************************************** //


private:

	void sort (void)
	{
		if (this->_size < 2)
			return ;
		Node<value_type> * temp;
		Node<value_type> * temp_bis;
		Node<value_type> * begin = this->_begin;

		while (begin != this->_end->previous)
		{
			temp = begin->next;
			temp_bis = begin;
			while (temp != this->_end)
			{
				if (_comp(temp->value.first, temp_bis->value.first) == true &&
				(temp_bis == begin || _comp(temp_bis->value.first, temp->value.first) == false))
					temp_bis = temp;
				temp = temp->next;
			}
			if (temp_bis != begin)
			{					
				if (begin == this->_begin)
					this->_begin = temp_bis;
				if (temp_bis == this->_end->previous)
					this->_end->previous = temp_bis->previous;
				begin->move_to_previous(temp_bis);
				if (_comp(temp_bis->value.first, begin->value.first) == true &&
					_comp(begin->value.first, temp_bis->value.first) == true)
					begin = begin->next;
			}
			else
				begin = begin->next;
		}	
	}



	//		----  Insert  ----

	template <class InputIterator, class InputIterator2>
	iterator insert_prototype (InputIterator first, InputIterator2 last, int)
	{
		(void) first;
		if (!this->_size)
			this->initiate_first_elem(last);
		
		iterator it = this->find(last.first);
		if (it != this->end())
			return it;
		
		it = this->lower_bound(last.first);
		it = this->Lst::insert(it, last);
		return it;
	}

	template <class InputIterator, class InputIterator2>
	void insert_prototype (InputIterator first, InputIterator2 last, void *)
	{
		while (first != last)
			this->insert(*first++);
	}


	// ========  Comparison  ========
public:	
	bool operator==(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator==(rhs);}

	bool operator!=(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator!=(rhs);}

	bool operator>(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator>(rhs);}

	bool operator<(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator<(rhs);}

	bool operator>=(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator>=(rhs);}

	bool operator<=(const Map& rhs)
	{return this->List< std::pair<const Key,T>, Alloc>::operator<=(rhs);}

};


// // ========  Comparison  ========

template < class Key, class T, class Compare, class Alloc>
bool operator==(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs == rhs);}

template < class Key, class T, class Compare, class Alloc>
bool operator!=(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs != rhs);}

template < class Key, class T, class Compare, class Alloc>
bool operator>(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs > rhs);}

template < class Key, class T, class Compare, class Alloc>
bool operator<(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs < rhs);}

template < class Key, class T, class Compare, class Alloc>
bool operator>=(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs >= rhs);}

template < class Key, class T, class Compare, class Alloc>
bool operator<=(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
{return (lhs <= rhs);}

template < class Key, class T, class Compare, class Alloc>
void swap (Map<Key, T, Compare, Alloc>& x, Map<Key, T, Compare, Alloc>& y) {x.swap(y);}


}

#endif
