/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:16:18 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/25 13:10:17 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    
}
RPN::RPN(std::string rpn){
    fillVec(rpn);
    if (checker() == 1)
        calculatingRpn(rpn);
    else
        std::cout << "Error" << std::endl;
}
RPN::~RPN(){
    
}
// RPN::RPN(const RPN& other){
    
// }
// const RPN& RPN::operator=(const RPN& other){
    
// }


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

void RPN::calculatingRpn(std::string rpn) {
    std::stack<int> mystack;
    std::string::iterator it = rpn.begin();
    // std::string::iterator pos = rpn.begin();

    for (; it != rpn.end(); it++) {
        if (*it >= '0' && *it <= '9') {
            // Convert the character digit to an integer and push onto the stack
            mystack.push(*it - '0');

        } else if (*it == '*' || *it == '-' || *it == '+' || *it == '/') {
            // Save the position of the last operator
            // pos = it;
            // Perform the operation based on the operator
            int operand2 = mystack.top();
            mystack.pop();
            int operand1 = mystack.top();
            mystack.pop();
            // std::cout << "operand2 " << operand2 << " operand1 " << operand1 << std::endl;
            if (*it == '*') {
                mystack.push(operand1 * operand2);
            } else if (*it == '-') {
                mystack.push(operand1 - operand2);
            } else if (*it == '+') {
                mystack.push(operand1 + operand2);
            }
            else if (*it == '/') {
                mystack.push(operand1 / operand2);
            }
        }
    }

    // At this point, mystack should contain the final result
    if (!mystack.empty()) {
        std::cout << mystack.top() << std::endl;
        // mystack.pop();
        // std::cout << mystack.top() << std::endl;
        // std::cout << "size = "<< mystack.size() << std::endl;
    }
    else {
        // Handle error (empty stack)
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

// "12*2/2*24-+"

void RPN::displayStack(){
    while (!mystack.empty()) {
        std::cout << mystack.top() << std::endl;
        mystack.pop();
    }
}