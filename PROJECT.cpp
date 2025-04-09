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
     void sellStock(const std::string& stockName, int quantity) {
        for (auto& pair : stocks) {
            if (pair.first.name == stockName) {
                if (pair.second >= quantity) {
                    pair.second -= quantity;
                    std::cout << "Sold " << quantity << " shares of " << stockName << "." << std::endl;
                    return;
                } else {
                    std::cout << "Not enough shares to sell." << std::endl;
                    return;
                }
            }
        }
        std::cout << "Stock not found in portfolio." << std::endl;
    }
 void showPortfolio() {
        std::cout << "Current Portfolio:" << std::endl;
        for (const auto& pair : stocks) {
            std::cout << pair.first.name << ": " << pair.second << " shares at $" << pair.first.price << " each." << std::endl;
        }
    }
};
class StockMarket {
private:
    std::vector<Stock> stocks;

public:
    void addStock(const Stock& stock) {
        stocks.push_back(stock);
    }
 void updatePrices() {
        for (auto& stock : stocks) {
            float randomChange = ((rand() % 200) - 100) / 100.0f; // Random change between -1 and 1
            stock.updatePrice(stock.price + randomChange);
        }
    }
     void displayStocks() {
        std::cout << "Available Stocks:" << std::endl;
        for (const auto& stock : stocks) {
            std::cout << stock.name << ": $" << stock.price << std::endl;
        }
    }
};
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    StockMarket market;
    Portfolio myPortfolio;

    // Adding stocks to the market
    market.addStock(Stock("AAPL", 150.00));
    market.addStock(Stock("GOOGL", 2800.00));
    market.addStock(Stock("TSLA", 700.00));

    // Display available stocks
    market.displayStocks();

    // Simulate buying stocks
    myPortfolio.buyStock(Stock("AAPL", 150.00), 10);
    myPortfolio.buyStock(Stock("TSLA", 700.00), 5);
    
   
     // Update stock prices
    market.updatePrices();
  
     // Display updated stocks
    market.displayStocks();
    
       // Show current portfolio
    myPortfolio.showPortfolio();

    // Simulate selling stocks
    myPortfolio.sellStock("AAPL", 5);
    myPortfolio.showPortfolio();

    return 0;
}


