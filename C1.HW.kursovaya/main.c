#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "temp_api.h"

int main(void)
{
    str_sensor info[SIZE];
    int number = AddInfo(info);

    // Вывод данных как они были занесены
    //    printf("Original data:\n");
    //    print(info, number);

    // Вывод статистики по месяцам
    print_monthly_statistics(info, number, 5, 2025); // Май 2025
    print_monthly_statistics(info, number, 6, 2025); // Июнь 2025

    // Вывод статистики за год
    print_yearly_statistics(info, number, 2023);

    return 0;
}