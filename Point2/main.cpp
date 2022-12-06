#include <iostream>
#include <cmath>

/*
The keyword public determines the access attributes of the members of the class that follows it.
A public member can be accessed from outside the class anywhere within the scope of the class object. You can also specify the members of a class as private or protected
*/
class Point{
public:
    double x;
    double y;

    double getLineLength(Point p2){
        return sqrt( (x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));;
    }

    void setX(double xVal);
    void setY(double yVal);
};

//Member functions definitions
void Point::setX(double xVal){
    x = xVal;
}

void Point::setY(double yVal){
    y = yVal;
}

int main()
{
    Point p1;
    Point p2;

    //p1 specification
    p1.x = 3.0;
    p1.y = 2.0;

    //p2 specification
    p2.x = 1.0;
    p2.y = 2.0;

    //length of line p1p2
    double lineLength = p1.getLineLength(p2);
    std::cout << "Line length: " << lineLength << std::endl;

    Point p3;
    p3.setX(5.0);
    p3.setY(7.0);

    Point p4;
    p4.setX(1.0);
    p4.setY(4.0);

    double lineLength2 = p3.getLineLength(p4);
    std::cout << "Line length: " << lineLength2 << std::endl;

    return 0;
}
