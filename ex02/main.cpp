/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:08 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/04 00:22:21 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void displaySortedPairs(const std::vector<std::pair<int, int> >& sortedPairs) {
    std::cout << "Sorted Pairs:\n";
    for (std::vector<std::pair<int, int> >::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")";
    }
}

// Function to calculate Jacobsthal numbers
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Function to generate order of insertion based on Jacobsthal numbers
std::vector<int> jacob_numbers(const std::vector<int>& pend) {
    std::vector<int> jacobNumbers;
    for (size_t i = 0; i < pend.size(); ++i) {
        int order = jacobsthal(static_cast<int>(i));
        jacobNumbers.push_back(order);
    }
    return jacobNumbers;
}

std::vector<int> generateInsertionOrder(std::vector<int>& pend, std::vector<int>& jacobNumbers) {
    std::vector<int> combination;
    std::vector<int>::iterator it;
    std::vector<int>::iterator itb;
    it = std::find(jacobNumbers.begin(), jacobNumbers.end(), 3);
    itb = it--;
    if (it != jacobNumbers.end()){
        int size = pend.size();
        for (; itb != jacobNumbers.end(); itb++){
            combination.push_back(*itb);
            for (int i = 2; i < size; i++) {
                if (i < *itb && i > *it){
                    combination.push_back(i);
                }
            }
            it++;
        }
    }
    return combination;
}

int main() {
    PmergeMe p;
    p.fill_vec();
    std::vector<std::pair<int, int> > sortedPairs = p.groupAndSortPairs();
    displaySortedPairs(sortedPairs);
    // Step 2: Determine the larger of the two elements in each pair
    std::vector<int> main_chain;
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        // Assuming the second element of the pair is the larger one, since pairs are sorted
        pend.push_back(sortedPairs[i].first);
        main_chain.push_back(sortedPairs[i].second);
    }
    std::cout << std::endl;
    // Output the main_chain
    std::cout << "main_chain : " << std::endl;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        std::cout << main_chain[i] << " ";
    }
    std::cout << std::endl;
    // Output the pend
    std::cout << "pend : " << std::endl;
    for (size_t i = 0; i < pend.size(); ++i) {
        std::cout << pend[i] << " ";
    }
    std::cout << std::endl;
    // main_chain.insert(main_chain.begin(), pend[0]);
    // pend.erase(pend.begin());
    std::vector<int> jacobNumbers = jacob_numbers(pend);
    // Output jacobNumbers
    std::cout << "jacobNumbers: " << std::endl;
    for (size_t i = 0; i < jacobNumbers.size(); ++i) {
        std::cout << jacobNumbers[i] << " ";
    }
    std::cout << std::endl;
    // Generate the order of insertion based on Jacobsthal numbers
    std::vector<int> insertionOrder = generateInsertionOrder(pend, jacobNumbers);

    // Output the insertion order
    std::cout << "Insertion Order: " << std::endl;
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        std::cout << insertionOrder[i] << " ";
    }
    std::cout << std::endl;
}
