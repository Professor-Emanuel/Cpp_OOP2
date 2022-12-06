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
};

int main()
{
    Point p1;
    Point p2;
    double lineLenght;

    //p1 specification
    p1.x = 3.0;
    p1.y = 2.0;

    //p2 specification
    p2.x = 1.0;
    p2.y = 2.0;

    //length of line p1p2
    lineLenght = sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    std::cout << "Line length: " << lineLenght << std::endl;

    return 0;
}
