#include "Model/Model.h"
#include <cmath>
#include <gtest/gtest.h>

TEST(test_check_av_print, test_1) {
  std::string str_1 = "14+2-2..+2.3/30-3";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_check_av_print, test_2) {
  std::string str_1 = "14+2-2+2.3/30--3";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_check_av_print, test_3) {
  std::string str_1 = "14+2-2+(2.3/(30--3))";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_check_av_print_func, test_1) {
  std::string str_1 = "sin2+cos2+tg(2";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_check_av_print_func, test_2) {
  std::string str_1 = "asin-acos2+atan(2";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_check_av_print_func, test_3) {
  std::string str_1 = "sqrt2+ln2+log(2";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_fix_e, test_1) {
  std::string str_1 = "1e";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_fix_e, test_2) {
  std::string str_1 = "1e-";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_fix_e, test_3) {
  std::string str_1 = "e+";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(false, res.second);
}
TEST(test_start, test_1) {
  std::string str_1 = "1/2*10";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(5, res.first);
}
TEST(test_start, test_2) {
  std::string str_1 = "2*2+2*2*2*2*3";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(52, res.first);
}
TEST(test_start, test_3) {
  std::string str_1 = "100^0.5";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(10, res.first);
}
TEST(test_start, test_4) {
  std::string str_1 = "sqrt(100)";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  EXPECT_EQ(10, res.first);
}
TEST(test_start_null, test_5) {
  std::string str_1 = "sqrt(-2)";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  bool res_1 = std::isnan(res.first);
  EXPECT_EQ(res_1, true);
}
TEST(test_start_null, test_6) {
  std::string str_1 = "asin(-2)";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  bool res_1 = std::isnan(res.first);
  EXPECT_EQ(res_1, true);
}
TEST(test_start_null, test_7) {
  std::string str_1 = "acos(-2)";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  bool res_1 = std::isnan(res.first);
  EXPECT_EQ(res_1, true);
}
TEST(test_start_null, test_8) {
  std::string str_1 = "atan(-2)";
  s21::Model our_model = s21::Model();
  std::pair<double, bool> res = our_model.start(str_1, 0);
  bool res_1 = std::isnan(res.first);
  EXPECT_EQ(res_1, false);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
