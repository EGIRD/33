#include <iostream>
#include <cmath> 
#include <iomanip>

long double funY(long double x){
  return x * atan(x) - log(sqrt(1+pow(x,2)));
}

int main(){
   std::cout << "Данная программа считает и воводит значения функций вычесленных рядом Тейлора и встроенных математических функций." << 
               "\nВыполнил Радюк Егор. Вариант:15. Группа:453505." << '\n' << '\n';

long double n;
std::cout << "Введите количество членов ряда: ";
std::cin >> n;          

long double d;
std::cout << "Введите количество переменных,от которых хотите посчитать функцию: ";
std::cin >> d;

long double x;    
std::cout << "Введите значение переменной х (0.1 - 1): ";
std::cin >> x;           

std::cout << "Значение Y(x):" << funY(x);


  return 0;
}