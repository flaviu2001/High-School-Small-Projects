#include <fstream>
#include <deque>
#define ff first
#define ss second

using namespace std;

deque< pair<int, int> > v;
int n, k;

long long solve();
void write();

int main(){
    write();
    return 0;
}

long long solve(){
    ifstream fin ("deque.in");
    int x;
    long long s(0);
    fin >> n >> k >> x;
    v.push_back(make_pair(x, 0));
    for (int i = 1; i < n; ++i){
        if (i - v.front().ss == k)
            v.pop_front();
        fin >> x;

        while (!v.empty() && v.back().ff >= x)
                v.pop_back();
        v.push_back(make_pair(x, i));

        if (i > k - 2)
            s += v.front().ff;
    }
    fin.close();
    return s;
}

void write(){
    ofstream fout ("deque.out");
    fout << solve() << "\n";
    fout.close();
}
