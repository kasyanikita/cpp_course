#include <algorithm>
#include <iostream>
#include <vector>

class FunctionPart {
private:
  char operation;
  double value;

public:
  FunctionPart(char new_op, double new_val) {
    operation = new_op;
    value = new_val;
  }
  double Apply(double val) const {
    if (operation == '+') {
      return val + value;
    } else {
      return val - value;
    }
  }
  void Invert() {
    if (operation == '+') {
      operation = '-';
    } else {
      operation = '+';
    }
  }
};

class Function {
public:
  void AddPart(char operation, double x) { parts.push_back({operation, x}); }
  double Apply(double val) const {
    for (const auto &part : parts) {
      val = part.Apply(val);
    }
    return val;
  }
  void Invert() {
    for (auto &part : parts) {
      part.Invert();
    }
    std::reverse(parts.begin(), parts.end());
  }

private:
  std::vector<FunctionPart> parts;
};
