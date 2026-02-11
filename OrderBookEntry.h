
#pragma once
#include<string>


enum class OrderBookType {bid, ask, unknown}; // enum class for order book type when there are fixed choices

class OrderBookEntry
{
	public:
		OrderBookEntry(double _price,
						double _amount,
						std::string _timestamp,
						std::string _product,
						OrderBookType _orderType);

		static OrderBookType stringToOrderBookType(std::string s);// static because it is not gonna be used in object on below

		double price;
		double amount;
		std::string timestamp;
		std::string product;
		OrderBookType orderType;
};