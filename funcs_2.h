#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <codecvt>

using namespace std;

// Ввод текста из файла.
void scanf_text_from_the_file(wstring &Text_User, bool &flag)
{
    flag = true;
    wifstream in ("lysikov.txt");
    in.imbue(locale(locale(), new
            codecvt_utf8<wchar_t,0x10ffff, consume_header>));
    wstring s_buff;
    while (getline(in, s_buff))
    {
        Text_User += s_buff + L'\n';
    }
    in.close();
}

// Произвести частотный анализ.
void frequency_analysis(wstring &Text_User, vector<wchar_t> &Alphabet, vector <int> &Frequency, bool &flag)
{
    if (flag)
    {
        for (int j = 0; j < Alphabet.size(); j++)
        {
            if (Alphabet[j] == Text_User[0])
            {
                Frequency[j]++;
            }
        }
        for (int i = 1; i < Text_User.size() - 2; i++)
        {
            if (((Text_User[i] == '.') || (Text_User[i] == '!') ||
                 (Text_User[i] == '?')) && ((Text_User[i + 1] == ' ') || (Text_User[i + 1] == '\n')))
            {
                for (int j = 0; j < Alphabet.size(); j++)
                {
                    if (Alphabet[j] == Text_User[i + 2])
                    {
                        Frequency[j]++;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Все плохо, сначала считайте текст из файла!\n";
    }
}

// Вывести букву(-ы) с которой(-ых) ЧАЩЕ всего начинается предложение.
void write_more_often_symbol_for_console(vector<wchar_t> &Alphabet, vector<int> &Frequency)
{
    int maxim = *max_element(Frequency.begin(), Frequency.end());
    cout << "Чаще всего начинается с:\n";
    for (int i = 0; i < Frequency.size(); i++)
    {
        if (Frequency[i] == maxim)
        {
            wcout.imbue(locale(locale(), new
                    codecvt_utf8<wchar_t,0x10ffff, consume_header>));
            wcout << Alphabet[i] << '\n';
        }
    }
}

// Вывести букву(-ы) с которой(-ых) реже всего начинается предложение.
void write_less_often_symbol_for_console(vector<wchar_t> &Alphabet, vector<int> &Frequency)
{
    int minim = *min_element(Frequency.begin(), Frequency.end());
    cout << "Реже всего начинается с:\n";
    for (int i = 0; i < Frequency.size(); i++)
    {
        if (Frequency[i] == minim)
        {
            wcout.imbue(locale(locale(), new
                    codecvt_utf8<wchar_t,0x10ffff, consume_header>));
            wcout << Alphabet[i] << '\n';
        }
    }
}