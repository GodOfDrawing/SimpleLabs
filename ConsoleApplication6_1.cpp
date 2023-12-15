
#include<Windows.h>
#include <iostream> 
using namespace std;


class HashQueue {   


    struct Map {
        string key;
        string value;
        Map* next;
    };   
    Map** mas;
    //Перевизначення в даній лабораторній роботі не реалізовано
    int tableSize = 1000;



public:
    HashQueue() {
        mas = new Map * [tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            mas[i] = NULL;
        }
    }

    string WriteKey()
    {
        string b;
        cout << "\nУведiть ключ:";
        cin >> b;
        return b;
    }
    bool SameKeyExists(Map*elem,string&b)
    {
        while (elem != NULL)
        {
            if (elem->key == b)
            {
                return true;
            }
            elem = elem->next;
        }
        return false;
    }
    Map* CreateElem(int c,string&b)
    {
        Map *q= new Map;
        cout << "\nУведіть value:";
        cin >> q->value;
        q->key = b;
        q->next = NULL;
        return q;
    }
    void AddElem()
    {
        string b = WriteKey();
        int j = UniversalHash(b);
        if (mas[j] == NULL)
        {
            mas[j] = CreateElem(j,b);
        }
        else {
           Map* work;
           work = mas[j];
           if (SameKeyExists(work, b) == 1) cout << "\nЕлемент з key=" << b << " вже існує!\n";
           else {
               work = mas[j];
               while (work->next != NULL) work = work->next;
               work->next = CreateElem(j, b);

           }
        }

    }
    void Delete()
    {
        string b = WriteKey();
        int j = UniversalHash(b);
        Map* work = mas[j];

        if (work==NULL)
        {
            cout << "Не має=" << b << endl;
            return;
        }
        if (work->key == b)
        {
            Map* del = work;
            mas[j] = work->next;
            delete del;
            cout << "\nЕлемент видалено!\n";
            return;
        }
        while (work->next != nullptr)
        {
            if (work->next->key == b)
            {
                Map* del = work->next;
                work->next = work->next->next;
                delete del;
                cout << "\nЕлемент видалено!\n";
                return;
            }
            work = work->next;
        }
        cout << "Не було знайдено елементу з ключем=" << b << endl;


    }
    void FindElem()
    {
        string b = WriteKey();
        int j = UniversalHash(b);
        if (mas[j] != NULL)
        {
            if (mas[j]->key == b)
            {
                cout << "Key=" << mas[j]->key << " \nValue=" << mas[j]->value;
            }
        }
    }
    void Show()
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (mas[i] != NULL) { cout << "Key=" << mas[i]->key << " \nValue=" << mas[i]->value; 
            if (mas[i]->next != NULL) {
                cout << "DUUUUUDE Key=" << mas[i]->next->key << " \nValue=" << mas[i]->next->value;
            }
            }
        }
    }
    int UniversalHash(string s)
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
        cout << "\t\t\t\tМеню\n1.Додати пару ключ-значення\n2.Видалити пару ключ-значення за ключем\n3.Пошук значення за ключем\n4.Вивести значення-колізії\n5.Вихід\n";
        cin >> b;

        switch (b)
        {
        case 1:s.AddElem(); break;
        case 2:s.Delete(); break;
        case 3:s.FindElem(); break;
        case 4:s.Show(); break;
        case 5:return 0;

        }
    }
}
