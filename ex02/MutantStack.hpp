/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/18 18:58:24 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack	( void ) {}
		MutantStack	( const MutantStack &other ) : std::stack<T>(other) {}
		MutantStack<T>	&operator=( const MutantStack &other ) {
			if (this != &other) {
				this->c = other.c;
			}
			return *this;
		}
		~MutantStack	( void ) {}

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin( void ) { return this->c.begin(); }
		iterator end( void ) { return this->c.end(); }

		const_iterator begin( void ) const { return this->c.begin(); }
		const_iterator end( void ) const { return this->c.end(); }
} ;

#endif

