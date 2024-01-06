/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:12:09 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 17:55:51 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <vector>

class RPN{
public:
    RPN();
    RPN(std::string rpn);
    ~RPN();
    RPN(const RPN& other);
    const RPN& operator=(const RPN& other);
    std::string New_Rpn(std::string rpn);
    int checker(std::string rpn);
    void calculatingRpn(std::string rpn);
private:
    std::stack<int>  mystack;
};

#endif
