/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:33:27 by rosman            #+#    #+#             */
/*   Updated: 2024/09/02 16:48:52 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
        int     filled;
        std::string check_text_len(const std::string &str);
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(Contact contact);
        void display_contacts();
        void display_one_contact(int index);
};