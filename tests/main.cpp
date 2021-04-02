#include <gtest/gtest.h>

#include "capacitors.h"
#include "circuits.h"
#include "inductors.h"
#include "resistors.h"

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
  EXPECT_EQ(rlc->get_resistance(), 1.0);
  EXPECT_EQ(rlc->get_inductance(), 1.0);
  EXPECT_EQ(rlc->get_capacitance(), 1.0);
}

TEST(CircuitTests, RCCircuitCreation) {
  double resistance = 1.0;
  double capacitance = 1.0;
  auto rc = Circuit::make_RC_circuit(resistance, capacitance);
  EXPECT_EQ(rc->get_resistance(), 1.0);
  EXPECT_EQ(rc->get_inductance(), 0.0);
  EXPECT_EQ(rc->get_capacitance(), 1.0);
}

TEST(CircuitTests, LCCircuitCreation) {
  double inductance = 1.0;
  double capacitance = 1.0;
  auto lc = Circuit::make_LC_circuit(inductance, capacitance);
  EXPECT_EQ(lc->get_resistance(), 0.0);
  EXPECT_EQ(lc->get_inductance(), 1.0);
  EXPECT_EQ(lc->get_capacitance(), 1.0);
}

TEST(CircuitTests, InputListenerTest) {
  double voltage = 1.0;
  double resistance = 1.0;
  double inductance = 1.0;
  double capacitance = 1.0;

  auto input = InputValues(voltage, resistance, inductance, capacitance);

  auto circuit1 =
      Circuit::make_RLC_circuit(resistance, inductance, capacitance);
  auto circuit2 =
      Circuit::make_RLC_circuit(resistance, inductance, capacitance);

  double new_voltage = 2.0;
  input.subscribe(circuit1);
  input.subscribe(circuit2);
  input.set_voltage(new_voltage);
  EXPECT_EQ(circuit1->get_voltage(), new_voltage);
  EXPECT_EQ(circuit2->get_voltage(), new_voltage);
}
