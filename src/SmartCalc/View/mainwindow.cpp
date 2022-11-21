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
  connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(digits_numbers()));
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
  QPushButton *button = (QPushButton *)sender();
  QString new_lable;
  new_lable = (ui->result_console->text());
  if (!find_error()) {
    ui->result_console->clear();
    new_lable.clear();
  }
  ui->result_console->setText(new_lable + button->text());
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

bool MainWindow::find_error() {
  bool res = true;
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  if (str.find("Incorrect input") != std::string::npos ||
      str.find("nan") != std::string::npos ||
      str.find("inf") != std::string::npos ||
      str.find("-inf") != std::string::npos)
    res = false;
  return res;
}
void MainWindow::Calc_x() {
  QString x_value = ui->result_console_x->text().toLatin1();
  std::string str_x = x_value.toStdString();
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  str.replace(str.find('x'), 1, str_x);
  ui->result_console_x->clear();
  if (str.length() <= 255) {
    std::pair<double, bool> respect = Controller_input->Calc_contr(str, 0);
    QString new_label;
    new_label = QString::number(respect.first, 'g', 7);
    if (respect.second) {
      ui->result_console->setText(new_label);
    } else {
      ui->result_console->setText("Incorrect input");
    }
  }
}

void MainWindow::Calc_() {
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
  if (str.length() <= 255) {
    std::pair<double, bool> respect = Controller_input->Calc_contr(str, 0);
    QString new_label;
    new_label = QString::number(respect.first, 'g', 7);
    if (respect.second) {
      ui->result_console->setText(new_label);
    } else {
      ui->result_console->setText("Incorrect input");
    }
  } else {
    ui->result_console->setText("Max size");
  }
}

void MainWindow::on_pushButton_12_clicked() // =
{
  QPushButton *Button = (QPushButton *)sender();
  if (ui->result_console->text().contains("x")) {
    Calc_x();
  } else {
    Calc_();
  }
  Button->setChecked(false);
}

void MainWindow::on_pushButton_34_clicked() { ui->result_console->clear(); }

void MainWindow::Create_graph() {
  QString barr = ui->result_console->text().toLatin1();
  std::string str = barr.toStdString();
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
    if (!Controller_input->Calc_contr(str, X).second)
      ui->result_console->setText("Incorrect function");
    else
      y.push_back(Controller_input->Calc_contr(str, X).first);
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
