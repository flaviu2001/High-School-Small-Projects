#include <fstream>
#define Nmax 100
using namespace std;
int N;
int K;
int A[Nmax][Nmax];
int C[Nmax][Nmax];
unsigned char P[Nmax][Nmax];
int  Move[2*Nmax];
 
ofstream fout("sudest.out");
 
void read(){
    ifstream fin("sudest.in");
    fin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) fin>>A[i][j];
    fin>>K;
    for(int i=1;i<=K;i++) fin>>Move[i];
    fin.close();
}
 
void init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {C[i][j]=-1; P[i][j]=255;}
}
 
int posibil(int x, int y){
    return 0<=x && 0<=y && x<N && y<N;
}
 
void drum(int x, int y, int pas){
    int i, gasit;
    if(x==0 && y==0) fout<<1<<" "<<1<<'\n';
    else
    {
        gasit=0;
        if (posibil(x,y-Move[pas]))
            if (C[x][y-Move[pas]]==C[x][y]-A[x][y] && P[x][y-Move[pas]]==pas-1){
                drum(x,y-Move[pas],pas-1);
                fout<<x+1<<" "<<y+1<<"\n";
                gasit=1;
            }
       if (!gasit)
           if (posibil(x-Move[pas],y))
               if (C[x-Move[pas]][y]==C[x][y]-A[x][y] && P[x-Move[pas]][y]==pas-1){
                    drum(x-Move[pas],y,pas-1);
                    fout<<x+1<<" "<<y+1<<"\n";
                }
    }
}
 
void solve(){
    int i,j, h;
    P[0][0]=0; C[0][0]=A[0][0];
    for (i=1; i<=K; i++)
        for (j=0; j<N; j++)
            for (h=0; h<N; h++)
                if (P[j][h]==i-1)
                {
                    if (posibil(j+Move[i],h))
                        if (C[j][h]+A[j+Move[i]][h]>C[j+Move[i]][h]){
                            P[j+Move[i]][h]=i;
                            C[j+Move[i]][h]=C[j][h]+A[j+Move[i]][h];
                        }
                     if (posibil(j,Move[i]+h))
                        if (C[j][h]+A[j][Move[i]+h]>C[j][Move[i]+h]){
                            P[j][Move[i]+h]=i;
                            C[j][Move[i]+h]=C[j][h]+A[j][Move[i]+h];
                            }
                }
    fout<<C[N-1][N-1]<<'\n';
    drum(N-1,N-1,K);
    fout.close();
}
 
int main(){
    ifstream fin("sudest.in");
    read();
    init();
    solve();
return 0;
}