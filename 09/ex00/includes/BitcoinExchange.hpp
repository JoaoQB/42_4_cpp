/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:54:15 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/23 13:13:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <cerrno>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& filePath);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& src);

		// const std::map<std::string, float>& getPriceHistory() const;
		void calculatePrices() const;

	private:
		std::string btcInputFilePath;
		std::map<std::string, float> priceHistory;

		BitcoinExchange();

		void validateFilePath(const std::string& path) const;

		bool validateDay(int year, int month, int day) const;
		bool validateDate(const std::string& date) const;
		std::string getDateFromLine(const std::string& line, const char delimiter) const;

		float getValueFromLine(const std::string& line, const char delimiter) const;

		void checkFilePath() const;
		void setPriceHistory();

		std::map<std::string, float>::const_iterator getClosestDate(const std::string& date) const;

		enum Month {
			JANUARY = 1,
			FEBRUARY,
			MARCH,
			APRIL,
			MAY,
			JUNE,
			JULY,
			AUGUST,
			SEPTEMBER,
			OCTOBER,
			NOVEMBER,
			DECEMBER
		};
};

#endif
