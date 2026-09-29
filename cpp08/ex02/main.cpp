/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:50:53 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/29 17:15:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void	printStack(const T& stack)
{
	typename T::const_iterator it = stack.begin();
	typename T::const_iterator ite = stack.end();
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
		else
			std::cout << '\n';
	}
}

int main()
{
	std::cout << "Test Case: push 5, 17, top then pop, push 3, 5, 737, 0, iterate and print\n\n";
	std::cout << "--- MutantStack<int, std::vector<int> > test" << " --- \n\n";
	{
		MutantStack<int, std::vector<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "stack = ";
		printStack(mstack);
		std::cout << "top = " << mstack.top() << '\n';
		mstack.pop();
		std::cout << "size = " << mstack.size() << '\n';
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
		++it;
		--it;
		printStack(mstack);
		std::stack<int, std::vector<int> > s(mstack);
	}
	std::cout << "\n--- MutantStack<int> test" << " --- \n\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "stack = ";
		printStack(mstack);
		std::cout << "top = " << mstack.top() << '\n';
		mstack.pop();
		std::cout << "size = " << mstack.size() << '\n';
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		++it;
		--it;
		printStack(mstack);
		std::stack<int> s(mstack);
	}
	std::cout << "\n--- std::list test" << " --- \n\n";
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "list = ";
		printStack(lst);
		std::cout << "back = " << lst.back() << '\n';
		lst.pop_back();
		std::cout << "size = " << lst.size() << '\n';
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		++it;
		--it;
		printStack(lst);
		std::list<int> s(lst);
	}
	return (0);
}