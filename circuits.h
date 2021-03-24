#pragma once

#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "capacitors.h"
#include "inductors.h"
#include "resistors.h"

enum class CircuitType { RLC, LC };
struct InputValues {
  CircuitType type = CircuitType::RLC;
  double voltage = 0.0;
  double resistance = 0.0;
  double inductance = 0.0;
  double capacitance = 0.0;
};

class Circuit {
 protected:
  Circuit() {}

 private:
  double voltage_;
  std::vector<Resistor *> resistors_;
  std::vector<Inductor *> inductors_;
  std::vector<Capacitor *> capacitors_;

 public:
  void run() {
    compute();
    make_plot();
  }
  virtual void compute() = 0;
  void make_plot(){};
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

  double get_voltage() { return voltage_; }
  double get_current() { return voltage_ / get_total_resistance(); }
  friend class CircuitFactory;
};

class RCCircuit : public Circuit {
 private:
  RCCircuit(){};

 public:
  void add_inductor() = delete;
  void compute() {}
  friend class CircuitFactory;
};

class LCCircuit : public Circuit {
 private:
  LCCircuit(){};

 public:
  void add_resistor() = delete;
  void compute() {}
  friend class CircuitFactory;
};

class RLCCircuit : public Circuit {
 private:
  RLCCircuit(){};

 public:
  void compute() {}
  friend class CircuitFactory;
};
