/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/22 14:02:27 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> // for std::max_element and min_element
# include <vector> // container for numbers
# include <limits> // to check number input bounds
# include <cmath> // for abs function

class	Span
{
	public:
		Span	( unsigned int N );
		Span	( const Span &other );
		Span	&operator=( const Span &other );
		~Span	( void );

		void	addNumber( long int num ) ;
		void	addRangeByNumber( long int begin, long int step, unsigned int n ) ;
		void	addRangeByDelimit( int begin, int end, int step) ;
		void	addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end) ;

		unsigned int shortestSpan() const ;
		unsigned int longestSpan() const ;

		void	print( void ) const ;

		std::vector<int>::iterator begin( void );
		std::vector<int>::iterator end( void );
	private:
		std::vector<int>	numbers;
		unsigned int		N;
} ;

#endif
