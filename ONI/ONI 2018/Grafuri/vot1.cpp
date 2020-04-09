#include <fstream>

using namespace std;

int n, d[1005], no_of_guys;
bool guys[1005];

void bf(int x)
{
    int pred[1005] = {0};
    bool ok[1005] = {0};
    for (; !ok[x]; x = d[x]){
        pred[d[x]] = x;
        ok[x] = 1;
    }
    int y = x;
    do{
        guys[x] = 1;
        x = pred[x];
    }while(x != y);

}

int main()
{
    ifstream fin ("vot1.in");
    ofstream fout ("vot1.out");
    fin >> n;
    for(int i = 1; i <= n; ++i){
        fin >> d[i];
        if(i == d[i])
            guys[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
        bf(i);
    for (int i = 1; i <= n; ++i)
        if(guys[i])
            ++no_of_guys;
    fout << no_of_guys << "\n";
    for (int i = 1; i <= n; ++i)
        if(guys[i])
            fout << i << " ";
    fin.close();
    fout.close();
    return 0;
}

