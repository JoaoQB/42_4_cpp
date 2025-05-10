/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:09:59 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 12:28:33 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() : key("")
			, value("")
			, isEncrypted(false) {
}

std::ostream& operator<<(std::ostream &out, const Data &myData) {
	out << "Data contains: \n"
		<< "{ key: \"" << myData.key
		<< "\", value: \"" << myData.value
		<< "\", isEncrypted: " << std::boolalpha << myData.isEncrypted << " }";

	return out;
}
