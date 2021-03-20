#pragma once

#include "components.h"

class IAnalysis {
 public:
  void Run(const Circuit& c) {
    load_input(c);
    perform_computations();
    generate_output();
  }

 private:
  virtual void load_input(const Circuit& c) = 0;
  virtual void perform_computations() = 0;
  virtual void generate_output() = 0;
};