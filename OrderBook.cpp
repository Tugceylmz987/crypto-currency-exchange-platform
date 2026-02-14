#include "OrderBook.h"
#include "CSVReader.h"
#include<map>



OrderBook::OrderBook(std::string filename)
{
	//constructor 
	// save it to orders
	orders= CSVReader::readCSV(filename);
}

// return vector of all know products in the dataset
std::vector<std::string> OrderBook::getKnownProducts()
{
	std::vector<std::string> products;

	/* Anahtar: std::string → ürün adı

	Değer( value): bool(key) → sadece “var mı?” demek için kullanılıyor*/
	std::map<std::string, bool> prodMap;

	//prodMap içinde, orders içinde geçen tüm benzersiz ürün isimleri key olarak bulunur.
	// need to iterate over all the orders and put every order into the map
	//“orders içinde hangi ürünler var?”
	for (OrderBookEntry& e : orders) 
	{
		// The key is going to be e.product and the value is going to be “true”
		prodMap[e.product] = true;
	}
	// now flatten the map to a vector of strings
	for(auto const& e:prodMap)
	{
		products.push_back(e.first);
		//e.first is key(string); e.last is value which is bool
	}

	return products;

}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
													std::string product,
													std::string timestamp) 
{

	std::vector<OrderBookEntry> orders_sub;
	for (OrderBookEntry& e: orders)
	{
		if (e.orderType == type &&
			e.product == product &&
			e.timestamp == timestamp) 
		{
			orders_sub.push_back(e);
		}
	}
	return orders_sub;
	  
}
