#include "Fruit.h"
#include <cstdlib>

void Fruit::Generate(int width, int height)
{
    x = rand() % width;
    y = rand() % height;
}
