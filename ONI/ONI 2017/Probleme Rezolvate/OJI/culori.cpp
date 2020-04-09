#include <fstream>

using namespace std;

ifstream fin ("culori1.in");
ofstream fout ("culori1.out");
int n;
string s;

void s_to_p(int p){
    string::iterator it;
    string::reverse_iterator r;
    int t, c;
    for(int i = 1; i <= p; ++i){
        t = 0;
        for (it = s.begin(); it < s.end(); ++it){
            c = (*it) - '0';
            c = c*3 + t;
            t = c/10;
            c = c%10;
            (*it) = c + '0';
        }
        if (t)
            s += t + '0';
    }
    for (r = s.rbegin(); r < s.rend(); ++r)
        fout << (*r);
    fout << "\n";
}

int main()
{
    int k;
    fin >> n;
    if (n == 1)
        fout << "5\n";
    else if (n == 2)
        fout << "8\n";
    else if (n == 3)
        fout << "14\n";
    else{
        if (n%2 == 0)
            s = "8";
        else s = "41";
        k = n/2;
        s_to_p(k-1);
    }
    return 0;
}