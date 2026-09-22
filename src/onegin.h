#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>


char* Get_Text_From_File(int argc, char* argv[], size_t* num_symbols);
size_t Get_File_Size(char* argv[]);
int Strings_Count(char* buffer, size_t num_symbols);
char** Strings_Arr(char* buffer, size_t num_symbols, int count_of_strings);
int Compare_For_ABC(const void* left_comp_elem, const void* right_comp_elem);
void Create_Onegin_File(char** index, int count_of_strings);
void Restore_Index(char** index, int count_of_strings);
void ValueChange(char** value1, char** value2);
char* Get_String(char** index, int num, int count_of_strings);