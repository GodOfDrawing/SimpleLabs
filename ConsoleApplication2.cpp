// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<Windows.h>
#include <iostream>
using namespace std;

class lab2 {
    struct num {
        int i;
        num* next;
    };
    num* work;
    num* work2;
    num* work3;
    num* copy;
    num* copy_first;
    num* first = NULL;
    num* sameMerged=NULL;
    num* sameMergedfirst=NULL;
    int n = 0;



public:
    void AddAtBeggining()
    {
        work = new num;
        cout << "\nВведіть число n:";
        cin >> work->i;
        work->next = first;
        first = work;
        n++;
    }
    void InsertAt()
    {

        if (first == NULL) AddAtBeggining();
        else{
        int Inum;
        work = new num;
        cout << "\nПісля якого елементу зробити вставлення:";
        cin >> Inum;
        work2 = work;
        if (Inum > n) cout << "Неможливо зробити вствавлення.Останній елемент має номер: " << n << endl;
        else
        {
            cout << "\nВведіть число n:";
            cin >> work->i;
            work = first;
            for (int b = 0; b < Inum - 1; b++)
            {
                work = work->next;
            }
            work3 = work->next;
            work->next = work2;
            work2->next = work3;
            n++;
        }
            }
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
    void Move()
    {
        if (first != NULL && first->next != NULL)
        {
            int Inum, Gnum;
            cout << "\nЯкий елемент перемістити:";
            cin >> Inum;
            if (Inum > n) cout << "Неможливо виконати операцію.Останній елемент має номер: " << n << endl;
            else
            {
                cout << "\nНа скільки позицій вправо перемістити:";
                cin >> Gnum;


                if (Inum + Gnum > n) cout << "Неможливо виконати операцію.Останній елемент має номер: " << n << endl;
                else
                {
                    if (Inum == 1) {
                        work3 = first;
                        first = first->next;
                        work = first;
                        for (int b = 0; b < Gnum - 1; b++)
                            work = work->next;
                        work2 = work->next;
                        work->next = work3;
                        work3->next = work2;

                    }

                    else
                    {
                        work = first;
                        for (int b = 0; b < Inum - 2; b++)
                        {
                            work = work->next;
                        }
                        work3 = work->next;
                        work->next = work->next->next;


                        for (int b = 0; b < Gnum; b++)
                        {
                            work = work->next;
                        }
                        work2 = work->next;
                        work->next = work3;
                        work3->next = work2;
                    }
                }
            }
        }
        else cout << "\nВ списку недостатньо елементів для цієї операції!\n";
        }
    void DeleteCh()
    {
        int target;
        cout << "Введіть елемент для видалення:";
        cin >> target;
        if(target>n) cout<< "Неможливо виконати операцію.Останній елемент має номер: " << n << endl;
        else {
            if (target == 1)
            {
                work3 = first;
                first = first->next;
                delete work3;
            }
            else
            {
                work = first;
                for (int i = 1; i < target - 1; i++)
                {
                    work = work->next;
                }
                work3 = work->next;
                work->next = work->next->next;
                delete work3;
            }
        }
    }
    void DeleteEach()
    {
        int target;
        cout << "\nВидалити кожен:";
        cin >> target;
        if(n<target)cout<<"В списку немає таких елементів!Останній елемент має номер: " << n << endl;
        else {
            if (target == 1)DeleteAll();
            int targ=1;
            work = first;
            work3 = NULL;
            while (work!=NULL)
            {
                if (((targ + 1) % target==0) && (work->next != NULL))
                {
                    work3 = work->next;      
                    if (work->next != NULL)work->next = work->next->next;
                    if (targ == target)work2 = work3;
                    work3->next = NULL;
                    work3 = work3->next;
                    targ++;
                    n--;
                }
                work = work->next;
                targ++;
            }
            work3 = work2;
            while (work3!=NULL)
            {     
                work2 = work3;
                work3 = work3->next;
                delete work2;
            }

            }
        }
    
    void DeleteAll()
    {            
        work = first;
        while (work != NULL)
        {
            n--;
            work3 = work;
            work = work->next;
            delete work3;
        }
        first = NULL;
    }

    void Sort()
    {
        work = first;
        
        for (int b = 1; b < n; b++) {
            work = first;
            for (int j = 1; j < n; j++)
            {
                if (work->next != NULL)
                {
                    if ((work->i > work->next->i)) swap(work->i, work->next->i);
                    work = work->next;
                }
            }
        }
    }
    void Copy()
    {
        if (first != NULL) {
            work = first;
            copy = new num;
            copy->i = work->i;
            copy_first = copy;
            work = work->next;
           while(work!=NULL){
                copy->next = new num;
                copy = copy->next;
                copy->i = work->i;    
                work = work->next;
            }
                copy->next = NULL;

        }
    }
    void Merge()
    {
        work = first;
        if (first != NULL)
        {
            while (work->next != NULL)
            {
                work = work->next;
            }
            work->next = copy_first;
        }
        else first = copy_first;
    }
    void MergeSame()
    {
        if (copy_first != NULL)
        {
            int counter = 0;
            while (copy != NULL)
            {
                counter++;
                copy = copy->next;
            }
            
            for (int j = 1; j < counter; j++)
            {
                work = first;
                for (int b = 1; b < n; b++)
                {
                    if (copy->i == work->i)
                    {
                        sameMerged = new num;
                        sameMerged->i = copy->i;
                        sameMerged->next = NULL;
                        if (first == NULL) first = sameMerged;
                        sameMerged = sameMerged->next;
                        break;
                    }
                    work = work->next;
                }
                copy = copy->next;
            }
        }
        else cout << "Помилка, лист для зливання пустий!";
    }

    };
    int main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "rus");
        int b;
        lab2 f;
        while (1)
        {
            cout << "\t\t\t\tМеню\n1.Ввести елемент у початок списку\n2.Вставити елемент у список\n3.Вивести список\n4.Пересунути елемент\n5.Видалити обраний елемент\n6.Видалити кожний n-ий елемент\n7.Сортування за спаданням\n8.Копіювання списку\n9.Очищення списку\n10.Склеювання двох списків\n11.Створити список, який містить спільні елементи двох списків\n";
            cin >> b;
            switch (b)
            {
            case 1:f.AddAtBeggining(); break;
            case 2:f.InsertAt(); break;
            case 3:f.Show(); break;
            case 4:f.Move(); break;
            case 5:f.DeleteCh(); break;
            case 6:f.DeleteEach(); break;
            case 7:f.Sort(); break;
            case 8:f.Copy(); break;
            case 9:f.DeleteAll(); break;
            case 10:f.Merge(); break;
            case 11:f.MergeSame(); break;
            }
        }
    }
