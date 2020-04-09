#ifndef INT_H
#define INT_H

#include <vector>
#include <iostream>

class Int{
    private:
        std::vector<int> v;
        void clear();
        void push_back(int);
        void pop_back();
        void resize(int, int);
        int back();
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
        void sum(Int &, Int, Int);
        void sub(Int &, Int, Int);
        void prod(Int &, Int, Int);
        void div(Int &, Int, Int);
        void mod(Int &, Int, Int);
        friend std::istream& operator>>(std::istream &, Int&);
        friend std::ostream& operator<<(std::ostream &, Int);
    public:
        Int();
        Int(int);
        Int(const char*);
        ~Int();
        int size();
        static Int pow(Int, Int);
        Int operator+(const Int);
        Int operator-(const Int);
        Int operator*(const Int);
        Int operator/(const Int);
        Int operator%(const Int);
        bool operator>(Int);
        bool operator<(Int);
        bool operator>=(Int);
        bool operator<=(Int);
        bool operator==(Int);
        bool operator!=(Int);
        bool operator>(const int &);
        bool operator<(const int &);
        bool operator>=(const int &);
        bool operator<=(const int &);
        bool operator==(const int &);
        bool operator!=(const int &);
        Int operator+(const int);
        Int operator-(const int);
        Int operator*(const int);
        Int operator/(const int);
        Int operator%(const int);
        operator bool ();
        operator int ();
        int& operator[] (int);
};

#endif // INT_H
