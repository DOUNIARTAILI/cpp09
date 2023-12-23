/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:31:21 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/23 01:21:19 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange{
public:
    BitcoinExchange();
    BitcoinExchange(std::string file_name);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    const BitcoinExchange& operator=(const BitcoinExchange& other);
    void loadExchangeRates(const char* filename);
    void displayExchangeRates() const;
    int Date_checker(std::string key);
    int ExchangeRate_checker(float value);
    float searchOnExchangeRate(std::string date);
    void output();
private:
    std::map<std::string, float> mapi;
};

#endif