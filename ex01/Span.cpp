/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/22 14:01:23 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N ) : N(N) {}

Span::Span( const Span& other )
{
	*this = other;
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

static void checkIntBounds( long int num ) {
	if (num > std::numeric_limits<int>::max()
		|| num < std::numeric_limits<int>::min())
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

void	Span::addNumber( long int num ) {
	if (numbers.size() >= N)
		throw std::runtime_error("Container is already full");
	checkIntBounds(num);
	numbers.push_back(static_cast<int>(num));
}

void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
	if (begin == end)
		throw std::invalid_argument("Invalid range");
	while (begin > end)
		addNumber(*--begin);
	while (begin != end)
		addNumber(*begin++);
}

void	Span::addRangeByNumber( long int begin, long int step, unsigned int n ) {
	for (unsigned int i = 0; i < n; i++) {
		checkIntBounds( begin );
		addNumber(begin);
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
		addNumber( begin );
		begin += step;
	}
}

unsigned int Span::shortestSpan() const {
	unsigned int span = std::numeric_limits<unsigned int>::max();

	if (numbers.size() < 2)
		throw (std::runtime_error("Insufficient numbers to calculate span"));
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
		for (std::vector<int>::const_iterator jt = numbers.begin(); jt != numbers.end(); jt++) {
			if (it != jt && static_cast<unsigned int>(abs(*it - *jt)) < span)
				span = abs(*it - *jt);
		}
	}
	return (span);
}

unsigned int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw (std::runtime_error("Insufficient numbers to calculate span"));
	std::vector<int>::const_iterator min = std::min(numbers.begin(), numbers.end());
	std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());
	return (max - min);
}
