#include <gtest/gtest.h>

#include "circuits.h"

TEST(ResistorTests, FactoryMethodTest) {
  double resistance = 1.0;
  auto r1 = Resistor::make_resistor(resistance);
  EXPECT_EQ(r1->get_resistance(), resistance);
}

TEST(InductorTests, FactorMethodTest) {
  double inductance = 1.0;
  auto l1 = Inductor::make_inductor(inductance);
  EXPECT_EQ(l1->get_inductance(), inductance);
}

TEST(CapacitorTests, FactorMethodTest) {
  double capacitance = 1.0;
  auto c1 = Capacitor::make_capacitor(capacitance);
  EXPECT_EQ(c1->get_capacitance(), capacitance);
}

TEST(CircuitTests, RLCCircuitCreation) {
  double resistance = 1.0;
  double inductance = 1.0;
  double capacitance = 1.0;
  auto rlc = Circuit::make_RLC_circuit(resistance, inductance, capacitance);
  EXPECT_EQ(rlc->get_total_resistance(), 1.0);
  EXPECT_EQ(rlc->get_total_inductance(), 1.0);
  EXPECT_EQ(rlc->get_total_capacitance(), 1.0);
}

TEST(CircuitTests, RCCircuitCreation) {
  double resistance = 1.0;
  double capacitance = 1.0;
  auto rc = Circuit::make_RC_circuit(resistance, capacitance);
  EXPECT_EQ(rc->get_total_resistance(), 1.0);
  EXPECT_EQ(rc->get_total_inductance(), 0.0);
  EXPECT_EQ(rc->get_total_capacitance(), 1.0);
}

TEST(CircuitTests, LCCircuitCreation) {
  double inductance = 1.0;
  double capacitance = 1.0;
  auto lc = Circuit::make_LC_circuit(inductance, capacitance);
  EXPECT_EQ(lc->get_total_resistance(), 0.0);
  EXPECT_EQ(lc->get_total_inductance(), 1.0);
  EXPECT_EQ(lc->get_total_capacitance(), 1.0);
}

TEST(CircuitTests, CombineResistorsInSeries) {
  double resistance = 1.0;
  double inductance = 1.0;
  double capacitance = 1.0;
  auto rlc_circuit =
      Circuit::make_RLC_circuit(resistance, inductance, capacitance);
  auto second_resistor = Resistor::make_resistor(resistance);
  rlc_circuit->add_resistor(second_resistor);
  EXPECT_EQ(rlc_circuit->get_total_resistance(), 2.0 * resistance);
  auto third_resistor = Resistor::make_resistor(resistance);
  rlc_circuit->add_resistor(third_resistor);
  EXPECT_EQ(rlc_circuit->get_total_resistance(), 3.0 * resistance);
}

TEST(CircuitTests, CombineInductorsInSeries) {
  double resistance = 1.0;
  double inductance = 1.0;
  double capacitance = 1.0;
  auto rlc_circuit =
      Circuit::make_RLC_circuit(resistance, inductance, capacitance);
  auto second_inductor = Inductor::make_inductor(inductance);
  rlc_circuit->add_inductor(second_inductor);
  EXPECT_EQ(rlc_circuit->get_total_inductance(), 2.0 * inductance);
  auto l3 = Inductor::make_inductor(inductance);
  rlc_circuit->add_inductor(l3);
  EXPECT_EQ(rlc_circuit->get_total_inductance(), 3.0 * inductance);
}

TEST(CircuitTests, CombineCapacitorsInSeries) {
  double resistance = 1.0;
  double inductance = 1.0;
  double capacitance1 = 1.0;
  double capacitance2 = 0.5;
  auto rlc_circuit =
      Circuit::make_RLC_circuit(resistance, inductance, capacitance1);
  auto second_capacitor = Capacitor::make_capacitor(capacitance1);
  rlc_circuit->add_capacitor(second_capacitor);
  EXPECT_EQ(rlc_circuit->get_total_capacitance(), 0.5);
  auto third_capacitor = Capacitor::make_capacitor(capacitance2);
  rlc_circuit->add_capacitor(third_capacitor);
  EXPECT_EQ(rlc_circuit->get_total_capacitance(), 0.25);
}
