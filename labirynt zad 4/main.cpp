#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <queue>
const int N=20;
using namespace std;
void wl (int lab[][N])
{
    string s;
    ifstream we("labirynt.txt");
    for (int i=0;i<N;i++)
    {
        we>>s;
        for (int j=0;j<N;j++)
            if (s[j]=='X') lab[i][j]=-1;
        else lab [i][j]=0;
    }
    we.close();
}
void wyl(int lab[][N])
{
    cout<<"   ";
    for (int j=0;j<N;j++)
        cout<<setw(3)<<j;
    cout<<endl;
    for (int i=0;i<N;i++)
    {

    cout<<setw(3)<<i;
    for(int j=0;j<N;j++)
    {


        if (lab[i][j]==-1) cout<<"  X";
    else if (lab[i][j]==-2) cout<<"  D";
    else cout<<"   ";
    }
    cout<<endl;
}
}
struct pole
{
    int w, k;
};

bool droga(int lab[][N], pole p1, pole &p2)
{
    int w,k;
    bool wyjscie=false;
    queue<pole> Q;
    Q.push(p1);
    lab[p1.w][p1.k]=1;
    while (!wyjscie && ! Q.empty())
    {
        p2=Q.front(); Q.pop(); w=p2.w; k=p2.k;
        if (w==0 || w==N-1 || k==0 || k==N-1)
            wyjscie=true;
        else
        {
            if(lab[w-1][k]==0)
            {
                lab[w-1][k]=lab[w][k]+1;
                p2.w=w-1; p2.k=k; Q.push(p2);
            }
            if(lab[w+1][k]==0)
            {
                lab[w+1][k]=lab[w][k]+1;
                p2.w=w+1; p2.k=k;
                Q.push(p2);
            }
             if(lab[w][k-1]==0)
            {
                lab[w][k-1]=lab[w][k]+1;
                p2.w=w; p2.k=k-1;
                Q.push(p2);
            }
             if(lab[w][k+1]==0)
            {
                lab[w][k+1]=lab[w][k]+1;
                p2.w=w; p2.k=k+1;
                Q.push(p2);
            }
        }
    }
    return wyjscie;
}
void ozndroge(int lab[][N],int w,int k)
{
    int x=lab[w][k];
    lab[w][k]=-2;
    while (x>1)
    {
        x--;
        if (w>0 && lab[w-1][k]==x) w--;
        else if (w<N-1 && lab[w+1][k]==x) w++;
        else if (k>0 && lab[w][k-1]==x) k--;
        else k++;
        lab[w][k]=-2;
    }
}

int main()
{
     int lab[N][N];
     pole p1,p2;
     wl(lab);
     wyl(lab);
     cout<<"wspolrzedne pola startowego: "<<endl;
     cout<<"w = "; cin>>p1.w;
     cout<<"k = "; cin>>p1.k;
     if (droga(lab,p1,p2))
     {
        ozndroge(lab,p2.w,p2.k);
        wyl(lab);

     }
     else
        cout<<"brak drogi";
     return 0;
}



