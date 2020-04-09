#include "Int.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

int max(int x, int y)
{
    return x > y ? x : y;
}

std::ostream &operator<<(std::ostream &os, Int a)
{
    std::string c;
    for (int i = 0; i < a.size(); ++i)
        c.push_back(a[i]+'0');
    return os << c;
}

std::istream &operator>>(std::istream &is, Int &a)
{
    a.clear();
    std::string s;
    is >> s;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        if(*it >= '0' && *it <= '9')
            a.push_back(*it-'0');
    return is;
}

void Int::clear()
{
    v.clear();
}

void Int::push_back(int x)
{
    v.push_back(x);
}

void Int::pop_back()
{
    v.pop_back();
}

void Int::resize(int x, int y = 0)
{
    v.resize(x, y);
}

int Int::back()
{
    return v.back();
}

std::vector<int>::iterator Int::begin()
{
    return v.begin();
}

std::vector<int>::iterator Int::end()
{
    return v.end();
}

void Int::sum(Int &dest, Int x, Int y)
{
    dest.clear();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int mn = max(x.size(), y.size()), t=0;
    for (int i = 0; i < mn; ++i){
        int X = 0, Y = 0;
        if(x.size() > i)
            X = x[i];
        if(y.size() > i)
            Y = y[i];
        dest.push_back(X+Y+t);
        t = dest[i]/10;
        dest[i] %= 10;
    }
    if(t)
        dest.push_back(t);
    reverse(dest.begin(), dest.end());
}

void Int::sub(Int &c, Int x, Int y)
{
    if(x < y)
        throw 1;
    c.clear();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int mn = max(x.size(), y.size()), t=0;
    for (int i = 0; i < mn; ++i){
        int X = 0, Y = 0;
        if(x.size() > i)
            X = x[i];
        if(y.size() > i)
            Y = y[i];
        c.push_back(X-Y-t);
        if(c[i] < 0){
            t = 1;
            c[i] += 10;
        }else
            t = 0;
    }
    while(c.size() > 1 && c.back() == 0)
        c.pop_back();
    reverse(c.begin(), c.end());
}

void Int::prod(Int &c, Int a, Int b)
{
    c.clear();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    c.resize(a.size() + b.size()-1, 0);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            c[i+j] += a[i] * b[j];
    int t = 0;
    for (int i = 0; i <= a.size() + b.size()-2; ++i){
        c[i] += t;
        t = c[i]/10;
        c[i] %= 10;
    }
    if(t)
        c.push_back(t);
    reverse(c.begin(), c.end());
}

void Int::div(Int &c, Int a, Int b)
{
    c.clear();
    if(a < b){
        c = 0;
        return;
    }
    if(b == 0)
        throw 2;
    Int remainder = a, res = 0;
    while(remainder >= b){
        Int sz = remainder.size()-b.size()-1, p = 1;
        if(b*pow(10, sz+1) <= remainder)
            sz = sz+1;
        Int dv = b*pow(10, sz);
        Int dv2 = dv;
        for (int i = 2; i <= 9; ++i)
            if(remainder-dv2 >= dv)
                dv2 = dv2 + dv,
                p = p+1;
            else break;
        remainder = remainder - dv2;
        res = res + pow(10, sz) * p;
    }
    c = res;
}

void Int::mod(Int &c, Int a, Int b)
{
    c.clear();
    if(a < b){
        c = 0;
        return;
    }
    if(b == 0)
        throw 2;
    Int remainder = a, res = 0;
    while(remainder >= b){
        Int sz = remainder.size()-b.size()-1, p = 1;
        if(b*pow(10, sz+1) <= remainder)
            sz = sz+1;
        Int dv = b*pow(10, sz);
        Int dv2 = dv;
        for (int i = 2; i <= 9; ++i)
            if(remainder-dv2 >= dv)
                dv2 = dv2 + dv,
                p = p+1;
            else break;
        remainder = remainder - dv2;
        res = res + pow(10, sz) * p;
    }
    c = remainder;
}

Int::Int()
{
    v.push_back(0);
}

Int::Int(int x)
{
    if(x < 0)
        x = -x;
    else if(x == 0)
        v.push_back(0);
    else
        while(x){
            v.push_back(x%10);
            x/=10;
        }
    reverse(v.begin(), v.end());
}

Int::Int(const char *q){
    int n = strlen(q);
    for (int i = 0; i < n; ++i)
        v.push_back(q[i]-'0');
}

Int::~Int()
{
    v.clear();
}

int Int::size()
{
    return v.size();
}

Int Int::pow(Int a, Int b)
{
    Int p = 1;
    while(b > 0)
        if(b.back()%2 == 0)
            a = a*a,
            b = b/2;
        else
            p = p*a,
            b = b-1;
    return p;
}

Int Int::operator+(const Int b)
{
    Int res;
    sum(res, *this, b);
    return res;
}

Int Int::operator-(const Int b)
{
    try{
        Int res;
        sub(res, *this, b);
        return res;
    }catch(int x){
        if(x == 1)
            std::cout << "Int is not a signed class\n";
    }
    return 0;
}

Int Int::operator*(const Int b)
{
    Int res;
    prod(res, *this, b);
    return res;
}

Int Int::operator/(const Int b)
{
    try{
        Int res;
        div(res, *this, b);
        return res;
    }catch(int x){
        if(x == 2)
            std::cout << "division by 0 is not permitted";
    }
    return 0;
}

Int Int::operator%(const Int b)
{
    try{
        Int res;
        mod(res, *this, b);
        return res;
    }catch(int x){
        if(x == 2)
            std::cout << "division by 0 is not permitted";
    }
    return 0;
}

bool Int::operator>(Int b)
{
    if(this->size() > b.size())
        return true;
    if(this->size() < b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return true;
        else if((*this)[i] < b[i])
            return false;
    return false;
}

bool Int::operator<(Int b)
{
    if(this->size() > b.size())
        return false;
    if(this->size() < b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return false;
        else if((*this)[i] < b[i])
            return true;
        return false;
}

bool Int::operator>=(Int b){
    if(this->size() > b.size())
        return true;
    if(this->size() < b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return true;
        else if((*this)[i] < b[i])
            return false;
    return true;
}

bool Int::operator<=(Int b)
{
    if(this->size() > b.size())
        return false;
    if(this->size() < b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return false;
        else if((*this)[i] < b[i])
            return true;
    return true;
}

bool Int::operator==(Int b)
{
    if(this->size() != b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] != b[i])
            return false;
    return true;
}

bool Int::operator!=(Int b)
{
    if(this->size() != b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] != b[i])
            return true;
    return false;
}

bool Int::operator>(const int &c)
{
    Int b = c;
    if(this->size() > b.size())
        return true;
    if(this->size() < b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return true;
        else if((*this)[i] < b[i])
            return false;
    return false;
}

bool Int::operator<(const int &c)
{
    Int b = c;
    if(this->size() > b.size())
        return false;
    if(this->size() < b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return false;
        else if((*this)[i] < b[i])
            return true;
        return false;
}

bool Int::operator>=(const int &c)
{
    Int b = c;
    if(this->size() > b.size())
        return true;
    if(this->size() < b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return true;
        else if((*this)[i] < b[i])
            return false;
    return true;
}

bool Int::operator<=(const int &c)
{
    Int b = c;
    if(this->size() > b.size())
        return false;
    if(this->size() < b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] > b[i])
            return false;
        else if((*this)[i] < b[i])
            return true;
    return true;
}

bool Int::operator==(const int &c)
{
    Int b = c;
    if(this->size() != b.size())
        return false;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] != b[i])
            return false;
    return true;
}

bool Int::operator!=(const int &c)
{
    Int b = c;
    if(this->size() != b.size())
        return true;
    for (int i = 0; i < b.size(); ++i)
        if((*this)[i] != b[i])
            return true;
    return false;
}

Int Int::operator+(const int c)
{
    Int b = c;
    Int res;
    sum(res, *this, b);
    return res;
}

Int Int::operator-(const int c)
{
    try{
        Int b = c;
        Int res;
        sub(res, *this, b);
        return res;
    }catch(int x){
        if(x == 1)
            std::cout << "Int is not a signed class\n";
    }
    return 0;
}

Int Int::operator*(const int c)
{
    Int b = c;
    Int res;
    prod(res, *this, b);
    return res;
}

Int Int::operator/(const int c)
{
    try{
        Int b = c;
        Int res;
        div(res, *this, b);
        return res;
    }catch(int x){
        if(x == 2)
            std::cout << "division by 0 is not permitted";
    }
    return 0;
}

Int Int::operator%(const int c)
{
    try{
        Int b = c;
        Int res;
        mod(res, *this, b);
        return res;
    }catch(int x){
        if(x == 2)
            std::cout << "division by 0 is not permitted";
    }
    return 0;
}

Int::operator bool()
{
    if(*this != 0)
        return true;
    return false;
}

int& Int::operator[] (int indx)
{
    return v[indx];
}

Int::operator int()
{
    int aux = 0;
    for (int i = 0; i < this->size(); ++i)
        aux = aux*10 + (*this)[i];
    return aux;
}
