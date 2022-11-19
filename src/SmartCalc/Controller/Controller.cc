#include "Controller.h"

std::pair<double, bool> s21::Controller::Calc_contr(std::string& str, double x) {
    return model_str->start(str, x);
}

