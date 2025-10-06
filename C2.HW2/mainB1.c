/*
 * Требуется реализовать только одну функцию, которая анализирует данный
 * список и возвращает сколько всего памяти используется. Адрес хранится
 * в поле address, поле size - соответствующий размер данного блока.
 * Если список пустой, то функция должна возвращать 0.

Входные данные
3
      140525067852320 10
      140525067852350 30
      140525067852900 100

Результат работы
140
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <locale.h>

typedef struct list
{
    uint64_t address;           // Адрес блока памяти
    size_t size;                // Размер блока
    char comment[64];
    struct list *next;
} list;

typedef struct list *head;  // Синоним для List*

size_t totalMemoryUsage(list *head); // Функция для подсчета занимаемой памяти

int main(void)
{
    setlocale(LC_ALL, "ru");    // Для вывода строк на русском языке в терминале
    int number = 0;             // Число строк, которое будет введено
    list Search[number];        // Образец структуры
    scanf( "%d", &number);      // Считываем количество строк
    if( number == 0)            // Провека на равенство 0 количество введенных строк
    {
        printf( "%s", "WTF? ZERO!");
    }
    else
    {
        for( int i=0; i < number; i++)  // Заполняем массив структур адресами и размерами
        {
            scanf( "%I64d%d", &Search[i].address, &Search[i].size); // Считываем адрес и размер
        }
        printf( "%s\t%s\n", "Address", "Size" );    // Печатаем заголовки


        for( int i=0; i < number; i++)  // Печатаем массив структур с адресами и размерами
        {
            printf( "%I64d\t%d\n", Search[i].address, Search[i].size );
        }

        printf( "%u\n", totalMemoryUsage( &Search[number] ));    // *head - указатель на объект типа struct list
    }
    return 0;
}

size_t totalMemoryUsage(list *head)
{
    if( head == NULL )                  // Проверка равен ли массив нулю
    {
        return 0;                       // Если равен нулю, вернуть 0
    }

    size_t all_size = 0;                // Переменная для размера блока

    list *current = head;               // Создаем указатель на структуру

    while (current != NULL) {           // Пока массив структур не закончился
        all_size += current->size;      // Считаем сумму всех значений
        current = current->next;
    }

    return all_size;                 // Возвращаем сумму значений
}
