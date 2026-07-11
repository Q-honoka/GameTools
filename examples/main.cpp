#include <iostream>
#include "Vector2D.h"

int main()
{
    Vector2D<float> v1(2.0f, 4.0f);
    Vector2D<float> v2(1.0f, 4.0f);
    Vector2D<float> v3(2.0f, 4.0f);
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;
    std::cout << "v3: (" << v3.x << ", " << v3.y << ")" << std::endl;

    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    return 0;
}