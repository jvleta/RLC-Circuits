#pragma once

class Capacitor {
 public:
  static Capacitor *make_capacitor(double c) { return new Capacitor(c); }
  double get_capacitance() { return capacitance_; }

 private:
  Capacitor(double c) { capacitance_ = c; }
  double capacitance_ = 0.0;
};

