#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  Controller_input = new s21::Controller();
  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_30, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_31, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_32, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_33, SIGNAL(clicked()), this, SLOT(operations()));
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);
  ui->pushButton_12->setCheckable(true);
}

MainWindow::~MainWindow() {
  delete ui;
  delete Controller_input;
}

void MainWindow::digits_numbers() {
  QString new_lable;
  new_lable = (ui->result_console->text());
  ui->result_console->setText(new_lable);
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  double all_numbers;
  QString new_label;

  if (button->text() == "+/-") {
    all_numbers = (ui->result_console->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result_console->setText(new_label);
  }
}

void MainWindow::on_pushButton_clicked()  // sin
{
  ui->result_console->setText(ui->result_console->text() + "sin");
}

void MainWindow::on_pushButton_2_clicked()  // cos
{
  ui->result_console->setText(ui->result_console->text() + "cos");
}

void MainWindow::on_pushButton_3_clicked()  // tan
{
  ui->result_console->setText(ui->result_console->text() + "tan");
}

void MainWindow::on_pushButton_4_clicked()  // asin
{
  ui->result_console->setText(ui->result_console->text() + "asin");
}

void MainWindow::on_pushButton_5_clicked()  // acos
{
  ui->result_console->setText(ui->result_console->text() + "acos");
}

void MainWindow::on_pushButton_6_clicked()  // atan
{
  ui->result_console->setText(ui->result_console->text() + "atan");
}

void MainWindow::on_pushButton_7_clicked()  // sqrt
{
  ui->result_console->setText(ui->result_console->text() + "sqrt");
}

void MainWindow::on_pushButton_8_clicked()  // ln
{
  ui->result_console->setText(ui->result_console->text() + "ln");
}

void MainWindow::on_pushButton_9_clicked()  // log
{
  ui->result_console->setText(ui->result_console->text() + "log");
}

void MainWindow::on_pushButton_10_clicked()  // mod
{
  ui->result_console->setText(ui->result_console->text() + "mod");
}

void MainWindow::on_pushButton_11_clicked()  // X
{
  ui->result_console->setText(ui->result_console->text() + "x");
}

void MainWindow::on_pushButton_14_clicked()  //+
{
  ui->result_console->setText(ui->result_console->text() + "+");
}

void MainWindow::on_pushButton_15_clicked()  //-
{
  ui->result_console->setText(ui->result_console->text() + "-");
}

void MainWindow::on_pushButton_16_clicked()  //*
{
  ui->result_console->setText(ui->result_console->text() + "*");
}

void MainWindow::on_pushButton_17_clicked()  // /
{
  ui->result_console->setText(ui->result_console->text() + "/");
}

void MainWindow::on_pushButton_18_clicked()  // ^
{
  ui->result_console->setText(ui->result_console->text() + "^");
}

void MainWindow::on_pushButton_13_clicked()  // clear
{}

void MainWindow::on_pushButton_19_clicked()  // 1
{
  ui->result_console->setText(ui->result_console->text() + "1");
}

void MainWindow::on_pushButton_20_clicked()  // 2
{
  ui->result_console->setText(ui->result_console->text() + "2");
}

void MainWindow::on_pushButton_21_clicked()  // 3
{
  ui->result_console->setText(ui->result_console->text() + "3");
}

void MainWindow::on_pushButton_22_clicked()  // 4
{
  ui->result_console->setText(ui->result_console->text() + "4");
}

void MainWindow::on_pushButton_23_clicked()  // 5
{
  ui->result_console->setText(ui->result_console->text() + "5");
}

void MainWindow::on_pushButton_24_clicked()  // 6
{
  ui->result_console->setText(ui->result_console->text() + "6");
}

void MainWindow::on_pushButton_26_clicked()  // 7
{
  ui->result_console->setText(ui->result_console->text() + "7");
}

void MainWindow::on_pushButton_25_clicked()  // 8
{
  ui->result_console->setText(ui->result_console->text() + "8");
}

void MainWindow::on_pushButton_30_clicked()  // 9
{
  ui->result_console->setText(ui->result_console->text() + "9");
}
void MainWindow::on_pushButton_27_clicked()  // 0
{
  ui->result_console->setText(ui->result_console->text() + "0");
}
void MainWindow::on_pushButton_29_clicked()  //.
{
  ui->result_console->setText(ui->result_console->text() + ".");
}
// void MainWindow::check_unary_minus(std::string &str) {
//   if (*(str.begin().base()) == '-') {
//     std::string str_1 = "0-" str.replace(str.begin(), 1, str_1);
//   }
//   std::string str_1 = "(-";
//   std::string str_2 = "0";
//   size_t iter = str.find(str_1);
//   while (iter != -1) {
//     str.insert(iter + 1, str_2);
//     iter = str.find(str_1);
//     continue;
//   };
// }
// void MainWindow::fix_e(std::string &str) {
//   std::string str_1 = "e-";
//   std::string str_2 = "/10^";
//   std::string str_1_ = "e+";
//   std::string str_2_ = "*10^";
//   auto iter = str.find("e");
//   while (iter != -1) {
//     if (str.find(str_1) != std::string::npos) {
//       str.replace(str.find(str_1), str_1.size(), str_2);
//     }
//     if (str.find(str_1_) != std::string::npos) {
//       str.replace(str.find(str_1_), str_1_.size(), str_2_);
//     } else
//       ui->result_console->setText("Incorrect input");
//     iter = str.find("e");
//     continue;
//   }
// }
void MainWindow::Calc_x() {
  QString x_value = ui->result_console_x->text().toLatin1();
  std::string str_x = x_value.toStdString();
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  if (str.length() <= 255) {
    double respect = Controller_input->Calc_contr(str, 0);
    QString new_label;
    new_label = QString::number(respect, 'g', 15);
    if (respect != NULL) {
      ui->result_console->setText(new_label);
    } else {
      ui->result_console->setText("Incorrect input");
    }
  }
}

void MainWindow::Calc_() {
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  double respect = Controller_input->Calc_contr(str, 0);
  QString new_label;
  if (str.length() <= 255) {
    double respect = Controller_input->Calc_contr(str, 0);
    QString new_label;
    new_label = QString::number(respect, 'g', 15);
    if (respect != NULL) {
      ui->result_console->setText(new_label);
    } else {
      ui->result_console->setText("Incorrect input");
    }
  } else {
    ui->result_console->setText("Max size");
  }
}

void MainWindow::on_pushButton_12_clicked()  // =
{
  QPushButton *Button = (QPushButton *)sender();
  if (ui->result_console->text().contains("x")) {
    Calc_x();
  } else {
    Calc_();
  }
  Button->setChecked(false);
}

void MainWindow::on_pushButton_31_clicked()  // (
{
  ui->result_console->setText(ui->result_console->text() + "(");
}

void MainWindow::on_pushButton_32_clicked()  // )
{
  ui->result_console->setText(ui->result_console->text() + ")");
}

void MainWindow::on_pushButton_34_clicked() { ui->result_console->clear(); }

void Create_graph() {
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  check_unary_minus(str);
  h = 0.1;
  xBegin = (ui->xmin->text()).toDouble();
  yBegin = (ui->ymin->text()).toDouble();
  xEnd = (ui->xmax->text()).toDouble() + h;
  yEnd = (ui->ymin->text()).toDouble();
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);
  X = xBegin;
  N = (xEnd - xBegin) / h + 2;
  for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    y.push_back(Controller_input->Calc_contr(str, X));
  }
  ui->widget->addGraph();
  ui->widget->graph()->addData(x, y);
  ui->widget->replot();
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_35_clicked() {
  ui->widget->clearGraphs();
  if (!(ui->xmin->text()).toDouble() || !(ui->ymin->text()).toDouble() ||
      !(ui->xmax->text()).toDouble() || !(ui->ymax->text()).toDouble()) {
    QMessageBox::critical(this, "", "Enter x and y coordinates");
    ui->widget->clearGraphs();
    x.clear();
    y.clear();
  } else {
    Create_graph();
  }
}
