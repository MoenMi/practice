#include <iostream>
#include <string>

class MyInt {
private:
    int a;
    int b;
public:
    MyInt() {
        a = 0;
        b = 0;
    }
    MyInt(int a, int b) {
        this->a = a;
        this->b = b;
    }
    void Print() {
        std::cout << "(" << a << "," << b << ")" << "\n";
    }

    MyInt operator+(MyInt rhs);
    MyInt operator-(MyInt rhs);
    MyInt operator*(MyInt rhs);
    MyInt operator/(MyInt rhs);
    MyInt operator%(MyInt rhs);

    MyInt operator=(MyInt rhs);
    MyInt operator+=(MyInt rhs);
    MyInt operator-=(MyInt rhs);
    MyInt operator*=(MyInt rhs);
    MyInt operator/=(MyInt rhs);
    MyInt operator%=(MyInt rhs);

    MyInt operator=(int rhs);
    MyInt operator+=(int rhs);
    MyInt operator-=(int rhs);
    MyInt operator*=(int rhs);
    MyInt operator/=(int rhs);
    MyInt operator%=(int rhs);

    MyInt operator-();
    MyInt operator++();
    MyInt operator--();
    MyInt operator++(int);
    MyInt operator--(int);

    bool operator==(MyInt rhs);
    bool operator!=(MyInt rhs);
        
    bool operator==(int rhs);
    bool operator!=(int rhs);

    bool operator>(MyInt rhs);
    bool operator<(MyInt rhs);
    bool operator>=(MyInt rhs);
    bool operator<=(MyInt rhs);
    
    bool operator>(int rhs);
    bool operator<(int rhs);
    bool operator>=(int rhs);
    bool operator<=(int rhs);

    friend std::ostream& operator<<(std::ostream &os, const MyInt &obj);
    friend std::istream& operator>>(std::istream &is, MyInt &obj);
};

MyInt MyInt::operator+(MyInt rhs) { return MyInt(a+rhs.a, b+rhs.b); }
MyInt MyInt::operator-(MyInt rhs) { return MyInt(a-rhs.a, b-rhs.b); }
MyInt MyInt::operator*(MyInt rhs) { return MyInt(a*rhs.a, b*rhs.b); }
MyInt MyInt::operator/(MyInt rhs) { return MyInt(a/rhs.a, b/rhs.b); }
MyInt MyInt::operator%(MyInt rhs) { return MyInt(a%rhs.a, b%rhs.b); }

MyInt MyInt::operator=(MyInt rhs) {
    a = rhs.a;
    b = rhs.b;
    return *this;
}
MyInt MyInt::operator+=(MyInt rhs) {
    a += rhs.a;
    b += rhs.b;
    return *this;
}
MyInt MyInt::operator-=(MyInt rhs) {
    a -= rhs.a;
    b -= rhs.b;
    return *this;
}
MyInt MyInt::operator*=(MyInt rhs) {
    a *= rhs.a;
    b *= rhs.b;
    return *this;
}
MyInt MyInt::operator/=(MyInt rhs) {
    a /= rhs.a;
    b /= rhs.b;
    return *this;
}
MyInt MyInt::operator%=(MyInt rhs) {
    a %= rhs.a;
    b %= rhs.b;
    return *this;
}

MyInt MyInt::operator=(int rhs) {
    a = rhs;
    b = rhs;
    return *this;
}
MyInt MyInt::operator+=(int rhs) {
    a += rhs;
    b += rhs;
    return *this;
}
MyInt MyInt::operator-=(int rhs) {
    a -= rhs;
    b -= rhs;
    return *this;
}
MyInt MyInt::operator*=(int rhs) {
    a *= rhs;
    b *= rhs;
    return *this;
}
MyInt MyInt::operator/=(int rhs) {
    a /= rhs;
    b /= rhs;
    return *this;
}
MyInt MyInt::operator%=(int rhs) {
    a %= rhs;
    b %= rhs;
    return *this;
}

MyInt MyInt::operator-() {
    a = -a;
    b = -b;
    return *this;
}
MyInt MyInt::operator++() {
    a++;
    b++;
    return *this;
}
MyInt MyInt::operator--() {
    a--;
    b--;
    return *this;
}
MyInt MyInt::operator++(int) { return MyInt(a++,b++); }
MyInt MyInt::operator--(int) { return MyInt(a--,b--); }

bool MyInt::operator==(MyInt rhs) { return a == rhs.a && b == rhs.b; }
bool MyInt::operator!=(MyInt rhs) { return a != rhs.a || b != rhs.b; }

bool MyInt::operator==(int rhs) { return a == rhs && b == rhs; }
bool MyInt::operator!=(int rhs) { return a != rhs || b != rhs; }

bool MyInt::operator>(MyInt rhs) { return a + b > rhs.a + rhs.b; }
bool MyInt::operator<(MyInt rhs) { return a + b < rhs.a + rhs.b; }
bool MyInt::operator>=(MyInt rhs) { return a + b >= rhs.a + rhs.b; }
bool MyInt::operator<=(MyInt rhs) { return a + b <= rhs.a + rhs.b; }

bool MyInt::operator>(int rhs) { return a + b > rhs; }
bool MyInt::operator<(int rhs) { return a + b < rhs; }
bool MyInt::operator>=(int rhs) { return a + b >= rhs; }
bool MyInt::operator<=(int rhs) { return a + b <= rhs; }

std::ostream& operator<<(std::ostream &os, const MyInt &obj) {
    os << "(" << obj.a << "," << obj.b << ")";
    return os;
}
std::istream& operator>>(std::istream &is, MyInt &obj) {
    std::cout << "a = ";
    std::cin >> obj.a;
    std::cout << "b = ";
    std::cin >> obj.b;
    return is;
}

int main(int argc, char *argv[]) {

    MyInt x,y;
    std::cin >> x;
    std::cin >> y;

    x += y;
    std::cout << x << '\n';
    std::cout << ++y << '\n';

    MyInt z = x + y;
    z.Print();

    return 0;
}
