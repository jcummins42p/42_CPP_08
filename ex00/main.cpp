/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/16 19:09:59 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

template <typename container_T>
void fill_container( container_T &container, int n) {
	for (int i = 0; i < n; i++) {
		container.push_back(i);
	}
}

template <typename container_T>
void print_container( const container_T &container ) {
	typename container_T::const_iterator it = container.begin();
	int size = container.size();
	for (int i = 0; i + 1 < size; i++) {
		std::cout << *it++ << ", ";
	}
	std::cout << *it << std::endl;
}

template <typename container_T>
void test_generic(container_T &container, int size) {
	try {
		fill_container(container, size);
		print_container(container);
		typename container_T::iterator it = easyfind(container, 10);
		std::cout << "Found " << *it << std::endl;
	}
	catch ( std::invalid_argument &e ) {
		std::cout << e.what();
	}
}

int	main(void) {
	std::list<int> mylist;
	std::vector<int> myvect;
	std::deque<int> mydeque;
	test_generic(mylist, 14);
	test_generic(myvect, 14);
	test_generic(mydeque, 14);
	return (0);
}
