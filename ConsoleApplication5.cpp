
#include<Windows.h>
#include <iostream>
using namespace std;

int MyltiplyHash(int b,const int tableSize)
{
    return tableSize*fmod((b* 0.618033), 1);

}
int DivideHash(int a, const int tableSize)
{
    return a % tableSize;
}
int UniversalHash(string s,int tableSize)
{
    int hashVal = 0;

    for (int i = 0; i < s.length(); i++)
        hashVal = 37 * hashVal + s[i];

    hashVal %= tableSize;

    if (hashVal < 0)
        hashVal += tableSize;

    return hashVal;


}
string KeyInput()
{
    cout << "\nУведіть ключ:";
    string s;
    cin >> s;
    return s;
}
double KeyInputInt()
{
    cout << "\nУведіть ключ:";
    double s;
    cin >> s;
    return s;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int b;
   while (1)
    {
        cout << "\t\t\t\tМеню\n1.Хешування множенням\n2.Хешування діленням\n3.Хешування строки\n4.Вихід\n";
        cin >> b;
        switch (b)
        {
        case 1:cout<<"Результат хешування="<<MyltiplyHash(KeyInputInt(), 100)<<endl; break;
        case 2:cout << "Результат хешування=" << DivideHash(KeyInputInt(), 100)<<endl; break;
        case 3:cout << "Результат хешування=" << UniversalHash(KeyInput(), 100)<<endl; break;
        case 4:return 0;

        }
    }
}
