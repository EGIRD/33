#include <iostream>
#include <cmath>

long double funC(long double x){
    return acos(exp(-(x+1*(x+1)))) + sin(x);
}

int main(){
   std::cout << "Данная программа приближенно находит корень уравнения для функции f(x) = arccose^(-(x+1)^2) + sinx." << 
                "\nCначала перебираем значения от начала до конца интервала с некоторым шагом и ищем значение функции " << 
                "\nминимальное по модулю. Аргумент, при котором оно достигается,считаем корнем уравнения и выводим его." << 
                "\nВыполнил Радюк Егор. Вариант: 15. Группа: 453505 ." << '\n' << '\n';

  long double x;
  long double a = -2;
  long double b = 2;  
  long double n;

  while (true) {
  int c;    
  std::cout << "Введите 1 - если хотите продолжить, 2 - если хотите прекратить." << '\n';
  std::cin >> c;

  if (c == 2) return 0;

  if (c != 1 && c != 2) {
    std::cout << "Неверный ввод.Принимаются только значения 1 или 2." << '\n'; 
    return 0; 
    } 
    
  std::cout << "Введите,на сколько частей разделить область поиска корня:";
  std::cin >> x;

  long double shag = (b - a) / x, min = 1000000000000, res ;
  std::cout << "Шаг:" << shag << '\n';

  for(long double i = -2; i < 2; i += shag) {
    if (min > fabs(funC(i))) {
      min = fabs(funC(i));
      res = i;
    }
  }

  std::cout << "Корень уравнения:" << res << '\n';
 }
  return 0;
} 
