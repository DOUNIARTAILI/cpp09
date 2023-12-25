/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:12:09 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/25 13:28:13 by drtaili          ###   ########.fr       */
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
    void calculatingRpn(std::string rpn);
    void fillVec(std::string rpn);
    void displayVec();
    void displayStack();
    int checker();
private:
    std::stack<int>  mystack;
    std::vector<char>  vec;
};

#endif
