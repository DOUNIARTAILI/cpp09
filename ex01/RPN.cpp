/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:16:18 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/25 13:30:44 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    
}
RPN::RPN(std::string rpn){
    fillVec(rpn);
    if (checker() == 1)
        calculatingRpn(rpn);
    else{
        std::cout << "Error" << std::endl;
    }
}
RPN::~RPN(){
    
}
RPN::RPN(const RPN& other){
    vec = other.vec;
    mystack = other.mystack;
}
const RPN& RPN::operator=(const RPN& other){
    if (this != &other) {
        vec = other.vec;
        mystack = other.mystack;
    }
    return *this;
}


void RPN::fillVec(std::string rpn){
    size_t i = 0;
    while (i < rpn.length()){
        if ((rpn[i] == ' ' || (rpn[i] <= 13 && rpn[i] >= 9)) && i < rpn.length())
            i++;
        vec.push_back(rpn[i]);
        i++;
    }
}

void RPN::displayVec(){
    std::vector<char>::iterator it = vec.begin();
    for (it = vec.begin(); it != vec.end(); it++){
        std::cout << *it;
    }
    std::cout << "\n";
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

int RPN::checker(){
    std::vector<char>::iterator it = vec.begin();
    for(; it != vec.end(); it++){
        if (*it != '+' && *it != '-' && *it != '/' && *it != '*' && !(*it >= '0' && *it <= '9')){
            return 0;
        }
    }
    return 1;
}

void RPN::displayStack(){
    while (!mystack.empty()) {
        std::cout << mystack.top() << std::endl;
        mystack.pop();
    }
}