/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:54:17 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/21 15:30:55 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const std::string& filePath)
	: btcInputFilePath(filePath)
	, priceHistory() {
	this->checkFilePath();
	this->setPriceHistory();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
	: btcInputFilePath(src.btcInputFilePath)
	, priceHistory() {
	this->checkFilePath();
	this->setPriceHistory();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		this->btcInputFilePath = src.btcInputFilePath;
		this->priceHistory = src.priceHistory;
	}
	return *this;
}

void BitcoinExchange::validateFilePath(const std::string& path) const {
	std::ifstream file(path.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("cannot open file: " + path);
	}
	file.peek();
	if (file.eof()) {
		throw std::runtime_error("file is empty: " + path);
	}
}

bool BitcoinExchange::validateDay(int year, int month, int day) const {
	bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int daysInMonth;
	if (month == JANUARY || month == MARCH || month == MAY
		|| month == JULY || month == AUGUST || month == OCTOBER
		|| month == DECEMBER) {
		daysInMonth = 31;
	}
	else if (month == FEBRUARY) {
		daysInMonth = leapYear ? 29 : 28;
	}
	else {
		daysInMonth = 30;
	}
	return day <= daysInMonth;
}

bool BitcoinExchange::validateDate(const std::string& date) const {
	if (date.size() != 10) {
		return false;
	}
	if (date.at(4) != '-' || date.at(7) != '-') {
		return false;
	}
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!std::isdigit(date[i])) {
			return false;
		}
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2008 || month < 1 || month > 12
		|| day < 1 || day > 31) {
		return false;
	}
	if (!validateDay(year, month, day)) {
		return false;
	}
	return true;
}

std::string BitcoinExchange::getDateFromLine(const std::string& line, const char delimiter) const {
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) {
		throw std::runtime_error("no delimiter: " + line);
	}
	std::size_t dateLength = 10;
	if (pos < dateLength) {
		throw std::runtime_error("invalid date format: " + line);
	}
	pos = line.at(pos - 1) == ' ' ? pos - 1 : pos;
	std::string date = line.substr(0, pos);
	// std::cout << date << "\n";
	if (!validateDate(date)) {
		throw std::runtime_error("invalid date format: " + line);
	}
	return (date);
}

float BitcoinExchange::getValueFromLine(const std::string& line, const char delimiter) const {
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) {
		throw std::runtime_error("no delimiter: " + line);
	}
	std::size_t start = line.at(pos + 1) == ' ' ? pos + 2 : pos + 1;
	if (start >= line.size()) {
		throw std::runtime_error("invalid line format: " + line);
	}
	std::string value = line.substr(start);
	bool hasDot = false;
	for (size_t i = 0; i < value.size(); ++i) {
		char c = value.at(i);
		if (i == 0 && (c == '-' || c == '+')) {
			continue ;
		}
		if (c == '.') {
			if (hasDot) {
				throw std::runtime_error("invalid line format: " + line);
			}
			hasDot = true;
			continue ;
		}
		if (!std::isdigit(c)) {
			throw std::runtime_error("invalid line format: " + line);
		}
	}
	char* endPtr = NULL;
	errno = 0;
	float result = std::strtof(value.c_str(), &endPtr);
	if (errno == ERANGE) {
		throw std::runtime_error("float conversion out of range: " + line);
	}
	const char* endOfString = value.c_str() + value.size();
	if (endPtr != endOfString) {
		throw std::runtime_error("invalid line format: " + line);
	}
	if (result < 0) {
		throw std::runtime_error("not a positive number: " + line);
	}
	return result;
}

void BitcoinExchange::checkFilePath() const {
	const std::string& filePath = this->btcInputFilePath;
	if (filePath.empty()) {
		throw std::runtime_error("input file path parameter is empty");
	}
	validateFilePath(filePath);
}

void BitcoinExchange::setPriceHistory() {
	const std::string priceHistoryFilePath = "./includes/data.csv";
	validateFilePath(priceHistoryFilePath);
	std::ifstream file(priceHistoryFilePath.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("cannot open file: " + priceHistoryFilePath);
	}
	std::string line;
	while (std::getline(file, line)) {
		if (line.compare("date,exchange_rate") == 0) {
			continue ;
		}
		try {
			std::string date = getDateFromLine(line, ',');
			float value = getValueFromLine(line, ',');
			this->priceHistory[date] = value;
			// std::cout << "DEBUG! Added line: " + line + "\n";
		} catch (std::exception& e) {
			// std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	if (this->priceHistory.size() == 0) {
		throw std::runtime_error(priceHistoryFilePath + " had no valid price entry.");
	}
}

std::map<std::string, float>::const_iterator BitcoinExchange::getClosestDate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = this->priceHistory.lower_bound(date);
	if (it == priceHistory.end()) {
		return --it;
	}
	if (it->first == date) {
		return it;
	}
	if (it == priceHistory.begin()) {
		throw std::runtime_error("no earlier date found.");
	}
	return --it;
}

void BitcoinExchange::calculatePrices() const {
	std::ifstream file(this->btcInputFilePath.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("cannot open file: " + this->btcInputFilePath);
	}
	std::string line;
	while (std::getline(file, line)) {
		if (line.compare("date | value") == 0) {
			continue ;
		}
		try {
			std::string date = getDateFromLine(line, '|');
			float value = getValueFromLine(line, '|');
			if (value > 1000) {
				throw std::runtime_error("too large a number.");
			}
			std::map<std::string, float>::const_iterator it = getClosestDate(date);
			float rate = it->second;
			float result = value * rate;
			std::cout << date << " => " << value << " = " << result << "\n";
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
