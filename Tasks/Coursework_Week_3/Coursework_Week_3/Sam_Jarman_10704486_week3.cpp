#include "mbed.h"
#include <cstring>

class Rectangle {
private:
    float length;  
    float width;

public:
    // Constructor to initialize length and width
    Rectangle(float l, float w) {
        length = l;  
        width = w;
    }

    // Function to get the width of the rectangle
    float getWidth() {
        return width;
    }

    // Function to get the length of the rectangle
    float getLength() {
        return length;
    }

    // Function to get the area of the rectangle
    float getArea() {
        return length*width;
    }

     // Function to get the perimeter of the rectangle
    float getPerimeter() {
        return (length*2) + (width*2);
    }
};

int main() {

    // Create a Rectangle object
    Rectangle rectangle1(3.5, 12.5);

    // Output the length, width, area and perimeter of the rectangle
    printf("\nLength: %.2f\nWidth: %.2f\nArea: %.2f\nPerimeter: %.2f\n ", rectangle1.getLength(), rectangle1.getWidth(), rectangle1.getArea(),rectangle1.getPerimeter() );

    return 0;
}


