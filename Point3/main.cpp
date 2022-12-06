#include <iostream>
#include <cmath>

class Point{
public:
    double x;
    void setX(double xVal);
    double getX(void);

private:
    double y;

public:
    void setY(double yVal);
    double getY(void);

protected:
    double z;
};

// Member functions definitions
void Point::setX(double xVal){
    x = xVal;
}

double Point::getX(void){
    return x;
}

void Point::setY(double yVal){
    y = yVal;
}

double Point::getY(void){
    return y;
}


class ChildPoint:Point{
public:
    void setZ(double zVal);
    double getZ(void);
};

// Member functions of child class
void ChildPoint::setZ(double zVal){
    z = zVal;
}

double ChildPoint::getZ(void){
    return z;
}

int main()
{
    Point p1;

    p1.setX(5.0);
    std::cout << "Point x: " << p1.getX() << std::endl;

    // set point x without member function
    p1.x = 10.0; // OK, because x is public
    std::cout << "Point x: " << p1.x << std::endl;

    //p1.y = 10.0; // error because y is private
    p1.setY(10.0); // Use member function to set it.
    std::cout << "Point y: " << p1.getY() << std::endl;

    ChildPoint p5;
    p5.setZ(11.0);
    std::cout << "Child Point z: " << p5.getZ() << std::endl;

    return 0;
}
