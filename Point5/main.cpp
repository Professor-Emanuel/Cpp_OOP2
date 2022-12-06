#include <iostream>

class Point{
private:
    double *x;

public:
    double getX(void);
    Point(double xVal); //constructor
    Point(const Point &obj); //copy constructor
    ~Point();

    friend void printX(Point p);
};

// Member functions definitions including constructor
Point::Point(double xVal){
    std::cout << "Normal constructor allocating x." << std::endl;
    // allocate memory for the pointer;
    x = new double;
    *x = xVal;
}

Point::Point(const Point &obj){
    std::cout << "Copy constructor allocating x." << std::endl;
    x = new double;
    *x = *obj.x; //copy the value
}

Point::~Point(){
    std::cout << "Freeing memory!" << std::endl;
    delete x;
}

double Point::getX(){
    return *x;
}

void display(Point obj){
    std::cout << "Point x: "<< obj.getX() << std::endl;
}

// Note: printX() is not a member function of any class.
void printX(Point p){
    //because printX() is a friend of Point, it can directly access any member of this class
    std::cout << "Point X using PrintX(): " << *p.x << std::endl;
}

inline int Max(int x, int y){
    return (x > y) ? x : y;
}

int main()
{
    Point p1(10);

    Point p2 = p1; //this calls copy constructor

    display(p1); //this calls copy constructor

    display(p2); //this calls copy constructor

    printX(p2);

    std::cout << "Max (20,10): " << Max(20,10) << std::endl;
    std::cout << "Max (0,200): " << Max(0,200) << std::endl;
    std::cout << "Max (100,1010): " << Max(100,1010) << std::endl;

    return 0;
}
