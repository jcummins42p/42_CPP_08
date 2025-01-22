/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/18 17:29:22 by jcummins         ###   ########.fr       */
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
		sp1->addRangeByNumber(1, 3, 20);
		sp1->print();
		std::cout << "Span 1 shortest span: " << std::endl;
		std::cout << sp1->shortestSpan() << std::endl;
		std::cout << "Span 1 longest span: " << std::endl;
		std::cout << sp1->longestSpan() << std::endl;

		//	Demonstrating use of iterators to fill sp2 from sp1
		std::cout << "Testing addrange iterators backwards:" << std::endl;
		sp2.addRange(sp1->end() - 3, sp1->begin() + 3);
		sp2.print();

		std::cout << "Testing addrange iterators forwards:" << std::endl;
		sp3.addRange(sp1->begin() + 3, sp1->end() - 3);
		sp3.print();

		std::cout << "Testing cpy assign operator:" << std::endl;
		sp4 = *sp1;
		delete sp1;
		//sp1->print(); //	uncommenting will cause segfault
		sp4.print();
	}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
