#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "temp_api.h"

// Заполняем структуру
void AddRecord(str_sensor info[], size_t number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, int8_t temperature)
{
    if (number < SIZE)
    {
        info[number].year = year;
        info[number].month = month;
        info[number].day = day;
        info[number].hour = hour;
        info[number].minute = minute;
        info[number].second = second;
        info[number].temperature = temperature;
    }
}

// Заполняем вручную массив структур данными
int AddInfo(str_sensor info[])
{
    int counter = 0;
    AddRecord(info, counter++, 1998, 5, 26, 14, 55, 23, 7);
    AddRecord(info, counter++, 1999, 7, 3, 9, 35, 21, 22);
    AddRecord(info, counter++, 1997, 6, 12, 17, 8, 47, 6);
    AddRecord(info, counter++, 1998, 5, 15, 10, 30, 0, -5);
    AddRecord(info, counter++, 1999, 5, 20, 14, 0, 0, 15);
    AddRecord(info, counter++, 1997, 6, 10, 12, 0, 0, 25);
    AddRecord(info, counter++, 1998, 6, 15, 16, 0, 0, 30);
    return counter;
}

// Загрузка данных из CSV файла
int load_from_csv(str_sensor info[], int max_records, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return -1;
    }

// Считываем строки из файла filename.csv
// Используем fgets() для считывания строк в массив line[256 байт], пока не достигнем max_records
// или достигнем конца файла.
char line[256];
    int counter = 0;
   
    while (fgets(line, sizeof(line), file) && counter < max_records)
    {
        // Пропускаем пустые строки
        if (strlen(line) <= 1) continue;

        uint16_t year;
        uint8_t month, day, hour, minute, second;
        int8_t temperature;

// Пробуем разные форматы CSV
        int parsed = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhu;%hhd", 
                   &year, &month, &day, &hour, &minute, &second, &temperature);
        
        if (parsed != 7) {
            // Пробуем с запятыми
            parsed = sscanf(line, "%hu,%hhu,%hhu,%hhu,%hhu,%hhu,%hhd", 
                   &year, &month, &day, &hour, &minute, &second, &temperature);
        }
        
        if (parsed != 7) {
            // Пробуем с пробелами
            parsed = sscanf(line, "%hu %hhu %hhu %hhu %hhu %hhu %hhd", 
                   &year, &month, &day, &hour, &minute, &second, &temperature);
        }
        
        if (parsed == 7) {
            // Проверяем корректность данных
            if (month >= 1 && month <= 12 && day >= 1 && day <= 31 && 
                hour <= 23 && minute <= 59 && second <= 59) {
                AddRecord(info, counter, year, month, day, hour, minute, second, temperature);
                printf("Record %d: %04d-%02d-%02d %02d:%02d:%02d t=%3d C\n", 
                       counter + 1, year, month, day, hour, minute, second, temperature);
                counter++;
            } else {
                printf("Warning: Skipping invalid data in line: %s", line);
            }
        } else {
            // Пропускаем строку заголовка если есть
            if (strstr(line, "Year") == NULL && strstr(line, "year") == NULL &&
                strstr(line, "YEAR") == NULL) {
                printf("Warning: Could not parse line %d: %s", counter + 1, line);
            }
        }
    }
    
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return -1;
    }

    fclose(file);
    if (counter == 0) {
        printf("Warning: No valid records found in file\n");
    }
    return counter;
}

// Удаление записи по индексу
int delete_record(str_sensor info[], int *num_records, int index)
{
    if (index < 0 || index >= *num_records)
    {
        return -1;
    }

    for (int i = index; i < *num_records - 1; i++)
    {
        info[i] = info[i + 1];
    }

    (*num_records)--;
    return 0;
}

// Функция сравнения для сортировки
int compare_sensors(const void *a, const void *b)
{
    const str_sensor *sensor_a = (const str_sensor *)a;
    const str_sensor *sensor_b = (const str_sensor *)b;

    // Сравниваем годы
    if (sensor_a->year != sensor_b->year)
    {
        return sensor_a->year - sensor_b->year;
    }
    // Сравниваем месяцы
    if (sensor_a->month != sensor_b->month)
    {
        return sensor_a->month - sensor_b->month;
    }
    // Сравниваем дни
    if (sensor_a->day != sensor_b->day)
    {
        return sensor_a->day - sensor_b->day;
    }
    // Сравниваем часы
    if (sensor_a->hour != sensor_b->hour)
    {
        return sensor_a->hour - sensor_b->hour;
    }
    // Сравниваем минуты
    if (sensor_a->minute != sensor_b->minute)
    {
        return sensor_a->minute - sensor_b->minute;
    }
    // Сравниваем секунды
    return sensor_a->second - sensor_b->second;
}

// Сортировка записей по дате и времени
void sort_by_date(str_sensor info[], int num_records)
{
    qsort(info, num_records, sizeof(str_sensor), compare_sensors);
}

void print(str_sensor *info, int number)
{
    if (number == 0) {
        printf("No records to display\n");
        return;
    }
    
    printf("========================================\n");
    printf("No  Date       Time     Temperature\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < number; i++)
    {
        printf("%-3d %04d-%02d-%02d %02d:%02d:%02d t=%3d C\n",
               i + 1,
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].second,
               info[i].temperature);
    }
    printf("========================================\n\n");
    printf("Total records: %d\n\n", number);
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
    int8_t min_temp = 127; // Используем максимальное значение для int8_t
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
    int8_t max_temp = -128; // Используем минимальное значение для int8_t
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
    int8_t min_temp = 127;
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
    int8_t max_temp = -128;
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
    float avg_temp = monthly_average_temperature(info, num_records, month, year);
    int8_t min_temp = monthly_min_temperature(info, num_records, month, year);
    int8_t max_temp = monthly_max_temperature(info, num_records, month, year);

    printf("=== Monthly Statistics for %02d/%04d ===\n", month, year);
    printf("Average temperature: %.2f C\n", avg_temp);
    printf("Minimum temperature: %d C\n", min_temp);
    printf("Maximum temperature: %d C\n", max_temp);
    printf("Records count: %d\n", count_monthly_records(info, num_records, month, year));
    printf("========================================\n\n");
}

// Вывод статистики за год
void print_yearly_statistics(str_sensor info[], int num_records, uint16_t year)
{
    float avg_temp = yearly_average_temperature(info, num_records, year);
    int8_t min_temp = yearly_min_temperature(info, num_records, year);
    int8_t max_temp = yearly_max_temperature(info, num_records, year);

    printf("=== Yearly Statistics for %04d ===\n", year);
    printf("Average temperature: %.2f C\n", avg_temp);
    printf("Minimum temperature: %d C\n", min_temp);
    printf("Maximum temperature: %d C\n", max_temp);
    printf("Records count: %d\n", count_yearly_records(info, num_records, year));
    printf("========================================\n\n");
}

// Подсчет записей за месяц
int count_monthly_records(str_sensor info[], int num_records, uint8_t month, uint16_t year)
{
    int count = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (info[i].month == month && info[i].year == year)
        {
            count++;
        }
    }
    return count;
}

// Подсчет записей за год
int count_yearly_records(str_sensor info[], int num_records, uint16_t year)
{
    int count = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (info[i].year == year)
        {
            count++;
        }
    }
    return count;
}