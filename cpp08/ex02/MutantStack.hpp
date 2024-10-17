#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>  // std::stack
#include <deque>  // std::deque, used as the default underlying container

#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(const MutantStack<T> &copy);
		MutantStack<T> &operator=(const MutantStack<T> &other);

		// Typedefs for iterator types
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		// Iterator functions
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
