#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "../Model/Model.h"
#include <iostream>
namespace s21 {
class Controller {
    private:
        Controller* cont_str;
        Model* model_str; 
    public:
        Controller();
        ~Controller();
        double Calc_contr(std::string *str);
    };  
}
#endif // CONTROLLER_H_