#include "funcs_2.h"
#include "menu_2.h"

int main()
{
    vector<wchar_t> Alphabet = { L'А', L'Б', L'В', L'Г', L'Д', L'Е', L'Ж', L'З', L'И', L'Й', L'К',
                                 L'Л', L'М', L'Н', L'О', L'П', L'Р', L'С', L'Т', L'У', L'Ф', L'Х', L'Ц',
                                 L'Ч', L'Ш', L'Щ', L'Ъ', L'Ы', L'Ь', L'Э', L'Ю', L'Я'};
    wstring Text_User;
    vector <int> Frequency(32, 0);
    bool flag_input_text = false;
    int number = -1;
    int end_number = 5;
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
            work_menu(Text_User, Alphabet, Frequency, flag_input_text, number);
        }
    }
    return 0;
}