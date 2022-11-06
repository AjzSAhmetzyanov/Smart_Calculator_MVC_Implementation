#ifndef MODEL_H_
#define MODEL_H_
#include <iostream>
#include "../Controller/Controller.h"
#include <string>
#include <stdlib.h>
#include <cmath>
#define SUCCES 0
#define FAILURE 1
#define MAX 255

namespace s21 {
typedef enum {
    XXX = 0,
    NUMBER = 1,
    PLUS = 2,
    SUB = 3,
    MULT = 4,
    DIV = 5,
    MOD = 6,
    POW = 7,
    SIN = 8,
    COS = 9,
    TAN = 10,
    ACOS = 11,
    ASIN = 12,
    ATAN = 13,
    SQRT = 14,
    LN = 15,
    LOG = 16,
    LEFT_BR = 17,
    RIGHT_BR = 18
} value_type;


struct Stack {
    double value;
    int priority;
    value_type oper;
    struct Stack *next;
};

    class Model {
        private:
            Model* model_cal;
            Controller* cont_cal;
        public:
            Model();
            ~Model();
            
            double Calc_model(std::string *str);
            int Check_Available_Print_Func(std::string *src, int *i);
            int Check_Available_Print(std::string *src, int *i);
            void push(Stack ** list, double data, value_type oper, int priority);
            void reverse_stack(Stack * src , Stack ** dst);
            Stack pop_back(Stack ** head);
            double pop_num(Stack ** main);
            double start(std::string * str, double x);
            void parse_lexeme(std::string * src, Stack ** operand, double x);
            void polish_note(Stack * src, Stack ** main, Stack ** support);
            void calc_process(Stack ** main, Stack ** result);
            void remove_spaces(std::string * str, std::string * new_str);
            int Check_Available_Print(std::string *src, int *n);
            int Check_Available_Print_Func(std::string *src, int *i);
    };
}
#endif // MODEL_H_