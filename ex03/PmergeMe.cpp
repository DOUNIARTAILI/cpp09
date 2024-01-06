/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:35 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/04 22:44:20 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Function to group elements into pairs and sort them
std::vector<std::pair<int, int> > PmergeMe::groupAndSortPairs() {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < elements.size(); i += 2) {
        if (i + 1 < elements.size()) {
            // If there are two elements, make a pair such that first is less than second
            if (elements[i] > elements[i + 1]) {
                pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
            } else {
                pairs.push_back(std::make_pair(elements[i + 1], elements[i]));
            }
        } else {
            // If there is an odd element, make a pair with itself
            pairs.push_back(std::make_pair(elements[i], elements[i]));
        }
    }
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}


void PmergeMe::fill_vec(){
    elements.push_back(7);
    elements.push_back(8);
    elements.push_back(27);
    // elements.push_back(100);
    // elements.push_back(11);
    // elements.push_back(46);
    // elements.push_back(2);
    // elements.push_back(53);
    // elements.push_back(0);
}

void PmergeMe::display_vec(){
    std::vector<int>::iterator it = elements.begin();
    for (; it != elements.end(); it++){
        std::cout << *it;
    }
    std::cout << std::endl;
}

// template <typename Container>
// class PmergeMe{
// public:
//     void fill_vec();
//     void display_vec();
//     std::vector<std::pair<int, int> > groupAndSortPairs();
// private:
//     Container elements;
//     std::vector<int> elements;
// };
