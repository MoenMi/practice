#include <iostream>
#include <string>
using namespace std;

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
            cout << "(" << a << "," << b << ")" << endl;
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

    friend ostream& operator<<(ostream &os, const MyInt &obj);
    friend istream& operator>>(istream &is, MyInt &obj);
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

ostream& operator<<(ostream &os, const MyInt &obj) {
    os << "(" << obj.a << "," << obj.b << ")";
    return os;
}
istream& operator>>(istream &is, MyInt &obj) {
    cout << "a = ";
    cin >> obj.a;
    cout << "b = ";
    cin >> obj.b;
    return is;
}

int main(int argc, char *argv[]) {

    MyInt x,y;
    cin >> x;
    cin >> y;

    x += y;
    cout << x << endl;
    cout << ++y << endl;

    MyInt z = x + y;
    z.Print();

    return 0;
}
