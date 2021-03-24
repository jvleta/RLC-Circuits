#pragma once

#include "circuits.h"

class CircuitFactory {
 public:
  static RCCircuit *make_RC_circuit(double r, double c) {
    RCCircuit *circuit = new RCCircuit();
    circuit->add_resistor(Resistor::make_resistor(r));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }

  static LCCircuit *make_LC_circuit(double l, double c) {
    LCCircuit *circuit = new LCCircuit();
    circuit->add_inductor(Inductor::make_inductor(l));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }
  static Circuit *make_RLC_circuit(double r, double l, double c) {
    RLCCircuit *circuit = new RLCCircuit();
    circuit->add_resistor(Resistor::make_resistor(r));
    circuit->add_inductor(Inductor::make_inductor(l));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }
};