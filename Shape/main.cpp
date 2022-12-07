#include <iostream>

//base class
class Shape{
public:
    void setWidth(double w){
        width = w;
    }
    void setHeight(double h){
        height = h;
    }

protected:
    double width;
    double height;
};

//base class
class PaintCost{
public:
    double getCost(int area){
        return area * 100;
    }
};

//derived class
class Rectangle:public Shape, public PaintCost{
public:
    double getArea(){
        return (width*height);
    }
};

int main()
{
    Rectangle rect;
    rect.setHeight(10.0);
    rect.setWidth(5.0);

    double area;
    area = rect.getArea();

    std::cout<< "Area = " << rect.getArea() << std::endl;
    std::cout<< "Cost = $" << rect.getCost(area) << std::endl;

    return 0;
}
