#include <iostream>

class Complex{
private:
    int real, imaginary;

public:
    Complex(int r = 0, int i = 0){
        real  = r;
        imaginary = i;
    }

    Complex operator+(Complex const &obj){
        Complex result;
        result.real = this->real + obj.real;
        result.imaginary = this->imaginary + obj.imaginary;

        return result;
    }

    void print(){
        std::cout << real << " + " << imaginary <<"i"<< std::endl;
    }
};

class Fraction{
private:
    int num, den;

public:
    Fraction(int n, int d){
        num = n;
        den =d;
    }

    // Conversion operator: return float value of fraction
    operator float() const{
        return float(num)/float(den);
    }
};


class Point{
private:
    int x, y;

public:
    Point(int i = 0, int j = 0){
        x = i;
        y = j;
    }

    void print(){
        std::cout<<"x = " <<x <<", y = "<< y<< std::endl;
    }
};
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c1.print();
    c2.print();
    c3.print();

    Fraction f(2, 5);
    float val = f;
    std::cout<< val << std::endl;

    Point p(20, 30);
    p.print();
    p = 30;  // Member x of p becomes 30 and y becomes 0
    p.print();


    return 0;
}
