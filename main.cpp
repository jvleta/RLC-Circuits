#include "analysis.h"
#include "components.h"

int main() {
  auto c = Circuit::make_RLC_circuit(10.0, 1.0, 2.0);
  c->set_voltage(5.0);
  
  std::cout << "V =" << c->get_voltage() << "\n";
  std::cout << "I =" << c->get_current() << "\n";
  std::cout << "R =" << c->get_total_resistance() << "\n";
}