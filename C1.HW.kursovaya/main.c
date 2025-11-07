#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "temp_api.h"

void print_help(void)
{
    printf("Temperature Statistics Application\n");
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  -h              Show this help message\n");
    printf("  -f <filename>   Input CSV file for processing\n");
    printf("  -m <month>      Show statistics for specified month (1-12)\n");
    printf("  -y <year>       Show statistics for specified year\n");
    printf("  -a              Show all statistics (monthly and yearly)\n");
    printf("  -p              Print all records\n");
    printf("  -s              Sort records by date and time\n");
}

int main(int argc, char *argv[])
{
    str_sensor info[SIZE];
    int number = 0;
    int opt;
    char *filename = NULL;
    int month = 0;
    int year = 0;
    int show_all = 0;
    int print_records = 0;
    int sort_records = 0;

    // Обработка аргументов командной строки
    while ((opt = getopt(argc, argv, "hf:m:y:aps")) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'f':
            filename = optarg;
            break;
        case 'm':
            month = atoi(optarg);
            if (month < 1 || month > 12)
            {
                fprintf(stderr, "Error: Month must be between 1 and 12\n");
                return 1;
            }
            break;
        case 'y':
            year = atoi(optarg);
            break;
        case 'a':
            show_all = 1;
            break;
        case 'p':
            print_records = 1;
            break;
        case 's':
            sort_records = 1;
            break;
        default:
            fprintf(stderr, "Unknown option. Use -h for help.\n");
            return 1;
        }
    }

    // Загрузка данных из файла
    if (filename)
    {
        number = load_from_csv(info, SIZE, filename);
        if (number < 0)
        {
            fprintf(stderr, "Error loading data from file: %s\n", filename);
            return 1;
        }
        printf("Loaded %d records from %s\n", number, filename);
    
    // Автоматически печатаем записи после загрузки из файла
        printf("\nLoaded records:\n");
        print(info, number);
    } else {
        number = AddInfo(info);
        printf("Loaded %d demo records\n", number);
    }

    // Сортировка если запрошена
    if (sort_records)
    {
        sort_by_date(info, number);
        printf("Records sorted by date and time\n");
    // Печатаем отсортированные данные после сортировки
        printf("\nSorted records:\n");
        print(info, number);
    }

    // Печать всех записей если запрошено
    if (print_records)
    {
        printf("All temperature records:\n");
        print(info, number);
    }

    // Вывод статистики
    if (month > 0)
    {
        // Статистика за конкретный месяц
        if (year == 0)
        {
            // Если год не указан, используем первый найденный год для этого месяца
            for (int i = 0; i < number; i++)
            {
                if (info[i].month == month)
                {
                    year = info[i].year;
                    break;
                }
            }
            if (year == 0)
                year = 2025; // год по умолчанию
                printf("Warning: No data found for month %d, using year %d as default\n", month, year);
        }
        print_monthly_statistics(info, number, month, year);
    }
    else if (year > 0)
    {
        // Статистика за год
        print_yearly_statistics(info, number, year);
    }
    else if (show_all)
    {
        // Вся статистика
        printf("=== ALL STATISTICS ===\n");
        // Находим все уникальные годы в данных
        uint16_t years[10] = {0};
        int year_count = 0;

        for (int i = 0; i < number; i++)
        {
            int found = 0;
            for (int j = 0; j < year_count; j++)
            {
                if (years[j] == info[i].year)
                {
                    found = 1;
                    break;
                }
            }
            if (!found && year_count < 10)
            {
                years[year_count++] = info[i].year;
            }
        }

        // Выводим статистику по каждому году и месяцу
        for (int y = 0; y < year_count; y++)
        {
            printf("\nYear: %d\n", years[y]);
            for (int m = 1; m <= 12; m++)
            {
                int has_data = 0;
                for (int i = 0; i < number; i++)
                {
                    if (info[i].year == years[y] && info[i].month == m)
                    {
                        has_data = 1;
                        break;
                    }
                }
                if (has_data)
                {
                    print_monthly_statistics(info, number, m, years[y]);
                }
            }
            print_yearly_statistics(info, number, years[y]);
        }
    }

    return 0;
}