#include <iostream>
#include <vector>

//Operators Overloading
class Point{
private:
    int x;
    int y;

public:
    void setX(int xVal){
        x = xVal;
    }
    void setY(int yVal){
        y = yVal;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

    Point(){
        x = 0;
        y = 0;
    }

    Point(int xVal, int yVal){
        x = xVal;
        y = yVal;
    }

    //Unary Operators Overloading in C++
    Point operator-(){
        x = -x;
        y = -y;
        return Point(x, y);
    }

    //overloaded prefix ++ and -- operators
    Point operator++(){
        x = x + 1;
        y = y + 1;
        return Point(x, y);
    }

    Point operator--(){
        x--;
        y--;
        return Point(x, y);
    }

    //overloaded postfix ++ and -- operators
    Point operator++(int){
        //save original values
        Point p(x, y);
        ++x;
        ++y;

        return p;
    }

    Point operator--(int){
        //save original values
        Point p(x, y);
        --x;
        --y;

        return p;
    }

    // Binary Operators Overloading in C++
    // Overload + operator to add two Point objects.
    Point operator+(const Point& p){
        Point point;
        point.x = this->x + p.x;
        point.y = this->y + p.y;

        return point;
    }

    Point operator-(const Point& p){
        Point point;
        point.x = this->x - p.x;
        point.y = this->y - p.y;

        return point;
    }

    Point operator*(const Point& p){
        Point point;
        point.x = this->x * p.x;
        point.y = this->y * p.y;

        return point;
    }

    // Relational Operators Overloading in C++
    // Compare x coordinates of the points
    bool operator<(const Point& p){
        if(x < p.x){
            return true;
        }

        return false;
    }

    bool operator>(const Point& p){
        if(x > p.x){
            return true;
        }
        return false;
    }

    bool operator==(const Point& p){
        if(x == p.x && y == p.y){
            return true;
        }

        return false;
    }

    //Input/Output Operators Overloading in C++
    friend std::ostream &operator<<(std::ostream &output, const Point &p){
        output << "x = " << p.x << " y = " << p.y;
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Point &p){
        input>> p.x >> p.y;
        return input;
    }

    //Assignment Operators Overloading in C++
    void operator = (const Point &p){
        x = p.x;
        y = p.y;
    }

    //Function Call Operator () Overloading in C++
    Point operator()(int a, int b, int c){
        Point point;

        //just some random calculations;
        point.x = a + b + 100;
        point.y = b + c + 200;

        return point;
    }

};

//Subscripting [] Operator Overloading in C++
const int SIZE = 10;

class safeArray{
private:
    int arr[SIZE];

public:
    safeArray(){
        register int i;
        for(i = 0; i< SIZE; i++){
            arr[i] = i;
        }
    }

    int &operator[](int i){
        if(i > SIZE){
            std::cout<<"Index out of bounds" << std::endl;
            return arr[0];
        }
        return arr[i];
    }
};

//Class Member Access Operator (->) Overloading in C++
class Obj{
    static int i, j;

public:
    void f() const{ std::cout << i++ << std::endl;}
    void g() const{ std::cout << j++ << std::endl;}
};

// Static member definitions:
int Obj::i = 10;
int Obj::j = 12;

// Implement a container for the above class
class ObjContainer{
    std::vector<Obj*> a;

public:
    void add(Obj* obj){
        a.push_back(obj); //call vector's standard method
    }

    friend class SmartPointer;
};

// implement smart pointer to access member of Obj class.
class SmartPointer{
    ObjContainer oc;
    int index;

public:
    SmartPointer(ObjContainer& objc){
        oc = objc;
        index = 0;
    }

    // Return value indicates end of list:
    bool operator++(){
        //Prefix version
        if(index >= oc.a.size()) return false;
        if(oc.a[++index] == 0) return false;

        return true;
    }

    bool operator++(int){
        //Postfix version
        return operator++();
    }

    //overload operator ->
    Obj* operator->() const{
        if(!oc.a[index]){
            std::cout<<"Zero value";
            return (Obj*)0;
        }

        return oc.a[index];
    }
};

int main()
{
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Point p5;
    Point p6(10, 20);

    p1.setX(10);
    p1.setY(20);

    p2.setX(12);
    p2.setY(22);

    // Add two object as follows:
    p3 = p1 + p2;

    std::cout << "Point 1, x = " << p1.getX() << ", y = " << p1.getY() << std::endl;
    std::cout << "Point 2, x = " << p2.getX() << ", y = " << p2.getY() << std::endl;
    std::cout << "Point 3, x = " << p3.getX() << ", y = " << p3.getY() << std::endl;

    -p3;
    std::cout << "Point 3, x = " << p3.getX() << ", y = " << p3.getY() << std::endl;

    ++p3;
    std::cout << "Point 3, x = " << p3.getX() << ", y = " << p3.getY() << std::endl;

    --p3;
    std::cout << "Point 3, x = " << p3.getX() << ", y = " << p3.getY() << std::endl;

    p4 = p2 - p1;
    std::cout << "Point 4, x = " << p4.getX() << ", y = " << p4.getY() << std::endl;

    p5 = p2 * p1;
    std::cout << "Point 5, x = " << p5.getX() << ", y = " << p5.getY() << std::endl;

    if(p1 < p2){
        std::cout<< "p1.x is less than p2.x"<< std::endl;
    }
    else{
        std::cout<< "p2.x is less than p1.x"<< std::endl;
    }

    if(p1 > p2){
        std::cout<< "p1.x is greater than p2.x"<< std::endl;
    }
    else{
        std::cout<< "p2.x is greater than p1.x"<< std::endl;
    }

    if(p1 == p6){
        std::cout<< "p1 is equal to p6"<< std::endl;
    }
    else{
        std::cout<< "p1 is not equal to p6"<< std::endl;
    }

    Point p7;
    std::cout<< "Enter the values of object: " << std::endl;
    std::cin>>p7;
    std::cout<< "Point 7: " <<p7 << std::endl;

    p7++;
    std::cout<< "Point 7: " <<p7 << std::endl;

    //p7--;
    //std::cout<< "Point 7: " <<p7 << std::endl;

    p1 = p7;
    std::cout << "Point 1, x = " << p1.getX() << ", y = " << p1.getY() << std::endl;

    Point p8;
    p8 = p1(10, 10, 10);
    std::cout << "Point 8, x = " << p8.getX() << ", y = " << p8.getY() << std::endl;


    safeArray A;
    std::cout << "Value of A[2] : " << A[2] <<std::endl;
    std::cout << "Value of A[5] : " << A[5]<<std::endl;
    std::cout << "Value of A[12] : " << A[12]<<std::endl;

    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;

    for(int i = 0; i < sz; i++){
        oc.add(&o[i]);
    }

    SmartPointer sp(oc); // create an iterator
    do{
        sp->f(); //smart pointer call
        sp->g();
    }while(sp++);

    return 0;
}
