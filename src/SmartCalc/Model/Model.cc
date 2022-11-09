#include "Model.h"
using namespace s21;

s21::Model::Model() {;}
s21::Model::~Model() {;}

void s21::Model::parse_lexeme(std::string src, std::list<Stack>& operand, double x) {
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
        } else if (src[i] == 'm' && src[i+1] == 'o' && src[i+2] == 'd') {
            i += 2;
            Stack obj(0, 2, MOD);
            operand.push_back(obj);
        } else if (src[i] == '(') {
            Stack obj(0, -1, LEFT_BR);
        } else if (src[i] == ')') {
            Stack obj(0, -1, RIGHT_BR);
            operand.push_back(obj);
        } else if (src[i] == 'c' && src[i+1] == 'o' && src[i+2] == 's') {
            i += 2;
            Stack obj(0, 4, COS);
            operand.push_back(obj);
        } else if (src[i] == 's' && src[i+1] == 'i' && src[i+2] == 'n') {
            i += 2;
            Stack obj(0, 4, SIN);
            operand.push_back(obj);
        } else if (src[i] == 't' && src[i+1] == 'a' && src[i+2] == 'n') {
            i += 2;
            Stack obj(0, 4, TAN);
            operand.push_back(obj);
        } else if (src[i] == 'a' && src[i+1] == 'c' && src[i+2] == 'o' && src[i+3] == 's') {
            i += 3;
            Stack obj(0, 4, ACOS);
            operand.push_back(obj);
        } else if (src[i] == 'a' && src[i+1] == 's' && src[i+2] == 'i' && src[i+3] == 'n') {
            i += 3;
            Stack obj(0, 4, ASIN);
            operand.push_back(obj);
        } else if (src[i] == 'a' && src[i+1] == 't' && src[i+2] == 'a' && src[i+3] == 'n') {
            i += 3;
            Stack obj(0, 4, ATAN);
            operand.push_back(obj);
        } else if (src[i] == 's' && src[i+1] == 'q' && src[i+2] == 'r' && src[i+3] == 't') {
            i += 3;
            Stack obj(0, 4, SQRT);
            operand.push_back(obj);
        } else if (src[i] == 'l' && src[i+1] == 'n') {
            i += 1;
            Stack obj(0, 4, LN);
            operand.push_back(obj);
        } else if (src[i] == 'l' && src[i+1] == 'o' && src[i+2] == 'g') {
            i += 2;
            Stack obj(0, 4, LOG);
            operand.push_back(obj);
        } else if (src[i] == 'x') {
            Stack obj(x, 0, XXX);
            operand.push_back(obj);
        }
    }
}

void s21::Model::calc_process(std::list<Stack>& main, std::list<Stack>& result) {
    for (auto i : main) {
        if (i.get_oper() == NUMBER || i.get_oper() == XXX) {
            result.push_back(i);
        } else if (i.get_oper() == PLUS) {
            double b = main.back().get_value();
            main.pop_back();
            double res = main.back().get_value() + b;
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == SUB) {
            double b = main.back().get_value();
            main.pop_back();
            double res = main.back().get_value() - b;
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == DIV) {
            double b = main.back().get_value();
            main.pop_back();
            double res = main.back().get_value() / b;
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == MULT) {
            double b = main.back().get_value();
            main.pop_back();
            double res = main.back().get_value() * b;
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper()== POW) {
            double b = main.back().get_value();
            main.pop_back();
            double res = pow(main.back().get_value(), b);
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == MOD) {
            double b = main.back().get_value();
            main.pop_back();
            double res = fmod(main.back().get_value(), b);
            main.pop_back();
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == COS) {
            double b = main.back().get_value();
            main.pop_back();
            double res = cos(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == SIN) {
            double b = main.back().get_value();
            main.pop_back();
            double res = sin(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == TAN) {
            double b = main.back().get_value();
            main.pop_back();
            double res = tan(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == ACOS) {
            double b = main.back().get_value();
            main.pop_back();
            double res = acos(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == ASIN) {
            double b = main.back().get_value();
            main.pop_back();
            double res = asin(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == ATAN) {
            double b = main.back().get_value();
            main.pop_back();
            double res = atan(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == SQRT) {
            double b = main.back().get_value();
            main.pop_back();
            double res = sqrt(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == LN) {
            double b = main.back().get_value();
            main.pop_back();
            double res = log(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        } else if (i.get_oper() == LOG) {
            double b = main.back().get_value();
            main.pop_back();
            double res = log(b);
            Stack obj(res, 0, NUMBER);
            result.push_back(obj);
        }
    }
}


void s21::Model::polish_note(std::list<Stack>& src, std::list<Stack>& main, std::list<Stack>& support) {
    int err = 0;
    auto iter = src.begin();
      auto iter_2 = support.begin();
        while (iter != src.end()) {
            if (!(src.empty())) {
                if (iter->get_oper() == RIGHT_BR) {
                    src.pop_back();
                    while (iter_2->get_oper() != LEFT_BR) {
                        Stack obj(iter_2->get_value(), iter_2->get_priority(), iter_2->get_oper_enum());
                        main.push_back(obj);
                        support.pop_back();
                        iter_2++;
                    }
                    support.pop_back();
                } else {
                    if (iter->get_oper() == NUMBER || iter->get_oper() == XXX) {
                        Stack obj(iter->get_value(), iter->get_priority(), iter->get_oper_enum());
                        main.push_back(obj);
                        src.pop_back();
                    } else {
                        if (iter_2 != support.end()) {
                            if (iter->get_priority() != -1 && iter->get_priority() <= iter_2->get_priority()) {
                                Stack obj(iter_2->get_value(), iter_2->get_priority(), iter_2->get_oper_enum());
                                main.push_back(obj);
                                support.pop_back();
                            }
                        }
                        iter_2++;
                        Stack obj(iter->get_value(), iter->get_priority(), iter->get_oper_enum());                        
                        support.push_back(obj);
                        src.pop_back();
                    }
                }
            }
            if (src.empty() || err) break;
            iter++;
        }
        err = 0;
        if (!support.empty()) {
            while (1) {
                Stack obj(iter_2->get_value(), iter_2->get_priority(), iter_2->get_oper_enum());
                main.push_back(obj);
                support.pop_back();
                if (err || support.empty()) break;
            }
        }
}

double get_value(std::list<Stack>& list_res) {
    auto iter = list_res.begin();
    return iter->get_value();
}
double s21::Model::start(std::string src, double x) {
    std::string new_str;
    double res = 0;
    size_t i = 0;
    if (src.length() < MAX) {
    remove_spaces(src, new_str);
    if (Check_Available_Print(new_str, &i) == 0 && Check_Available_Print_Func(new_str, &i) == 0) {
        std::list<Stack> operand;
        parse_lexeme(new_str, operand, x);
        std::list<Stack> main;
        std::list<Stack> support;
        polish_note(operand, main, support);
        std::list<Stack> result;
        calc_process(support, result);
        res = get_value(result);
    } else {
       printf("incorrect input");
       res = 1.11111111;
    }
    } else {
        printf("unvailable size of input");
        res = 2.22222222;
    }
return res;
}

void s21::Model::remove_spaces(std::string str, std::string new_str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            continue;
        new_str.push_back(str[i]);
    }
}

int s21::Model::Check_Available_Print(std::string src, size_t* count_) {
    int res = FAILURE;
    int flag_brac_1 = 0, flag_brac_2 = 0, flag_float = 0, flag_operand = 0, flag_number = 0;
    if (src.length() < MAX) {
        for (size_t i = *count_; i < src.length(); i++) {
            if (src[i] == '(' && src[i+1] != ')') flag_brac_1++;
            if (src[i] == ')') flag_brac_2++;
            if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '.') {
                if ((src[i+1] == '+' || src[i+1] == '-' || src[i+1] == '*' || src[i+1] == '/'
                     || src[i+1] == '.' || src[i+1] == '^') || (src[i-1] == '+' || src[i-1] == '-' ||
                     src[i-1] == '*' || src[i-1] == '/' || src[i-1] == '.' || src[i-1] == '^')) {
                    flag_operand = 1;
                } else {
                    flag_operand = 0;
                }
            }
            if ((src[i] >= '0' && src[i] <= '9') && (src[i+1] != '.' && src[i-1] != '.') &&
                    (!(src[i-1] >= '0' && src[i-1] <= '9')) && (!(src[i+1] >= '0' && src[i+1] <= '9'))
                    && (src[i+1] != '+' && src[i-1] != '+') && (src[i+1] != '-' && src[i-1] != '-') &&
                    (src[i+1] != '*' && src[i-1] != '*') && (src[i+1] != '/' && src[i-1] != '/') &&
                    (src[i-1] != '^' && src[i+1] != '^') && ((src[i+1] != ')' && src[i-1] != '(') ||
                    ((src[i+1] == ')' && src[i-1] != '(')) || (src[i+1] != ')' && src[i-1] == '('))
                    && (src[i+1] == 'm' && src[i+2] == 'o' && src[i+3] == 'd')) {
                flag_number = 1;
            }
            if (src[i] == '.' && (!(src[i-1] >= '0' && src[i-1] <= '9'))) flag_float = 1;
            if (src[i] >= '0' && src[i] <= '9' && src[i+1] == '.') {
                for (int j = i+2; (src[j] >= '0' && src[j] <= '9') || src[j] == '.'; j++) {
                    if (src[j] == '.') {
                                    flag_float = 1;
                                    break;
                                } else {}
                        }
                }
        }
         if ((flag_brac_1 == flag_brac_2) && (flag_float != 1) && flag_operand == 0 && flag_number == 0) {
        res = SUCCES;
    }
    }

    return res;
}

int s21::Model::Check_Available_Print_Func(std::string src, size_t* count_) {
    size_t flag_sin = 0, flag_cos = 0, flag_tan = 0, flag_asin = 0, flag_acos = 0,
            flag_atan = 0, flag_sqrt = 0, flag_ln = 0, flag_log = 0, flag_mod = 0, flag_brush = 0,
            res = FAILURE;
    if (src.length() <= MAX) {
    for (size_t j = *count_; src[j] != '\0'; j++) {
    if (src[j] == 's' || src[j] == 'c' || src[j] == 't' || src[j] == 'a' || src[j] == 'l' || src[j] == 'm') {
        if (src[j] == 's' && src[j+1] == 'i' && src[j+2] == 'n' && src[j-1] != '(') {
            flag_sin = 1;
            if (src[j+3] == '(') {
                size_t h = j+3;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_sin = 0;
        } else {
            flag_sin = 1;
        }
                     } else {
                                flag_sin = 1;
                            }
           j = j + 3;
    } else if (src[j] == 'c' && src[j+1] == 'o' && src[j+2] == 's' && src[j-1] != '(') {
            if (src[j+3] == '(') {
                flag_cos = 1;
                size_t h = j+3;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_cos = 0;
        } else {
            flag_cos = 1;
        }
            } else {
                flag_cos = 1;
            }
           j = j + 3;
    } else if (src[j] == 't' && src[j+1] == 'a' && src[j+2] == 'n' && src[j-1] != '(') {
            if (src[j+3] == '(') {
                size_t h = j+3;
                flag_tan = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_tan = 0;
        } else {
            flag_tan = 1;
         }
            } else {
                flag_tan = 1;
             }
           j = j + 3;
    } else if (src[j] == 'a' && src[j+1] == 's' && src[j+2] == 'i' && src[j+3] == 'n' && src[j-1] != '(') {
    if (src[j+4] == '(') {
                size_t h = j+4;
                flag_asin = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_asin = 0;
        } else {
               flag_asin = 1;
          }
    } else {
           flag_asin = 1;
      }
            j = j + 4;
    } else if (src[j] == 'a' && src[j+1] == 'c' && src[j+2] == 'o' && src[j+3] == 's' && src[j-1] != '(') {
            if (src[j+4] == '(') {
                size_t h = j+4;
                flag_acos = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_acos = 0;
        } else {
                        flag_acos = 1;
             }
            } else {
                            flag_acos = 1;
                 }
                    j = j + 4;
    } else if (src[j] == 'a' && src[j+1] == 't' && src[j+2] == 'a' && src[j+3] == 'n' && src[j-1] != '(') {
            if (src[j+4] == '(') {
                size_t h = j+4;
                flag_atan = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_atan = 0;
        } else {
                        flag_atan = 1;
                    }
            } else {
                            flag_atan = 1;
                        }
                    j = j + 4;
    } else if (src[j] == 's' && src[j+1] == 'q' && src[j+2] == 'r' && src[j+3] == 't' && src[j-1] != '(') {
            if (src[j+4] == '(') {
                size_t h = j+4;
                flag_sqrt = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_sqrt = 0;
        } else {
                        flag_sqrt = 1;
                    }
            } else {
                            flag_sqrt = 1;
                        }
                    j = j + 4;
    } else if (src[j] == 'l' && src[j+1] == 'n' && src[j-1] != '(') {
            if (src[j+2] == '(') {
                size_t h = j+2;
                flag_ln = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_ln = 0;
            } else {
            flag_ln = 1;
        }
            } else {
            flag_ln = 1;
        }
        j = j + 2;
    } else if (src[j] == 'l' && src[j+1] == 'o' && src[j+2] == 'g' && src[j-1] != '(') {
            if (src[j+3] == '(') {
                size_t h = j+3;
                flag_log = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_log = 0;
            } else {
                flag_log = 1;
               }
        } else {
            flag_log = 1;
           }
            j = j + 3;
        } else if (src[j] == 'm' && src[j+1] == 'o' && src[j+2] == 'd') {
        if ((src[j-1] <= '9' && src[j-1] >= '0') && (src[j+3] <= '9' && src[j+3] >= '0')) {
                size_t h = j+3;
                flag_mod = 1;
                    if (Check_Available_Print(src, &h) == 0) {
                        flag_mod = 0;
            } else {
              flag_mod = 1;
                    }
        } else {
          flag_mod = 1;
                }
                    j = j + 3;
    }
    } else if (src[j] == '(' || src[j] == ')' || (src[j] <= '9' && src[j] >= '0')) {
        flag_brush = 0;
    } else {
        flag_brush = 1;
    }
    }
     if ((flag_sin == 0 && flag_cos == 0 && flag_tan == 0 && flag_sqrt == 0 && flag_acos == 0
     && flag_asin == 0 && flag_atan == 0 && flag_ln == 0 && flag_log == 0 && flag_mod == 0)
     && flag_brush == 0) {
      res = SUCCES;
    }
    }
    return res;
}
