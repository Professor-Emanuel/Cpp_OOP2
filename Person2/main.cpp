#include <iostream>
#include<string.h>

//base class
class Person{
    int id;
    char name[100];

public:
    void setPerson(int, char[]);
    void displayPerson();
};

void Person::setPerson(int id, char n[]){
    this->id = id;
    strcpy(this->name, n);
}

void Person::displayPerson(){
    std::cout<< id << "\t" << name << "\t";
}

//derived class
class Student:private Person{
private:
    char course[50];
    int fee;

public:
    void setStudent(int, char[], char[], int);
    void displayStudent();
};

void Student::setStudent(int id, char n[], char c[], int f){
    setPerson(id, n);
    strcpy(course, c);
    fee = f;
}

void Student::displayStudent(){
    displayPerson();
    std::cout<< course <<"\t"<< fee;
}

int main()
{
    Student s;
    s.setStudent(1001, "Emanuel", "Math101", 2000);
    s.displayStudent();
    return 0;
}
