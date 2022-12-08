#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "dynamicarray.h"
#include "map.h"
#include "qtablewidget.h"

using namespace std;


int check_valid(char c);
int check_token(char i);
int prec(char c);
int check_geometry(string str);
DynamicArray<string> split(string str, char delim);
string infixtopos(string a);
double evaluate(string a, Map dict);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Map dictionary;
    ~MainWindow();

private slots:


    void on_subBtn_clicked();

    void on_btn7_clicked();

    void on_btn4_clicked();

    void on_btn2_clicked();

    void on_btn1_clicked();

    void on_btn3_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_cosBtn_clicked();

    void on_sinBtn_clicked();

    void on_tanBtn_clicked();

    void on_cotBtn_clicked();

    void on_openPar_clicked();

    void on_closePar_clicked();

    void on_plusBtn_clicked();

    void on_divBtn_clicked();

    void on_multiBtn_clicked();

    void on_btn9_2_clicked();

    void on_apply_clicked();

    void on_equalBtn_clicked();

    void on_negativeBtn_clicked();

    void on_atanBtn_clicked();

    void on_asinBtn_clicked();

    void on_acosBtn_clicked();

    void on_floatingPoint_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
