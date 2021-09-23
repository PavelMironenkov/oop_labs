#include <iostream>
#include "dialog_functions.h"
using namespace std;

const char *msgs[] = {"0.Выход\n", "1.Вывести радиус дельтоиды\n", "2.Изменить радиус дельтоиды\n",
                      "3.Вывести длину пересечения\n", "4.Вывести длину кривой\n",
                      "5.Вывести площадь, ограниченную кривой\n",
                      "6.Вывести координаты X и Y, зависящие от параметра t\n",
                      "7.Текстовое представление уравнения дельтоиды\n"};

const int Nmsgs = sizeof(msgs) / sizeof(msgs[0]);

template<typename T>

int getNum(T &a) {
    while (!(cin >> a)) {
        if (cin.eof()) // If we have reached EOF, break of the loop or exit.
            return -1; // End of stream;

            cin.clear(); // Clear the error state of the stream.

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of the line.

            cout << "Неверно! Повторите, пожалуйста, ввод!" << endl; // Ask more fresh input.
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 1;
}

int dialog(const char *msgs[], const int Nmsgs) {
    const char *errmsg = "";
    int rc;
    do {
        cout << errmsg;
        errmsg = "Неверно! Повторите, пожалуйста, ввод.\n";
        for (int i = 0; i < Nmsgs; ++i)
            cout << msgs[i];
        cout << "Ваш выбор:--> ";
        int n = getNum<int>(rc);
        if (n == -1) {
            rc = 0;
        }
    } while (rc >= Nmsgs || rc < 0);
    return rc;
}

void choose_alternative(deltoida& delt){
    int rc;
    do {
        rc = dialog(msgs, Nmsgs);
        switch (rc) {
            case 1: {
                cout << "Радиус дельтоиды: " << delt.get() << endl;
                break;
            }
            case 2: {
                double new_radius;
                cout << "Введите новый радиус дельтоиды: ";
                getNum<double>(new_radius);
                try{
                    delt.set_radius(new_radius);
                }catch(std::runtime_error &a){
                    std::cout << "Ошибка: " << a.what() << std::endl;
                    delt.set_radius(0);
                }
                cout << "Новый радиус дельтоиды - " << delt.get() << endl;
                break;
            }
            case 3: {
                cout << "Длина пересечения области, ограниченной дельтоидой, с любой ее касательной: "
                << delt.the_length_of_the_intersection() << endl;
                break;
            }
            case 4: {
                cout << "Длина кривой: " << delt.length_of_the_curve() << endl;
                break;
            }
            case 5: {
                cout << "Площадь ограниченная кривой: " << delt.area() << endl;
                break;
            }
            case 6: {
                double t;
                cout << "Введите параметр t: ";
                getNum<double>(t);
                double *x_y = delt.x_and_y_dependence_from_t(t);
                cout << "X и Y при заданном t: " << x_y[0] << "\t" << x_y[1] << endl;
                delete[] x_y;
                break;
            }
            case 7: {
                cout << "Текстовое представление уравнения дельтоиды в декартовой системе координат в виде строки: "
                << endl;
                cout << delt.text_view_of_equation() << endl;
                break;
            }
            default: {
                if (rc)
                    cout << "Введен неверный номер альтернативы" << endl;
            }
        }
    } while (rc);
}
