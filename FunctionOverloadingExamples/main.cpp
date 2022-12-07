#include <iostream>

class printData{
public:
    void print(int i){
        std::cout<<"Printing int: "<< i << std::endl;
    }
    void print(double f){
        std::cout<<"Printing float: "<< f << std::endl;
    }
    void print(char const *c){
        std::cout<<"Printing character: "<< c << std::endl;
    }
};

void add(int a, int b){
    std::cout<<"Sum = " << (a+b) << std::endl;
}

void add(double a, double b){
    std::cout<<"Sum = " << (a+b) << std::endl;
}

void add(int a, int b, int c){
    std::cout<<"Sum = " << (a+b+c) << std::endl;
}

/*
Function Overriding (achieved at run time)
It is the redefinition of base class function in its derived class with same signature i.e return type and parameters.
*/
class BaseClass{
public:
    virtual void Display(){
        std::cout<<"Display() method in base class" <<std::endl;
    }

    void Show(){
        std::cout<<"Show() method in base class" <<std::endl;
    }
};

class DerivedClass:public BaseClass{
public:
    // Overriding method - new working of
    // base class's display method
    void Display(){
        std::cout<<"Display() method in derived class" <<std::endl;
    }
};

int main()
{
    printData pd;

    pd.print(2);
    pd.print(30.10);
    pd.print("Hello C++");

    add(10, 20);
    add(10.10, 20.20);
    add(10, 20, 30);

    //overriding
    DerivedClass dr;
    BaseClass &bs = dr;
    bs.Display();
    dr.Show();

    return 0;
}
