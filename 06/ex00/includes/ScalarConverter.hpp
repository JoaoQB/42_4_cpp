/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:41:33 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/08 17:55:23 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <climits>
# include <cmath>

enum LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter {
	public:
		static void convert(const std::string& input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&);

		static std::string trimInput(const std::string& input);
		static bool isPseudoLiteral(const std::string& input);
		static void printPseudoLiteral(const std::string& input);
		static LiteralType findType(const std::string& input);
		static bool hasFloatSuffix(const std::string& input);
		static void printCharFromDouble(double number);
		static void convertChar(const std::string& input);
		static void convertDouble(const std::string& input);
};

#endif
