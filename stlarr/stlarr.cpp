#include <iostream>
#include <map>
#include <windows.h>
using namespace std;
typedef pair<string, string> mypair;

class PhoneBook
{
    map<string, string> book;
public:
    void Add(string s1, string s2)
    {
        book.insert(mypair(s1, s2));
    }
    void Find(string s1)
    {
        auto ptr = book.find(s1);
        if (ptr != book.end())
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
    }
    void Delete(string s1)
    {
        auto ptr = book.find(s1);
        if (ptr != book.end())
        {
            book.erase(ptr->first);
        }
        else
        {
            cout << "No value";
        }
    }
    void Output()
    {
        for (auto ptr = book.begin(); ptr != book.end(); ptr++)
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
    }
};

class Student
{
    string name;
    int average;
public:
    Student(string n, int a)
    {
        name = n;
        average = a;
    }
    void Output()
    {
        cout << name << "\nAverage: " << average << endl << endl;
    }
};
typedef pair<int, Student> stpair;

class Dictionary
{
    map<string, string> dict;
public:
    void Add(string s1, string s2)
    {
        dict.insert(mypair(s1, s2));
    }
    void Find(string s1)
    {
        auto ptr = dict.find(s1);
        if (ptr != dict.end())
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
    }
    void Delete(string s1)
    {
        auto ptr = dict.find(s1);
        if (ptr != dict.end())
        {
            dict.erase(ptr->first);
        }
        else
        {
            cout << "No value";
        }
    }
    void Output()
    {
        for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");

    PhoneBook book;
    book.Add("john", "38041334533");
    book.Add("rose", "38045612344");
    book.Add("dave", "38010251111");
    book.Output();
    book.Find("rose");


    Student st1("john", 10);
    Student st2("rose", 12);
    Student st3("dave", 9);
    map<int, Student> students;
    students.insert(stpair(1, st1));
    students.insert(stpair(2, st2));
    students.insert(stpair(3, st3));
    for (auto ptr = students.begin(); ptr != students.end(); ptr++)
    {
        cout << ptr->first << ".\n";
        ptr->second.Output();
    }
    auto ptr = students.find(2);
    if (ptr != students.end())
    {
        cout << ptr->first << ".\n";
        ptr->second.Output();
    }
    

    Dictionary dict;
    dict.Add("dog", "собака");
    dict.Add("cat", "кот");
    dict.Add("city", "город");
    dict.Output();
    dict.Delete("city");
    dict.Output();
    dict.Find("cat");

}