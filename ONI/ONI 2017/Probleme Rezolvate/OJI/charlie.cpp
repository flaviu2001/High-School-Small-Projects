#include <fstream>
#include <vector>

using namespace std;

vector<char> c, q;
int test, s;

void read();
int solve_a();
void solve_b();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read(){
    ifstream fin ("charlie.in");
    fin >> test;
    char q;
    while(fin.good()){
        fin >> q;
        c.push_back(q);
    }
    c.pop_back();
    fin.close();
}

int solve_a(){
    int k(0), mx(0);
    for (unsigned i = 2; i < c.size(); ++i){
        if ((c[i] > c[i-1] && c[i-1] < c[i-2]) || (c[i] < c[i-1] && c[i-1] > c[i-2] && k))
            if(!k)
                k = 3;
            else ++k;
        else k = 0;
        if (mx < k && c[i] > c[i-1] && c[i-1] < c[i-2])
            mx = k;
    }
    return mx;
}

void solve_b(){
    q.push_back(c[0]);
    q.push_back(c[1]);
    for(unsigned i = 2; i < c.size(); ++i){
        while(q.size() > 1 && c[i] > q[q.size()-1] && q[q.size()-1] < q[q.size()-2])
            s += max(q[q.size()-2] - 'a'+1, c[i] - 'a' + 1),
            q.pop_back();
        q.push_back(c[i]);
    }
}

void write(){
    ofstream fout ("charlie.out");
    if (test == 1)
        fout << solve_a() << "\n";
    else{
        solve_b();
        for (unsigned i = 0; i < q.size(); ++i)
            fout << q[i];
        fout << "\n" << s << "\n";
    }
    fout.close();
}
