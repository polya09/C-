#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include <sstream>
# include < list>

using namespace std;

struct Subject {
    string name;
    string TypeControl;
    int LectureHours;
    int HoursOfPractice;
    string F;
    string I;
};

void DataEntry(Subject* (&s), int& n) {
    cout << "������� ����������� ������: ";
    cin >> n;
    s = new Subject[n];
    for (int i = 0; i < n; i++)
    {
        cout << "������� ������������:   ";
        cin >> s[i].name;
        cout << "��� ��������� ��������(�����/�������):   ";
        cin >> s[i].TypeControl;
        cout << "���-�� ���������� �����:   ";
        cin >> s[i].LectureHours;
        cout << "���-�� ����� �� ��������:   ";
        cin >> s[i].HoursOfPractice;
        cout << "������� ������� � ��� �������������:   ";
        cin >> s[i].F;
        cin >> s[i].I;
    }
}
void Print(Subject* s, int n)
{
    for (int i = 0; i < n; i++) {
        cout << "������������:  " << s[i].F << endl;
        cout << "��� ��������� ��������:  " << s[i].F << endl;
        cout << "���-�� ���������� �����:  " << s[i].F << endl;
        cout << "���-�� ����� �� ��������:  " << s[i].F << endl;
        cout << "���, ������� ������������� :  " << s[i].F << "   " << s[i].I << endl;
        cout << "_______________________________________" << endl;
    }
}

void task1() {

    float B;
    char C[10];
    //int a = atoi(const char* str);
    //long b = atol(const char* str);
    //double c = atof(const char* str);
    B = atof(C);
    cout << B << " ";
}
void task2() {

    list<double> l = { 10 , 2 , 22 , 2, -14 , 5.5 };

    list<double>::iterator p = l.begin();
    for (; p != l.end(); ++p)
        cout << *p << '  ';
    cout << endl;

    for (p = l.begin(); p != l.end();)
    {
        if (*p == 2)
        {
            l.insert(++p, 1);
        }
        else
            ++p;
    }
    cout << endl;
    for (p = l.begin(); p != l.end(); ++p)
        cout << *p << '  ';
    cout << endl;

}
void task3()
{
    /*��� �����, ��������� �� ����, ����������� ���������� � ������� ����������.
    ���������� ����� ������ ������� ����� � ������.*/

    string str, s, word;
    int max = 0;
    cout << "Input str:" << endl;
    getline(cin, str);
    str += ' ';
    for (int i = 0; str[i]; i++)
    {
        s += str[i];
        if (!(isalpha(str[i])))
        {
            s.pop_back();
            if (s != "")
                if (s.length() > max)
                {
                    max = s.length();
                    word = s;
                }
            s = "";
        }
    }
    cout << "����� ������� �����: " << word << endl;
    cin.get();
}

void task4() {
    /* �� ������ ���������� ������� "����������": ������������; ��� ��������� ��������(�����/�������); ���-�� ���������� �����;
    ���-�� ����� �� ��������; �������������(�������, ���); ������� ������������ ������ ��������. ����������� �������-������,
    ������� �� �������� ������ ���� ���������� � �������� ���������, ���������� ������ ����������. ��� ������ ������� �
    ���������� ������� �� ����� ���������� �������.*/

    int amoundOfData = 0;
    Subject* s = new Subject[amoundOfData];
    DataEntry(s, amoundOfData);
    system("cls");
    Print(s, amoundOfData);
    //DataFind(s, amoundOfData);

}
void task5()
{
    double q;
    ofstream fout("f_task5.txt");
    ofstream f("g_task5.txt");
    cout << "Enter 10 marks (from 1 to 12):\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> q;
        fout << q << endl;
    }
    fout.close();

    ifstream fin("f_task5.txt");

    if (fin.is_open())
    {
        double a, sum = 0.0;
        int Qg = 0, Qb = 0;
        while (fin >> a)
        {
            if (a >= 10)
                Qg++;
            if (a <= 3)
                Qb++;
            sum += a;
        }
        double cp = sum / 10;
        cout << "������� ���� �� �����������: = " << cp << "\n";
        f << cp << endl;
        cout << "����������� ������� ������: " << Qg << endl;
        f << Qg << endl;
        cout << "����������� ������ ������:"
            << Qb << endl;
        f << Qb;
    }
    else
        cout << "������ �������� �����\n";

    fin.close();
    fout.close();
    f.close();
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task1();
    task2();
    task3();
    task4();
    task5();
}

