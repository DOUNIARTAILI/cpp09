/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:16:18 by drtaili           #+#    #+#             */
/*   Updated: 2024/01/06 18:04:38 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    
}
RPN::RPN(std::string rpn){
    std::string newRpn = New_Rpn(rpn);
    if (checker(newRpn) == 1)
        calculatingRpn(newRpn);
    else{
        std::cout << "Error" << std::endl;
    }
}
RPN::~RPN(){
    
}
RPN::RPN(const RPN& other){
    mystack = other.mystack;
}
const RPN& RPN::operator=(const RPN& other){
    if (this != &other) {
        mystack = other.mystack;
    }
    return *this;
}


std::string RPN::New_Rpn(std::string rpn){
    size_t i = 0;
    std::string newRpn;
    
    while (i < rpn.length()){
        if ((rpn[i] == 32 || (rpn[i] <= 13 && rpn[i] >= 9)) && i < rpn.length()){
            i++;
            continue;
        }
        newRpn += rpn[i];
        i++;
    }
    return newRpn;
}

void RPN::calculatingRpn(std::string rpn){
    std::string::iterator it = rpn.begin();
    for (; it != rpn.end(); it++){
        if (*it >= '0' && *it <= '9'){
            mystack.push(*it - '0');
        } 
        else if (*it == '*' || *it == '-' || *it == '+' || *it == '/'){
            int operand2 = mystack.top();
            mystack.pop();
            int operand1 = mystack.top();
            mystack.pop();
            if (*it == '*')
                mystack.push(operand1 * operand2);
            else if (*it == '-')
                mystack.push(operand1 - operand2);
            else if (*it == '+')
                mystack.push(operand1 + operand2);
            else if (*it == '/')
                mystack.push(operand1 / operand2);
        }
    }
    if (!mystack.empty())
        std::cout << mystack.top() << std::endl;
    else{
        std::cout << "Error" << std::endl;
    }
}

int RPN::checker(std::string rpn){
    std::string::iterator it = rpn.begin();
    
    for(; it != rpn.end(); it++){
        if (*it != '+' && *it != '-' && *it != '/' && *it != '*' && !(*it >= '0' && *it <= '9')){
            return 0;
        }
    }
    return 1;
}
    
