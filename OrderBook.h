#pragma once 
#include "OrderBook.h"
#include "CSVReader.h"
#include<string>
#include<vector>

class OrderBook
{


	public:

	/* contractor , reading a CSV data file  */
	//construct(file name)
		OrderBook(std::string filename);


	/* return vector of all know products in the dataset */
	//getKnownProducts();
	//to give us a list of all the products, and then getOrders.
		std::vector<std::string> getKnownProducts();


	/* return  vector of Orders according to the sent filters */
	//getOrders( type, product, timestamp)
		std::vector<OrderBookEntry> getOrders(OrderBookType type,
			std::string product,
			std::string timestamp);

	private:
	//store this onto orders
		std::vector<OrderBookEntry> orders;

};
