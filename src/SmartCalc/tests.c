#include "check_print.h"
#include <check.h>

START_TEST(test_1) {
    double a = start("2^6", 0);
    double b = pow(2, 6);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_2) {
    double a = fabs(start("cos(x)", 10));
    double b = fabs(cos(10));
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_3) {
    double a = fabs(start("sin(x)", 10));
    double b = fabs(sin(10));
    ck_assert_double_eq_tol(a, b, 1e-7);
}
END_TEST

START_TEST(test_4) {
    double a = start("2+(3*(1-2))", 0);
    double b = 2+(3*(1-2));
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_5) {
    double a = start("ln(5)", 0);
    double b = log(5);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_6) {
    double a = start("   log(5)", 0);
    double b = log10(5);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_7) {
    double a = start("10 mod 2", 0);
    double b = 10 % 2;
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_8) {
    double a = start("sqrt(4)", 0);
    double b = sqrt(4);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_9) {
    double a = start("tan(3)", 0);
    double b = tan(3);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_10) {
    double a = start("atan(0)", 0);
    double b = atan(0);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_11) {
    double a = start("acos(1)", 0);
    double b = acos(1);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_12) {
    double a = start("asin(1)", 0);
    double b = asin(1);
    ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_13) {
    double a = start("1.2546-0.5", 0);
    double b = 1.2546-0.5;
    ck_assert_double_eq(a, b);
}
END_TEST

int main(void) {
    Suite *s = suite_create("Unit-tests");
    TCase *tscase_core = tcase_create("Core");
    SRunner *suite_runner = srunner_create(s);
    int result;
    suite_add_tcase(s, tscase_core);
    tcase_add_test(tscase_core, test_1);
    tcase_add_test(tscase_core, test_2);
    tcase_add_test(tscase_core, test_3);
    tcase_add_test(tscase_core, test_4);
    tcase_add_test(tscase_core, test_5);
    tcase_add_test(tscase_core, test_6);
    tcase_add_test(tscase_core, test_7);
    tcase_add_test(tscase_core, test_8);
    tcase_add_test(tscase_core, test_9);
    tcase_add_test(tscase_core, test_10);
    tcase_add_test(tscase_core, test_11);
    tcase_add_test(tscase_core, test_12);
    tcase_add_test(tscase_core, test_13);
    srunner_run_all(suite_runner, CK_ENV);

    result = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return result == 0 ? 0 : 1;
}

