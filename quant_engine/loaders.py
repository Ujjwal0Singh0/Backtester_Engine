from .core_engine import Portfolio
import pandas as pd

def run_backtest(csv_path, initial_capital=100000):
    df = pd.read_csv(csv_path)
    portfolio = Portfolio(initial_capital)

    for _, row in df.iterrows():
        # Map your signal (1 or -1) to BUY or SELL
        side = "BUY" if row['signal'] == 1 else "SELL"
        
        # Call the C++ engine
        portfolio.execute_trade(
            ticker=row['ticker'],
            quantity=int(row['quantity']),
            price=float(row['price']),
            side=side
        )

    return {
        "final_cash": portfolio.get_cash(),
        "positions": portfolio.get_position(df['ticker'].iloc[0]) # Example
    }