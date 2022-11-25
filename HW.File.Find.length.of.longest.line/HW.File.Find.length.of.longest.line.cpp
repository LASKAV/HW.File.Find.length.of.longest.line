#include <iostream>
#include <string>
#include <fstream>

// Дан текстовый файл. Найти длину самой длинной строки.

int main()
{
    setlocale(LC_ALL, "ru");

    std::string File_name = "file_str.txt"; 

    std::ifstream Reader_FILE;   //   R                       

    const size_t BUFF = 1000;

    char str[BUFF];
    char str1[BUFF];

    int max_str_line = 0;  

    Reader_FILE.open(File_name);

    if (!Reader_FILE)                                    
    {
        std::cout << "file_str.txt open error";
        return -1;
    }
    else
    {
        while (!Reader_FILE.eof())                       
        {
            Reader_FILE.getline(str, BUFF);              
            int length = strnlen_s(str, BUFF); 
            if (length > max_str_line)                   
            {
                max_str_line = length;                   
                strcpy_s(str1, str);                       
            }
        }
     
        std::cout << "Длина самой длинной строки = " << max_str_line << std::endl;
        Reader_FILE.close();
    }
    
    return 0;
}
