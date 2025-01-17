/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/17 19:27:46 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &input, int search) {
	typename T::iterator it = input.begin();
	while (it != input.end()) {
		if (*it == search)
			return it;
		it++;
	}
	throw std::invalid_argument("Argument not found in container");
}

#endif

