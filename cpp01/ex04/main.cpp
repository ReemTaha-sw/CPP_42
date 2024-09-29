/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:32:10 by rosman            #+#    #+#             */
/*   Updated: 2024/09/08 13:56:40 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool replaceInFile(std::string filename, std::string s1, std::string s2)
{
    if (s1.empty() || s2.empty(), filename.empty())
        return (std::cout << "\033[31mOne or more of the args is EMPTY!\033[0m\nTry again with right args🙃\n", false);
    
    std::ifstream infile(filename.c_str()); // open the input file using infile var (.c_str() to Convert filename to const char*)
    if (!infile)
        return (std::cout << "\033[31mError\033[0m:\nCould not open file: " << filename << "\n", false);
    std::string file_content((std::istreambuf_iterator<char>(infile)),
                            std::istreambuf_iterator<char>()); // read all the file content into the file_content var
    infile.close();
    
    std::string::size_type pos = 0;
    while ((pos = file_content.find(s1, pos)) != std::string::npos)
    {
        file_content.erase(pos, s1.length());
        file_content.insert(pos, s2);
        pos += s2.length();
    }

    std::string new_file = filename + ".replace";
    std::ofstream output_file(new_file.c_str()); // creating and writing to the new_file file
    if (!output_file)
        return (std::cout << "\033[31mError\033[0m:\nCould not create file: " << new_file << "\n", false);
    output_file << file_content; // writing in the new_file
    output_file.close();

    std::cout << "File (" << new_file << ") Created \033[32mSuccessfully\033[0m✨\n";
    return true;
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];

        if (!replaceInFile(filename, s1, s2))
            return 1;
    }
    else
        std::cout << "\033[31m./replace <filename> <string to replace> <replacement string>\033[0m\n";
    return 0;
}