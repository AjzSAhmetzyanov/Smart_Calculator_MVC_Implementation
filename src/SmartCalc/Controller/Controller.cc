#include "Controller.h"

//s21::Controller::Controller() {
//    Controller_input = new Controller;
//}

//s21::Controller::~Controller() {
//    delete Controller_input;
//}

double s21::Controller::Calc_contr(char* str, double x) {
    return model_str->start(str, x);
}

int s21::Controller::Check_string(char* str, int x) {
    return model_str->Check_Available_Print(str, &x);
}

int s21::Controller::Check_string_func(char* str, int x) {
    return model_str->Check_Available_Print_Func(str, &x);
}
