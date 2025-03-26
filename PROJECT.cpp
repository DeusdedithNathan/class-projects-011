#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class Stock {
public:
    std::string name;
    float price;

    Stock(std::string stockName, float stockPrice) : name(stockName), price(stockPrice) {}

    void updatePrice(float newPrice) {
        price = newPrice;
    }
};
class Portfolio {
private:
    std::vector<std::pair<Stock, int>> stocks; // Stock and quantity

public:
    void buyStock(const Stock& stock, int quantity) {
        stocks.push_back(std::make_pair(stock, quantity));
        std::cout << "Bought " << quantity << " shares of " << stock.name << " at $" << stock.price << "." << std::endl;
    }