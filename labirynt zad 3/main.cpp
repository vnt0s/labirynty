#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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

bool droga(int lab[][N], int w, int k,int x, int&w1, int&k1)
{
    lab[w][k]=x;
    if (w==0 || w==N-1 || k==0 || k==N-1) // te dwa || oznaczaja lub
    {
        w1=w; k1=k;
        return true;
    }
    if (lab[w-1][k]==0 && droga(lab,w-1,k,x+1,w1,k1))
        return true;
    if (lab[w+1][k]==0 && droga(lab,w+1,k,x+1,w1,k1))
        return true;
    if (lab[w][k-1]==0 && droga(lab,w,k-1,x+1,w1,k1))
        return true;
    if (lab[w][k+1]==0 && droga(lab,w,k+1,x+1,w1,k1))
        return true;
    return false;

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
     int w,k,w1,k1;
     int lab[N][N];
     wl(lab);
     wyl(lab);
     cout<<"wspolrzedne pola startowego: "<<endl;
     cout<<"w = "; cin>>w;
     cout<<"k = "; cin>>k;
     if (droga(lab,w,k,1,w1,k1))
     {
        ozndroge(lab,w1,k1);
        wyl(lab);

     }
     else
        cout<<"brak drogi";
     return 0;
}



