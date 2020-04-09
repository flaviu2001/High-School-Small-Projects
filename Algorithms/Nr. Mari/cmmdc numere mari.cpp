#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> >vv;
int n1, n2, n3;

void read()
{
    freopen("div.in", "r", stdin);
    char q;
    while(!feof(stdin)){
        do{
            scanf("%c", &q);
            if(feof(stdin)){
                fclose(stdin);
                return;
            }
        }while(!(q >= '0' && q <= '9'));
        vector<int> v;
        v.push_back(q-'0');
        do{
            scanf("%c", &q);
            if(q >= '0' && q <= '9')
                v.push_back(q-'0');
        }while(q >= '0' && q <= '9');
        vv.push_back(v);
    }
}

int compare(vector<int> s1, vector<int> s2)
{
    if(s1.size() > s2.size())
        return 1;
    if(s1.size() < s2.size())
        return -1;

    for (unsigned i = 0; i < s1.size(); ++i)
        if(s1[i] > s2[i])
            return 1;
        else if(s1[i] < s2[i])
            return -1;
    return 0;
}

void reverse(vector<int> &s)
{
    for (unsigned i = 0; i < s.size()/2; ++i){
        int aux = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = aux;
    }
}

void diff(vector<int> &s3, vector<int> s1, vector<int> s2)
{
    reverse(s1);
    reverse(s2);
    int t = 0, n3;
    n3 = s1.size();
    s3.resize(n3);
    for (unsigned i = 0; i < s1.size(); ++i){
        if(i < s2.size())
            s3[i] = s1[i] - s2[i] - t;
        else
            s3[i] = s1[i] - t;
        if (s3[i] < 0){
            t = 1;
            s3[i] += 10;
        }
        else t = 0;
    }
    while(s3.size() > 0 && s3[s3.size()-1] == 0)
        s3.pop_back();
    reverse(s3);
}

void copy(vector<int> &destination, vector<int> source)
{
    destination.resize(source.size());
    for (unsigned i = 0; i < source.size(); ++i)
        destination[i] = source[i];
}

vector<int> scaderi_repetate(vector<int> s1, vector<int> s2)
{
    vector<int> s3;
    if(s1.size() == 1 && s1[0] == 0)
        return s2;
    if(s2.size() == 1 && s2[0] == 0)
        return s1;
    while(!(s1.size() == 1 && s1[0] == 0) && !(s2.size() == 1 && s2[0] == 0)){
        if(compare(s1, s2) == 1){
            diff(s3, s1, s2);
            copy(s1, s3);
        }else if(compare(s1, s2) == -1){
            diff(s3, s2, s1);
            copy(s2, s3);
        }else
            return s2;
    }
    return s3;
}

vector<int> cmmdc(int p, int q)
{
    if(q-p <= 1)
        return scaderi_repetate(vv[p], vv[q]);
    int m = (p+q)/2;
    return scaderi_repetate(cmmdc(p, m), cmmdc(m+1, q));
}

void write()
{
    freopen("div.out", "w", stdout);
    vector<int> result = cmmdc(0, vv.size()-1);
    for (int i = 0; i < result.size(); ++i)
        printf("%d", result[i]);
    fclose(stdout);
}

int main()
{
    read();
    write();
    return 0;
}

