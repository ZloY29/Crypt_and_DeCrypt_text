#pragma once
#include "funcs.h"

void show_menu()
{
    cout << "1. Ввод текста из файла.\n";
    cout << "2. Вычисление ключа шифровки.\n";
    cout << "3. Генерация алфавита с помощью ключа для шифровки.\n";
    cout << "4. Зашифровать текст.\n";
    cout << "5. Вывести зашифрованный текст в файл.\n";
    cout << "6. Расшифровать текст.\n";
    cout << "7. Вывести расшифрованный текст в файл.\n";
    cout << "0. Закончить работу.\n";
}

void work_menu(int number, wstring &Text_User, wstring &Alphabet,
               wstring &Alphabet_key, wstring &Text_Crypt,
               wstring &Text_De_Crypt, int &key_symbols_of_shift)
{
    switch (number)
    {
        case 1:
        {
            scanf_text_from_the_file(Text_User);
            break;
        }
        case 2:
        {
            key_symbols_of_shift = finding_key_symbols_of_shift();
            break;
        }
        case 3:
        {
            generate_key(Alphabet, Alphabet_key, key_symbols_of_shift);
            break;
        }
        case 4:
        {
            encryption_text(Text_User, Text_Crypt, Alphabet, Alphabet_key);
            break;
        }
        case 5:
        {
            write_file_encryption(Text_Crypt);
            break;
        }
        case 6:
        {
            de_encryption_text(Text_Crypt, Text_De_Crypt, Alphabet, Alphabet_key);
            break;
        }
        case 7:
        {
            write_file_de_encryption(Text_De_Crypt);
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            break;
        }
    }
}