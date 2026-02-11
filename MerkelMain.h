 
//Class’ın ne yapabildiğini söyler
//Ama nasıl yaptığını söylemez
//.h → ne var
//.cpp → nasıl çalışıyor
#pragma once //  include only once 
#include<vector>
#include"OrderBookEntry.h"
#include "OrderBook.h"


class MerkelMain
{
	public:

		MerkelMain(); // can be public
		void init();// can be public 
	private:
		void printMenu(); // this function prints the menu options and no return value( int, float, char etc) due to void function.
		void printHelp();
		void printMarketStats();
		void enterOffer();
		void enterBid();
		void printWallet();
		void gotoNextTimeFrame();
		int getUserOption();// this function gets the user option
		void processUserOption(int userOption); // this function processes the user option
	
		OrderBook orderBook{"20200317.csv"};

};