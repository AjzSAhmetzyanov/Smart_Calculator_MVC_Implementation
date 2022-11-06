#include "check_print.h"
int Check_Available_Print(char *src, int *n) {
    int res = FAILURE, len = strlen(src);
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

int Check_Available_Print_Func(char *src, int *i) {
    int len = strlen(src), flag_sin = 0, flag_cos = 0, flag_tan = 0, flag_asin = 0, flag_acos = 0,
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
