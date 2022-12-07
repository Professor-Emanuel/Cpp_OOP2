#include <iostream>

using namespace std;

//base class
class Parent{
public:
    int id_p;
};

//derived class
class Child:public Parent{
public:
    int id_c;
};

//base class
class A{
public:
    int x;

protected:
    int y;

private:
    int z;
};

//derived class
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

//1. Single Inheritance: In single inheritance, a class is allowed to inherit from only one class. i.e. one subclass is inherited by one base class only.
class Vehicle{
public:
    Vehicle(){
        std::cout<< "This is a vehicle\n";
    }
};

class Car:public Vehicle{

};

//base class
class A1{
protected:
    int a;

public:
    void setA1(){
        std::cout<<"Enter the value of A1 = ";
        std::cin>>a;
    }

    void displayA1(){
        std::cout<<std::endl<<"Value of A1 = " <<a;
    }
};

//derived class
class B1: public A1{
    int b,p;

public:
    void setB1(){
        setA1();
        std::cout<<"Enter the value of B = ";
        std::cin>>b;
    }

    void displayB1(){
        displayA1();
        std::cout<<std::endl<<"Value of B = "<<b;
    }

    void calProduct(){
        p = a*b;
        std::cout<<std::endl<<"Product of "<< a << "*"<<b<<" = " <<p;
    }
};

//base class
class A2{
protected:
    int a;

public:
    void setA2(int x){
        a = x;
    }

    void displayA2(){
        std::cout<<std::endl<<"Value of A2 = " <<a;
    }
};

//derived class
class B2:public A2{
    int b, p;

public:
    void setB2(int x, int y){
        setA2(x);
        b = y;
    }

    void displayB2(){
        displayA2();
        std::cout<<std::endl<<"Value of B = "<<b;
    }

    void calProduct(){
        p = a*b;
        std::cout<<std::endl<<"Product of "<< a << "*"<<b<<" = " <<p;
    }

};

//2. Multiple Inheritance: Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.

//base class
class Vehicle2{
public:
    Vehicle2(){
        std::cout << "\nThis is a Vehicle\n";
    }
};

class FourWheeler{
public:
    FourWheeler(){
        std::cout << "This is a 4 wheeler Vehicle\n";
    }
};

//derived class
class Car2: public Vehicle2, public FourWheeler{

};



//3. Multilevel Inheritance: In this type of inheritance, a derived class is created from another derived class

//base class
class A3{
protected:
    int a;

public:
    void set_A()
    {
        std::cout<<"Enter the Value of A=";
        std::cin>>a;

    }

    void disp_A()
    {
        std::cout<<std::endl<<"Value of A="<<a;
    }
};

class B3: public A3
{
protected:
    int b;

public:
    void set_B()
    {
        std::cout<<"Enter the Value of B=";
        std::cin>>b;
    }


    void disp_B()
    {
        std::cout<<std::endl<<"Value of B="<<b;
    }
};

class C3: public B3
{
int c,p;

public:
    void set_C()
    {
        std::cout<<"Enter the Value of C=";
        std::cin>>c;
    }

    void disp_C()
    {
        std::cout<<std::endl<<"Value of C="<<c;
    }

    void cal_product()
    {
        p=a*b*c;
        std::cout<<std::endl<<"Product of "<<a<<" * "<<b<<" * "<<c<<" = "<<p <<std::endl;
    }
};

//base class
class Vehicle3{
public:
    Vehicle3(){
        std::cout << "This is a Vehicle\n";
    }
};

//derived class
class FourWheeler3:public Vehicle3{
public:
    FourWheeler3(){
        std::cout << "Objects with 4 wheels are vehicles\n";
    }
};

//derived class from derived class
class Car3:public FourWheeler3{
public:
    Car3(){
        std::cout << "Car has 4 Wheels\n";
    }
};


//4. Hierarchical Inheritance: In this type of inheritance, more than one subclass is inherited from a single base class. i.e. more than one derived class is created from a single base class.
class Vehicle4{
public:
    Vehicle4(){
        std::cout << "This is a Vehicle\n";
    }
};

class Car4:public Vehicle4{

};

class Bus4:public Vehicle4{

};

//5. Hybrid (Virtual) Inheritance: Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance.
// base class
class Vehicle5 {
public:
    Vehicle5() { cout << "This is a Vehicle\n"; }
};

// base class
class Fare5 {
public:
    Fare5() { cout << "Fare of Vehicle\n"; }
};

// first sub class
class Car5 : public Vehicle5 {
};

// second sub class
class Bus5 : public Vehicle5, public Fare5 {
};

int main()
{
    Child obj1;
    obj1.id_c = 10;
    obj1.id_p = 90;

    std::cout<<"Child id is: "<< obj1.id_c << std::endl;
    std::cout<<"Parent id is: "<< obj1.id_p << std::endl;

    //1.
    // Creating object of sub class will
    // invoke the constructor of base classes
    Car obj2; //returns the cout from Vehicle()

    B1 _b;
    _b.setB1();
    _b.calProduct();

    B2 _b2;
    _b2.setB2(4,5);
    _b2.calProduct();

    //2.
    Car2 obj3;

    //3.
    C3 _c;
    _c.set_A();
    _c.set_B();
    _c.set_C();
    _c.disp_A();
    _c.disp_B();
    _c.disp_C();
    _c.cal_product();

    Car3 obj4;

    //4.
    Car4 obj5;
    Bus4 obj6;

    //5.
    Bus5 obj7;

    return 0;
}
