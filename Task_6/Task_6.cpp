#include <iostream>
#include <limits>

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

long double MyFmod(long double x) {
    const long double two_pi = 6.28318530717958647692L; 
    long double y = two_pi;
    int n = 0;
    while (x > y) {
        y = Pow(2, n) * two_pi;
        n++;
    }
    long double powtwo = Pow(2, n - 2) * two_pi;
    long double endx = x - powtwo;
    if (endx > two_pi) {
        endx = MyFmod(endx);
    }
    return endx;
}

long double MySin(long double x) {
    x = MyFmod(x);
    const double PI = 3.141592;
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
    x = MyFmod(x);
    const double PI = 3.141592;
    const long double pr = 1e-12;
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

long double MyLn(long double x) {   
    double result = 0, result2 = 0, term, ln2 = 0.69314, xInit = x;
    long long quant2;

    while(x > 2)  {
        x = x / 2;
        quant2++;
    }

    for(int n = 1; n < 1000; n++) {
        term = Pow(-1, n + 1) * Pow(x - 1, n) / n;
        result += term;
    }

    if(xInit <= 2) return result;
    else  {
        result2 = result + quant2 * ln2;
        return result2;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Данная программа находит минимальное значение введенного аргумента среди функций sin(x), cos(x), ln(x)." << '\n';
    std::cout << "Выполнил Радюк Егор. 453505. Вариант: 15." << '\n';

    long long k, n, size;
    long double hhh, sinx, cosx, logx;
    const double e = 2.7182818;
    const double PI = 3.141592;

    while (true) {
        std::cout << "Введите 1 - если хотите продолжить, 2 - если хотите прекратить." << '\n';
        std::cin >> k;
        switch(k) {
        case (1): 
            std::cout << "Введите значение х:";
            std::cin >> hhh;
            if (std::cin.fail()) {
                std::cout << "Ошибка ввода." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
          
            if (hhh < 0) {
                hhh = -hhh;
                std::cout << "sin:" << -MySin(hhh) << "\n"; //<< sinx << "\n";
                std::cout << "cos:" << -MyCos(hhh) << "\n"; //<< cosx << "\n";
                std::cout << "ln:" << MyLn(hhh) << "\n"; //<< logx << "\n";
            }
            else {
            std::cout << "sin:" << MySin(hhh) << "\n"; //<< sinx << "\n";
            std::cout << "cos:" << MyCos(hhh) << "\n"; //<< cosx << "\n";
            std::cout << "ln:" << MyLn(hhh) <<  "\n"; //<< logx << "\n";
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

