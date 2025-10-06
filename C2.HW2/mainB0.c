/*Требуется реализовать только одну функцию, которая в данном списке находит
адрес блока памяти занимающий больше всего места.

Адрес хранится в поле address, поле size - соответствующий размер данного блока.
 - Если список пустой, то функция должна возвращать 0.
 - Если есть несколько таких блоков, то вернуть адрес любого из них.

Входные данные
3
      140525067852320 10
      140525067852350 30
      140525067852900 100

Результат работы
140525067852900
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

//typedef struct list List;     // Синоним для struct list
typedef struct list *head;  // Синоним для List*

uint64_t findMaxBlock( list *head ); // Функция для определения самого большого блока

int main(void)
{
    setlocale(LC_ALL, "ru");    // Для вывода строк на русском языке в терминале
    //list List;                //
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

        printf( "%I64d\n", findMaxBlock( &Search[number] ));    // *head - указатель на объект типа struct list
    }
    return 0;
}

uint64_t findMaxBlock(list *head)
{
    if( head == NULL )                  // Проверка равен ли массив нулю
    {
        return 0;                       // Если равен нулю, вернуть 0
    }

    uint64_t max_address = head->address;   // Переменная для адреса блока памяти
    size_t max_size = head->size;           // Переменная для размера блока

   list *current = head->next;          // Создаем указатель на структуру

    while (current != NULL) {           // Пока массив структур не закончился
        if (current->size > max_size) { // Поиск максимального размера
            max_size = current->size;
            max_address = current->address;
        }
        current = current->next;
    }

    return max_address;                 // Возвращаем адрес максимального значения
}
