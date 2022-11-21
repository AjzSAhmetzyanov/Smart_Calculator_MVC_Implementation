#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "../Model/Model.h"
#include <iostream>
namespace s21 {
class Controller {
private:
  Model *model_str = new s21::Model();

public:
  Controller() { ; }
  ~Controller() { delete model_str; }
  std::pair<double, bool> Calc_contr(std::string &str, double x);
};
} // namespace s21
#endif // CONTROLLER_H_
