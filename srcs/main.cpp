#include <iostream>
#include <fstream>
#include <ostream>
#include <locale>
#include <sys/stat.h>

int	write_files(std::string name, std::ofstream files[2]);


bool file_exists (std::string name)
{
	struct stat buffer;   
	return (stat (name.c_str(), &buffer) == 0); 
}

int	check_args(int argc, char **argv, std::ofstream files[2])
{
	if (argc != 2)
		return (printf("usage: canon Classname\n"));
	if (file_exists(std::string (argv[1]) + ".hpp"))
		return (printf("%s.hpp already exists ! \n", argv[1]));
	if (file_exists(std::string (argv[1]) + ".cpp"))
		return (printf("%s.cpp already exists ! \n", argv[1]));
	
	files[0].open((std::string(argv[1]) + ".hpp").c_str() , std::ofstream::out | std::ofstream::app);
	files[1].open((std::string(argv[1]) + ".cpp").c_str() , std::ofstream::out | std::ofstream::app);
	return (0);
}

int	main(int argc, char **argv)
{
	std::ofstream 	files[2];

	if (check_args(argc, argv, files))
		return (1);
	else
		return (write_files(std::string(argv[1]), files));
}