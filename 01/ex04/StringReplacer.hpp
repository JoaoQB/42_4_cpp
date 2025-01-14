/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/14 17:31:14 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACER_HPP
#define STRINGREPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

class StringReplacer {
	private:
		const std::string	filename;
		const std::string	s1;
		const std::string	s2;

		int		validateArgs();
		void	copyAndReplaceStringToFile(const std::string& string,
											const std::string& outfileName);
	public:
		StringReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
		~StringReplacer();
		void	replaceToFile();
};

#endif
