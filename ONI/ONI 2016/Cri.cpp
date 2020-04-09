#include <fstream>

using namespace std;

int main()
{
    FILE*fin=fopen("cri.in","r");
    FILE*fout=fopen("cri.out","w");
    int maxLinie,maxColoana,ventx,venty,i,j,zona1=0,zona2=0,zona3=0,zona4=0;
    int boabeCamera,min1=8001,min2=8001,min3=8001,min4=8001;
    int camera,camera1=0,camera2=0,camera3=0,camera4=0,zona=1,maxBoabe;
    fscanf(fin,"%d%d%d%d",&maxLinie,&maxColoana,&ventx,&venty);
    for(i=1;i<=maxLinie;++i)
        for(j=1;j<=maxColoana;++j)
        {
            fscanf(fin,"%d",&boabeCamera);
            if(i<=ventx&&j<=venty)
            {
                zona1+=boabeCamera;
                ++camera1;
                if((ventx+venty-i-j)%2!=0&&min1>boabeCamera)
                    min1=boabeCamera;
            }
            if(i<=ventx&&j>=venty)
            {
                zona2+=boabeCamera;
                ++camera2;
                if((ventx-venty-i+j)%2!=0&&min2>boabeCamera)
                    min2=boabeCamera;
            }
            if(i>=ventx&&j<=venty)
            {
                zona3+=boabeCamera;
                ++camera3;
                if((i-j+venty-ventx)%2!=0&&min3>boabeCamera)
                    min3=boabeCamera;
            }
            if(i>=ventx&&j>=venty)
            {
                zona4+=boabeCamera;
                ++camera4;
                if((i-ventx+j-venty)%2!=0&&min4>boabeCamera)
                    min4=boabeCamera;
            }
        }
    if(ventx%2==0&&venty%2==0)
        zona1-=min1, --camera1;
    if(ventx%2==0&&(maxColoana-venty+1)%2==0)
        zona2-=min2, --camera2;
    if((maxLinie-ventx+1)%2==0&&venty%2==0)
        zona3-=min3, --camera3;
    if((maxLinie-ventx+1)%2==0&&(maxColoana-venty+1)%2==0)
        zona4-=min4, --camera4;
    maxBoabe=zona1, camera=camera1;
    if(maxBoabe<zona2) maxBoabe=zona2, zona=2, camera=camera2;
        else if(maxBoabe==zona2&&camera2<camera)
                camera=camera2, zona=2;
    if(maxBoabe<zona3) maxBoabe=zona3, zona=3, camera=camera3;
        else if(maxBoabe==zona3&&camera3<camera)
                camera=camera3, zona=3;
    if(maxBoabe<zona4) maxBoabe=zona4, zona=4, camera=camera4;
        else if(maxBoabe==zona4&&camera4<camera)
                camera=camera4, zona=4;
    fprintf(fout,"%d %d %d",zona,maxBoabe,camera);
    return 0;
}
