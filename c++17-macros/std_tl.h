#ifndef __STL_TL_H
#define __STL_TL_H

// C++
#include <iostream>

#define tl int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)

#define print(val) std::cout << val
#define println(val) print(val) << std::endl

template<typename T>
class let {
    static_assert(std::is_arithmetic_v<T>);
public:
    let() = delete;

    let(const T& val) {
        m_val = val;
    }

    let<T>& operator=(const let<T>& l) {
        m_val = l.m_val;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const let<T>& l) {
        os << l.m_val;
        return os;
    }
    
private:
    T m_val;
};

template<size_t N>
class let<char[N]> {
public:
    let() = delete;

    let(const char (&str)[N]) {
        m_val = std::string_view(str);
    }

    friend std::ostream& operator<<(std::ostream& os, const let<char[N]>& l) {
        os << l.m_val;
        return os;
    }

private:
    std::string_view m_val;
};

#endif // __STL_TL_H
