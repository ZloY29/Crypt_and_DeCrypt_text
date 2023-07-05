#include "funcs.h"
#include "menu.h"

int main()
{
    int key_symbols_of_shift;
    wstring Text_User;
    wstring Text_Crypt;
    wstring Text_De_Crypt;
    wstring Alphabet = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";
    wstring Alphabet_key = Alphabet;
    int number = -1;
    int end_number = 8;
    while (number != end_number)
    {
        show_menu();
        cin >> number;
        if (!(number >= 0 && number <= end_number))
        {
            cout << "Все плохо!\n";
        }
        else
        {
            work_menu(number, Text_User, Alphabet,
                      Alphabet_key, Text_Crypt,
                      Text_De_Crypt, key_symbols_of_shift);
        }
    }
    return 0;
}