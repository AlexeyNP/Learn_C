#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

#define SIZE 30

#pragma pack(push, 1)
typedef struct sensor {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t temperature;
} str_sensor;
#pragma pack(pop)

// Функции для работы с данными
void AddRecord(str_sensor info[], size_t number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, int8_t temperature);
int AddInfo(str_sensor info[]);
void print(str_sensor* info, int number);
void changeIJ(str_sensor info[], int i, int j);

// Функции статистики по месяцам
float monthly_average_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year);
int8_t monthly_min_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year);
int8_t monthly_max_temperature(str_sensor info[], int num_records, uint8_t month, uint16_t year);

// Функции статистики за год
float yearly_average_temperature(str_sensor info[], int num_records, uint16_t year);
int8_t yearly_min_temperature(str_sensor info[], int num_records, uint16_t year);
int8_t yearly_max_temperature(str_sensor info[], int num_records, uint16_t year);

// Функции вывода статистики
void print_monthly_statistics(str_sensor info[], int num_records, uint8_t month, uint16_t year);
void print_yearly_statistics(str_sensor info[], int num_records, uint16_t year);

#endif