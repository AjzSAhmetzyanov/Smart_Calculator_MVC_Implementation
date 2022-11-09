#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "../Model/Model.h"
#include <iostream>
namespace s21 {
class Controller {
    private:
        Controller* Controller_input;
        Model* model_str; 
    public:
        Controller();
        ~Controller();
        double Calc_contr(char* str, double x);
        int Check_string(char* str, int x);
        int Check_string_func(char* str, int x);
    };  
}
#endif // CONTROLLER_H_