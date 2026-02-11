#include"CSVReader.h"
#include<string>
#include<iostream>
#include<fstream> // to include fstream ->ifstream

//constructor
CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
	std::vector<OrderBookEntry> entries;
	std::ifstream csvFile{ csvFilename }; // {} means we are calling a constructor
	std::string line;
	if (csvFile.is_open())
	{
		while (std::getline(csvFile, line))// reads in a line
		{
			try {
				OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
				// tokenise is vector of string and pass that string to obe function 
				// which then converts into an order book entry.
				entries.push_back(obe);// push back to entries and pass it to obe
			}
			catch (const std::exception& e)
			{

				std::cout << "CSVReader::readCSV is bad " << std::endl;

			}

		}//end of line

		std::cout << "CSVReader::readCSV  read  " << entries.size() << "  entries" << std::endl;
	}
	return entries;

}
		
std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
	std::vector<std::string> tokens;
	signed int start, end; // could be positive and negative 
	std::string token;//declare a variable to store temporary token
	start = csvLine.find_first_not_of(separator, 0); // separator starts at 0 as position
	do
	{
		end = csvLine.find_first_of(separator, start);// where the token ends(right before the separator)

		if (start == csvLine.length() || start == end) break;
		if (end >= 0) token = csvLine.substr(start, end - start);// start, substring length
		else token = csvLine.substr(start, csvLine.length() - start);
		tokens.push_back(token);// save the token
		start = end + 1;
	} while (end > 0);	//while (end > 0) ## continue loop contion

	return tokens;

}
			
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens )
{
	
	double price, amount;
	if (tokens.size() != 5) //bad
	{
		std::cout << "bad line: not 5 tokens in the line " << std::endl;
		throw std::exception{};
		//continue; // abort this line and move on next when there is while conditon
	}

	// we have 5 tokens
	try { // try and call this lines 
		price = std::stod(tokens[3]);
		amount = std::stod(tokens[4]);
		//std::cout << price << ";" << amount << std::endl;
	}
	catch (const std::exception& e) { // if there is a exception it comes to this function
		std::cout << "bad line  :" << tokens[3] << std::endl;
		std::cout << "bad line  :" << tokens[4] << std::endl;
		throw;
	}
	OrderBookEntry obe{price,
						 amount,
						 tokens[0],
						 tokens[1],
						 OrderBookEntry::stringToOrderBookType(tokens[2])};

	return obe;
}
