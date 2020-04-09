#include <fstream>
#include <deque>
#define ff first
#define ss second

using namespace std;

deque< pair<int, int> > v, r;
int n, k;

int solve();
void write();

int main(){
    write();
    return 0;
}

int solve(){
    ifstream fin ("vila2.in");
    int mx(0), x;
    fin >> n >> k >> x; ++k;
    v.push_back(make_pair(x, 0));
    r.push_back(make_pair(x, 0));
    for (int i = 1; i < n; ++i){
        if (i-v.front().ss == k)
            v.pop_front();
        if (i-r.front().ss == k)
            r.pop_front();
        fin >> x;

        while(!v.empty() && v.back().ff >= x)
            v.pop_back();
        while(!r.empty() && r.back().ff <= x)
            r.pop_back();

        v.push_back(make_pair(x, i));
        r.push_back(make_pair(x, i));

        if (i > k-2 && r.front().ff - v.front().ff > mx)
            mx = r.front().ff - v.front().ff;
    }
    fin.close();
    return mx;
}

void write(){
    ofstream fout ("vila2.out");
    fout << solve() << "\n";
    fout.close();
}
