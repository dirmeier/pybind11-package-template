#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <vector>

#include "clazz.hpp"

namespace py = pybind11;

PYBIND11_MODULE(clazz, m) {
  py::class_<clazz>(m, "clazz")
      .def(py::init<std::vector<int>&>())
      .def("add", &clazz::add)
      .def("get", &clazz::get);
}
