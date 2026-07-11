#include <iostream>
#include "Vector2D.h"

int main()
{
    Vector2D<float> v1(0.0f, 0.0f);
    Vector2D<float> v2(10.5f, -20.25f);
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;

    std::cout << "v1.length(): " << v1.length() << std::endl;
    std::cout << "v2.length(): " << v2.length() << std::endl;
    return 0;
}