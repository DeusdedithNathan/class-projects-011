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