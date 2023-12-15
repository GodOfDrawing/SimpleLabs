
#include<Windows.h>
#include <iostream> 
using namespace std;


class HashQueue {


    struct Map {
        bool deleted=false;
        string key="";
        string value="";
    };
    Map* mas;
    //Перевизначення в даній лабораторній роботі не реалізовано
    int tableSize = 1000;



public:
    HashQueue() {
        mas=new Map[tableSize];

    }
    ~HashQueue() {
        delete[] mas;
    }
    string WriteKey()
    {
        string b;
        cout << "\nУведiть ключ:";
        cin >> b;
        return b;
    }
    


  
    void Delete()
    {
        string b = WriteKey();
        int j = DoubleHash(b, 0);

        if (mas[j].key ==b) {
            mas[j].key = "";
            mas[j].value = "";
            mas[j].deleted = true;
            cout << "\nЕлемент було успішно видалено!\n";
            return;
        }
        else {
            for (int i = 0; i < tableSize; i++)
            {

                j = DoubleHash(b, 1);
                if (mas[j].key == "" && mas[j].deleted == false) {
                    cout << "\nЕлементу з ключем " << b << " не існує!\n";
                    return;
                }
                if (mas[j].key == b) {
                    mas[j].key = "";
                    mas[j].value = "";
                    mas[j].deleted = true;
                    cout << "\nЕлемент було успішно видалено!\n";
                }      
            }
            cout << "\nЕлементу з ключем " << b << " не існує!Таблиця завповнена!\n";

        }

    }
    void FindElem()
    {

        string b = WriteKey();
        int j = DoubleHash(b, 0);
        for (int i = 0; i < tableSize; i++)
        {
            if (mas[j].key == "" && mas[j].deleted == false)
            {
                cout << "\nЕлементу з ключем " << b << " не існує!\n";
                return;
            }
            if(mas[j].key==b){
                cout << "\nValue елементу з ключем " << b << " =" << mas[j].value << endl;
                return;
            }
            j = DoubleHash(b, 1);
        }
    }

    void AddElem()
    {
        string b = WriteKey();
        int j= DoubleHash(b,0);
        if (mas[j].key == b)
        {
            cout << "\nЕлемент з таким ключем вже існує!\n"; return;
        }
        if (mas[j].value == "") {
            mas[j].key = b;
            cout << "\nУведіть значення value:";
            cin >> mas[j].value;
        }
        else {
            for (int i = 0; i < tableSize; i++)
            {
                j = DoubleHash(b, 1);
                if (mas[j].key == b)
                {
                    cout << "\nЕлемент з таким ключем вже існує!\n"; return;
                }
                if (mas[j].value == "")
                {
                    mas[j].key = b;
                    cout << "\nУведіть значення value:";
                    cin >> mas[j].value;
                    return;
                }
            }
            cout << "\nТаблиця повністью заповнена, елемент не було вставлено!\n";
            
        }
    }
    
    //I won't use multiply cuz i don't wanna balance it...yeah?
    int DoubleHash(string b,int koef)
    {
        int firsthash = UniversalHashFunction1(b);
        int secondhash = HashFunction2(firsthash);
        return (firsthash + koef * secondhash) % tableSize;

    }
    int HashFunction2(int firsthash)
    {
        return 1 + firsthash % (tableSize - 1);

    }
    int UniversalHashFunction1(string s)
    {
        int hashVal = 0;
        for (int i = 0; i < s.length(); i++)
            hashVal = 37 * hashVal + s[i];
        hashVal %= tableSize;
        if (hashVal < 0)
            hashVal += tableSize;
        return hashVal;
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int b;



    HashQueue s;
    while (1)
    {
        cout << "\n\t\t\t\tМеню\n1.Додати пару ключ-значення\n2.Видалити пару ключ-значення за ключем\n3.Пошук значення за ключем\n4.Вихід\n";
        cin >> b;

        switch (b)
        {
        case 1:s.AddElem(); break;
        case 2:s.Delete(); break;
        case 3:s.FindElem(); break;
        case 4:return 0;

        }
    }
}
