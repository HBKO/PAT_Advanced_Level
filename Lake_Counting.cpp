#include<iostream>
using namespace std;
//输入

const int MAX_N=200,MAX_M=200;
int N,M;
char field[MAX_N][MAX_M+1];


void dfs(int x,int y)
{
    field[x][y]='.';
    int nx,ny;
    for(int dx=-1;dx<=1;++dx)
    {
        for(int dy=-1;dy<=1;++dy)
        {
            nx=x+dx;ny=y+dy;
            if(nx>=0 && nx<=N-1 && ny>=0 && ny<=M-1 && field[nx][ny]=='W') dfs(nx,ny);
        }
    }
    return;
}


int main()
{
    int i,j;

    while(cin>>N>>M)
    {
        int count=0;
        for(i=0;i<N;++i)
            cin>>field[i];
        for(i=0;i<N;++i)
        {
            for(j=0;j<M;++j)
            {
                if(field[i][j]=='W')
                {
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}