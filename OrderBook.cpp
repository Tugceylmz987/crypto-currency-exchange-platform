#include "OrderBook.h"
#include "CSVReader.h"
#include<map>



OrderBook::OrderBook(std::string filename)
{
	//constructor 
	// save it to orders
	orders= CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
	std::vector<std::string> products;
	std::map<std::string, bool> prodMap;

	// need to iterate over all the orders and put every order into the map
	for (OrderBookEntry& e : orders) 
	{

		prodMap[e.product] = true;
	}

	return products;

}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
	std::string product,
	std::string timestamp) 
{

	std::vector<OrderBookEntry> orders_sub;
	return orders_sub;


}
