#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtMath>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

extern "C" {
#include "../backend/calculator.h"
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void paintGrath();
  stack_operators stack_op;
  stack_numbers stack_num;

 private:
  Ui::MainWindow *ui;

 private slots:
  void scan_numbers();
  void on_pushButton_point_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_X_clicked();
  void on_pushButton_grapf_clicked();
};

#endif  // MAINWINDOW_H
