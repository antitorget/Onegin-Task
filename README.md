# Onegin-Task

Создал массив, хранящий строки текстового файла.

## Библиотеки:
`<stdio.h>`     - подключение работы ввода-вывода
`<stdlib.h>`    - подключение базовых функций С (в моем примере - calloc)
`<sys/types.h>` - определение новых типов данных для работы со структурой stat 
`<sys/stat.h>`  - определение структуры stat
`<assert.h>`    - кто не ставит ассерты - тот на завтрак ест десерты

Переменные:
  size_t num_symbols - количество символов в тексте
  char* buffer - массив, хранящий текст
  int count_of_strings - количество строк в тексте
  char** index - массив указателей на строки
  struct stat text - структура, хранящая данные о файле
  int string_num - номер строки в массиве строк
  
  FILE* onegin - название текстового файла для работы с ним

Функции:
  char* File_Open(size_t* num_symbols);                                       - открывает файл, сохраняет структуру, создает буффер, хранящий текст, и возвращает его.
  int Strings_Count(char* buffer, size_t num_symbols);                        - подсчитывает количество строк в тексте.
  char** Strings_Arr(char* buffer, size_t num_symbols, int count_of_strings); - cоздает массив строк и возвращает его.
  char* Get_String(char** index, int num, int count_of_strings);              - Проверяет выход за пределы массива строк и возвращает его num элемент.
