#include <iostream>

class Point {
private:
    int x;

public:
    Point(int xVal = 10){
        std::cout << "Parameterized constructor." << std::endl;
        x = xVal;

        objectCount++;
    }

    int compare(Point p){
        return this->x > p.x;
    }

    static int objectCount;

    static int getCount(){
        return objectCount;
    }
};

// Initialize static member of class Point
int Point::objectCount = 0;

int main()
{
    // Print total number of objects before creating object.
    std::cout << "Inital Stage Count: " << Point::getCount() << std::endl;

    Point p1(100);
    Point p2(12);
    Point *p3;

    p3 = &p2; // reference, won't be counted.

    if(p1.compare(p2)){
        std::cout << "Point 1 is greater than point 2." << std::endl;
    } else{
        std::cout << "Point 2 is greater or equal than point 1." << std::endl;
    }

    // Now try to access a member using member access operator
    if(p3->compare(p2)){
        std::cout << "Point 3 is greater than point 2." << std::endl;
    } else{
        std::cout << "Point 2 is greater or equal than point 3." << std::endl;
    }

    std::cout << "Total object count: " << Point::objectCount << std::endl;

    // Print total number of objects after creating object.
    std::cout << "Final Stage Count: " << Point::getCount() << std::endl;

    return 0;
}
