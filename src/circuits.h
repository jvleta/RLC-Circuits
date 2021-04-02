#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

struct InputValues;

struct InputListener {
  virtual ~InputListener() = default;
  virtual void InputChanged(InputValues &input, const std::string field_name,
                            const double &field_value) = 0;
};

struct InputValues {
 public:
  InputValues(){};
  InputValues(double v, double r, double l, double c) {
    voltage = v;
    resistance = r;
    inductance = l;
    capacitance = c;
  }

  void set_voltage(double v) {
    notify("voltage", v);
    voltage = v;
  }
  double get_voltage() { return voltage; }
  void subscribe(InputListener *listener) { listeners_.push_back(listener); }
  void notify(const std::string field_name, const double field_value) {
    for (const auto listener : listeners_) {
      listener->InputChanged(*this, field_name, field_value);
    }
  }

 private:
  double voltage = 0.0;
  double resistance = 0.0;
  double inductance = 0.0;
  double capacitance = 0.0;
  std::vector<InputListener *> listeners_;
};

class Circuit : public InputListener {
 private:
  Circuit(double r, double l, double c) {
    resistance_ = r;
    inductance_ = l;
    capacitance_ = c;
    circuit_id_ = std::rand();
  }
  double voltage_ = 0.0;
  double resistance_ = 0.0;
  double inductance_ = 0.0;
  double capacitance_ = 0.0;
  int circuit_id_ = 0;

 public:
  void InputChanged(InputValues &input, const std::string field_name,
                    const double &field_value) {
    // std::cout << "Circuit ID: " << circuit_id_ << "\n";
    // std::cout << "input's " << field_name << " has been changed to "
    //           << field_value << "\n";
    if (field_name == "voltage") {
      set_voltage(field_value);
    }
  }
  void run() {
    compute();
    make_plot();
  }
  virtual void compute(){};
  virtual void make_plot(){};
  void set_voltage(double v) { voltage_ = v; }
  void set_resistance(double r) { resistance_ = r; }
  void set_inductance(double l) { inductance_ = l; }
  void set_capacitance(double c) { capacitance_ = c; }
  double get_voltage() { return voltage_; }
  double get_resistance() { return resistance_; }
  double get_inductance() { return inductance_; }
  double get_capacitance() { return capacitance_; }

  static Circuit *make_RC_circuit(double r, double c) {
    Circuit *circuit = new Circuit(r, 0.0, c);
    return circuit;
  }

  static Circuit *make_LC_circuit(double l, double c) {
    Circuit *circuit = new Circuit(0.0, l, c);
    return circuit;
  }

  static Circuit *make_RLC_circuit(double r, double l, double c) {
    Circuit *circuit = new Circuit(r, l, c);
    return circuit;
  }
};
