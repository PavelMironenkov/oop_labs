#include "dialog_functions.h"
int main() {
        std::cout << "Введите радиус окружности дельтоиды: ";
        double rad;
        getNum<double>(rad);
        try{
            deltoida delt(rad);
            choose_alternative(delt);
        }catch(std::runtime_error&a){
            std::cout << "Ошибка: " << a.what() << std::endl;
            deltoida delt;
            std::cout << "Радиус дельтоиды устанавливается- " << delt.get() << std::endl;
            choose_alternative(delt);
        }
    return 1;
}