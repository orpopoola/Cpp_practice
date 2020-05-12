#include <iostream>
#include <cmath>
#include <assert.h>
#define PI 3.14159
// Define pi

// Define Line Class
class LineSegment{
    // Define protected attribute length
    public:
    int length;
};    
// Define Circle subclass
class Circle{
// Define public setRadius() and getArea()
    public:
    Circle(LineSegment& radius);
    double Area(); 

    private:
    LineSegment& radius_;
};
//Declare circle class
Circle::Circle(LineSegment& radius): radius_(radius){}

double Circle::Area(){
    return PI*Circle::radius_.length*Circle::radius_.length;
}

    
// Test in main()
int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}