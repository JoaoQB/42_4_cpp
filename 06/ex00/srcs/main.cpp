/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:41:00 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 14:07:34 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main() {
	const std::string testCases[] = {
		"a",         // CHAR
		"z",         // CHAR
		"0",         // INT
		"42",        // INT
		"   123   ", // INT with whitespace
		"128",         // INT out of char range
		"127",         // CHAR edge case
		"-2147483648", // INT min
		"2147483647",  // INT max
		"-2147483649", // INT min - 1
		"2147483648",  // INT max + 1
		"3.14",      // DOUBLE
		"2.71828",   // DOUBLE
		"0.0",       // DOUBLE
		"3.14f",     // FLOAT
		"42.0f",     // FLOAT
		"nan",       // DOUBLE pseudo-literal
		"nanf",      // FLOAT pseudo-literal
		"+inf",      // DOUBLE pseudo-literal
		"-inff",     // FLOAT pseudo-literal
		"++42",      // Invalid
		"4..2",      // Invalid
		"1.0ff",     // Invalid
		"42f0",      // Invalid
		"",          // Empty
		" ",		 // Single Space
		"     ",     // Whitespace only
		"99999999999999999999999999999999", // Overflow
		"-99999999999999999999999999999999", // Underflow
		"#",         // Non-digit printable char
	};

	for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
		std::cout << "\n=== Test Case: \"" << testCases[i] << "\" ===" << std::endl;
		ScalarConverter::convert(testCases[i]);
	}
	return 0;
}
