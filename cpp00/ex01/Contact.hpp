/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:36:34 by rosman            #+#    #+#             */
/*   Updated: 2024/09/02 17:01:28 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();
        Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
        std::string get_f_name();
        std::string get_l_name();
        std::string get_n_name();
        std::string get_phone();
        std::string get_secret();
};