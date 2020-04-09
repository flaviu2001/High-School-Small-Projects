#include <bits/stdc++.h>

using namespace std;

deque< pair<int, int> > deq;
int duce[100005], h[100005], stars[100005], test, n, l;
char c[100005], ducec[100005];

int main()
{
    ifstream fin ("sirag2.in");
    ofstream fout ("sirag2.out");
    fin >> test;
    while(test--){
        fin >> n >> l >> c;
        int mx = l;
        memset(h, 0, sizeof(h));
        memset(stars, 0, sizeof(stars));
        memset(duce, 0, sizeof(duce));
        memset(ducec, 0, sizeof(ducec));
        for (int i = 0; i < l; ++i){
            duce[i] = i;
            ducec[i] = c[i];
            if(c[i] == '*')
                stars[i] = 1;
        }
        deq.clear();
        deq.push_back(make_pair(0, 0));
        for (int i = 1; i < l; ++i){
            while(!deq.empty() && deq.back().first >= 0)
                deq.pop_back();
            deq.push_back(make_pair(0, i));
        }
        for (int i = l; i < n; ++i){
            if(c[i] == '*'){
                duce[i] = duce[i-l];
                ducec[i] = ducec[i-l];
                stars[i] = stars[i-l]+1;
            }else{
                if(ducec[i-l] != c[i] && ducec[i-l] != '*'){
                    duce[i] = i;
                    ducec[i] = c[i];
                }else{
                    duce[i] = duce[i-l];
                    if(ducec[i-l] == '*')
                        ducec[i] = c[i];
                    else ducec[i] = ducec[i-l];
                }
            }
            h[i] = (i-duce[i])/l+1;
            if(ducec[i-l] != c[i] && c[i] != '*' && c[i-l] == '*'){
                h[i] = stars[i-l]+1;
                duce[i] = i-stars[i-l]*l;
                ducec[i] = c[i];
            }
            if(i-deq.front().second == l)
                deq.pop_front();
            while(!deq.empty() && deq.back().first >= h[i])
                deq.pop_back();
            deq.push_back(make_pair(h[i], i));
            mx = max(mx, deq.front().first*l);
        }
        fout << mx << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

