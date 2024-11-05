#include <iostream>

long double pow(double x, int n) {
    double res = 1.0;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

int main(){
    setlocale(LC_ALL, "RU");
    std::cout << "Данная программа находит все числа Армстронга в диапазоне от 1 до n, где n введен пользователем\n";
    std::cout << "Выполнил Радюк Егор. 453505. Вариант 15 ." << '\n';


    while(true){
    int c;
    std::cout << "Введите 1 - если хотите продолжить. 2 - если хотите прекратить." << '\n';
    std::cin >> c;

    if(c == 2) return 0;
    if(c != 1 && c != 2) {
        std::cout << "Неверный ввод. Принимаются только значения 1 или 2." << '\n'; 
        return 0;
    } else {
    
    unsigned int x;
    long int sum = 0;
    long int max;
    long int per;
    long int temp;

    std::cout << "Введите х:";
    std::cin >> x;

    for(int i = 0; i < x; i++){
        temp = i;
        while (temp != 0) {
            temp /= 10;
            ++per;
        }
        temp = i;
        while(temp){
            sum += pow (temp % 10, per);
            temp /= 10;
        }
        if(sum == i) std::cout <<  i << '\n';
        sum = 0; per =0;
    }
    }
    };
    return 0;
     
}