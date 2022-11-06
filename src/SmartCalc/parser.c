#include "check_print.h"

void parse_lexeme(char * src, Stack ** operand, double x) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if ((src[i] >= 48 && src[i] <= 57) || src[i] == '.') {
            char tmp[MAX] = {0};
            int j = 0;
            while ((src[i] >= 48 && src[i] <= 57) || src[i] == '.') {
                tmp[j++] = src[i++];
            }
            i--;
            double tmp_f = atof(tmp);
            push(operand, tmp_f, NUMBER, 0);
        } else if (src[i] == '+') {
            push(operand, 0, PLUS, 1);
        } else if (src[i] == '-') {
            push(operand, 0, SUB, 1);
        } else if (src[i] == '*') {
            push(operand, 0, MULT, 2);
        } else if (src[i] == '/') {
            push(operand, 0, DIV, 2);
        } else if (src[i] == '^') {
            push(operand, 0, POW, 3);
        } else if (src[i] == 'm' && src[i+1] == 'o' && src[i+2] == 'd') {
            i += 2;
            push(operand, 0, MOD, 2);
        } else if (src[i] == '(') {
            push(operand, 0, LEFT_BR, -1);
        } else if (src[i] == ')') {
            push(operand, 0, RIGHT_BR, -1);
        } else if (src[i] == 'c' && src[i+1] == 'o' && src[i+2] == 's') {
            i += 2;
            push(operand, 0, COS, 4);
        } else if (src[i] == 's' && src[i+1] == 'i' && src[i+2] == 'n') {
            i += 2;
            push(operand, 0, SIN, 4);
        } else if (src[i] == 't' && src[i+1] == 'a' && src[i+2] == 'n') {
            i += 2;
            push(operand, 0, TAN, 4);
        } else if (src[i] == 'a' && src[i+1] == 'c' && src[i+2] == 'o' && src[i+3] == 's') {
            i += 3;
            push(operand, 0, ACOS, 4);
        } else if (src[i] == 'a' && src[i+1] == 's' && src[i+2] == 'i' && src[i+3] == 'n') {
            i += 3;
            push(operand, 0, ASIN, 4);
        } else if (src[i] == 'a' && src[i+1] == 't' && src[i+2] == 'a' && src[i+3] == 'n') {
            i += 3;
            push(operand, 0, ATAN, 4);
        } else if (src[i] == 's' && src[i+1] == 'q' && src[i+2] == 'r' && src[i+3] == 't') {
            i += 3;
            push(operand, 0, SQRT, 4);
        } else if (src[i] == 'l' && src[i+1] == 'n') {
            i += 1;
            push(operand, 0, LN, 4);
        } else if (src[i] == 'l' && src[i+1] == 'o' && src[i+2] == 'g') {
            i += 2;
            push(operand, 0, LOG, 4);
        } else if (src[i] == 'x') {
            push(operand, x, XXX, 0);
        }
    }
}

void polish_note(Stack * src, Stack ** main, Stack ** support) {
    int err = 0;
        while (1) {
            if (src) {
                if ((src)-> oper == RIGHT_BR) {
                    pop_back(&src);
                    while ((*support)->oper != LEFT_BR) {
                        push(main, (*support)->value, (*support)->oper, (*support)->priority);
                        pop_back(support);
                    }
                    pop_back(support);
                } else {
                    if ((src)->oper == NUMBER || (src)->oper == XXX) {
                        push(main, (src)->value, (src)->oper, (src)->priority);
                        pop_back(&src);
                    } else {
                        if (*support) {
                            if ((src)->priority != -1 && (src)->priority <= (*support)->priority) {
                                push(main, (*support)->value, (*support)->oper, (*support)->priority);
                                pop_back(support);
                            }
                        }
                        push(support, (src)->value, (src)->oper, (src)->priority);
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
                push(main, (*support)->value, (*support)->oper, (*support)->priority);
                pop_back(support);
                if (err || !*support) break;
                if (!(*support)->next) err++;
            }
        }
}

void calc_process(Stack ** main, Stack ** result) {
    while ((*main) != NULL) {
        if ((*main)->oper == NUMBER || (*main)->oper == XXX) {
            push(result, (*main)->value, (*main)->oper, (*main)->priority);
        } else if ((*main)->oper == PLUS) {
            double b = pop_num(result);
            double res = pop_num(result) + b;
            push(result, res, 0, 0);
        } else if ((*main)->oper == SUB) {
            double b = pop_num(result);
            double res = pop_num(result) - b;
            push(result, res, 0, 0);
        } else if ((*main)->oper == DIV) {
            double b = pop_num(result);
            double res = pop_num(result) / b;
            push(result, res, 0, 0);
        } else if ((*main)->oper == MULT) {
            double b = pop_num(result);
            double res = pop_num(result) * b;
            push(result, res, 0, 0);
        } else if ((*main)->oper == POW) {
            double b = pop_num(result);
            double res = pow(pop_num(result), b);
            push(result, res, 0, 0);
        } else if ((*main)->oper == MOD) {
            double b = pop_num(result);
            double res = fmod(pop_num(result), b);
            push(result, res, 0, 0);
        } else if ((*main)->oper == COS) {
            push(result, cos(pop_num(result)), 0, 0);
        } else if ((*main)->oper == SIN) {
            push(result, sin(pop_num(result)), 0, 0);
        } else if ((*main)->oper == TAN) {
            push(result, tan(pop_num(result)), 0, 0);
        } else if ((*main)->oper == ACOS) {
            push(result, acos(pop_num(result)), 0, 0);
        } else if ((*main)->oper == ASIN) {
            push(result, asin(pop_num(result)), 0, 0);
        } else if ((*main)->oper == ATAN) {
            push(result, atan(pop_num(result)), 0, 0);
        } else if ((*main)->oper == SQRT) {
            push(result, sqrt(pop_num(result)), 0, 0);
        } else if ((*main)->oper == LN) {
            push(result, log(pop_num(result)), 0, 0);
        } else if ((*main)->oper == LOG) {
            push(result, log10(pop_num(result)), 0, 0);
        }
        Stack * tmp = (*main);
        (*main) = (*main)->next;
        free(tmp);
    }
}

double start(char *src, double x) {
    char new_str[MAX] = {0};
    double res = 0;
    int i = 0;
    if (strlen(src) < MAX) {
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
