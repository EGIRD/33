#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    setlocale(LC_ALL, "RU");
    
    std::cout << "В данном задании,находим сумму ряда, используя члены и заданную точность E=1e-3." <<
                 "\nВыполнил Радюк Егор. Вариант: 15." << '\n';

    long double exp = 1e-3;
    long double n = 1;
    long double sum = 0;
    long double d;

    std::cout << "Введите n:";
    std::cin >> n;

    do {
        d = (1 / n ) + 1 / (n * n);
        sum += d ;
        n++;
    } while(d >= exp);
    
    std::cout << std::fixed << std::setprecision(6) << "sum = " << sum << '\n';
    
    return 0;
}