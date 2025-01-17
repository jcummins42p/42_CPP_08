/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/17 19:32:12 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N ) : N(N) {}

Span::Span( const Span& other )
{
	N = other.N;
}

Span &Span::operator=( const Span& other ) {
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span( void ) {}

static unsigned int abs( int num ) {
	return (num < 0 ? -num : num);
}

static void checkIntBounds( long int num ) {
	if (num > INT_MAX || num < INT_MIN)
		throw std::runtime_error("Number out of int bounds");
}

std::vector<int>::iterator Span::begin( void ) {
	return (numbers.begin());
}

std::vector<int>::iterator Span::end( void ) {
	return (numbers.end());
}

void	Span::print( void ) const {
	std::vector<int>::const_iterator it = numbers.begin();
	int size = numbers.size();
	for (int i = 0; i + 1 < size; i++) {
		std::cout << *it++ << ", ";
	}
	std::cout << *it << std::endl;
}

void	Span::addNumber( int num ) {
	if (numbers.size() >= N)
		throw std::runtime_error("Container is already full");
	numbers.push_back(num);
}

void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
	if (begin >= end)
		throw std::runtime_error("Invalid range");
	while (begin != end) {
		numbers.push_back(*begin++);
	}
}

void	Span::addRangeByNumber( long int begin, long int step, unsigned int n ) {
	for (unsigned int i = 0; i < n; i++) {
		checkIntBounds( begin );
		numbers.push_back(begin);
		begin += step;
	}
}

void	Span::addRangeByDelimit( int begin, int end, int step ) {
	if (step == 0)
		throw std::runtime_error("Invalid step");
	if (begin > end && step > 0)
		throw std::runtime_error("Invalid range");
	if (begin < end && step > 0)
		throw std::runtime_error("Invalid range");
	while (begin != end) {
		checkIntBounds( begin );
		numbers.push_back( begin );
		begin += step;
	}
}

int		Span::shortestSpan() const {
	unsigned int span = INT_MAX;

	if (numbers.size() < 2)
		throw (std::runtime_error("Insufficient numbers to calculate span"));
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
		for (std::vector<int>::const_iterator jt = numbers.begin(); jt != numbers.end(); jt++) {
			if (it != jt && abs(*it - *jt) < span)
				span = abs(*it - *jt);
		}
	}
	return span;
}

int		Span::longestSpan() const {
	unsigned int span = 0;

	if (numbers.size() < 2)
		throw (std::runtime_error("Insufficient numbers to calculate span"));
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
		for (std::vector<int>::const_iterator jt = numbers.begin(); jt != numbers.end(); jt++) {
			if (it != jt && abs(*it - *jt) > span)
				span = abs(*it - *jt);
		}
	}
	return span;
}
