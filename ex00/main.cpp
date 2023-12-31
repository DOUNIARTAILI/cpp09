/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:31:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/12/24 12:03:04 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac == 2){
        BitcoinExchange bitcoina; 
        // bitcoina.displayExchangeRates();
        std::ifstream file(av[1]);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file." << av[1] << std::endl;
            return 0;
        }
        std::string dummyLine;
        std::getline(file, dummyLine);
        if ("date | value" != dummyLine){
            std::cerr << "Error: invalid input file." << std::endl;
            return 0;
        }

        std::string line;
        while (std::getline(file, line)) {
            // std::cout << "line|"<< line<< "|"<< std::endl;
            if (line.empty()) {
                // Ignore empty lines and continue to the next line
                continue;
            }
            std::string d;
            std::string l = line;
            std::string v;
            int end = l.find('|'); 
            if (end != -1) {
                d = l.substr(0, end - 1);
                l.erase(l.begin(), l.begin() + end + 2);
                v = l.substr(0, end);
                // std::cout << "d: "<< d << std::endl;
                // std::cout << "v: "<< v << std::endl;
            }
            if (bitcoina.valid_value(v) && bitcoina.valid_date(d)){
                std::istringstream iss(line);
                std::string date;
                float exchangeRate;

                if (std::getline(iss, date, '|') && (iss >> exchangeRate)) {
                    // std::cout << "date: "<< date<< std::endl;
                    // std::cout << "exchangeRate: "<< exchangeRate<< std::endl;
                    if (bitcoina.Date_checker(date) == 1){
                        if(bitcoina.ExchangeRate_checker(exchangeRate) == -1)
                            std::cout << "Error: not a positive number." << std::endl;
                        else if (bitcoina.ExchangeRate_checker(exchangeRate) == -2)
                            std::cout << "Error: too large number." << std::endl;
                        else if (bitcoina.ExchangeRate_checker(exchangeRate) == 1){
                            float res = bitcoina.searchOnExchangeRate(date);
                            std::cout << date << " => "<< exchangeRate << " = " << std::fixed <<std::setprecision(1) << res * exchangeRate << std::endl;
                        }
                    }
                    else{
                        std::cout << "Error: bad input => "<< date << std::endl;
                    }
                }
            }
            else if (!bitcoina.valid_date(d)){
                // std::cout << "bitcoina.all_digits(v) "<< bitcoina.all_digits(v) << std::endl;
                // std::cout << "bitcoina.valid_date(d) "<< bitcoina.valid_date(d) << std::endl;
                std::cout << "Error: bad input => "<< d << std::endl;
            }
            else
                std::cout << "Error: not a positive number." << std::endl;
        }
        file.close();
    } 
    else{
        std::cout << "Error: could not open file." << std::endl;
    }
    return 0;
}

// int main()
// {
//     std::string key  = "2022-01-01" ;
//     int year, month, day;
//     std::istringstream issYear(key.substr(0, 4));
//     std::istringstream issMonth(key.substr(5, 2));
//     std::istringstream issDay(key.substr(8, 2));

//     if (issYear >> year && issMonth >> month && issDay >> day)
//     {
//         std::cout << year << std::endl;
//         std::cout << month << std::endl;
//         std::cout << day << std::endl;
//     }
//     BitcoinExchange b; //1 valid
//     std::cout << "res = " << b.valid_value(".23")<< std::endl;
// }

