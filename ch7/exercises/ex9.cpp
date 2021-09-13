// ex9.cpp -- student struct
#include <iostream>
#include <iomanip>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// Solicit and store data about students.
int GetInfo(student pa[], int n);

// Display information of a studnet: value passing
void Display1(student st);

// Display information of a student: address passing
void Display2(const student *st);

// Display contents of an array of students
void Display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student *ptr_stu = new student[class_size];
    int entered = GetInfo(ptr_stu, class_size);
    for (int i = 0; i < entered; ++i)
    {
        Display1(ptr_stu[i]);
        Display2(&ptr_stu[i]);
    }
    Display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";

    return 0;
}

int GetInfo(student pa[], int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        cout << "Student #" << i + 1 << "\n";
        cout << "Name: ";
        cin.getline(pa[i].fullname, SLEN);
        cout << "Hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Ooplevel: ";
        cin >> pa[i].ooplevel;
        while (cin.get() != '\n') continue;
    }
    return i;
}

void Display1(student st)
{
    cout << setw(SLEN) << "Full Name"
         << setw(SLEN)  << "Hobby"
         << setw(SLEN) << "Ooplevel" << endl;
    cout << setw(SLEN) << st.fullname
         << setw(SLEN)  << st.hobby
         << setw(SLEN) << st.ooplevel << endl;
}

void Display2(const student *st)
{
    cout << setw(SLEN) << "Full Name"
         << setw(SLEN)  << "Hobby"
         << setw(SLEN) << "Ooplevel" << endl;
    cout << setw(SLEN) << st->fullname
         << setw(SLEN)  << st->hobby
         << setw(SLEN) << st->ooplevel << endl;
}

void Display3(const student pa[], int n)
{
    cout << setw(SLEN) << "Full Name"
         << setw(SLEN)  << "Hobby"
         << setw(SLEN) << "Ooplevel" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << setw(SLEN) << pa[i].fullname
             << setw(SLEN)  << pa[i].hobby
             << setw(SLEN) << pa[i].ooplevel << endl;
    }
}
