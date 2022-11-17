#ifndef MODEL_H_
#define MODEL_H_
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
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
  Stack(double value, int priority, value_type oper)
      : value_(value), priority_(priority), oper_(oper) {}
  ~Stack() {}
  double get_value() { return value_; }
  double get_oper() { return oper_; }
  double get_priority() { return priority_; }
  value_type get_oper_enum() { return oper_; }
};

class Model {
 public:
  Model();
  ~Model();
  void plus_(std::list<Stack>& result);
  void sub_(std::list<Stack>& result);
  void div_(std::list<Stack>& result);
  void mult_(std::list<Stack>& result);
  void pow_(std::list<Stack>& result);
  void mod_(std::list<Stack>& result);
  void cos_(std::list<Stack>& result);
  void sin_(std::list<Stack>& result);
  void tan_(std::list<Stack>& result);
  void acos_(std::list<Stack>& result);
  void asin_(std::list<Stack>& result);
  void atan_(std::list<Stack>& result);
  void sqrt_(std::list<Stack>& result);
  void ln_(std::list<Stack>& result);
  void log_(std::list<Stack>& result);
  bool Check_Available_Print_Func(std::string& src);
  bool Check_Available_Print(std::string& src);
  double start(std::string& str, double x);
  void parse_lexeme(std::string& src, std::list<Stack>& operand, double x);
  void polish_note(std::list<Stack>& operand, std::list<Stack>& main,
                   std::list<Stack>& support);
  void calc_process(std::list<Stack>& main, std::list<Stack>& result);
};
}  // namespace s21
#endif  // MODEL_H_f
