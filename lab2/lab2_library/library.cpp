#include "library.h"

double deltoida::get() const{
    return radius;
}

double deltoida::set_radius(double new_radius) {
        if(new_radius>=0){
            radius = new_radius;
        }
        else{
            throw std::runtime_error("указанный радиус < 0");
        }
        return new_radius;
}

double deltoida::the_length_of_the_intersection() const{
    return 4 * b * radius / 3;
}

double deltoida::length_of_the_curve() const{
    return 16 * b * radius / 3;
}

double* deltoida::x_and_y_dependence_from_t(double t) const{
    double* res=new double[2];
    res[0]=(b-1) * radius * cos(t) + radius * cos((b-1) * t);
    res[1]=(b-1) * radius * sin(t) - radius * sin((b-1) * t);
    return res;
}

double deltoida::area() const{
    return (2 * pi * (b * radius) * (b * radius) / 9);
}

const char* deltoida::text_view_of_equation() const{
    const char* equation = "(x^2+y^2)^2+18(x^2+y^2)=8x^3+24xy^2+27";
    return equation;
}