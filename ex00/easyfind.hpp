/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/22 13:05:06 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <stdexcept>

template <typename T>
static std::string toString( const T &input ) {
	std::stringstream ss;

	ss << input;
	return (ss.str());
}

template <typename T>
typename T::iterator easyfind(T &input, int search) {\
	typename T::iterator out = std::find(input.begin(), input.end(), search);

	if (out == input.end())
		throw std::invalid_argument(toString(search) + " not found in container");
	return (out);
}

#endif

