# QuantEngine-CPP 📈

A high-performance, event-driven backtesting engine designed for quantitative research. This project bridges the speed of **C++** with the flexibility of **Python** using **Pybind11**, allowing for rapid strategy iteration without sacrificing execution performance.

## 🚀 Key Features
* **Hybrid Architecture:** Core execution logic (Order Management, Portfolio Tracking) written in C++ for maximum throughput.
* **Event-Driven Design:** Mimics real-time trading environments to eliminate look-ahead bias.
* **Pythonic Interface:** Seamless integration with the Python ecosystem (Pandas/NumPy) for signal generation and data analysis.
* **Modular Loader System:** Support for custom data providers, currently optimized for CSV-based signal streams.
* **Institutional Metrics:** (In Progress) Implementation of Sharpe Ratio, Max Drawdown, and Sortino Ratio.



## 🛠 Tech Stack
* **Language:** C++17, Python 3.10+
* **Bindings:** Pybind11
* **Build System:** CMake
* **Data Handling:** Pandas (Python), STL Containers (C++)

## 📁 Directory Structure
```text
quant_engine/
├── CMakeLists.txt           # Build configuration
├── pyproject.toml           # Python package metadata
├── src/                     # C++ Source Code (The Core)
│   ├── main.cpp             # Pybind11 bindings
│   ├── engine.cpp           # Trade execution logic
│   └── include/             # Header files
├── quant_engine/            # Python Package Wrapper
│   ├── __init__.py          
│   └── loaders.py           # Data ingestion logic
└── examples/                # Usage demonstrations
