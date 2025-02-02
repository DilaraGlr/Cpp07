#include "Iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x += 1;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, print);
    
    std::cout << "After increment:" << std::endl;
    ::iter(tab, 5, increment);
    ::iter(tab, 5, print);

    return 0;
}
