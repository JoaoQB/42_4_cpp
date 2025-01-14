/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:32:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/14 20:43:06 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"
#include <fstream>

StringReplacer::StringReplacer(const std::string& filename,
								const std::string& s1,
								const std::string& s2)
	: filename(filename), s1(s1), s2(s2) {
	// std::cout << "StringReplacer constructed" << std::endl;
}

StringReplacer::~StringReplacer() {
	// std::cout << "StringReplacer destroyed" << std::endl;
}

int	StringReplacer::validateArgs() {
	if (filename.empty()) {
		std::cerr << "Error: filename can't be empty" << std::endl;
		return (0);
	}
	struct stat	st;
	if (stat(this->filename.c_str(), &st) != 0) {
		std::cerr << "can't read file " << filename;
		std::cerr << ": No such file or directory" << std::endl;
		return (0);
	}
	if (st.st_mode & S_IFDIR) {
		std::cerr << "read error on " << filename;
		std::cerr << ": Is a directory" << std::endl;
		return (0);
	}
	if ((st.st_mode & S_IEXEC)) {
		return (0);
	}
	if (s1.empty()) {
		std::cerr << "Error: String to be replaced cannot be empty" << std::endl;
		return (0);
	}
	return (1);
}

void	StringReplacer::copyAndReplaceStringToFile(const std::string& string,
													const std::string& outfileName) {
	std::ofstream outfile(outfileName.c_str());
	if (!outfile || !outfile.is_open()) {
		std::cerr << "Error: can't open outfile " << filename;
		return ;
	}
	std::string	newString = string;
	size_t		pos = 0;
	size_t		s1Len = this->s1.length();
	pos = newString.find(this->s1, pos);
	while (pos != std::string::npos) {
		std::string	before = newString.substr(0, pos);
		std::string	after = newString.substr(pos + s1Len);
		newString = before + this->s2 + after;
		pos += s2.length();
		pos = newString.find(this->s1, pos);
	}
	outfile << newString;
	outfile.close();
}

void	StringReplacer::replaceToFile() {
	if (!this->validateArgs()) {
		return ;
	}
	std::ifstream	file(filename.c_str());
	if(!file || !file.is_open()) {
		std::cerr << "Error: can't open file " << filename;
		return ;
	}
	std::ostringstream	buffer;
	buffer << file.rdbuf();
	std::string	content = buffer.str();
	if (content.empty()) {
		return ;
	}
	std::string outfileName = filename + ".replace";
	copyAndReplaceStringToFile(content, outfileName);
	file.close();
}
