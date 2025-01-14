/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/14 17:07:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>

template <typename container_T>
typename container_T::iterator easyfind(container_T &input, int search) {
	typename container_T::iterator it = input.begin();
	while (it != input.end()) {
		if (*it == search)
			return it;
		it++;
	}
	std::cout << "Unable to find " << search << " in container provided" << std::endl;
	throw std::invalid_argument("Argument not found in container");
}

#endif
