/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:41:33 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/06 23:01:14 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

enum LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&);

		static void printErr(const std::string& error);
		static std::string trimInput(const std::string& input);
		static bool isPseudoLiteral(const std::string& input);
		static void printPseudoLiteral(const std::string& input);
		static LiteralType findType(const std::string& input);

		static void convertChar(const std::string& input);
		static void convertInt(const std::string& input);
		static void convertFloat(const std::string& input);
		static void convertDouble(const std::string& input);

		public:
			static void convert(const std::string& input);
};

#endif
