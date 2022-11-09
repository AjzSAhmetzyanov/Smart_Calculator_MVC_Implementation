#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <iostream>
#include "../Model/Model.h"
namespace s21 {
class Controller {
    private:
        Model* model_str = new s21::Model();
    public:
        Controller(){;}
        ~Controller(){;}
        double Calc_contr(std::string str, double x);
        int Check_string(std::string str, size_t x);
        int Check_string_func(std::string str, size_t x);
    };  
}
#endif // CONTROLLER_H_
