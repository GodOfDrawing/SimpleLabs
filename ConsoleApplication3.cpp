
#include<Windows.h>
#include <iostream>
using namespace std;
/*
-основні операції (додавання та видалення елементу стека);
-змінити місцями перший та останній елемент стеку;
-розвернути стек (зробити «дно» стеку вершиною, а вершину –«дном»);
-операція «чи належить заданий елемент» стеку;
-видалити всі елементи стек*/
class lab3 {
    struct num {
        int i;
        num* next;
    };
    num* work;
    num* last;
    num* work2;
    num* first=NULL;


public:
    void AddAtBeggining()
    {
        work = new num;
        cout << "\nВведіть число n:";
        cin >> work->i;
        if (first == NULL)last = work;
        work->next = first;
        first = work;
    }

    void StackElemDelete()
    {
        if (first != NULL)
        {
            work = first;
            first = first->next;
            delete work;
        }
        else cout << "\nОперація недоступна!\n";
}

    void Show()
    {
        work = first;
        while (work != NULL)
        {
            cout << "Число:" << work->i << endl;
            work = work->next;
        }
    }
    void MoveElem()
    {
        if (first != NULL && first->next != NULL)
        {
            work = first;
            while (work->next->next != NULL)
            {
                work = work->next;
            }
            work2 = work->next;
            work2->next = first->next;
            first->next = NULL;
            work->next = first;
            last = first;
            first = work2;
        }
        else cout << "\nОперація недоступна!\n";
    }
    //Первая реализация
    /*    void Reverse()
    {
        work = first;
        num* work3;
        work2 = work->next;
        first->next = NULL;
        while (work2->next!=NULL)
        {
            work3 = work2->next;
            work2->next = work; 
            work = work2;

            work2 = work3;

        }  
        
        work3 = work2->next;
        work2->next = work;
        work = work2;

        work2 = work3;


        first = work;
    }*/
    //Нормальная реализация
    void Reverse()

    {
        if (first != NULL && first->next != NULL)
        {
            num* new_first = NULL;
            for (num* current = first; current;)
            {
                num* save_next = current->next;
                current->next = new_first;
                new_first = current;
                current = save_next;
            }
            first = new_first;
        }
        else cout << "\nОперація недоступна!\n";
    }
    void IsPart()
    {
        if (first != NULL)
        {
        work = first;
        cout << "Введіть елемент для перевірки його:";
        int abo;
        cin >> abo;
        while (work != NULL)
        {
            if (abo = work->i) {
                cout << "Елемент " << abo << " належить стеку!\n";
                break;
            }
            work = work->next;
        }
        }
        else cout << "\nОперація недоступна!\n";
    }
    void DeleteAll()
    {
        while (first != NULL)
        {
            work = first;
            first = first->next;
            delete work;
        }
        first = NULL;
        last = NULL;
    }

};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int b;
    lab3 f;
    while (1)
    {
        cout << "\t\t\t\tМеню\n1.Ввести елемент у початок списку\n2.Вивести список\n3.Видалити елемент стеку\n4.Пересунути елемент\n5.Чи являється елемент частиною стеку\n6.Очитстити стек\n7.Перегорнути стек\n";
        cin >> b;
        switch (b)
        {
        case 1:f.AddAtBeggining(); break;
        case 2:f.Show(); break;
        case 3:f.StackElemDelete(); break;
        case 4:f.MoveElem(); break;
        case 5:f.IsPart(); break;
        case 6:f.DeleteAll(); break;
        case 7:f.Reverse(); break;
        }
    }
}
