#pragma once

class Resistor {
 public:
  static Resistor *make_resistor(double r) { return new Resistor(r); }
  double get_resistance() { return resistance_; }

 private:
  Resistor(double r) { resistance_ = r; }
  double resistance_ = 0.0;
};