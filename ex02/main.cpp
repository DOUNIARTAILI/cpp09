/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:08 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 19:08:55 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int checker(std::string str){
    size_t i = 0;
    while (i < str.length()){
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        i++;
    }
    return 1;
}

void showlist(std::list<int> g)
{
    std::list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';
}

int main(int ac, char **av) {
    if (ac > 1){
        int i = 1;
        std::vector<int> vec;
        std::list<int> lst;
        while (i < ac){
            if (std::atoi(av[i]) < 0 || !checker(av[i])){
                std::cout << "Error" << std::endl;
                return 0;
            }
            vec.push_back(std::atoi(av[i]));
            lst.push_back(std::atoi(av[i]));
            i++;
        }

        // std::cout << "elements : " << std::endl;
        // showlist(lst);
        PmergeMe p(vec);
        // clock_t start_time = clock();
        p.merge_insert_algo();
        // clock_t end_time = clock();
        // double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        // // Print the elapsed time
        // std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;

    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}


