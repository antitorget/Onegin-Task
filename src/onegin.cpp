#include "onegin.h"

int main()
{
    size_t num_symbols = 0;
    char* buffer = File_Open(&num_symbols);

    int count_of_strings = Strings_Count(buffer, num_symbols);

    char** index = Strings_Arr(buffer, num_symbols, count_of_strings);

    printf("%s", Get_String(index, 0, count_of_strings));
}

char* File_Open(size_t* num_symbols)
{
    assert(num_symbols != NULL);

    FILE* onegin = fopen("onegin_orig.txt", "r");
    struct stat text = {};
    stat("onegin_orig.txt", &text);

    *num_symbols = (size_t)(text.st_size + 1);
    char* buffer = (char*)calloc(*num_symbols, sizeof(char));

    fread(buffer, sizeof(buffer[0]), *num_symbols, onegin);
    fclose(onegin);

    return buffer;
}

int Strings_Count(char* buffer, size_t num_symbols)
{
    assert(buffer != NULL);

    int count_of_strings = 0;

    for(size_t i = 0; i < num_symbols; i++)
    {
        if(buffer[i] == '\n')
        {
            count_of_strings++;
        }
    }

    return count_of_strings;
}

char** Strings_Arr(char* buffer, size_t num_symbols, int count_of_strings)
{
    assert(buffer != NULL);

    char** index = (char**)calloc((size_t)(count_of_strings + 1), sizeof(*index));

    index[0] = buffer;
    int string_num = 1;

    for(size_t i = 0; i < num_symbols; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            index[string_num] = &buffer[i + 1];
            string_num++;
        }
    }

    return index;
}

char* Get_String(char** index, int num, int count_of_strings)
{
    assert(index != NULL);
    assert(num <= count_of_strings);
    assert(num >= 0);
    
    return index[num];
}