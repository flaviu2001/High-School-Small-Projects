#include <fstream>

using namespace std;

int n, s, test, t, xe, ye, xp;
bool v[42];

                                                //length = 1, 2, 4, 8...
void cerinta1(int &x, int &y, int h, int len)   //height = 1, 2, 4, 8...
{
    if(len == 1)
        return;
    if(h == (1<<n))
        return;
    if(x <= len/2 && xp <= len/2){
        cerinta1(x, y, h*2, len/2);
        return;
    }
    if(x <= len/2 && xp > len/2){
        x = len/2+1-x;
        y = h+1-y;
        y += h;
        xp -= len/2;
        cerinta1(x, y, h*2, len/2);
    }
    if(x > len/2 && xp > len/2){
        x -= len/2;
        xp -= len/2;
        cerinta1(x, y, h*2, len/2);
    }
    if(x > len/2 && xp <= len/2){ //i know it's redundant, but it helps me think
        x -= len/2;
        x = len/2+1-x;
        y = h+1-y;
        y += h;
        cerinta1(x, y, h*2, len/2);
    }
}

int main()
{
    ifstream fin ("banda.in");
    ofstream fout ("banda.out");
    fin >> n >> s >> test >> t;
    if(test == 1){
        xe = t;
        ye = 1;
        xp = s;
        cerinta1(xe, ye, 1, (1<<n));
        fout << ye << "\n";
    }else{
        int x = s, len = (1<<n);
        for (int i = 1; i <= n; ++i){
            if(x > len/2){
                x -= len/2;
                v[i] = 1;
            }
            len >>= 1;
        }
        x = 1;
        int y = t, h = (1<<n);
        len = 1;
        for (int i = n; i > 0; --i){
            if(!v[i]){
                if(y <= h/2){
                    // Nothing *ever* happens
                }else{
                    y -= h/2;
                    y = h/2+1-y;
                    x = len+1-x;
                    x += len;
                }
            }else{
                if(y <= h/2){
                    x += len;
                }else{
                    y -= h/2;
                    y = h/2+1-y;
                    x = len+1-x;
                }
            }
            len *= 2; h /= 2;
        }
        fout << x << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

