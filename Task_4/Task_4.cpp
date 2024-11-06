#include <iostream>
#include <iomanip>
#include <cmath>

int InputInt(){
    int x;
    bool znach = true;
    while (znach) {
       znach = false;

        std::cin.clear();

        std::cin >> x;

        while (std::cin.peek() != '\n') {
            if (std::cin.get() != ' ') znach = true;
            std::cin.clear();
        }

        if (znach) std::cout << (char)-1 << ' ' << "Ошибка ввода.\n";
    }
    return x;
}

double InputDouble(){
    double x;
    bool znach  = true;
    while (znach ) {
        znach  = false;

        std::cin.clear();

        std::cin >> x;

        while (std::cin.peek() != '\n') {
            if (std::cin.get() != ' ') znach  = true;
            std::cin.clear();
        }

        if (znach) std::cout << (char)-1 << ' ' << "Ошибка ввода.\n";
    }
    return x;
}

int main(){

    std::cout << "Данная программа демонстрирует разницу значений вычесленных рядом Тейлора и встроенных математических функций\n";
    std::cout << "Выполнил Радюк Егор. 453505. Вариант: 15." << '\n';

    while(true){
        std::cout << "Введите 1, если хотите продолжить работу с программой и 2, если хотите прекратить: " << '\n';
        int cont = InputInt();
        if(cont != 1 && cont != 2) {std::cout << "Ошибка ввода.\n"; continue;};
        if(cont == 2) return 0;

        int kolIter, kolInput;

        std::cout << "Введите количество членов ряда: ";
        kolIter = InputInt();

        std::cout << "Введите какое количество переменных вы хотите обработать: ";
        kolInput = InputInt();

        std::cout << "\nЗначения выводятся в формате: значение переменной || Значение, вычисленное рядом || Значение полученное функциями. \n \n";

        while(kolInput){
            kolInput--;

            int n = 0, m = kolIter;
            double x;

            std::cout << "Введите значение переменной х: ";

            x = InputDouble();

            if(x < 0.1 || x > 1){ std::cout << "Ошибка ввода.\n"; kolInput++; continue;};

            double res = x, ter = x;
            while(m > 0){
                ter *= x * x / (4 * n * n + 10 * n + 6);
                res += ter;
                n++; m--;
            }

             std::cout << std::setprecision(10) <<"х: " << x << " | " << res << " | " << (exp(x) - exp(-x))/2 << '\n';
        }
    }
}
