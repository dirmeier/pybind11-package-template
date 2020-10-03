#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "clazz.hpp"

TEST(test_suite, test_case) {
  std::vector<int> vec{1, 2, 3};
  clazz c(vec);
  c.add(1);

  EXPECT_EQ(c.get()[0], 2);
}
