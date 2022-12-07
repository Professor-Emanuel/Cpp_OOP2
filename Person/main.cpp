#include <iostream>

//base class
class Person{
private:
    int id;
    char name[100];

public:
    void setPerson(){
        std::cout<<"Enter the id: ";
        std::cin>> id;

        fflush(stdin);

        std::cout<< "Enter the name: ";
        std::cin.get(name, 100);
    }

    void displayPerson(){
        std::cout<< id << "\t" << name << "\t";
    }
};

//derived class
class Student:private Person{
    char course[50];
    int fee;

public:
    void setStudent(){
        setPerson();
        std::cout<< "Enter course name: ";
        fflush(stdin);
        std::cin.getline(course, 50);
        std::cout<<"Enter the course fee: ";
        std::cin>>fee;
    }

    void displayStudent(){
        displayPerson();
        std::cout<< course <<"\t" << fee << std::endl;
    }
};

int main()
{
    Student s;
    s.setStudent();
    s.displayStudent();
    return 0;
}
