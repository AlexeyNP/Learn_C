#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "temp_api.h"

int main(void)
{
    str_sensor info[SIZE];
    int number = AddInfo(info);
    
    printf("Original data:\n");
    print(info, number);
    
    changeIJ(info, 1, 2);
    printf("\nAfter swapping elements 1 and 2:\n");
    print(info, number);
    
    // Вывод статистики по месяцам
    print_monthly_statistics(info, number, 5, 2023);  // Май 2023
    print_monthly_statistics(info, number, 6, 2023);  // Июнь 2023
    
    // Вывод статистики за год
    print_yearly_statistics(info, number, 2023);
    
    return 0;
}