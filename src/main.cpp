#include <pybind11/pybind11.h>
#include "include/engine.hpp"

namespace py = pybind11;

PYBIND11_MODULE(core_engine, m) {
    py::class_<Portfolio>(m, "Portfolio")
        .def(py::init<double>()) // Constructor: Portfolio(10000.0)
        .def("execute_trade", &Portfolio::execute_trade)
        .def("get_cash", &Portfolio::get_cash)
        .def("get_total_pnl", &Portfolio::get_total_pnl)
        .def("get_position", &Portfolio::get_position);
}