#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "temp_api.h"

// Заполняем структуру
void AddRecord(str_sensor info[], size_t number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, int8_t temperature)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].second = second;
    info[number].temperature = temperature;
}

// Заполняем массив структур данными
int AddInfo(str_sensor info[])
{
    int counter = 0;
    AddRecord(info, counter++, 2023, 5, 26, 14, 55, 23, 7);
    AddRecord(info, counter++, 2024, 7, 3, 9, 35, 21, 22);
    AddRecord(info, counter++, 2025, 6, 12, 17, 8, 47, 6);
    AddRecord(info, counter++, 2025, 5, 15, 10, 30, 0, -5);
    AddRecord(info, counter++, 2025, 5, 20, 14, 0, 0, 15);
    AddRecord(info, counter++, 2025, 6, 10, 12, 0, 0, 25);
    AddRecord(info, counter++, 2025, 6, 15, 16, 0, 0, 30);
    return counter;
}

void print(str_sensor *info, int number)
{
    printf("=====================================================\n");
    for (int i = 0; i < number; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d:%02d t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].second,
               info[i].temperature);
    }
}

// Смена местами I-й и J-й строки массива
void changeIJ(str_sensor info[], int i, int j)
{
    str_sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// Поиск средней температуры за месяц
float monthly_average_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].month == month && info[i].year == year)
        {
            sum += info[i].temperature;
            count++;
        }
    }

    return count > 0 ? (float)sum / count : 0.0f;
}

// Поиск минимальной температуры за месяц
int8_t monthly_min_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year)
{
    int8_t min_temp = 99;
    int found = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].month == month && info[i].year == year)
        {
            if (!found || info[i].temperature < min_temp)
            {
                min_temp = info[i].temperature;
                found = 1;
            }
        }
    }

    return found ? min_temp : 0;
}

// Поиск максимальной температуры за месяц
int8_t monthly_max_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year)
{
    int8_t max_temp = -99;
    int found = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].month == month && info[i].year == year)
        {
            if (!found || info[i].temperature > max_temp)
            {
                max_temp = info[i].temperature;
                found = 1;
            }
        }
    }

    return found ? max_temp : 0;
}

// Поиск средней температуры за год
float yearly_average_temperature(str_sensor info[], int num_records, uint16_t year)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].year == year)
        {
            sum += info[i].temperature;
            count++;
        }
    }

    return count > 0 ? (float)sum / count : 0.0f;
}

// Поиск минимальной температуры за год
int8_t yearly_min_temperature(str_sensor info[], int num_records, uint16_t year)
{
    int8_t min_temp = 99;
    int found = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].year == year)
        {
            if (!found || info[i].temperature < min_temp)
            {
                min_temp = info[i].temperature;
                found = 1;
            }
        }
    }

    return found ? min_temp : 0;
}

// Поиск максимальной температуры за год
int8_t yearly_max_temperature(str_sensor info[], int num_records, uint16_t year)
{
    int8_t max_temp = -99;
    int found = 0;

    for (int i = 0; i < num_records; i++)
    {
        if (info[i].year == year)
        {
            if (!found || info[i].temperature > max_temp)
            {
                max_temp = info[i].temperature;
                found = 1;
            }
        }
    }

    return found ? max_temp : 0;
}

// Вывод статистики за месяц
void print_monthly_statistics(str_sensor info[], int num_records, uint8_t month, uint16_t year)
{
    printf("\n=== Monthly Statistics for %02d/%04d ===\n", month, year);
    printf("Average temperature: %.2f C\n", monthly_average_temperature(info, num_records, month, year));
    printf("Minimum temperature: %d°C\n", monthly_min_temperature(info, num_records, month, year));
    printf("Maximum temperature: %d°C\n", monthly_max_temperature(info, num_records, month, year));
    printf("===================================\n\n");
}

// Вывод статистики за год
void print_yearly_statistics(str_sensor info[], int num_records, uint16_t year)
{
    printf("=== Yearly Statistics for %04d ===\n", year);
    printf("Average temperature: %.2f°C\n", yearly_average_temperature(info, num_records, year));
    printf("Minimum temperature: %d°C\n", yearly_min_temperature(info, num_records, year));
    printf("Maximum temperature: %d°C\n", yearly_max_temperature(info, num_records, year));
    printf("================================\n\n");
}