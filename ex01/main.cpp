/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:04:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/25 10:15:36 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    if (ac == 2){
        std::string s = av[1];
        RPN rpn(s);
    }
    else
        std::cout << "Enter an inverted Polish mathematical expression"<< std::endl;
}