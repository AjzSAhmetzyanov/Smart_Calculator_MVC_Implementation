#ifndef MODEL_H_
#define MODEL_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#define SUCCES 0
#define FAILURE 1
#define MAX 255
#include <list>
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


class Stack {
  private:
    double value_;
    int priority_;
    value_type oper_;
  public:
    Stack() : value_(0), priority_(0), oper_(XXX) {}
    Stack(double value, int priority, value_type oper) : value_(value), priority_(priority), oper_(oper) {}
    ~Stack() {}
    double get_value() {
      return value_;
    }
    double get_oper() {
      return oper_;
    }
    double get_priority() {
      return priority_;
    }
    value_type get_oper_enum() {
      return oper_;
    }
};

    class Model {
        public:
            Model();
            ~Model();

            int Check_Available_Print_Func(std::string src, size_t* count_);
            int Check_Available_Print(std::string src, size_t* count_);
            double start(std::string str, double x);
            double get_value(std::list<Stack>& list_res);
            void parse_lexeme(std::string src, std::list<Stack>& operand, double x);
            void polish_note(std::list<Stack>& src, std::list<Stack>& main, std::list<Stack>& support);
            void calc_process(std::list<Stack>& main, std::list<Stack>& result);
            void remove_spaces(std::string str, std::string new_str);
};
}
#endif // MODEL_H_f
