#include <iostream>
#include <vector>
using namespace std;
class Doctor
{
public:
    int id;
    string name;
    string role;
    Doctor(int i, string n, string r)
    {
        id = i;
        name = n;
        role = r;
    }
};
class Hopital
{
public:
    vector<Doctor> doctors;
    void adddoctor(Doctor doctor)
    {
        doctors.push_back(doctor);
    }
    void updateadoctor(int id, Doctor doctor)
    {
        for (int i = 0; i < doctors.size(); i++)
        {
            if (doctors[i].id = id)
            {
                doctors[i] = doctor;
                break;
            }
        }
    }
    void deleteadoctor(int id)
    {

        for (int i = 0; i < doctors.size(); i++)
        {
            if (doctors[i].id == id)
            {
                doctors.erase(doctors.begin() + i);
                break;
            }
        }
    }
    bool find_Adoctor(int id)
    {
        for (int i = 0; i < doctors.size(); i++)
        {
            if (doctors[i].id == id)
            {
                return true;
            }
        }
        return false;
    }
    void display()
    {
        for (int i = 0; i < doctors.size(); i++)
        {
            cout << "the id is :"
                 << doctors[i].id << endl;
            cout << "the name is :"
                 << doctors[i].name << endl;
            cout << "the role is :"
                 << doctors[i].role << endl;
        }
    }
};
int main()
{
    int choise;
    Hopital hopital;
    while (true)
    {

        cout << "system management hopital" << endl;
        cout << "1 add a doctor" << endl;
        cout << "2  delete a doctor" << endl;
        cout << "3 update a doctor" << endl;
        cout << "4 display the doctors" << endl;
        cout << "5 find a doctor" << endl;

        cout << "6 exsit" << endl;
        cin >> choise;
        if (choise == 1)
        {
            int id;
            string name;
            string role;
            cout << "enter a id";
            cin >> id;
            cout << "enter a name";
            cin >> name;
            cout << "enter a role";
            cin >> role;
            Doctor doctor(id, name, role);

            hopital.adddoctor(doctor);
        }
        else if (choise == 2)
        {
            int id;
            cout << "enter a id: ";
            cin >> id;
            hopital.deleteadoctor(id);
        }
        else if (choise == 3)
        {

            int id;
            string name;
            string role;
            cout << "enter a id";
            cin >> id;
            cout << "enter a name";
            cin >> name;
            cout << "enter a role";
            cin >> role;
            Doctor doctor(id, name, role);

            hopital.updateadoctor(id, doctor);
        }
        else if (choise == 4)
        {
            hopital.display();
        }
        else if (choise == 5)
        {
            int id;
            cout << "Enter an ID for search: ";
            cin >> id;
            if (hopital.find_Adoctor(id))
            {
                cout << "The doctor is found and has a time slot\n";
            }
            else
            {
                cout << "Doctor with this ID not found\n";
            }
        }
        else if (choise == 6)
        {
            break;
        }
    }
    return 0;
}
