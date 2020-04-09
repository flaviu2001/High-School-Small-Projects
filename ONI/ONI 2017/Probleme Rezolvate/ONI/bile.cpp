#include <fstream>

using namespace std;

int s[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
int n, k;

int main()
{
    ifstream fin ("bile3.in");
    ofstream fout ("bile3.out");
    fin >> n >> k;

    while(s[k] != n+1){
        for (int i = 1; i <= k; ++i)
            fout << s[i] << " ";
        fout << "\n";
        int j;
        for (j = 1; j <= k && s[j] == j; ++j);
        if(j%2 != k%2)
            if(j == 1)
                --s[1];
            else{
                s[j-1] = j;
                s[j-2] = j-1;
            }
        else if(s[j+1] != s[j]+1){
                s[j-1] = s[j];
                ++s[j];
            }else{
                s[j+1] = s[j];
                s[j] = j;
            }
    }
    fin.close();
    fout.close();
    return 0;
}

