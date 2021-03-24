#pragma once

class Inductor {
 public:
  static Inductor *make_inductor(double l) { return new Inductor(l); }
  double get_inductance() { return inductance_; }

 private:
  Inductor(double l) { inductance_ = l; }
  double inductance_ = 0.0;
};