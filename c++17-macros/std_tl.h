#ifndef __STL_TL_H
#define __STL_TL_H

#include <iostream>

#define tl int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)

#define print(str) \
    std::cout << str
#define println(str) \
    print(str) << std::endl

#endif // __STL_TL_H
