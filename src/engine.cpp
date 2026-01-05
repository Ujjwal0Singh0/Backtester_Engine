#include "include/engine.hpp"
#include <iostream>

Portfolio::Portfolio(double initial_cash) : cash(initial_cash), total_pnl(0.0) {}

void Portfolio::execute_trade(std::string ticker, int quantity, double price, std::string side) {
    double transaction_amount = quantity * price;

    if (side == "BUY") {
        if (cash >= transaction_amount) {
            cash -= transaction_amount;
            positions[ticker] += quantity;
            trade_history.push_back({ticker, quantity, price, "BUY"});
        } else {
            std::cout << "Insufficient funds for " << ticker << std::endl;
        }
    } 
    else if (side == "SELL") {
        if (positions[ticker] >= quantity) {
            cash += transaction_amount;
            positions[ticker] -= quantity;
            trade_history.push_back({ticker, quantity, price, "SELL"});
        } else {
            std::cout << "Insufficient position to sell " << ticker << std::endl;
        }
    }
    // Note: You can add logic here to update total_pnl based on current market price
}

int Portfolio::get_position(std::string ticker) {
    if (positions.find(ticker) != positions.end()) {
        return positions[ticker];
    }
    return 0;
}