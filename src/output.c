#include <stdio.h>
#include <math.h>




int main() //поле 25 на 80 точек
 {
    int disper_round = 12; 
    char Natur = '*';
    char Speace = '.';
  //if(calculate!=0) 
    for(double y = -1.0 ; y <= 1.0 ; y += 0.08) 
  { //80 клеток ввысоту
       for(double x = 0; x < (M_PI * 4) ; x += (M_PI * 4) / 80 ) // 25 клеток в ширену // преобразование области определения 4 пи
    {
      if(round(sin(cos(2*x))*disper_round)/disper_round == round(y*disper_round)/disper_round) //образующая функция в ифе проверяет существование функции в зависимости от значения  х и у
     
      printf("%c", Natur);
      else
        { 
          printf("%c", Speace);
        }
       
     }   
  
        printf("%c", '\n');
   
   }
   //else
   //{
    //printf("n/a");
   //}
   //printf("%f\n",round((M_PI * 4.0)*100)/100);//промежут по оси х должен быть поделен 80 сигментов// потом для каждого икса считаю игрики по функции введенной пользователем// 4 умножить на пи == 
}