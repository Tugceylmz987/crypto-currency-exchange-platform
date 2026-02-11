// Testing tokenise function with try_catch error handling method

#include<iostream>
#include<vector>
#include<string>
#include<fstream>


std::vector<std::string> tokenise(std::string csvLine, char separator)

{
	//	string vector token ## stores tokens
		std::vector<std::string> tokens;



		//	int start, end ## use to delineate the position of the tokens(controller variables here)
		signed int start, end; // could be positive and negative 
		std::string token;


		start = csvLine.find_first_not_of(separator, 0); // separator starts at 0 as position

		do{
			//	end = next 'separator' after start
			end = csvLine.find_first_of(separator, start);// where the token ends(right before the separator)
		
		//	if start == csvLine.length or start == end ## nothing more to find
		//			break
		if (start == csvLine.length() || start == end) break;


		if (end >= 0)
				//	token = cvsLine.substr(start, end - start) ## start, substring length
			token = csvLine.substr(start, end - start);// start, substring length
		else
			token = csvLine.substr(start, csvLine.length() - start);


		//	tokens.push_back(token) ## save the token
		tokens.push_back(token);// save the token

		//	start = end + 1 ## move past this token
        start = end + 1;


		

		//while (end > 0) ## continue loop contion
		}while (end > 0);

		return tokens;
}


int main()
{
	// create file stream
	//class..>object
	// ifstream class in C++ is used to read data from files.
	std::ifstream csvFile{ "random_data_excel.csv"}; // {} means we are calling a constructor
	std::string line;
	std::vector <std::string> tokens;
	if (csvFile.is_open())
	{
		std::cout << "file open " << std::endl;

		while (std::getline(csvFile, line)) //getline is a standard C++ function used to read an entire line of text
		{
		std::cout << "read line is : " << line << std::endl;
		tokens = tokenise(line, ',');

			if (tokens.size()!= 5) //bad
			{
				std::cout << "bad line: not 5 tokens in the line " << std::endl;
				continue; // abort this line and move on next
			} 

			// we have 5 tokens
			try{ // try and call this lines 
				double price = std::stod(tokens[3]);
				double amount = std::stod(tokens[4]);
				std::cout << price << ";" << amount << std::endl;
			}
			catch (std::exception& e) { // if there is a exception it comes to this function
				std::cout << "bad line  :" << tokens[3] << std::endl;
				std::cout << "bad line  :" << tokens[4] << std::endl;
				break;// abort this line and move on next
			}
		}

		csvFile.close(); //
	}
	else
	{
		std::cout << "file is not open" << std::endl;
	}


return 0;
}

