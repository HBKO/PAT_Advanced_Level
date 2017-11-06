#include<iostream>
#include<string>
#include<vector>
using namespace std;

string MAX="99:99:99";
string MIN="00:00:00";
vector<string> ID;
vector<string> st;
vector<string> finish;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string IDn;
        string stn;
        string endn;
        cin>>IDn>>stn>>endn;
        ID.push_back(IDn);st.push_back(stn);finish.push_back(endn);
    }
    int stlo,endlo;
    string stm=MAX;
    string endm=MIN;
    for(int i=0;i<n;++i)
    {
        if(st[i]<stm)
        {
            stlo=i;
            stm=st[i];
        }

        if(finish[i]>endm)
        {
            endlo=i;
            endm=finish[i];
        }
    }

    cout<<ID[stlo]<<" "<<ID[endlo];
    return 0;

}