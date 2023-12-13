/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:20:27 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/13 19:04:40 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

void	fill_outfile(char **arg, std::ifstream& input_file, std::ofstream& outfile)
{
	std::string const to_be_replaced = arg[2], replacing = arg[3];
	// Lecture de l'ensemble du fichier
	while (!input_file.eof())
	{
		std::string line;
		std::getline(input_file, line);
		size_t	pos = line.find(to_be_replaced, 0);
		//Modification de chaque ligne
		while (pos != std::string::npos)
		{
			line.erase(pos, to_be_replaced.size());
			line.insert(pos, replacing);
			pos = line.find(to_be_replaced, pos + replacing.size());
		}
		// Inclusion des lignes que l'on veut au fichier de sortie
		outfile<<line;
		if (!input_file.eof())
			outfile<<std::endl;
	}
}

void	new_file_replace(char **arg, std::ifstream& input_file)
{
	//Ouverture du nouveau fichier
	std::string outfile_name = (std::string)arg[1] + ".replace";
	const char	*file_name =outfile_name.c_str();
	std::ofstream outfile(file_name, std::ofstream::out);
	if (!outfile.is_open())
	{
		std::cout<<"The new file couldn't be open"<<std::endl;
		input_file.close();
		exit(EXIT_FAILURE);
	}
	fill_outfile(arg, input_file, outfile);
	// Fermeture des fichiers par precaution
	outfile.close();
	input_file.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout<<"This program required 3 valids arguments"<<std::endl;
		return -1;
	}
	else
	{
		//Ouverture du fichier
		std::ifstream input_file (argv[1]);
		if (input_file.is_open())
			new_file_replace(argv, input_file);
		else
		{
			std::cerr<<"The file can't be open"<<std::endl;
			return -1;
		}



	}
	return 0;
}
