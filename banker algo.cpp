#include<iostream>
using namespace std;
 const int p =5;
 const int r=3;
void calculateNeed( int need[p][r],int maxm[p][r],int allot[p][r])
{
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need [i][j] = maxm[i][j]-allot[i][j];
        }
    }
}
 int issafe(int proccesor[], int avail[], int maxm [][r], int allot[][r] )
{
    int need[p][r];
    calculateNeed(need,maxm,allot);
    bool finish[p]= {0};
    int safeseq[p];
    int work[r];
    for(int i=0;i<r;i++)
    work[i] = avail[i];
    int count =0;
    while (count<p)
    {
        bool found = false;
        for(int p=0;p<p;p++)
        {
            if(finish[p] == 0)
            {
                int j;
                for(j=0;j<r;j++)
                {
                    if(need[p][j]>work[j])
                    {
                        break;
                    }
                    if(j==r)
                    {
                        for(int k=0;k<r;k++)
                            work[k] += allot[p][r];
                            safeseq[count++]= p;
                            found = true;
                    }
                }
            }
        }
        if(found == false)
        {
            cout<<"system is not in safe mode ";
            return false ; 
        }
    }
    cout<<"system is found in safe state.\n safe""sequence is:";
    for(int i=0;i<p;i++)
    {
        cout<<safeseq[i]<<" ";
        return true;
    }
}
int main()
{
    int avail[] = {};
     int processes[] = {0,1,2,3,4};
     int maxm[][r] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
     int allot[][r] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
     issafe(processes,avail,maxm,allot);
     return 0;

}