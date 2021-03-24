#include "gtest/gtest.h"

#include "resistors.h"

TEST(ResistorTests, FactoryMethodTest) {
  double resistance = 1.0;
  auto r1 = Resistor::make_resistor(resistance);
  EXPECT_EQ(r1->get_resistance(), resistance);
}