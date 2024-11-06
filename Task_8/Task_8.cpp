#include <iostream>
#include <limits>

int main(){
   setlocale(LC_ALL, "RU");

   std::cout << "Программа запрашивает у пользователя количество элементов, а далее считает и выводит сумму ряда." << '\n';
   std::cout << "Выполнил Радюк Егор. Вариант:15. " << '\n';

   while(true){
    int c;
    std::cout << "Введите 1 - если хотите продолжить. 2 - если хотите прекратить." << '\n';
    std::cin >> c;

    if(c == 2) return 0;
    if(c != 1 && c != 2) {
        std::cout << "Неверный ввод. Принимаются только значения 1 или 2." << '\n'; 
        return 0;
    } else {

    int n;
    std::cout << "Введите количество членов(n):";
    std::cin >> n;

    long int sum = 0;
    long int pow = 1;

    for(int i = 0; i < n; i++) {
        long int a;
        std::cout << "Введите коэффициент(а):";
        std::cin >> a;
        sum += (i % 2 == 0) ? a * pow : -a * pow;
        pow *= 2;
        }
        std::cout << "Сумма ряда равна: " << sum << '\n';
     }
    }

    std::cout <<  std::numeric_limits<int>::max();
    return 0;
}

