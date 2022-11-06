#include "Controller.h"

s21::Controller::Controller() {
    cont_str = new Controller;
}

s21::Controller::~Controller() {
    delete cont_str;
}

double s21::Controller::Calc_contr(std::string *str) {
    return model_str->Calc_model(str);
}
