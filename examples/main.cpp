#include <iostream>
#include "Vector2D.h"

int main()
{
    Vector2D<float> v1(1.0f, 1.0f);
    Vector2D<float> v2(3.0f, 4.0f);
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;

    std::cout << "v1.length(): " << v1.length() << std::endl;
    std::cout << "v2.length(): " << v2.length() << std::endl;
    std::cout << "v1.lengthSquared(): " << v1.lengthSquared() << std::endl;
    std::cout << "v2.lengthSquared(): " << v2.lengthSquared() << std::endl;
    return 0;
}