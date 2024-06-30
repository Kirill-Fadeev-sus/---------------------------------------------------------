#include <iostream>
#include <cmath>

using namespace std;



int ConvertToTen(string number, int base)
{
    int result = 0;

    for (int i = 0; i < number.length(); i++)
    {
        int digit;

        if (number[i] >= '0' && number[i] <= '9')
        {
            digit = (int)number[i] - 48;
        }
        else
        {
            digit = number[i] - 'A' + 10;
        }
        result += digit * (int)pow(base, number.length() - 1 - i);
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");

    string number;
    int base;
    char choice;

    while (true)
    {
        cout << "Введите систему счисления вашего числа (2-30): ";
        cin >> base;

        cout << "Введите число: ";
        cin >> number;

        if (base < 2 || base > 30)
        {
            cout << "Система счисления должна быть от 2-ой до 30-ой!" << endl;
            continue;
        }

        int result = ConvertToTen(number, base);

        cout << "Число в 10-ой системе: " << result << endl;

        cout << "Хотите начать сначала? (y/n): ";
        cin >> choice;

        if (choice == 'n')
        {
            system("cls");
            cout << "Завершение программы...";
            break;
        }
        else if (choice == 'y')
        {
            continue;
        }
        else
        {
            cout << "Некорректный ввод! \n" << "Попробуйте еще раз: ";
            cin >> choice;

            if (choice == 'n')
            {
                system("cls");
                cout << "Завершение программы...";
                break;
            }
        }
    }

    system("pause");
    
    return 0;
}
