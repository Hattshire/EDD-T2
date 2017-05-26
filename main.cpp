#include <iostream>
#include <fstream>
#include <string>

#include "lists.hpp"

int main()
{
	std::ifstream inputDataFile( "input.dat" );
	if( !inputDataFile.is_open() )
	{
		std::cout << "Can't Open File :(" << std::endl;
		return -1;
	}
	std::ofstream outputDataFile( "ouput.dat" );
	if( !outputDataFile.is_open() )
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
	
	list L1 = newList( totalMemory ), L2 = newList( 0 );

	for( int i = 0; i < totalOperations; i++ )
	{
		if( !std::getline( inputDataFile, line ) )
		{
			std::cout << "Can't read that line :(" << std::endl;
			return 3+i;
		}
		if( !line.find("malloc") )
		{   
		    int bytes = std::stoi( line.substr(7) ), position;
			if( (position = allocate( bytes, L1, L2)) )
			    outputDataFile << "Bloque de " << bytes << " bytes asignado a partir del byte " << position << std::endl;
		    else
			    outputDataFile << "Bloque de " << bytes << " bytes NO puede ser asignado" << std::endl;
		}
		else if( !line.find("free ") )
		{
		    int bytes = std::stoi( line.substr(5) );
			deallocate(bytes, L1, L2);
			outputDataFile << "Bloque de " << bytes << " bytes liberado" << std::endl;
			
		}
		else
		{
			std::cout << "Unknown token in \"" << line << "\"" << std::endl;
			return 3+i;
		}
	}
	
	deleteList(L1);
	deleteList(L2);

	inputDataFile.close();
	return 0;
}
