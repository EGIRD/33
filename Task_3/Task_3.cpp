#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    setlocale(LC_ALL, "RU");

    std::cout << "Используя цикл for составить программу вычисления значений функции " <<
                 " y = sin(x) - cos(x) на отрезке [0, 1.5708]." << "\nВыполнил Радюк Егор. Вариант: 15 ." << '\n';

    const long int  M = 20;
    const long double  A = 0;
    const long double B = M_PI / 2;
    const long double H = (B - A) / M;
    long double i;

    std::cout << "Отрезок [" << A << "," << B << "]" << '\n';

    for(int i = 0; i <= M; i++){
         long double X = A + i * H;
         long double Y = sin(X) - cos(X);
         std::cout << "x:" << X << ", y:" << Y << '\n'; 
        std::cout << std::fixed << std::setprecision(5) << "Значение уравнения Y = " << Y << '\n';
    }

    return 0;
}