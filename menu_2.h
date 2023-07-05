#pragma once
#include "funcs_2.h"

void show_menu()
{
    cout << "1. Ввод текста из файла.\n";
    cout << "2. Произвести частотный анализ.\n";
    cout << "3. Вывести букву(-ы) с которой(-ых) ЧАЩЕ всего начинается предложение.\n";
    cout << "4. Вывести букву(-ы) с которой(-ых) РЕЖЕ всего начинается предложение.\n";
    cout << "0. Закончить работу.\n";
}

void work_menu(wstring &Text_User, vector<wchar_t> Alphabet, vector <int> &Frequency, bool &flag, int number)
{
    switch (number)
    {
        case 1:
        {
            scanf_text_from_the_file(Text_User, flag);
            break;
        }
        case 2:
        {
            frequency_analysis(Text_User, Alphabet, Frequency, flag);
            break;
        }
        case 3:
        {
            write_more_often_symbol_for_console(Alphabet, Frequency);
            break;
        }
        case 4:
        {
            write_less_often_symbol_for_console(Alphabet, Frequency);
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