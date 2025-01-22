/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/22 14:00:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	try {
		//	Declaring span objects
		Span *sp1 = new Span(20);
		Span sp2 = Span(20);
		Span sp3 = Span(20);
		Span sp4 = Span(20);

		std::cout << "Testing span 1:" << std::endl;
		sp1->addRangeByNumber(1, 3, 19);	// Adds first, step, quantity
		//sp1->addRangeByNumber(1, 3, 19);	// Demonstrates exceeding N
		//sp1->addNumber(2147483648); //	Demonstrates bounds-testing
		sp1->addNumber(1);
		sp1->print();
		std::cout << "Span 1 shortest span: " << std::endl;
		std::cout << sp1->shortestSpan() << std::endl;
		std::cout << "Span 1 longest span: " << std::endl;
		std::cout << sp1->longestSpan() << std::endl;

		//	Demonstrating use of iterators to fill sp2 from sp1
		std::cout << "Testing addrange iterators backwards:" << std::endl;
		sp2.addRange(sp1->end() - 10, sp1->begin() + 1);
		sp2.print();

		std::cout << "Testing addrange iterators forwards:" << std::endl;
		sp3.addRange(sp1->begin() + 8, sp1->end() - 1);
		sp3.print();

		std::cout << "Testing cpy assign operator:" << std::endl;
		sp4 = *sp1;
		delete sp1;
		//sp1->print(); //	uncommenting will cause segfault - demonstrates deep copy into sp4
		sp4.print();
	}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
