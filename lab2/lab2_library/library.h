#ifndef LAB2_LIB_LIBRARY_H
#define LAB2_LIB_LIBRARY_H
#include <cmath>
#include <iostream>

const double pi = 3.141592653589793;
const double b=3;//Во сколько раз радиус большей неподвижной окружности превышает радиус подвижной

//x=(3r-r)cos(t)+r*cos((3r-r)t/r);
//y=(3r-r)sin(t)-r*sin((3r-r)t/r);

//(x^2+y^2)^2+18(x^2+y^2)=8x^3+24y^2x+27;

class deltoida {
private:
    double radius;//радиус двигающейся окружности
public:
    //1 задание:
    deltoida() {//Инициализирующий конструктор 1
        radius = 0;
    }

    deltoida(double rad) {//Инициализирующий конструктор 2
            if(rad>=0)
                radius = rad;
            else{
                throw std::runtime_error("указанный радиус < 0");
//                std::cout<<"Указан радиус < 0, поэтому выставлено значение радиуса равное 0"<<std::endl;
//                radius=0;
            }
    }

    deltoida(const deltoida &other){//Копирующий конструктор
        radius = other.radius;
    }

    ~deltoida() = default;

    //2 задание:
    double get() const;

    double set_radius(double new_radius);
    //3 задание:
    double the_length_of_the_intersection() const;
    //4 задание:
    double length_of_the_curve() const;
    //5 задание:
    double area() const;
    //6 задание:
    double* x_and_y_dependence_from_t(double t) const;
    //7 задание:
    const char* text_view_of_equation() const;
};

#endif //LAB2_LIB_LIBRARY_H