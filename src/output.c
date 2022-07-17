#include "calculation.h"
#include "stack_and_struct.h"
#include "output_supplement.h"
#include <stdio.h>
#include <math.h>

//int calculate(lex* queue, double *res);

// double imputable_function(double x) {
//    x = sin(cos(2 * x));
//    //x = sin(x);
//    //x = cos(x);
//     //x = tan(x);
//     //x = log(x);
//    //x = x;
  
//   return x; 
// } 
void header() {
    printf("Добро пожаловать! Если вам нужно вывести график вашей функции, вы обратились по адресу!\n");
    printf("    Перед вами алгоритм, высчитывающий значения с помощью обратной польской нотации!   \n");
    printf("                                    Здорово, правда?                                   \n");
    printf("         Если вам не кажется, что это здорово, мы не знаем, зачем вы пришли...         \n");
    printf("                             В любом случае, это неважно.                              \n");
    printf("                           Введите строку до 100 элементов                             \n");
}


void output(lex* queue) {
    double OPR_FUNK =M_PI * 4 ;  // преобразование для условия задачи
    int disper_round = 12;  // дополнительное округление для эроунд
    char Natur = '*';
    char Speace = '.';
    for(double y = -1.0 ; y <= 1.0 ; y += 0.08) { 
        int flag = 1;
        for(double x = 0; x < OPR_FUNK ; x += OPR_FUNK / 79 ) {
            double res;
            flag = calculate(queue, &res, x);
            if (flag != 1) {
                printf("Хммм... Что-то пошло не так... \nВидимо, ты делишь на ноль или что-то подобное...\n");
                printf("Послушай, я знаю, что ты хочешь сломать нашу программу, но, может, не надо?\n");
                break;
            } else {
                if (round(res * disper_round) / disper_round == round(y * disper_round)/disper_round) {
                    printf("%c", Natur);
                } else { 
                    printf("%c", Speace);
                }
            }
        }  
        if (flag != 1)
            break; 
        printf("%c", '\n');
    }
   
}
