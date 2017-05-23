#include <iostream>
#include <string>

#include "list.hpp"

int main()
{
	std::ifstream inputDataFile( "input.dat" );
	inputDataFile.open();
	if( !inputDataFile.is_open() )
	{
		std::cout << "Can't Open File :(" << std::endl;
		return -1;
	}

	std::string line;
	int totalMemory, totalOperations;

	if( !std::getline( inputDataFile, line ) )
	{
		std::cout << "Can't read First line :(" << std::endl;
		return 1;
	}
	totalMemory = std::stoi( line );

	if( !std::getline( inputDataFile, line ) )
	{
		std::cout << "Can't read Second line :(" << std::endl;
		return 2;
	}
	totalOperations = std::stoi( line );
	
	list L1 = newList( totalMemory ), L2;

	for( int i = 0; i < totalOperations; i++ )
	{
		if( !std::getline( inputDataFile, line ) )
		{
			std::cout << "Can't read that line :(" << std::endl;
			return 3+i;
		}
		int position;
		if( position = line.find("malloc ") )
		{
			allocate(std::stoi( line.substr(position) ), L1, L2);
		}
		else if( position = line.find("free ") )
		{
			deallocate(std::stoi( line.substr(position) ), L1, L2);
		}
		else
		{
			std::cout << "Unknown token in " << line << std::endl;
			return 3+i;
		}
	}

	inputDataFile.close();
	return 0;
}
