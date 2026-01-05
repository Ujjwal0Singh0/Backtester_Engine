#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <map>
#include <vector>

struct Trade {
    std::string ticker;
    int quantity;
    double price;
    std::string side; // "BUY" or "SELL"
};

class Portfolio {
public:
    Portfolio(double initial_cash);

    // Core logic
    void execute_trade(std::string ticker, int quantity, double price, std::string side);
    
    // Getters for Python
    double get_cash() const { return cash; }
    double get_total_pnl() const { return total_pnl; }
    int get_position(std::string ticker);

private:
    double cash;
    double total_pnl;
    std::map<std::string, int> positions; // Ticker -> Quantity
    std::vector<Trade> trade_history;
};

#endif