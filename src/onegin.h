#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <ctype.h>

char* Get_Text_From_File(size_t* num_symbols);
int Strings_Count(char* buffer, size_t num_symbols);
char** Strings_Arr(char* buffer, size_t num_symbols, int count_of_strings);
char* Get_String(char** index, int num, int count_of_strings);
int Compare_For_ABC(const void* a, const void* b);