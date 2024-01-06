/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:05 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 00:47:45 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <algorithm>

// template <typename Container>
class PmergeMe{
public:
    PmergeMe();
    PmergeMe(std::vector<int> vec);
    ~PmergeMe();
    std::vector<std::pair<int, int> > groupAndSortPairs();
    void displaySortedPairs(const std::vector<std::pair<int, int> >& sortedPairs);
    void insertPendIntoMain(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& insertionOrder);
    std::vector<std::pair<int, int> > indexing(std::vector<int>& pend, std::vector<int>& insertionOrder);
    int findInsertPosition(const std::vector<int>& mainChain, int value);
    int jacobsthal(int n);
    // std::vector<int> jacob_numbers(const std::vector<int>& pend);
    std::vector<int> jacob_numbers(int n);
    int findElementByIndex(std::vector<std::pair<int, int> > indexed, int index);
    std::vector<int> generateInsertionOrder(std::vector<int>& pend, std::vector<int>& jacobNumbers);
    void merge_insert_algo();
private:
    std::vector<int> elements;
    int odd;
};

// template <typename Container>
// class PmergeMe {
// public:
//     PmergeMe();
//     PmergeMe(const Container& vec); // Accept a Container type in the constructor
//     ~PmergeMe();
//     std::vector<std::pair<int, int>> groupAndSortPairs();
//     void displaySortedPairs(const std::vector<std::pair<int, int>>& sortedPairs);
//     void insertPendIntoMain(Container& mainChain, Container& pend, Container& insertionOrder);
//     std::vector<std::pair<int, int>> indexing(Container& pend, Container& insertionOrder);
//     int findInsertPosition(const Container& mainChain, int value);
//     int jacobsthal(int n);
//     Container jacob_numbers(const Container& pend);
//     int findElementByIndex(const std::vector<std::pair<int, int>>& indexed, int index);
//     Container generateInsertionOrder(Container& pend, const Container& jacobNumbers);
//     void merge_insert_algo();

// private:
//     Container elements;
//     int odd;
// };