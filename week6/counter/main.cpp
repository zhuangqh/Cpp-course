#include <iostream>
#include "counter.h"

int main() {
        counter2 c;
        int x;
        for (std::cin >> x; x > 0; --x)
                std::cout << ++c << ' ';
        std::cout << std::endl;
        for (std::cin >> x; x > 0; --x)
                std::cout << c++ << ' ';
        std::cout << std::endl;
        for (std::cin >> x; x > 0; --x)
                std::cout << --c << ' ';
        std::cout << std::endl;
        for (std::cin >> x; x > 0; --x)
                std::cout << c-- << ' ';
        std::cout << std::endl;
        std::cout << c.show() << std::endl;
        return 0;
}
