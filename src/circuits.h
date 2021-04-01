#pragma once

#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "capacitors.h"
#include "inductors.h"
#include "resistors.h"

struct InputValues {
  double voltage = 0.0;
  double resistance = 0.0;
  double inductance = 0.0;
  double capacitance = 0.0;
};

class Circuit {
 private:
  Circuit() {}
  double voltage_;
  std::vector<Resistor *> resistors_;
  std::vector<Inductor *> inductors_;
  std::vector<Capacitor *> capacitors_;

 public:
  void run() {
    compute();
    make_plot();
  }
  virtual void compute(){};
  virtual void make_plot(){};
  virtual void add_resistor(Resistor *resistor) {
    resistors_.push_back(resistor);
  }
  virtual void add_inductor(Inductor *inductor) {
    inductors_.push_back(inductor);
  }
  virtual void add_capacitor(Capacitor *capacitor) {
    capacitors_.push_back(capacitor);
  }
  void set_voltage(double v) { voltage_ = v; }

  double get_total_resistance() {
    return std::accumulate(
        resistors_.begin(), resistors_.end(), 0.0,
        [](double sum, Resistor *r) { return sum + r->get_resistance(); });
  }

  double get_total_inductance() {
    return std::accumulate(
        inductors_.begin(), inductors_.end(), 0.0,
        [](double sum, Inductor *l) { return sum + l->get_inductance(); });
  }

  double get_total_capacitance() {
    double one_over_c =
        std::accumulate(capacitors_.begin(), capacitors_.end(), 0.0,
                        [](double sum, Capacitor *c) {
                          return sum + 1.0 / c->get_capacitance();
                        });
    return 1.0 / one_over_c;
  }

  double get_voltage() { return voltage_; }
  double get_current() { return voltage_ / get_total_resistance(); }

  static Circuit *make_RC_circuit(double r, double c) {
    Circuit *circuit = new Circuit();
    circuit->add_resistor(Resistor::make_resistor(r));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }

  static Circuit *make_LC_circuit(double l, double c) {
    Circuit *circuit = new Circuit();
    circuit->add_inductor(Inductor::make_inductor(l));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }

  static Circuit *make_RLC_circuit(double r, double l, double c) {
    Circuit *circuit = new Circuit();
    circuit->add_resistor(Resistor::make_resistor(r));
    circuit->add_inductor(Inductor::make_inductor(l));
    circuit->add_capacitor(Capacitor::make_capacitor(c));
    return circuit;
  }
};
