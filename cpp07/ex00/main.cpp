#include "whatever.hpp"


class Awesome {
private:
    int _n;
public:
    Awesome(int n) : _n(n) {}
    bool operator<(Awesome const &rhs) const {
        return this->_n < rhs._n;
    }
    bool operator>(Awesome const &rhs) const {
        return this->_n > rhs._n;
    }
    int getValue() const { return _n; }
};

std::ostream &operator<<(std::ostream &out, Awesome const &obj) {
    out << obj.getValue();
    return out;
}


int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    {std::cout << "\n Complex type -----------\n\n";
    Awesome a(2), b(3);
    
    // Testing swap
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    // Testing min and max
    std::cout << "min(a, b): " << min(a, b) << std::endl;
    std::cout << "max(a, b): " << max(a, b) << std::endl;}
    return 0;
}
