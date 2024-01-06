/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:42:05 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 21:39:48 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <algorithm>
#include <ctime>

// template <typename Container>
class PmergeMe{
public:
    PmergeMe();
    PmergeMe(std::vector<int> vec);
    ~PmergeMe();
    std::vector<std::pair<int, int> > groupAndSortPairs();
    std::list<std::pair<int, int> > groupAndSortPairs_lst();
    void displaySortedPairs(const std::vector<std::pair<int, int> >& sortedPairs);
    void displaySortedPairs_lst(const std::list<std::pair<int, int> >& sortedPairs_lst);
    void insertPendIntoMain(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& insertionOrder);
    void insertPendIntoMain_lst(std::list<int>& mainChain, std::list<int>& pend, std::list<int>& insertionOrder);
    std::vector<std::pair<int, int> > indexing(std::vector<int>& pend, std::vector<int>& insertionOrder);
    std::list<std::pair<int, int> > indexing_lst(std::list<int>& pend, std::list<int>& insertionOrder);
    int findInsertPosition(const std::vector<int>& mainChain, int value);
    int findInsertPosition_lst(const std::list<int>& mainChain, int value);
    std::vector<int> jacob_numbers(int n);
    std::list<int> jacob_numbers_lst(int n);
    int findElementByIndex(std::vector<std::pair<int, int> > indexed, int index);
    int findElementByIndex_lst(std::list<std::pair<int, int> > indexed, int index);
    std::vector<int> generateInsertionOrder(std::vector<int>& pend, std::vector<int>& jacobNumbers);
    std::list<int> generateInsertionOrder_lst(std::list<int>& pend, std::list<int>& jacobNumbers);
    void merge_insert_algo();
    void merge_insert_algo_lst();
private:
    std::vector<int> elements;
    std::list<int> lst;
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