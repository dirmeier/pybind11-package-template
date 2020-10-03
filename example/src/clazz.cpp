#include "clazz.hpp"

void clazz::add(int k) {
  for (auto& el : vec_)
    el += k;
}
