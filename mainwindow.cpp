#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dynamicarray.cpp"
#include "map.h"
#include "stack.cpp"
#include <string>
#define PI 3.14159265
using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QTableWidgetItem *item = new QTableWidgetItem(QString("Variable"));
    QTableWidgetItem *item2 = new QTableWidgetItem(QString("Value"));
    char character = 'A';
    for (int i = 0; i < 26; i++) {
        QTableWidgetItem *item3 = new QTableWidgetItem(QString(character));
        QTableWidgetItem *item4 = new QTableWidgetItem(QString("0"));
        ui->tableValue->setItem(i,0,item3);
        ui->tableValue->setItem(i,1,item4);
        character++;
    }
    ui->tableValue->setHorizontalHeaderItem(0,item);
    ui->tableValue->setHorizontalHeaderItem(1,item2);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_subBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"-");
}


void MainWindow::on_btn7_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"7");
}


void MainWindow::on_btn4_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"4");
}

void MainWindow::on_btn2_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"2");
}


void MainWindow::on_btn1_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"1");
}


void MainWindow::on_btn3_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"3");
}


void MainWindow::on_btn5_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"5");
}


void MainWindow::on_btn6_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"6");
}


void MainWindow::on_btn8_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"8");
}


void MainWindow::on_btn9_clicked()
{
     ui->InputBox->setText(ui->InputBox->toPlainText()+"9");
}


void MainWindow::on_cosBtn_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"cos(");
}


void MainWindow::on_sinBtn_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"sin(");
}


void MainWindow::on_tanBtn_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"tan(");
}


void MainWindow::on_cotBtn_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"cot(");
}


void MainWindow::on_openPar_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+"(");
}


void MainWindow::on_closePar_clicked()
{
    ui->InputBox->setText(ui->InputBox->toPlainText()+")");
}


void MainWindow::on_plusBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"+");
}


void MainWindow::on_divBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"/");
}


void MainWindow::on_multiBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"*");
}

void MainWindow::on_negativeBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"~");
}

void MainWindow::on_atanBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"atan(");
}

void MainWindow::on_asinBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"asin(");
}

void MainWindow::on_acosBtn_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+"acos(");
}

void MainWindow::on_floatingPoint_clicked() {
    ui->InputBox->setText(ui->InputBox->toPlainText()+".");
}

void MainWindow::on_btn9_2_clicked() {
    ui->InputBox->setText("");
    ui->ResultBox->setText("");
}

void MainWindow::on_apply_clicked() {
    for (int i = 0; i < 26; i++) {
        char a = ui->tableValue->item(i,0)->text().toStdString().at(0);
        double value = ui->tableValue->item(i,1)->text().toDouble();
        dictionary.insert(a,value);
    }
}

void MainWindow::on_equalBtn_clicked() {
    string infix = ui->InputBox->toPlainText().toStdString();
    string pos = infixtopos(infix);
    string result = to_string(evaluate(pos, dictionary));
    ui->ResultBox->setText(QString(result.c_str()));
}

//O(1)
int check_valid(char c) {
    if (c < 'A' || c > 'Z') {
        return 0;
    }
    return 1;
}

// O(1)
int check_token(char i) { // check char category
    if (i == '(') {
        return 1;
    } else if (i == ')') {
        return 2;
    } else if ((i >= 48 && i <= 57)) { // if char is a number
        return 3;
    } else if ((i >= 65 && i <= 90) || (i >=97 && i <= 122)) { // if char is character
        return 4;
    } else if (i == '+' || i == '-' || i == '/' || i == '*' || i == '^') { // char is operator
        return 5;
    } else if (i == '~') { // represent the negative sign
        return 6;
    }
    return -1;
}
// O(1)
int prec(char c) { // precedence of operator
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// O(n)
int check_geometry(string str) { // check if it is geometry function
    string store[] = {"sin","cos","tan","cot","asin","acos","atan"};
    for (int i = 0; i < 7; i++) {
        if (store[i] == str) {
            return 1;
        }
    }
    return 0;
}

// O(n)
DynamicArray<string> split(string str, char delim) { // split by delimeter
    DynamicArray<string> token(30);
    string word = "";
    for (auto x : str) {
        if (x == delim) {
            token.append(word);
            word = "";
        } else {
            word = word + x;
        }
    }
    return token;
}
// O(n)
string infixtopos(string a) {
    string pos;
    Stack<string> temp;
    for (int i = 0; i < (int) a.length(); i++) {

        // case 1: current char is open paren '('
        if (check_token(a[i]) == 1) {
            temp.push("(");
            continue;
        }
        // case 2: current char is close paren ')'
        if (check_token(a[i]) == 2) {
            while (temp.peek() != "(") {
                pos.append(temp.peek());
                pos.push_back(' ');
                temp.pop();
            }
            temp.pop();
            try {
                // after pop out the '(' check if peek is geometry fuction
                if (check_geometry(temp.peek()) || temp.peek() == "log") {
                    pos.append(temp.peek()); // if yes pop out of stack also
                    pos.push_back(' ');
                    temp.pop();
                }
            } catch (...) {
                continue;
            }
            continue;
        }
        // case 3: current char is a digt-> start of a number
        if (check_token(a[i]) == 3) {
            double num = 0;

            // get the number before the floating point
            while(isdigit(a[i])) {
                num = num * 10 + (int)(a[i] - '0');
                i++;
            }

            // get all the number after the floating point
            int decimal = 1;
            float float_num = 0;

            if(a[i] == '.') { // check if that number have floating point
                i++; // move to next to get number
                while(isdigit(a[i])) {
                    float_num = float_num * 10 + (int)(a[i] - '0');
                    decimal *= 10;
                    i++;
                }
            }
            i--; // prevent skipping char

            float_num = float_num/decimal;
            num += float_num; // construct a real number

            string number = to_string(num); // add to string
            pos.append(number);
            pos.push_back(' ');
            continue;
        }

        // special case for pi

        // case 4: current char is a character
        if (check_token(a[i]) == 4) {
            if (a[i] == 'p') {
                string oper = "";
                oper.push_back(a[i]);
                for (int j = i+1; j <= i+1; j++) {
                    oper.push_back(a[j]);
                } // fully construct to check if it is inversion of geometry fuction
                if (oper == "pi") {
                    pos.append("3.14159265");
                    pos.push_back(' ');
                    i += 1; // if yes then skip the next character
                }
                continue;
            }

            if (a[i] == 'a') {
                string oper = "";
                oper.push_back(a[i]);
                for (int j = i+1; j <= i+3; j++) {
                    oper.push_back(a[j]);
                } // fully construct to check if it is inversion of geometry fuction
                if (check_geometry(oper)) {
                    temp.push(oper);
                    i+= 3; // if yes then skip the next 3 character
                }
                continue;
            }
            if (a[i] == 's' || a[i] == 'c' || a[i] == 't' || a[i] == 'l') { // check if char is start of geometry fuction
                string oper = "";
                oper.push_back(a[i]);
                for (int j = i+1; j <= i+2; j++) {
                    oper.push_back(a[j]);
                } // fully construct to check if it is geometry fuction
                if (check_geometry(oper) || oper == "log") {
                    temp.push(oper);
                    i+= 2; // if yes then skip the next 2 character
                }
                continue;
            }
            pos.push_back(a[i]);
            pos.push_back(' ');
            continue;
        }

        // case 6: current char is a negative marker
        if (check_token(a[i]) == 6) {
            pos.push_back('~');
            continue;
        }

        // case 5: current char is operator
        while (!temp.isEmpty() && prec(a[i]) <= prec(temp.peek().at(0))) {
            pos.push_back(temp.peek().at(0));
            pos.push_back(' ');
            temp.pop();
        }

        string con;
        con.push_back(a[i]); // convert to become string
        temp.push(con); // push to stack
    }
    while (!temp.isEmpty()) {
        pos.append(temp.peek());
        pos.push_back(' ');
        temp.pop();
    }
    return pos;
}
// O(n)
double evaluate(string a, Map dict) {
    Stack<double> temp; // stack to store value
    DynamicArray<string> token = split(a, ' '); // split by delimeter

    for (int i = 0; i < token.getLength(); i++) { // traversal through array of string
        string current = token.getAt(i); // get current string

        // case start of string is negative marker
        if (current[0] == '~') {

            double num = stod(current.substr(1,current.length())); // get the number after ~
            num = num * -1; // change number to negative
            temp.push(num); // push to stack

        } else if (check_token(current[0]) == 3) { // case if char is digit

            double num = stod(current); // retrive the positive number
            temp.push(num);

        } else if ((current[0] >= 65 && current[0] <= 90)) {
            double value = dict.get_value(current[0]);
            temp.push(value);
        } else if (check_token(current[0]) == 5) { // check if it binary operator

            double number2 = temp.peek();
            temp.pop();
            double number1 = temp.peek();
            temp.pop();

            double result = 0;

            switch (current[0]) {
                case '+':
                    result = number1 + number2;
                    temp.push(result);
                    break;
                case '-':
                    result = number1 - number2;
                    temp.push(result);
                    break;
                case '*':
                    result = number1 * number2;
                    temp.push(result);
                    break;
                case '/':
                    result = number1 / number2;
                    temp.push(result);
                    break;
                case '^':
                    result = (double) pow(number1,number2);
                    temp.push(result);
                    break;
            }
        } else if (check_token(current[0]) == 4) { // check if it is function
            double number2 = temp.peek();
            temp.pop();
            if (current == "log") {
                double result = log(number2);
                temp.push(result);
            }
            if (current == "atan") {
                double result = atan(number2) * 180 / PI;;
                temp.push(result);
            }
            if (current == "asin") {
                double result = asin(number2) * 180 / PI;;
                temp.push(result);
            }
            if (current == "acos") {
                double result = acos(number2) * 180 / PI;;
                temp.push(result);
            }
            if (current == "cos") {
                double result = cos(number2 * PI / 180.0);
                temp.push(result);
            }
            if (current == "sin") {
                double result = sin(number2 * PI / 180.0);
                temp.push(result);
            }
            if (current == "tan") {
                double result = tan(number2 * PI / 180.0);
                temp.push(result);
            }
            if (current == "cot") {
                double result = (double) cos(number2 * PI / 180.0)/sin(number2 * PI / 180.0);
                temp.push(result);
            }
        }
    }
    if (temp.isEmpty()) {
//        cout << "Error expression";
        exit(-1);
    }
    double result = temp.peek();
    temp.pop();
    return result;
}

