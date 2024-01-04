/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:35 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/04 22:36:56 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    
}
PmergeMe::~PmergeMe(){
    
}
PmergeMe::PmergeMe(std::vector<int> vec){
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        this->elements.push_back(*it);
    }
}
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
            odd = elements[i];
            // pairs.push_back(std::make_pair(elements[i], elements[i]));
        }
    }
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}

void PmergeMe::displaySortedPairs(const std::vector<std::pair<int, int> >& sortedPairs) {
    std::cout << "Sorted Pairs:\n";
    for (std::vector<std::pair<int, int> >::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")";
    }
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> PmergeMe::jacob_numbers(const std::vector<int>& pend) {
    std::vector<int> jacobNumbers;
    for (size_t i = 0; i < pend.size(); ++i) {
        int order = jacobsthal(static_cast<int>(i));
        jacobNumbers.push_back(order);
    }
    return jacobNumbers;
}

std::vector<int> PmergeMe::generateInsertionOrder(std::vector<int>& pend, std::vector<int>& jacobNumbers) {
    std::vector<int> combination;
    std::vector<int>::iterator it;
    std::vector<int>::iterator itb;
    it = std::find(jacobNumbers.begin(), jacobNumbers.end(), 3);
    itb = it--;
    if (it != jacobNumbers.end()){
        for (; itb != jacobNumbers.end(); itb++){
            combination.push_back(*itb);
            for (int i = *itb - 1; i > *it; i--) {
                combination.push_back(i);
                if (combination.size() == pend.size()) {
                    return combination;
                }
            }
            it++;
        }
    }
    return combination;
}

int PmergeMe::findInsertPosition(const std::vector<int>& mainChain, int value) {
    int low = 0;
    int high = mainChain.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mainChain[mid] == value) {
            return mid;
        } else if (mainChain[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

std::vector<std::pair<int, int> > PmergeMe::indexing(std::vector<int>& pend, std::vector<int>& insertionOrder) {
    std::vector<std::pair<int, int> > indexed;
    std::vector<int>::iterator it = insertionOrder.begin();
    int i = 1;
    indexed.push_back(std::make_pair(pend[0], 1));
    for (; it != insertionOrder.end(); it++) {
        indexed.push_back(std::make_pair(pend[i], *it));
        i++;
    }
    indexed.push_back(std::make_pair(pend[i], pend.size()));
    return indexed;
}

int PmergeMe::findElementByIndex(std::vector<std::pair<int, int> > indexed, int index){
    for (size_t i = 0; i < indexed.size(); ++i) {
        if (indexed[i].second == index) {
            return indexed[i].first;
        }
    }
    return 0;
}

void PmergeMe::insertPendIntoMain(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& insertionOrder) {
    std::vector<std::pair<int, int> > indexed = indexing(pend, insertionOrder);
    size_t i = 1;
    int element;
    mainChain.insert(mainChain.begin(), findElementByIndex(indexed, 1));
    for (i = 2; i <= pend.size(); i++){
        element = findElementByIndex(indexed, i);
        int position = findInsertPosition(mainChain, element);
        mainChain.insert(mainChain.begin() + position, element);
    }
    int position = findInsertPosition(mainChain, odd);
    mainChain.insert(mainChain.begin() + position, odd);
}

void PmergeMe::merge_insert_algo(){
    std::vector<std::pair<int, int> > sortedPairs = groupAndSortPairs();
    std::vector<int> main_chain;
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        main_chain.push_back(sortedPairs[i].first);
        pend.push_back(sortedPairs[i].second);
    }
    std::vector<int> jacobNumbers = jacob_numbers(pend);
    std::vector<int> insertionOrder = generateInsertionOrder(pend, jacobNumbers);
    insertPendIntoMain(main_chain, pend, insertionOrder);
    std::cout << "result : " << std::endl;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        std::cout << main_chain[i] << " ";
    }
}

// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
