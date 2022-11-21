#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Controller/Controller.h"
#include <QByteArray>
#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void operations();
  void digits_numbers();
  void on_pushButton_12_clicked();
  void on_pushButton_34_clicked();
  void on_pushButton_35_clicked();

private:
  Ui::MainWindow *ui;
  s21::Controller *Controller_input = new s21::Controller();
  void Calc_x();
  void Calc_();
  void Create_graph();
  bool find_error();
  double xBegin, xEnd, h, X, Y, yBegin, yEnd;
  int N;
  QVector<double> x, y;
};
#endif // MAINWINDOW_H
