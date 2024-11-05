#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "RU");
    
    std::cout << "В данной программе мы суммируем 30 раз и выводим сумму значение выражения (а-b)^2 " << 
                 "\nВыполнил Радюк Егор. Вариант: 15. Группа:453505." << '\n';

    long double  a;
    long double b;
    long int i;

    std::cout << "Введите i:";
    std::cin >> i;

    i % 2 == 0 ? a = i / 2 : a = i;
    std::cout << "Значение а = " << a; 

    i % 2 == 0 ? b = i * i * i : b = i * i;
    std::cout << "\nЗначение b = " << b << '\n';

    int d = pow(a - b,2);
    std::cout << "Значение выраажения (a-b)^2 = " << d << '\n';  

    long double N = 0;
    int n = 0;
    for(int m  = 0; m < 30; m++){
    while (n <= 30) {
        int result = pow(a - b, 2);
        m += 1;
        std::cout  << m << ":" << result << '\n';
        N += result;
        n++; 
    }
    }

    std::cout  << "Сумма N = " << N << '\n';
    return 0;
}