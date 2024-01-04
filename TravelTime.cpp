#include <iostream>
#include <cstdlib>

using namespace std;

int AskTime(string text) { // Метод проверяет корректность ввода данных и переводит строковое значение 
                           // в целочисленное, с переводом часов в минуты
    int hours;
    int minutes;
    string time;

    while (true) { // В первом ифе проверяем что 0, 1, 3 и 4 значение являются цифрой
        cout << text;
        cin >> time;
        if (time.length() != 5 || time[0] < '0' || time[0]>'9' || time[1] < '0' || time[1]>'9'
            || time[3] < '0' || time[3]>'9' || time[4] < '0' || time[4]>'9' || time[2] != ':') {
            cout << " Ввод некорректен, попробуйте ещё раз." << endl;
            // Данные две строки необходимы для очистки буфера ввода, без них, 
            // при последующем вводе данных, произойдёт зацикливание:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else { // Во втором ифе проверяем что введённые часы и минуты не выходят за предел
            hours = (time[0] - '0') * 10 + (time[1] - '0');
            minutes = (time[3] - '0') * 10 + (time[4] - '0');
            if (hours > 23 || minutes > 59) {
                cout << " Ввод некорректен, попробуйте ещё раз." << endl;
                // Данные две строки необходимы для очистки буфера ввода, без них, 
                // при последующем вводе данных, произойдёт зацикливание:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else return hours*60+minutes; // Если всё корректно переводим часы в минуты и возвращаем
        }
    }
}

int main()
{
    // Изменение кодировки терминала:
    system("chcp 1251 > nul");
    // Установка цвета фона терминала и цвета текста
    system("color 80");

    cout << endl;
    string text1 = " Введите время отправления (HH:MM): "; // Тексты для запроса данных
    string text2 = " Введите время прибытия (HH:MM): ";
    int departure = AskTime(text1);                        // Переменные отправления и пребытия в минутах
    int arrival = AskTime(text2);

    if (departure > arrival) {  // Если отправление больше пребытия то прибавляем к пребытию 24 часа в минутах
        cout << " Поездка составила " << ((arrival + 24 * 60) - departure) / 60 << " час. " 
            << ((arrival + 24 * 60) - departure) % 60 << " мин." << endl;
    }
    else {                     // Иначе просто из пребытия вычитаем отправление
        cout << " Поездка составила " << (arrival - departure) / 60 << " час. " 
            << (arrival - departure) % 60 << " мин." << endl;
    }
    
    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}