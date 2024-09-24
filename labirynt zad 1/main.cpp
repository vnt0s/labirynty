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



int main()
{
     int w,k,w1,k1;
     int lab[N][N];
     wl(lab);
     wyl(lab);


}



