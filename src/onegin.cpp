#include "onegin.h"

int main(int argc, char *argv[])
{
    size_t num_symbols = 0;
    char* buffer = Get_Text_From_File(argv, &num_symbols);

    int count_of_strings = Strings_Count(buffer, num_symbols);

    char** index = Strings_Arr(buffer, num_symbols, count_of_strings);

    qsort(index, (size_t)count_of_strings, sizeof(*index), Compare_For_ABC);
    
    Create_Onegin_File(index, count_of_strings); //TODO: unsort text output
    
    free(buffer);
    free(index);
}

char* Get_Text_From_File(char* argv[], size_t* num_symbols)
{
    assert(num_symbols != NULL);

    FILE* onegin = fopen(argv[1], "r");
    assert(onegin != NULL);

    *num_symbols = Get_File_Size(argv);
    char* buffer = (char*)calloc(*num_symbols, sizeof(char));

    fread(buffer, sizeof(buffer[0]), *num_symbols, onegin);
    fclose(onegin);

    return buffer;
}

size_t Get_File_Size(char* argv[])
{
    assert(argv != NULL);

    struct stat text = {};
    stat(argv[1], &text);
    
    return (size_t)text.st_size + 1;
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

int Compare_For_ABC(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);
    
    const char* s1 = *(char* const*)a;
    const char* s2 = *(char* const*)b;

    while(*s1 != '\0' && !isalpha((unsigned char)*s1))
    {
        s1++;
    }
    while(*s2 != '\0' && !isalpha((unsigned char)*s2))
    {
        s2++;
    }

    while(1)
    {
        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);

        if(c1 < c2) return -1;
        if(c1 > c2) return 1;
        if(c1 == '\0') return 0;

        s1++;
        s2++;
    }
}

void Create_Onegin_File(char** index, int count_of_strings)
{
    assert(index != NULL);

    const char* Sorted_Onegin = "onegin_sorted.txt";

    FILE *file = fopen(Sorted_Onegin, "w");
    
    if(file)
    {
        for(int i = 0; i < count_of_strings; i++)
        {
            fputs(index[i], file);
            fputs("\n", file);
        }

        fclose(file);
        printf("File was created");
    }
    else{
        printf("File cant be created");
    }
}