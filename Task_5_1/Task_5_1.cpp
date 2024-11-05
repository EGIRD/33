#include <iostream>
#include <cmath>
#include <iomanip> 

/*long double funY(long double Y,long double x){
    return acos(exp(-pow((x + 1),2))) + (sin(x));
}*/

int main(){
   setlocale(LC_ALL, "RU");
 
   long double x;
   std::cout << "\nВведите х:";
   std::cin >> x;

   if(x <-2 || x > 2){
    std::cout << "Значение х вне заданного диапазона [-2;2].";
    return -1;
   }
   
   /*funY(Y,x);
   std::cout << "y:" << Y << '\n';*/

   std::cout << std::fixed << std::setprecision(3);

   long double Y = acos(exp(-pow((x + 1),2))) + (sin(x));
   std::cout << "Значение уравнения(Y):" << Y << '\n';
   
   /*long double cor = sqrt(Y);
   std::cout << "Корень уравнения:" << cor << '\n';1.394*/

   long double A = -2;
   long double B = 2;
   long int n;
   long double sum;
   long double st = A;
   std::cout << "Введите, на сколько частей делим:";
   std::cin >> n;

   long double H = (B - A) / n;

   for(int i = 0; i < n; ++i){
    long double x = A + i * H;
        long double value = Y;
            st = x;
    }


    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Приближенный корень уравнения: " << st << '\n';
  

    return 0;
}