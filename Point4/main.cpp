#include <iostream>

class Point{
public:
    void setX(double xVal);
    double getX(void);
    Point(); // default constructor
    Point(double xVal); // parameterized constructor
    ~Point(); // destructor

private:
    double x;
};

// Member functions definitions including constructor
Point::Point(){
    std::cout << "Object was created." << std::endl;
}

Point::Point(double xVal){
    std::cout << "Object was created using parameterized constructor." << std::endl;
    x = xVal;
}

/*
equivalent with above initialization:
Point::Point(double xVal): x(xVal){
    std::cout << "Object was created using parameterized constructor." << std::endl;
}
*/

Point::~Point(){
    std::cout << "Object is being deleted" << std::endl;
}

void Point::setX(double xVal){
    x = xVal;
}

double Point::getX(){
    return x;
}

int main()
{
    Point p1;
    p1.setX(10.0);
    std::cout << "Point x: " << p1.getX() << std:: endl;

    Point p2(11.0);
    std::cout << "Point x: " << p2.getX() << std:: endl;

    p2.setX(20.0);
    std::cout << "Point x: " << p2.getX() << std:: endl;

    return 0;
}
