#include "Model.h"

#include <algorithm>
using namespace s21;

s21::Model::Model() { ; }
s21::Model::~Model() { ; }

void s21::Model::parse_lexeme(std::string& src, std::list<Stack>& operand,
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

void s21::Model::plus_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() + b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::sub_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() - b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::div_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() / b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::mult_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = result.back().get_value() * b;
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::pow_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = pow((result.back().get_value()), b);
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::mod_(std::list<Stack>& result) {
  double b = result.back().get_value();
  result.pop_back();
  double res = fmod(result.back().get_value(), b);
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::cos_(std::list<Stack>& result) {
  double res = std::cos(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::sin_(std::list<Stack>& result) {
  double res = std::sin(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::tan_(std::list<Stack>& result) {
  double res = std::tan(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::acos_(std::list<Stack>& result) {
  double res = std::acos(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::asin_(std::list<Stack>& result) {
  double res = std::asin(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::atan_(std::list<Stack>& result) {
  double res = std::atan(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::sqrt_(std::list<Stack>& result) {
  double res = std::sqrt(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::ln_(std::list<Stack>& result) {
  double res = std::log(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::log_(std::list<Stack>& result) {
  double res = std::log(result.back().get_value());
  result.pop_back();
  Stack obj(res, 0, NUMBER);
  result.push_back(obj);
}

void s21::Model::calc_process(std::list<Stack>& main,
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
      cos_(result);
    } else if (i.get_oper() == SIN) {
      sin_(result);
    } else if (i.get_oper() == TAN) {
      tan_(result);
    } else if (i.get_oper() == ACOS) {
      acos_(result);
    } else if (i.get_oper() == ASIN) {
      asin_(result);
    } else if (i.get_oper() == ATAN) {
      atan_(result);
    } else if (i.get_oper() == SQRT) {
      sqrt_(result);
    } else if (i.get_oper() == LN) {
      ln_(result);
    } else if (i.get_oper() == LOG) {
      log_(result);
    }
  }
}

void s21::Model::polish_note(std::list<Stack>& operand, std::list<Stack>& main,
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

void s21::Model::check_unary_minus(std::string& str) {
  if ((*str.begin()) == '-') {
    std::string str_1 = "0-";
    str.replace(str.find('-'), 1, str_1);
  }
  std::string str_1 = "(-";
  std::string str_2 = "0";
  size_t iter = str.find(str_1);
  while (iter != std::string::npos) {
    str.insert(iter + 1, str_2);
    iter = str.find(str_1);
    continue;
  };
}

bool s21::Model::fix_e(std::string& str) {
  bool res = true;
  std::string str_1 = "e-";
  std::string str_2 = "/10^";
  std::string str_1_ = "e+";
  std::string str_2_ = "*10^";
  auto iter = str.find("e");
  while (iter != std::string::npos) {
    if (str.find(str_1) != std::string::npos) {
      str.replace(str.find(str_1), str_1.size(), str_2);
    }
    else if (str.find(str_1_) != std::string::npos) {
      str.replace(str.find(str_1_), str_1_.size(), str_2_);
    } else {
      res = false;
      break;
    }
    iter = str.find("e");
    continue;
  }
  return res;
}

std::pair<double, bool> s21::Model::start(std::string& str, double x) {
  std::pair<double, bool> res = { 0, true };
  for (auto iter : str) {
    if (iter == 'e') fix_e(str);
    if (!fix_e(str)) res.second = false;
  }
  check_unary_minus(str);
  if ((Check_Available_Print(str) == 1) &&
      (Check_Available_Print_Func(str) == 1)) {
    std::list<Stack> operand;
    parse_lexeme(str, operand, x);
    std::list<Stack> main;
    std::list<Stack> support;
    polish_note(operand, main, support);
    std::list<Stack> result;
    calc_process(main, result);
    res.first = result.back().get_value();
  } else {
    res.second = false;
  }
  return res;
}

bool s21::Model::Check_Available_Print(std::string& src) {
  bool number_ = true, operand_ = true, brackets_ = true, num_oper = true, res = false;
  for (size_t i = 0; i < src.size(); i++) {
    if ((src[i] >= '0' && src[i] <= '9')) {
        size_t count_ = 0;
        for (size_t j = i; (src[j] >= '0' && src[j] <= '9') || (src[j] == '.');
             j++) {
          if (src[j] == '.') count_++;
        }
        if (count_ > 1) number_ = false;
      } else {
    if ((src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' ||
         src[i] == '^' || src[i] == '.') &&
        (src[i + 1] == '+' || src[i + 1] == '-' || src[i + 1] == '*' ||
         src[i + 1] == '/' || src[i + 1] == '^' || src[i + 1] == '.' || src[i + 1] == '\0'))
      operand_ = false;
    if ((src[i] == '.') && (!(src[i + 1] >= '0' && src[i + 1] <= '9')))
      operand_ = false;
    if ((src[i] == '(') &&
        (src[i + 1] == '+' || src[i + 1] == '*' || src[i + 1] == '/' ||
         src[i + 1] == '^' || src[i + 1] == '.'))
      operand_ = false;
    if ((src[i] == ')') &&
        (src[i - 1] == '+' || src[i - 1] == '-' || src[i - 1] == '*' ||
         src[i - 1] == '/' || src[i - 1] == '^' || src[i - 1] == '.'))
      operand_ = false;
      }
    if ((src[i] >= '0' && src[i] <= '9') && (!(src[i+1] == '+' || src[i+1] == '-' || src[i+1] == '*' || src[i+1] == '/' ||
         src[i+1] == '^' || src[i+1] == '.' || src[i+1] == '\0' || src[i+1] == ')' || (src[i+1] >= '0' && src[i+1] <= '9')))) num_oper = false;
    if (!(std::count(src.begin(), src.end(), '(') ==
        std::count(src.begin(), src.end(), ')'))) brackets_ = false;
        else brackets_ = true;
    }
     if ((src.find(')')) == (src.find('(') + 1) || (src.find('(')) == (src.find(')') + 1)) brackets_ = false;
     if (number_ && operand_ && brackets_ && num_oper) res = true;
     return res;
}

bool s21::Model::Check_Available_Print_Func(std::string& src) {
  bool res = true;
  for (size_t i = 0; i < src.size(); i++) {
    if (src[i] == 's' || src[i] == 'c' || src[i] == 't' || src[i] == 'a' ||
        src[i] == 'l' || src[i] == 'm') {
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 's' && src[i + 1] == 'i' && src[i + 2] == 'n')) {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 3] == '(') res = true;
      }
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 'c' && src[i + 1] == 'o' && src[i + 2] == 's')) {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 3] == '(') res = true;
      }
      if ((src[i - 1] != 'a' && src[i - 1] != ')') &&
          (src[i] == 't' && src[i + 1] == 'a' && src[i + 2] == 'n')) {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 3] == '(') res = true;
      }
      if (src[i - 1] != ')' && (src[i] == 'a') &&
          src[i + 1] == 's' && src[i + 2] == 'i' && src[i + 3] == 'n') {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 4] == '(') res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'a') &&
          (src[i + 1] == 'c' && src[i + 2] == 'o' && src[i + 3] == 's')) {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 4] == '(') res = true;
      }
      if (((src[i - 1] != ')') && (src[i] == 'a')) &&
          ((src[i + 1] == 't' && src[i + 2] == 'a' && src[i + 3] == 'n'))) {
           res = false;
        if (Check_Available_Print(src) == 1 && src[i + 4] == '(') res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 's') &&
          (src[i + 1] == 'q' && src[i + 2] == 'r' && src[i + 3] == 't')) {
           res = false;
        if (Check_Available_Print(src) == 1  && src[i + 4] == '(') res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'l') &&
          (src[i + 1] == 'o' && src[i + 2] == 'g')) {
          res = false;
          if (Check_Available_Print(src) == 1  && src[i + 3] == '(') res = true;
      }
      if ((src[i - 1] != ')') && (src[i] == 'l') && (src[i + 1] == 'n')) {
           res = false;
          if (Check_Available_Print(src) == 1  && src[i + 2] == '(') res = true;
      }
      if ((src[i] == 'm' && src[i + 1] == 'o' && src[i + 2] == 'd')) {
           res = false;
          if (Check_Available_Print(src) == 1 && (src[i - 1] >= '0' && src[i - 1] <= '9') &&
         (((src[i + 3] >= '0' && src[i + 3] <= '9')) || (src[i + 3] == '('))) res = true;
      }
    }
  }
  return res;
}
