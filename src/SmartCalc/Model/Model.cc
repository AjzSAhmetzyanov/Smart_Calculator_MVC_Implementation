#include "Model.h"
using namespace s21;

s21::Model::Model() {
    //model_cal = new Model;
}
s21::Model::~Model() {
 //   delete model_cal;
}

void s21::Model::parse_lexeme(char *src, Stack ** operand, double x) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if ((src[i] >= '0' && src[i] <= '9') || src[i] == '.') {
            char tmp[MAX] = {' '};
            int j = 0;
            while ((src[i] >= '0' && src[i] <= '9') || src[i] == '.') {
                tmp[j++] = src[i++];
            }
            i--;
            double tmp_f = atof(tmp);
            push_back(operand, tmp_f, NUMBER, 0);
        } else if (src[i] == '+') {
            push_back(operand, 0, PLUS, 1);
        } else if (src[i] == '-') {
            push_back(operand, 0, SUB, 1);
        } else if (src[i] == '*') {
            push_back(operand, 0, MULT, 2);
        } else if (src[i] == '/') {
            push_back(operand, 0, DIV, 2);
        } else if (src[i] == '^') {
            push_back(operand, 0, POW, 3);
        } else if (src[i] == 'm' && src[i+1] == 'o' && src[i+2] == 'd') {
            i += 2;
            push_back(operand, 0, MOD, 2);
        } else if (src[i] == '(') {
            push_back(operand, 0, LEFT_BR, -1);
        } else if (src[i] == ')') {
            push_back(operand, 0, RIGHT_BR, -1);
        } else if (src[i] == 'c' && src[i+1] == 'o' && src[i+2] == 's') {
            i += 2;
            push_back(operand, 0, COS, 4);
        } else if (src[i] == 's' && src[i+1] == 'i' && src[i+2] == 'n') {
            i += 2;
            push_back(operand, 0, SIN, 4);
        } else if (src[i] == 't' && src[i+1] == 'a' && src[i+2] == 'n') {
            i += 2;
            push_back(operand, 0, TAN, 4);
        } else if (src[i] == 'a' && src[i+1] == 'c' && src[i+2] == 'o' && src[i+3] == 's') {
            i += 3;
            push_back(operand, 0, ACOS, 4);
        } else if (src[i] == 'a' && src[i+1] == 's' && src[i+2] == 'i' && src[i+3] == 'n') {
            i += 3;
            push_back(operand, 0, ASIN, 4);
        } else if (src[i] == 'a' && src[i+1] == 't' && src[i+2] == 'a' && src[i+3] == 'n') {
            i += 3;
            push_back(operand, 0, ATAN, 4);
        } else if (src[i] == 's' && src[i+1] == 'q' && src[i+2] == 'r' && src[i+3] == 't') {
            i += 3;
            push_back(operand, 0, SQRT, 4);
        } else if (src[i] == 'l' && src[i+1] == 'n') {
            i += 1;
            push_back(operand, 0, LN, 4);
        } else if (src[i] == 'l' && src[i+1] == 'o' && src[i+2] == 'g') {
            i += 2;
            push_back(operand, 0, LOG, 4);
        } else if (src[i] == 'x') {
            push_back(operand, x, XXX, 0);
        }
    }
}

void s21::Model::polish_note(Stack * src, Stack ** main, Stack ** support) {
    int err = 0;
        while (1) {
            if (src) {
                if ((src)-> oper == RIGHT_BR) {
                    pop_back(&src);
                    while ((*support)->oper != LEFT_BR) {
                        push_back(main, (*support)->value, (*support)->oper, (*support)->priority);
                        pop_back(support);
                    }
                    pop_back(support);
                } else {
                    if ((src)->oper == NUMBER || (src)->oper == XXX) {
                        push_back(main, (src)->value, (src)->oper, (src)->priority);
                        pop_back(&src);
                    } else {
                        if (*support) {
                            if ((src)->priority != -1 && (src)->priority <= (*support)->priority) {
                                push_back(main, (*support)->value, (*support)->oper, (*support)->priority);
                                pop_back(support);
                            }
                        }
                        push_back(support, (src)->value, (src)->oper, (src)->priority);
                        pop_back(&src);
                    }
                }
            }
            if (!src || err) break;
            if (!(src)->next) err++;
        }
        err = 0;
        if (*support) {
            while (1) {
                push_back(main, (*support)->value, (*support)->oper, (*support)->priority);
                pop_back(support);
                if (err || !*support) break;
                if (!(*support)->next) err++;
            }
        }
}

void s21::Model::calc_process(Stack ** main, Stack ** result) {
    while ((*main) != NULL) {
        if ((*main)->oper == NUMBER || (*main)->oper == XXX) {
            push_back(result, (*main)->value, (*main)->oper, (*main)->priority);
        } else if ((*main)->oper == PLUS) {
            double b = pop_num(result);
            double res = pop_num(result) + b;
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == SUB) {
            double b = pop_num(result);
            double res = pop_num(result) - b;
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == DIV) {
            double b = pop_num(result);
            double res = pop_num(result) / b;
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == MULT) {
            double b = pop_num(result);
            double res = pop_num(result) * b;
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == POW) {
            double b = pop_num(result);
            double res = pow(pop_num(result), b);
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == MOD) {
            double b = pop_num(result);
            double res = fmod(pop_num(result), b);
            push_back(result, res, XXX, 0);
        } else if ((*main)->oper == COS) {
            push_back(result, cos(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == SIN) {
            push_back(result, sin(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == TAN) {
            push_back(result, tan(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == ACOS) {
            push_back(result, acos(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == ASIN) {
            push_back(result, asin(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == ATAN) {
            push_back(result, atan(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == SQRT) {
            push_back(result, sqrt(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == LN) {
            push_back(result, log(pop_num(result)), XXX, 0);
        } else if ((*main)->oper == LOG) {
            push_back(result, log10(pop_num(result)), XXX, 0);
        }
        Stack * tmp = (*main);
        (*main) = (*main)->next;
        free(tmp);
    }
}

double s21::Model::start(char *src, double x) {
    char new_str[MAX] = {0};
    double res = 0;
    int i = 0;
    size_t len = strlen(src);
    if (len < MAX) {
    remove_spaces(src, new_str);
    if (Check_Available_Print(new_str, &i) == 0 && Check_Available_Print_Func(new_str, &i) == 0) {
        Stack * operand = NULL;
        parse_lexeme(new_str, &operand, x);
        Stack * reversed = NULL;
        reverse_stack(operand, &reversed);
        Stack * main = NULL;
        Stack * support = NULL;
        polish_note(reversed, &main, &support);
        Stack *calculate = NULL;
        Stack *result = NULL;
        reverse_stack(main, &calculate);
        calc_process(&calculate, &result);
        res = result->value;
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

void s21::Model::push_back(Stack ** list, double data, value_type oper, int priority) {
    Stack *tmp = new Stack;
        tmp->value = data;
        tmp->priority = priority;
        tmp->oper = oper;
        tmp->next = *list;
        *list = tmp;
}
void s21::Model::remove_spaces(char * str, char * new_str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ')
            continue;
        *new_str++ = str[i];
    }
}

void s21::Model::reverse_stack(Stack * src , Stack ** dst) {
    while (src != NULL) {
        push_back(dst, src->value, src->oper, src->priority);
        src = src->next;
    }
}
s21::Stack s21::Model::pop_back(Stack ** head) {
    Stack * last = NULL;
    Stack tmp = {0};
    last = (*head);
    tmp.value = last->value;
    tmp.priority = last->priority;
    tmp.oper = last->oper;
    (*head) = (*head)->next; 
    free(last);
    return tmp;
}

double s21::Model::pop_num(Stack ** main) {
    double result = 0;
    if ((*main) != NULL) {
        Stack * tmp = (*main);
        result = (*main)->value;
        (*main) = (*main)->next;
        free(tmp);
    }
    return result;
}

int s21::Model::Check_Available_Print(char *src, int *n) {
    int res = FAILURE;
    size_t len = strlen(src);
    int flag_brac_1 = 0, flag_brac_2 = 0, flag_float = 0, flag_operand = 0, flag_number = 0;
    if (len < MAX) {
        for (int i = *n; i < len; i++) {
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

int s21::Model::Check_Available_Print_Func(char *src, int *i) {
    size_t len = strlen(src), flag_sin = 0, flag_cos = 0, flag_tan = 0, flag_asin = 0, flag_acos = 0,
            flag_atan = 0, flag_sqrt = 0, flag_ln = 0, flag_log = 0, flag_mod = 0, flag_brush = 0,
            res = FAILURE;
    if (len <= MAX) {
    for (int j = *i; src[j] != '\0'; j++) {
    if (src[j] == 's' || src[j] == 'c' || src[j] == 't' || src[j] == 'a' || src[j] == 'l' || src[j] == 'm') {
        if (src[j] == 's' && src[j+1] == 'i' && src[j+2] == 'n' && src[j-1] != '(') {
            flag_sin = 1;
            if (src[j+3] == '(') {
                int h = j+3;
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
                int h = j+3;
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
                int h = j+3;
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
                int h = j+4;
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
                int h = j+4;
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
                int h = j+4;
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
                int h = j+4;
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
                int h = j+2;
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
                int h = j+3;
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
                int h = j+3;
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
