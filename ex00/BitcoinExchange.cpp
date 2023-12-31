/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:31:03 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/24 11:44:52 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::loadExchangeRates(const char* filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    // Ignore the first line
    std::string dummyLine;
    std::getline(file, dummyLine);
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float exchangeRate;

        if (std::getline(iss, date, ',') && (iss >> exchangeRate)) {
            mapi[date] = exchangeRate;
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(){
    loadExchangeRates("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string file_name){
    loadExchangeRates("data.csv");
    (void)file_name;
}
BitcoinExchange::~BitcoinExchange(){
    
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    mapi = other.mapi;
}
const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other) {
        mapi = other.mapi;
    }
    return *this;
}

void BitcoinExchange::displayExchangeRates() const {
    for (std::map<std::string, float>::const_iterator it = mapi.begin(); it != mapi.end(); it++){
        std::cout << it->first << " , " << it->second << std::endl;
        break;
    }
}

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int BitcoinExchange::Date_checker(std::string key){
    int year, month, day;
    std::istringstream issYear(key.substr(0, 4));
    std::istringstream issMonth(key.substr(5, 2));
    std::istringstream issDay(key.substr(8, 2));

    if (issYear >> year && issMonth >> month && issDay >> day)
    {
        if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1) {
            return false;
        }
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year)) {
            daysInMonth[2] = 29;
        }
        return day <= daysInMonth[month];
    }
    return 0;
}//Error: bad input => 2001-42-42 std::cout << "Error: bad input => "<< key << std::endl;

// float BitcoinExchange::searchOnExchangeRate(std::string date){
   
//     std::map<std::string, float>::iterator it = mapi.find(date);
//     if (it != mapi.end()){
//         std::cout << "it->first " << it->first << std::endl;
//         std::cout << "it->second " << it->second << std::endl;
//         return it->second;
//     }
//     return 0;
// }

float BitcoinExchange::searchOnExchangeRate(std::string date){
    std::map<std::string, float>::iterator it = mapi.find(date);
    if (it != mapi.end()){
        return it->second;
    }
    else{
        it = mapi.begin();
        if (date < it->first)
            return 0.0;
        for(; it != mapi.end(); it++){
            if (it->first > date){
                return (--it)->second;
            }
        }
    }
    return (--mapi.end())->second;
}

int BitcoinExchange::ExchangeRate_checker(float value){
    // std::cout << "value " << value << std::endl;
    if (value < 0)
        return -1; //Error: not a positive number.
    if (value > 1000)
        return -2; //Error: too large number
    return 1;//cpp06
}

void BitcoinExchange::output(){
    
}

// void BitcoinExchange::find_str(string s, string del) {
//     // Use find function to find 1st position of delimiter.
//     int end = s.find(del); 
//     if (end != -1) {
//         date = s.substr(0, end) << endl;
//         s.erase(s.begin(), s.begin() + end + 1);
//         value = s.substr(0, end);
//     }
// }


int BitcoinExchange::all_digits(std::string str){
    // std::cout << "value|"<< str << "|"<< std::endl;
    size_t i = 0;
    while (i < str.length()){
        if (std::isdigit(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}

int BitcoinExchange::valid_value(std::string value){
    size_t i = 0;
    int dotCount = 0;

    while (i < value.length()){
        if (value[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return 0;
            }
        } else if (!std::isdigit(value[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int BitcoinExchange::valid_date(std::string key){
    
    if (key.size() != 10)
        return 0;
    // std::cout << "key.size() "<< key.size() << std::endl;
    // std::cout << "date|"<< key << "|"<< std::endl;
    std::string YYYY = key.substr(0, 4);
    std::string MM = key.substr(5, 2);
    std::string DD = key.substr(8, 2);
    // std::cout << "yyyy "<< YYYY << "MM "<< MM << "dd " << DD << std::endl;
    if (all_digits(YYYY) && all_digits(MM) && all_digits(DD) && (key[4] == '-' && key[7] == '-'))
        return 1;
    return 0;
}