# crypto currency exchange platform

#  Cryptocurrency Exchange (C++)

This project is a **command-line cryptocurrency trading platform simulator** written in **C++**, developed as part of the University of London BSc Computer Science (Object Oriented Programming) curriculum on Coursera, which I am currently taking.

The project is structured across **5 modules**. I am currently completing **Module 4**, with **Module 5 still in progress**.


The program simulates the experience of **buying and selling cryptocurrencies** using a **real order book dataset** loaded from a CSV file. It focuses on **object-oriented design**, **modular programming**, and **data processing** in C++.

---

##  Learning Objectives

This project demonstrates:

- Using **control flow** to build interactive, multi-branch, iterative programs
- Selecting appropriate **data types** to model a trading platform
- Converting **algorithms from pseudocode to C++**
- Using **classes** to combine data and functions
- Modeling interactions between different parts of a program
- Building a **larger program from multiple modules**
- Reading and processing **CSV data files**

---

##  What the Program Does

- Runs in the **terminal / command line**
- Loads market data from a **CSV file** into an order book
- Displays a **menu-driven interface**:
  - Print help
  - Show market statistics
  - Make an offer (sell)
  - Make a bid (buy)
  - Show wallet
  - Move to next time frame
- Uses classes to represent:
  - The main application controller (`MerkelMain`)
  - The order book (`OrderBook`)
  - Individual orders (`OrderBookEntry`)
  - CSV file parsing (`CSVReader`)

---

##  Project Structure

```text
.
├── MerkelMain.h / MerkelMain.cpp   # Main application logic and menu system
├── OrderBook.h / OrderBook.cpp     # Stores and queries all orders
├── OrderBookEntry.h / .cpp         # Represents a single order entry
├── CSVReader.h / CSVReader.cpp     # Reads and parses CSV data into objects
├── mainn.cpp                       # Program entry point 
├── 20200317.csv                    # Market data file (example), soon it will be worked with live data ..(in process)
└── README.md                       # Project documentation
