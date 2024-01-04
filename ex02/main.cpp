/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:08 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/04 22:37:37 by drtaili          ###   ########.fr       */
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



int main(int ac, char **av) {
    if (ac > 1){
        int i = 1;
        std::vector<int> vec;
        while (i < ac){
            if (std::atoi(av[i]) < 0 || !checker(av[i])){
                std::cout << "Error" << std::endl;
                return 0;
            }
            vec.push_back(std::atoi(av[i]));
            i++;
        }
        PmergeMe p(vec);
        p.merge_insert_algo();
    }
    else
        std::cout << "Error" << std::endl;
}


