/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:32:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/13 15:06:10 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"
#include <fstream>

StringReplacer::StringReplacer(const std::string& filename,
								const std::string& s1,
								const std::string& s2)
	: filename(filename), s1(s1), s2(s2) {
	std::cout << "StringReplacer constructed" << std::endl;
}

StringReplacer::~StringReplacer() {
	std::cout << "StringReplacer destroyed" << std::endl;
}

// Returns false if doesn't exist, no permissions to read.
// Returns true if file executable or folder
int	StringReplacer::filenameExists() {
	std::ifstream	file(this->filename.c_str());
	return (file.good());
}

// if empty or not existing <filename>:
	// sed: can't read : No such file or directory
	// sed: can't read text2.txt: No such file or directory
// if filename is folder:
	// sed: read error on anotherfolder: Is a directory
// if no permissions in file:
	// sed: can't read text2.txt: Permission denied
// if filename executable:
	// new prompt
// if empty s1, throw error
// if empty s2, remove s1
int	StringReplacer::parseArgs() {
	if (filename.empty() || !this->filenameExists()) {
		std::cerr << "can't read file: " << filename << std::endl;
		return (0);
	} else {
		std::cout << "filename exists" << std::endl;
		return (1);
	}
}

void	StringReplacer::replaceToFile() {
	this->parseArgs();
}
