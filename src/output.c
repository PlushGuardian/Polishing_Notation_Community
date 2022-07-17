#include <stdio.h>
#include <math.h>

//int calculate(lex* queue, double *res);

double imputable_function(double x) {
   x = sin(cos(2 * x));
   //x = sin(x);
   //x = cos(x);
    //x = tan(x);
    //x = log(x);
   //x = x;
  
  return x; 
} 

int main() //поле 25 на 80 точек
 {
    double OPR_FUNK =M_PI * 4 ;//преобразование для условия задачи
    int disper_round = 12; // дополнительное округление для эроунд
    char Natur = '*';
    char Speace = '.';

    
 
    for(double y = -1.0 ; y <= 1.0 ; y += 0.08) //
  { 
       for(double x = 0; x < OPR_FUNK ; x += OPR_FUNK / 79 ) // Тут происходит преобразование
    {
      if (round(imputable_function(x) * disper_round) / disper_round == round(y * disper_round)/disper_round) {
          printf("%c", Natur);
      } else { 
          printf("%c", Speace);
      }
       
     }   
  
        printf("%c", '\n');
   
   }
   //else
   //{
    //printf("n/a");
   //}
   
}


/*int calculate(lex* queue, double *res) {
    int flag = 1;
    stack* nums;
    while (queue) {
        if (queue->type == NUM) {
            push(&nums, queue->elem.num);
            pop_lex(&queue);
        } else {
            *res = operations(&nums, queue->elem.func, &flag);
            push(&nums, *res);
        }
        if (flag == 0) 
            break;
    }
    return flag;
}*/
