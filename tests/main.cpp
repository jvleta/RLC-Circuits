#include "capacitors.h"
#include "factories.h"
#include "gtest/gtest.h"
#include "inductors.h"
#include "resistors.h"

// Resistor
TEST(ResistorTests, FactoryMethodTest) {
  double resistance = 1.0;
  auto r1 = Resistor::make_resistor(resistance);
  EXPECT_EQ(r1->get_resistance(), resistance);
}

// Inductor
TEST(InductorTests, FactorMethodTest) {
  double inductance = 1.0;
  auto l1 = Inductor::make_inductor(inductance);
  EXPECT_EQ(l1->get_inductance(), inductance);
}

// Capacitor
TEST(CapacitorTests, FactorMethodTest) {
  double capacitance = 1.0;
  auto c1 = Capacitor::make_capacitor(capacitance);
  EXPECT_EQ(c1->get_capacitance(), capacitance);
}

TEST(CircuitTests, CombineResistorsInSeries) {
  double r = 1.0;
  double l = 1.0;
  double c = 1.0;
  auto rlc = CircuitFactory::make_RLC_circuit(r, l, c);
  auto r2 = Resistor::make_resistor(r);
  rlc->add_resistor(r2);
  EXPECT_EQ(rlc->get_total_resistance(), 2.0 * r);
}

TEST(CircuitTests, CombineInductorsInSeries) {
  double r = 1.0;
  double l = 1.0;
  double c = 1.0;
  auto rlc = CircuitFactory::make_RLC_circuit(r, l, c);
  auto l2 = Inductor::make_inductor(l);
  rlc->add_inductor(l2);
  EXPECT_EQ(rlc->get_total_inductance(), 2.0 * l);
}

TEST(CircuitTests, CombineCapacitorsInSeries) {
  double r = 1.0;
  double l = 1.0;
  double c = 1.0;
  auto rlc = CircuitFactory::make_RLC_circuit(r, l, c);
  auto c2 = Capacitor::make_capacitor(c);
  rlc->add_capacitor(c2);
  EXPECT_EQ(rlc->get_total_capacitance(), 0.5);
}