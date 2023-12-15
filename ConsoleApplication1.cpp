#include"windows.h"
#include <iostream>
using namespace std;
class CitizensList {

    struct Citizen {
        string name, surname;
        string city, adress;
        char gender;
        Citizen* next;
    };
    Citizen* first = NULL;
    Citizen* citiz;
    Citizen* swaper;
public:
    void add()
    {

        citiz = new Citizen;
        cout << "Введiть призвiсько:";
        cin >> citiz->name;
        cout << "\nВведiть iм'я:";
        cin >> citiz->surname;
        cout << "\nВведiть мiсто:";
        cin >> citiz->city;
        cout << "\nВведiть адресу:";
        cin >> citiz->adress;
        cout << "\nВведiть генедер(Ж/М):";
        cin >> citiz->gender;
        citiz->next = first;
        first = citiz;
    }
    void show_elem()
    {
        cout << "ПI: " << citiz->surname << " " << citiz->name << '\n';
        cout << "Гендер:" << citiz->gender << '\n';
        cout << "Мiсце проживання: " << citiz->city << ',' << citiz->adress << "    \n\n";

    }
    void show()
    {
        citiz = first;
        while (citiz != NULL) {
            show_elem();
            citiz = citiz->next;
        }
    }

    void bad_sort()
    {
        citiz = first;
        int count = 0;
        while (citiz != NULL)
        {
            count++;
            citiz = citiz->next;
        }
        for (int i = 0; i <= count; i++)
        {
            citiz = first;
            for (int b = 0; b < count - 1; b++)
            {
                if (citiz->adress > citiz->next->adress)
                {
                    swap(citiz->adress, citiz->next->adress);
                    swap(citiz->name, citiz->next->name);
                    swap(citiz->surname, citiz->next->surname);
                    swap(citiz->city, citiz->next->city);
                    swap(citiz->gender, citiz->next->gender);

                }
                citiz = citiz->next;
            }

        }
        citiz = first;
    }
    void show_magick()
    {
        bad_sort();
        
        citiz = first;

        bool same = false;
        while (citiz != NULL)
        {
            if (citiz->next != NULL && citiz->adress == citiz->next->adress)
            {
                show_elem(); same = true;
            }
            else if (same == true)
            {
                show_elem(); same = false;
            }
            citiz = citiz->next;
        }
    }
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");
    CitizensList obj;

    int answer;
        while (1)
        {
            cout << "\t\t\tМеню\n1.Ввести iнформацiю жителя\n2.Вивести iнформацiю жителiв\n3.Вивести iнформацiю жителiв, що живуть на однiй вулицi\n4.Вихiд\n";
            cin >> answer;
            switch (answer)
            {
            case 1:obj.add(); break;
            case 2:obj.show(); break;
            case 3:obj.show_magick(); break;
            case 4: return 0;
            }

        }
    
}
