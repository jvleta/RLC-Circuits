#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

constexpr double k5Ohms = 5.0;
constexpr double k10Ohms = 10.0;
constexpr double k15Ohms = 15.0;

class Resistor {

public:
  double get_resistance() { return resistance_; }

private:
  Resistor(double r) { resistance_ = r; }
  double resistance_ = 0.0;
  double rating_ = 0.0;
  friend class ComponentFactory;
};

class ComponentFactory {
public:
  static Resistor *make_5_ohm_resistor() { return new Resistor(k5Ohms); }
  static Resistor *make_10_ohm_resistor() { return new Resistor(k10Ohms); }
  static Resistor *make_15_ohm_resistor() { return new Resistor(k15Ohms); }
  static Resistor *make_custom_resistor(double r) { return new Resistor(r); }
};

class Circuit {
public:
  Circuit(double v) { voltage_ = v; }

  void add_resistor(double r) {
    resistors_.push_back(ComponentFactory::make_custom_resistor(r));
  }

  void add_resistor(Resistor *resistor) { resistors_.push_back(resistor); }

  double get_total_resistance() {
    return std::accumulate(
        resistors_.begin(), resistors_.end(), 0.0,
        [](double sum, Resistor *r) { return sum + r->get_resistance(); });
  }

  double get_voltage() { return voltage_; }
  double get_current() { return voltage_ / get_total_resistance(); }

private:
  double voltage_;
  std::vector<Resistor *> resistors_;
};

int main() {
  auto r5 = ComponentFactory::make_5_ohm_resistor();
  auto r15 = ComponentFactory::make_15_ohm_resistor();
  double voltage = 10.0;
  auto c = Circuit(voltage);
  c.add_resistor(r5);
  c.add_resistor(r15);

  std::cout << "V =" << c.get_voltage() << "\n";
  std::cout << "I =" << c.get_current() << "\n";
  std::cout << "R =" << c.get_total_resistance() << "\n";
}