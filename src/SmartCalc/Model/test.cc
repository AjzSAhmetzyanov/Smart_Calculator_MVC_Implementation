#include <iostream>
#include <algorithm>
#include <cmath>
#define SUCCES 0
#define FAILURE 1
#define MAX 255
#include <list>
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

void   parse_lexeme(std::string src, std::list<Stack>& operand,
                              double x) {
  for (size_t i = 0; i < src.length(); i++) {
    if ((src[i] >= '0' && src[i] <= '9') || src[i] == '.') {
      std::string tmp;
      size_t j = 0;
      while ((src[i] >= '0' && src[i] <= '9') || src[i] == '.') {
        tmp[j++] = src[i++];
      }
      i--;
      double tmp_f = stod(tmp);
      Stack obj(tmp_f, 0, NUMBER);
      operand.push_back(obj);
    } else if (src[i] == '+') {
      Stack obj(0, 1, PLUS);
      operand.push_back(obj);
    } else if (src[i] == '-') {
      Stack obj(0, 1, SUB);
      operand.push_back(obj);
    } else if (src[i] == '*') {
      Stack obj(0, 2, MULT);
      operand.push_back(obj);
    } else if (src[i] == '/') {
      Stack obj(0, 2, DIV);
      operand.push_back(obj);
    } else if (src[i] == '^') {
      Stack obj(0, 3, POW);
      operand.push_back(obj);
    } else if (src[i] == 'm' && src[i + 1] == 'o' && src[i + 2] == 'd') {
      i += 2;
      Stack obj(0, 2, MOD);
      operand.push_back(obj);
    } else if (src[i] == '(') {
      Stack obj(0, -1, LEFT_BR);
      operand.push_back((obj));
    } else if (src[i] == ')') {
      Stack obj(0, -1, RIGHT_BR);
      operand.push_back(obj);
    } else if (src[i] == 'c' && src[i + 1] == 'o' && src[i + 2] == 's') {
      i += 2;
      Stack obj(0, 4, COS);
      operand.push_back(obj);
    } else if (src[i] == 's' && src[i + 1] == 'i' && src[i + 2] == 'n') {
      i += 2;
      Stack obj(0, 4, SIN);
      operand.push_back(obj);
    } else if (src[i] == 't' && src[i + 1] == 'a' && src[i + 2] == 'n') {
      i += 2;
      Stack obj(0, 4, TAN);
      operand.push_back(obj);
    } else if (src[i] == 'a' && src[i + 1] == 'c' && src[i + 2] == 'o' &&
               src[i + 3] == 's') {
      i += 3;
      Stack obj(0, 4, ACOS);
      operand.push_back(obj);
    } else if (src[i] == 'a' && src[i + 1] == 's' && src[i + 2] == 'i' &&
               src[i + 3] == 'n') {
      i += 3;
      Stack obj(0, 4, ASIN);
      operand.push_back(obj);
    } else if (src[i] == 'a' && src[i + 1] == 't' && src[i + 2] == 'a' &&
               src[i + 3] == 'n') {
      i += 3;
      Stack obj(0, 4, ATAN);
      operand.push_back(obj);
    } else if (src[i] == 's' && src[i + 1] == 'q' && src[i + 2] == 'r' &&
               src[i + 3] == 't') {
      i += 3;
      Stack obj(0, 4, SQRT);
      operand.push_back(obj);
    } else if (src[i] == 'l' && src[i + 1] == 'n') {
      i += 1;
      Stack obj(0, 4, LN);
      operand.push_back(obj);
    } else if (src[i] == 'l' && src[i + 1] == 'o' && src[i + 2] == 'g') {
      i += 2;
      Stack obj(0, 4, LOG);
      operand.push_back(obj);
    } else if (src[i] == 'x') {
      Stack obj(x, 0, XXX);
      operand.push_back(obj);
    }
  }
}

void   plus_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() + b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   sub_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() - b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   div_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() / b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   mult_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() * b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   pow_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = pow((result.back().get_value()), b);
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   mod_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = fmod(result.back().get_value(), b);
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   cos_(std::list<Stack>& main, std::list<Stack>& result) {
 double res = std::cos(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   sin_(std::list<Stack>& main, std::list<Stack>& result) {
  double res = std::sin(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   tan_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::tan(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   acos_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::acos(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   asin_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::asin(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   atan_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::atan(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   sqrt_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::sqrt(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void   ln_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::log(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void log_(std::list<Stack>& main, std::list<Stack>& result) {
double res = std::log(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void calc_process(std::list<Stack>& main,
                              std::list<Stack>& result) {
  for (auto i : main) {
    if ((i.get_oper() == NUMBER || i.get_oper() == XXX)) {
      result.push_back(i);
    } else if (i.get_oper() == PLUS) {
      plus_(result);
    } else if (i.get_oper() == SUB) {
      sub_(result);
    } else if (i.get_oper() == DIV) {
      div_(result);
    } else if (i.get_oper() == MULT) {
      mult_(result);
    } else if (i.get_oper() == POW) {
      pow_(result);
    } else if (i.get_oper() == MOD) {
      mod_(result);
    } else if (i.get_oper() == COS) {
      cos_(main, result);
    } else if (i.get_oper() == SIN) {
      sin_(main, result);
    } else if (i.get_oper() == TAN) {
      tan_(main, result);
    } else if (i.get_oper() == ACOS) {
      acos_(main, result);
    } else if (i.get_oper() == ASIN) {
      asin_(main, result);
    } else if (i.get_oper() == ATAN) {
      atan_(main, result);
    } else if (i.get_oper() == SQRT) {
      sqrt_(main, result);
    } else if (i.get_oper() == LN) {
      ln_(main, result);
    } else if (i.get_oper() == LOG) {
      log_(main, result);
    }
  }
}

void polish_note(std::list<Stack>& operand, std::list<Stack>& main,
                             std::list<Stack>& support) {
  if (!operand.empty()) {
    for (auto iter_operand : operand) {
      if (iter_operand.get_oper() == NUMBER || iter_operand.get_oper() == XXX) {
        main.push_back(iter_operand);
      } else {
        if (support.empty()) {
          support.push_back(iter_operand);
        } else {
          if (iter_operand.get_oper() == RIGHT_BR) {
            while (support.back().get_oper() != LEFT_BR) {
              main.push_back(support.back());
              support.pop_back();
            }
            support.pop_back();
          } else {
          if (iter_operand.get_priority() <= support.back().get_priority() &&
              iter_operand.get_oper() != LEFT_BR) {
            main.push_back(support.back());
            if (!support.empty()) {
              support.pop_back();
            }
            support.push_back(iter_operand);
          } else {
            if ((iter_operand.get_oper() != RIGHT_BR)) {
              support.push_back(iter_operand);
            }
          }
        }
      }
      }
    }
    while (!support.empty()) {
      main.push_back(support.back());
      support.pop_back();
    }
  }
}

double start(std::string str, double x) {
  std::string new_str;
  double res = 0;
  std::list<Stack> operand;
  parse_lexeme(str, operand, x);
  std::list<Stack> main;
  std::list<Stack> support;
  polish_note(operand, main, support);
  std::list<Stack> result;
  calc_process(main, result);
  res = result.back().get_value();
  return res;
}

bool Check_Available_Print(std::string src) {
  bool res = false;
  if (std::count(src.begin(), src.end(), '(') ==
      std::count(src.begin(), src.end(), ')'))
    res = true;
  for (size_t i = 0; i < src.size(); i++) {
    if ((src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' ||
         src[i] == '^' || src[i] == '.') &&
        (src[i + 1] == '+' || src[i + 1] == '-' || src[i + 1] == '*' ||
         src[i + 1] == '/' || src[i + 1] == '^' || src[i + 1] == '.'))
      res = false;
    if ((src[i] == '.') && (!(src[i + 1] >= '0' && src[i + 1] <= '9')))
      res = false;
    if ((src[i] == '(') &&
        (src[i + 1] == '+' || src[i + 1] == '*' || src[i + 1] == '/' ||
         src[i + 1] == '^' || src[i + 1] == '.' || src[i + 1] == ')'))
      res = false;
    if ((src[i] == ')') &&
        (src[i - 1] == '+' || src[i - 1] == '-' || src[i - 1] == '*' ||
         src[i - 1] == '/' || src[i - 1] == '^' || src[i - 1] == '.' ||
         src[i + 1] == '('))
      res = false;
    if ((src[i] >= '0' && src[i] <= '9')) {
      size_t count_ = 0;
      for (size_t j = i; (src[j] >= '0' && src[j] <= '9') || (src[j] == '.');
           j++) {
        if (src[j] == '.') count_++;
      }
      if (count_ > 1) res = false;
    }
  }
  return res;
}

bool Check_Available_Print_Func(std::string src) {
  bool res = false;
  for (size_t i = 0; i < src.size(); i++) {
    if (src[i] == 's' || src[i] == 'c' || src[i] == 't' || src[i] == 'a' ||
        src[i] == 'l' || src[i] == 'm') {
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 's' && src[i + 1] == 'i' && src[i + 2] == 'n' &&
           src[i + 3] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 'c' && src[i + 1] == 'o' && src[i + 2] == 's' &&
           src[i + 3] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 't' && src[i + 1] == 'a' && src[i + 2] == 'n' &&
           src[i + 3] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'a') &&
          (src[i + 1] == 's' && src[i + 2] == 'i' && src[i + 3] == 'n' &&
           src[i + 4] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'a') &&
          (src[i + 1] == 'c' && src[i + 2] == 'o' && src[i + 3] == 's' &&
           src[i + 4] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'a') &&
          (src[i + 1] == 't' && src[i + 2] == 'a' && src[i + 3] == 'n' &&
           src[i + 4] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 's') &&
          (src[i + 1] == 'q' && src[i + 2] == 'r' && src[i + 3] == 't' &&
           src[i + 4] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'l') &&
          (src[i + 1] == 'o' && src[i + 2] == 'g' && src[i + 3] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'l') &&
          (src[i + 1] == 'n' && src[i + 2] == '(')) {
        if (Check_Available_Print(src) == 1) res = true;
      }
      if ((src[i - 1] >= '0' && src[i - 1] <= '9') &&
          (src[i] == 'm' && src[i + 1] == 'o' && src[i + 2] == 'd') &&
          (((src[i + 3] >= '0' && src[i + 3] <= '9')) || (src[i + 3] == '('))) {
        if (Check_Available_Print(src) == 1) res = true;
      }
    }
  }
  return res;
}


int main() {
    std::string str = "sin(3)+2+cos(3-2*2)/2223w435w52";
    double res = start(str, 0);
    std::cout << res << std::endl;
    return 0;
}