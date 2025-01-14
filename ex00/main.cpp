/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2025/01/14 17:07:22 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main(void) {
	std::vector<int> test;
	for (int i = 0; i < 7; i++)
		test.push_back(i);
	std::cout << "Searching in vector ";
	for (int i = 0; i < 7; i++)
		std::cout << test[i];
	std::cout << std::endl;
	std::vector<int>::iterator it = easyfind(test, 9);
	std::cout << "Found " << *it << std::endl;
	return (0);
}
