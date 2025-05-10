/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:47:49 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 12:27:41 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

struct Data {
	std::string key;
	std::string value;
	bool isEncrypted;

	Data();
};

std::ostream& operator<<(std::ostream &out, const Data &myData);

#endif
