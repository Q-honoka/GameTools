#include <iostream>
#include "Vector2D.h"

int main()
{
    Vector2D<float> v1(1.0f, 1.0f);
    Vector2D<float> v2(3.0f, 4.0f);
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;

    std::cout << "v1.normalized(): (" << v1.normalized().x << ", " << v1.normalized().y << ")" << std::endl;
    std::cout << "v2.normalized(): (" << v2.normalized().x << ", " << v2.normalized().y << ")" << std::endl;
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;

    std::cout << "v1.normalize(): (" << v1.normalize().x << ", " << v1.normalize().y << ")" << std::endl;
    std::cout << "v2.normalize(): (" << v2.normalize().x << ", " << v2.normalize().y << ")" << std::endl;
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")" << std::endl;

    return 0;
}