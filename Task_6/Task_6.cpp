#include <iostream>
#include <limits>

const long double PI = 3.14159265358979323846264338327950;
const long double TwoPI = 6.28318530717958647692L; 
const long double E = 2.71828;

long double Abs(long double x) {
    if (x < 0) 
        x *= -1;
    else 
        x = x;
    return x;
}

long double Pow(long double x, long double y) {
    long double number = x;
    for (int i = 1; i < Abs(y); i++) {
        number *= x;
        
    }
    return number;
}

long double Factorial(long double n) {
    if (n == 0 || n == 1) 
        return 1;
    else 
        return n * Factorial(n - 1); 
}

long double Normalize(long double x){
    long double del = TwoPI;
    while (del < Abs(x)) {del *= 2;};
    while (Abs(x) > TwoPI) {
        while (del > Abs(x) && Abs(x - del) > 0.1 && del > TwoPI) del /= 2;
        x =(x > 0)? x - del : x + del;
    }
    return x;
}
long double MySin(long double x) {
    x = Normalize(x);
    const long double pr = 1e-12;
    long double seqm = x;
    int n = 1;

    long double sum = seqm;
    while (Abs(seqm) > pr) {
        seqm = Pow(-1, n) * Pow(x, 2 * n + 1) / Factorial(2 * n + 1);
        sum += seqm;
        n++;
    }
    return sum;
}

long double MyCos(long double x) {
    x = Normalize(x);
    const long double pr = 1e-10;
    long double seqm = 1; 
    int n = 1;
    long double sum = seqm; 
    
    while (Abs(seqm) > pr) {
        seqm = Pow(-1, n) * Pow(x, 2 * n) / Factorial(2 * n); 
        sum += seqm;
        n++;
    }
    return sum;
}

long double MyLn(double x){

    long long n = 1, c = 0;
    while(x > 1){
        x = x / E;
        c++;
    }
    while(x < 1e-5){
        x = x * E;
        c--;
    }
    double res = 0 , ter = x - 1;
    while(Abs(ter) > 1e-8){
        res += ter;
        ter *= -(x - 1) * n / (n + 1);
        n++;
    }
    return res + (double)c;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Данная программа находит минимальное значение введенного аргумента среди функций sin(x), cos(x), ln(x)." << '\n';
    std::cout << "Выполнил Радюк Егор. 453505. Вариант: 15." << '\n';

    long long k, n, size;
    long double h, sinx, cosx, logx;

    while (true) {
        std::cout << "Введите 1 - если хотите продолжить, 2 - если хотите прекратить." << '\n';
        std::cin >> k;
        switch(k) {
        case (1): 
            std::cout << "Введите значение переменной х:";
            std::cin >> h;
            if (std::cin.fail()) {
                std::cout << "Ошибка ввода." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
          
            if (h < 0) {
                h = -h;
                std::cout << "sin:" << -MySin(h) << '\n'; 
                std::cout << "cos:" << -MyCos(h)  << '\n';
                std::cout << "ln:" << MyLn(h) << '\n'; 
            }
            else {
            std::cout << "sin:" << MySin(h)  << '\n'; 
            std::cout << "cos:" << MyCos(h)  << '\n'; 
            std::cout << "ln:" << MyLn(h)  << '\n'; 
            }
            break;

        case (2):
            return 0;
            break;

        default:
            std::cout << "Ошибка ввода." << '\n';
            return 0;
            break;
        }
    }
}
