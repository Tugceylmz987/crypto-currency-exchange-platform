#pragma once 

#include <vector>
#include "OrderBookEntry.h"
#include <string>

class CSVReader
{
	public:

	CSVReader();
	//Declares a constructor.(CVSReader();)
	//But notice : all your methods are static.
	//That means you don’t actually need to create a CSVReader object at all.


	//return as vectors of OrderBookEntry objects & static function is used without creating csvfile, just to read!
	// if it is not static then we need to create instance of csvFile.
	 static std::vector<OrderBookEntry> readCSV(std::string csvFile);
	
	private:
	//tekonizing
	 static std::vector<std::string> tokenise(std::string csvLine, char separator);
	 //reading each line in the file
	 static OrderBookEntry stringsToOBE(std::vector<std::string> strings);


};