/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:35 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 19:55:02 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    
}
PmergeMe::~PmergeMe(){
    
}
PmergeMe::PmergeMe(std::vector<int> vec): odd(-1){
    
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        this->elements.push_back(*it);
        this->lst.push_back(*it);
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
        }
    }
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}

std::list<std::pair<int, int> > PmergeMe::groupAndSortPairs_lst() {
    std::list<std::pair<int, int> > pairs;

    std::list<int>::iterator it = lst.begin();

    while (it != lst.end()) {
        // Check if there are at least two lst remaining
        if (++it != lst.end()) {
            int first = *(--it);
            ++it;
            int second = *it;
            ++it;

            // Make a pair such that the first element is less than the second
            if (first > second) {
                pairs.push_back(std::make_pair(first, second));
            } else {
                pairs.push_back(std::make_pair(second, first));
            }
        } 
        else {
            std::list<int>::iterator ity = lst.end();
            ity--;
            odd = *ity;
        }
    }
    pairs.sort();
    return pairs;
}

void PmergeMe::displaySortedPairs(const std::vector<std::pair<int, int> >& sortedPairs) {
    std::cout << "Sorted Pairs:\n";
    for (std::vector<std::pair<int, int> >::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")";
    }
}

void PmergeMe::displaySortedPairs_lst(const std::list<std::pair<int, int> >& sortedPairs_lst){
    std::cout << "Sorted Pairs:\n";
    for (std::list<std::pair<int, int> >::const_iterator it = sortedPairs_lst.begin(); it != sortedPairs_lst.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")";
    }
}

std::vector<int> PmergeMe::jacob_numbers(int n){
    std::vector<int> dp(n);

    // base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + 2 * dp[i - 2];

    return dp;
}

std::list<int> PmergeMe::jacob_numbers_lst(int n) {
    std::list<int> dp;

    // base case
    dp.push_back(0);
    dp.push_back(1);

    for (int i = 2; i < n; i++) {
        int value = dp.back() + 2 * *std::prev(dp.end(), 2);
        dp.push_back(value);
    }

    return dp;
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
    std::vector<int>::iterator it = pend.begin();
    int i = 0;
    indexed.push_back(std::make_pair(pend[0], 1));
    it++;
    for (; it != pend.end(); it++) {
        indexed.push_back(std::make_pair(*it, insertionOrder[i]));
        i++;
    }
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
    displaySortedPairs(indexed);
    std::cout << "\n";

    mainChain.insert(mainChain.begin(), findElementByIndex(indexed, 1));
    for (size_t i = 0; i < insertionOrder.size() - 1; i++){
        int element = findElementByIndex(indexed, insertionOrder[i]);
        std::cout << "insertionOrder[i] : " << insertionOrder[i] << std::endl;
        std::cout << "element : " << element << std::endl;
        int position = findInsertPosition(mainChain, element);
        mainChain.insert(mainChain.begin() + position, element);
    }
    if (odd != -1){
        int position = findInsertPosition(mainChain, odd);
        mainChain.insert(mainChain.begin() + position, odd);
    }
}

// void PmergeMe::merge_insert_algo(){
//     std::vector<std::pair<int, int> > sortedPairs = groupAndSortPairs();
//     displaySortedPairs(sortedPairs);
//     std::cout << "\n";
//     std::vector<int> main_chain;
//     std::vector<int> pend;
//     for (size_t i = 0; i < sortedPairs.size(); ++i) {
//         main_chain.push_back(sortedPairs[i].first);
//         pend.push_back(sortedPairs[i].second);
//     }
//     std::cout << "main_chain : " << std::endl;
//     for (size_t i = 0; i < main_chain.size(); ++i) {
//         std::cout << main_chain[i] << " ";
//     }
//     std::cout << "\n";
//     std::cout << "pend : " << std::endl;
//     for (size_t i = 0; i < pend.size(); ++i) {
//         std::cout << pend[i] << " ";
//     }
//     std::cout << "\n";
//     std::vector<int> jacobNumbers = jacob_numbers(pend.size()-1);
//     std::cout << "jacobNumbers : " << std::endl;
//     for (size_t i = 0; i < jacobNumbers.size(); ++i) {
//         std::cout << jacobNumbers[i] << " ";
//     }
//     std::cout << "\n";
//     std::vector<int> insertionOrder = generateInsertionOrder(pend, jacobNumbers);
//     std::cout << "insertionOrder : " << std::endl;
//     for (size_t i = 0; i < insertionOrder.size(); ++i) {
//         std::cout << insertionOrder[i] << " ";
//     }
//     std::cout << "\n";
//     insertPendIntoMain(main_chain, pend, insertionOrder);
//     std::cout << "result : " << std::endl;
//     for (size_t i = 0; i < main_chain.size(); ++i) {
//         std::cout << main_chain[i] << " ";
//     }
// }

void PmergeMe::merge_insert_algo(){
    std::vector<std::pair<int, int> > sortedPairs = groupAndSortPairs();
    std::list<std::pair<int, int> > sortedPairs_lst = groupAndSortPairs_lst();
    displaySortedPairs(sortedPairs);
    std::cout << "\n";
    displaySortedPairs_lst(sortedPairs_lst);
    std::cout << "\n";
    std::vector<int> main_chain;
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        main_chain.push_back(sortedPairs[i].first);
        pend.push_back(sortedPairs[i].second);
    }
    std::list<std::pair<int, int> >::iterator it = sortedPairs_lst.begin();
    std::list<int> main_chainl;
    std::list<int> pendl;
    for (; it != sortedPairs_lst.end(); it++) {
        main_chainl.push_back(it->first);
        pendl.push_back(it->second);
    }
    std::cout << "main_chain : " << std::endl;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        std::cout << main_chain[i] << " ";
    }
    std::cout << "\n";
    std::list<int>::iterator itl = main_chainl.begin();
    std::cout << "main_chainl : " << std::endl;
    for (; itl != main_chainl.end(); itl++) {
        std::cout << *itl << " ";
    }
    std::cout << "\n";
    std::cout << "pend : " << std::endl;
    for (size_t i = 0; i < pend.size(); ++i) {
        std::cout << pend[i] << " ";
    }
    std::cout << "\n";
    std::list<int>::iterator itp = pendl.begin();
    std::cout << "pendl : " << std::endl;
    for (; itp != pendl.end(); itp++) {
        std::cout << *itp << " ";
    }
    std::cout << "\n";
    std::vector<int> jacobNumbers = jacob_numbers(pend.size());
    std::cout << "jacobNumbers : " << std::endl;
    for (size_t i = 0; i < jacobNumbers.size(); ++i) {
        std::cout << jacobNumbers[i] << " ";
    }
    std::cout << "\n";
    std::list<int> jacobNumbers_lst = jacob_numbers_lst(pendl.size());
    std::list<int>::iterator itj;
    std::cout << "jacobNumbers_lst size : "<< jacobNumbers_lst.size() << std::endl;
    std::cout << "jacobNumbers_lst : " << std::endl;
    for (itj = jacobNumbers_lst.begin() ; itj != jacobNumbers_lst.end(); itj++) {
        std::cout << *itj << " ";
    }
    std::cout << "\n";
    // std::vector<int> insertionOrder = generateInsertionOrder(pend, jacobNumbers);
    // std::cout << "insertionOrder : " << std::endl;
    // for (size_t i = 0; i < insertionOrder.size(); ++i) {
    //     std::cout << insertionOrder[i] << " ";
    // }
    // std::cout << "\n";
    // insertPendIntoMain(main_chain, pend, insertionOrder);
    // std::cout << "result : " << std::endl;
    // for (size_t i = 0; i < main_chain.size(); ++i) {
    //     std::cout << main_chain[i] << " ";
    // }
}

// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

// 42 17 89 23 56 34 98 11 72 5 67 8 91 20 53 77 3 45 29 63
// 0 3 8 11 17 20 23 29 34 42 45 53 56 63 67 72 77 89 91 98    5


