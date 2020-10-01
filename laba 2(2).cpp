#include <iostream>
#include <string>
#include <algorithm> // для сортировки
#include <sstream> // для разбиения предложения на слова

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите произвольное предложение:\n";
    string str;
    getline(cin, str);

    stringstream ss(str);//создается  объект  stringstream под названием ss c содержимым str

    string word, newStr;
    while (ss >> word) // разбиваем строку на слова
    {
        sort(word.begin(), word.end()); // сортируем буквы в слове
        newStr += word + " "; // формируем новую строку
    }
    cout << newStr << endl;
    return 0;
}
