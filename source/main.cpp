#include "./random.h"
#include <iostream>

int main()
{
    Random rand(0);
    double min = 0.0;
    double max = 1.0;
    rand.uniformReal( min, max );
    for( unsigned cycle = 0; cycle < 40; cycle++ )
    {
        std::cout << rand.RNG() << std::endl;
    }
    return 0;
}
