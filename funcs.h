#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>

using namespace std;

// Ввод текста из файла.
void scanf_text_from_the_file(wstring &Text_User)
{
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

// Вычисление ключа шифровки.
int finding_key_symbols_of_shift()
{
    wstring s_buff;
    wifstream in ("lysikov.txt");
    in.imbue(locale(locale(), new
            codecvt_utf8<wchar_t,0x10ffff, consume_header>));
    getline(in, s_buff);
    in.close();
    return s_buff.size() % 10;
}

// Генерация алфавита с помощью ключа для шифровки.
void generate_key(wstring &Alphabet, wstring &Alphabet_key, int key_symbols_of_shift)
{
    for (int i = 0; i < Alphabet.size(); i++)
    {
        Alphabet_key[i] = Alphabet[(i + key_symbols_of_shift) % Alphabet.size()];
    }
}

// Зашифровать текст.
void encryption_text(wstring Text_User, wstring &Text_Crypt, wstring Alphabet, wstring Alphabet_key)
{
    for (int i = 0; i < Text_User.size(); i++)
    {
        int check_elem = 0;
        for (int j = 0; j < Alphabet.size(); j++)
        {
            if (Alphabet[j] == Text_User[i])
            {
                check_elem = 1;
                Text_Crypt += Alphabet_key[j];
            }
        }
        if (check_elem == 0)
        {
            Text_Crypt += Text_User[i];
        }
    }
}

// Расшифровать текст.
void de_encryption_text(wstring Text_Crypt, wstring &Text_De_Crypt, wstring Alphabet, wstring Alphabet_key)
{
    for (int i = 0; i < Text_Crypt.size(); i++)
    {
        int check_elem = 0;
        for (int j = 0; j < Alphabet.size(); j++)
        {
            if (Alphabet_key[j] == Text_Crypt[i])
            {
                check_elem = 1;
                Text_De_Crypt += Alphabet[j];
            }
        }
        if (check_elem == 0)
        {
            Text_De_Crypt += Text_Crypt[i];
        }
    }
}

// Вывести зашифрованный текст в файл.
void write_file_encryption(wstring Text_Crypt)
{
    wofstream out ("lysikovCrypt.txt");
    out.imbue(locale(locale(), new
            codecvt_utf8<wchar_t,0x10ffff, consume_header>));
    out << Text_Crypt << '\n';
    out.close();
}

// Вывести расшифрованный текст в файл.
void write_file_de_encryption(wstring &Text_De_Crypt)
{
    wofstream out ("lysikovDeCrypt.txt");
    out.imbue(locale(locale(), new
            codecvt_utf8<wchar_t,0x10ffff, consume_header>));
    out << Text_De_Crypt << '\n';
    out.close();
}