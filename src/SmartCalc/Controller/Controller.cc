#include "Controller.h"

double s21::Controller::Calc_contr(std::string& str, double x) {
    return model_str->start(str, x);
}

bool s21::Controller::Check_string(std::string& str) {
    return model_str->Check_Available_Print(str);
}

bool s21::Controller::Check_string_func(std::string& str) {
    return model_str->Check_Available_Print_Func(str);
}
