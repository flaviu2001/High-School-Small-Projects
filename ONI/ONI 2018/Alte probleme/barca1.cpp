#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct elem{
    int in;
    int weight;

    bool operator> (const elem &obj) const{
        if(weight > obj.weight)
            return true;
        if(weight < obj.weight)
            return false;
        if(in < obj.in)
            return true;
        return false;
    }

    bool operator< (const elem &obj) const{
        if(weight < obj.weight)
            return true;
        if(weight > obj.weight)
            return false;
        if(in > obj.in)
            return true;
        return false;
    }
};

int n, m, g, t[10], rnk[200005], total_weight, cnt;
vector<elem> h;

elem make_elem(int in, int weight)
{
    elem aux;
    aux.in = in;
    aux.weight = weight;
    return aux;
}

int main()
{
    ifstream fin ("barca1.in");
    ofstream fout ("barca1.out");
    fin >> n >> g >> m;
    n += m;
    for (int i = 0; i < 10; ++i)
        fin >> t[i];
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        h.push_back(make_elem(i, x));
        push_heap(h.begin(), h.end());
        total_weight += x;
        if(total_weight > g){
            rnk[h.front().in] = ++cnt;
            total_weight -= h.front().weight;
            pop_heap(h.begin(), h.end());
            h.pop_back();
        }
    }
    for (int i = 0; i < 10; ++i)
        fout << rnk[t[i]] << "\n";
    fin.close();
    fout.close();
    return 0;
}

