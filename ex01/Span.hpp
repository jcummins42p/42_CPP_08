/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/17 19:31:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <limits.h>

class	Span
{
	public:
		Span	( unsigned int N );
		Span	( const Span &other );
		Span	&operator=( const Span &other );
		~Span	( void );

		void	addNumber( int num ) ;
		void	addRangeByNumber( long int begin, long int step, unsigned int n ) ;
		void	addRangeByDelimit( int begin, int end, int step) ;
		void	addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end) ;

		int		shortestSpan() const ;
		int		longestSpan() const ;

		void	print( void ) const ;

		std::vector<int>::iterator begin( void );
		std::vector<int>::iterator end( void );
	private:
		std::vector<int>	numbers;
		unsigned int		N;
} ;

#endif

