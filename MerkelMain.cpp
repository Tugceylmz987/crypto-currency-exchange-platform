//.h → ne var
// .h  (header file) got all function
//.cpp → nasıl çalışıyor
//.cpp got all implementation
#include"MerkelMain.h"
#include <iostream>
#include <vector>
#include"OrderBookEntry.h"
#include"CSVReader.h"



MerkelMain::MerkelMain() 
//constructor
{

}
void MerkelMain::init()
//Bu → Fonksiyonların gerçek kodları
{
	//loadOrderBook();
	int input;
	while (true)
	{
		printMenu();
		input = getUserOption();
		processUserOption(input);
	}
}

void MerkelMain::printMenu() // this function prints the menu options and no return value( int, float, char etc) due to void function.
{
	//1 print help
	std::cout << "1: Print help " << std::endl;
	//2 print exchange stats
	std::cout << "2: Print exchange stats " << std::endl;
	//3 make an offer such as what you got to sell
	std::cout << "3: Make an offer " << std::endl;
	//4 make a bid means to buy
	std::cout << "4: Make a bid " << std::endl;
	//5 print my wallet
	std::cout << "5: Print my wallet " << std::endl;
	//6 continue
	std::cout << "6: Continue " << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void MerkelMain::printHelp()
{

}

void MerkelMain::printMarketStats()

{

	for(std::string const& p:orderBook.getKnownProducts())
	{
		std::cout << "products: " << p << std::endl;
		std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
																	p,
																	"2020/03/17 17:01:24.884492");
		std::cout << "Asks seen:" << entries.size() << std::endl;

	}
}
	//std::cout << "number of products" << products.size() << std::endl;

	/*std::cout << "orderBook contains:" << orders.size()<<"  entries"<<std::endl;
	unsigned int bids = 0;2
	unsigned int asks = 0;
	for (OrderBookEntry& e : orders)
	{
		if (e.orderType == OrderBookType::ask)
		{
			asks++;
		}
		if (e.orderType==OrderBookType::bid)
		{
			bids++;
		}

	}
	std::cout << "orderBook asks:" << asks << "&  bids  :" << bids <<std::endl;*/


void MerkelMain::enterOffer()
{
	std::cout << " make an offer - enter the amount" << std::endl;
}
void MerkelMain::enterBid()
{
	std::cout << " make a bid- enter the amount" << std::endl;
}
void MerkelMain::printWallet()
{

	std::cout << " your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
	std::cout << "Going to next time frame." << std::endl;
}


int MerkelMain::getUserOption() // this function gets the user option
{
	int userOption;
	std::cout << "Choose an option from 1 to 6: " << std::endl;
	std::cin >> userOption;
	std::cout << "you chose :" << userOption << std::endl;
	return userOption; // get return to local variable in main
}

void MerkelMain::processUserOption(int userOption) // this function processes the user option
{

	if (userOption == 0) // bad choice 
	{
		std::cout << " Invalid value. Choose 1 to 6." << std::endl;
	}

	if (userOption == 1) //  
	{
		printHelp();
	}
	if (userOption == 2) //  
	{
		printMarketStats();
	}
	if (userOption == 3) //  
	{
		enterOffer();
	}
	if (userOption == 4) //  
	{
		enterBid();
	}
	if (userOption == 5) //  
	{
		printWallet();
	}
	if (userOption == 6) //  
	{
		gotoNextTimeFrame();
	}

}