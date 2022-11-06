#include "check_print.h"

void push(Stack ** list, double data, value_type oper, int priority) {
    Stack *tmp = malloc(sizeof(Stack));
        tmp->value = data;
        tmp->priority = priority;
        tmp->oper = oper;
        tmp->next = *list;
        *list = tmp;
}
void remove_spaces(char * str, char * new_str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ')
            continue;
        *new_str++ = str[i];
    }
}

void reverse_stack(Stack * src , Stack ** dst) {
    while (src != NULL) {
        push(dst, src->value, src->oper, src->priority);
        src = src->next;
    }
}
Stack pop_back(Stack ** head) {
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

double pop_num(Stack ** main) {
    double result = 0;
    if ((*main) != NULL) {
        Stack * tmp = (*main);
        result = (*main)->value;
        (*main) = (*main)->next;
        free(tmp);
    }
    return result;
}
