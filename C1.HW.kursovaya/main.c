/*
    1. Создать массив из структурного типа данных для хранения температуры.
    2. Структура типа: 
        - dddd - год 4 цифры 
        - mm - месяц 2 символа 
        - dd - день 2 цифры 
        - hh - часы 2 цифры 
        - mm - минуты 2 цифры 
        - temperature - целое число от -99 до 99
    3. Создать прототипы (заглушки) функций вывода статистики по каждому месяцу: среднемесячная 
температура, минимальная температура в текущем месяце, максимальная температура в текущем 
месяце, вывод статистику за год: • среднегодовая температура • минимальная температура • 
максимальная температура
    4. Все прототипы функций используемые в приложении должны быть вынесены в отдельный файл 
temp_api.h
    5. Тексты функций - в файл temp_api.c.
    6. Приложение должно собираться при помощи утилиты make
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define SIZE 30                         // Размер массива для хранения значений температур

typedef struct sensor {                 // Струтура для сбора данных
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t mounth;
    uint16_t year;
    int8_t temperature;
} str_sensor;

// Добавление записи с датой, временем и температурой
void AddRecord(str_sensor info[], size_t number, uint8_t year, uint8_t mounth, uint8_t day,  uint8_t hour, uint8_t minute, uint16_t second, int8_t temperature)
{
    info[number].year = year;
    info[number].mounth = mounth;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].second = second;
    info[number].temperature = temperature;

}

// Добрвление записей в массив
void AddInfo(str_sensor info[])
{
    int counter = 0;
    AddRecord(info, counter++, 2023, 5, 26, 14, 55, 23, 7);
    AddRecord(info, counter++, 2024, 7, 3, 9, 35, 21, 22);
    AddRecord(info, counter++, 2025, 6, 12, 17, 8, 47, 6);
    return counter;
}

// Вывод на печать массива структур со значениями даты, времени и температур
void print(str_sensor* info, int number)
{
    printf("=====================================================\n");
    for(int i=0; i<number; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d:%02d t=%3d\n",
        info[i].year,
        info[i].mounth,
        info[i].day,
        info[i].hour,
        info[i].minute,
        info[i].second,
        info[i].temperature);
    }
}

int main(void)
{
    str_sensor info[SIZE];

}