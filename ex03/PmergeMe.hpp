/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:05 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/04 00:18:18 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <algorithm>

class PmergeMe{
public:
    void fill_vec();
    void display_vec();
    std::vector<std::pair<int, int> > groupAndSortPairs();
private:
    std::vector<int> elements;
};