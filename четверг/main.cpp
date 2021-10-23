#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define N 1000
#define F 100

int main()
{
    ifstream inn;
    inn.open("inn.txt");
    ofstream outt;
    outt.open ("outt.txt");
    int o;
    int p;
    inn>>o>>p;
    int* sum=new int[o];
    
    int** zap=new int*[o];
    for (int i=0; i<o; ++i)
    {
        zap[i]=new int[p];
    }

    int** array=new int*[o];
    for (int i=0; i<o; ++i)
    {
        array[i]=new int[p];
    }

    for (int i=0; i<o; ++i)
    {
        for (int j=0; j<p; ++j)
        {
            int a;
            inn>>a;
            array[i][j]=a;
            zap[i][j]=a;
        }
    }
    
    for (int i=0; i<o; ++i)
    {
        sum[i]=0;
    }
    
    for (int i=0; i<o; ++i)
    {
        for (int j=0; j<p; ++j)
        {
            sum[i]+=array[i][j];
        }
    }
    
    int max = 0;

    for (int i=0; i<o-1; ++i)
    {
        for (int j=1; j<o; ++j)
        {
            if (sum[i]>sum[j])
                max=i;
            else
                max=j;
        }
        if (max==i)
            break;
    }

    for (int i=0; i<p; ++i)
    {
        zap[max][i]+=1;
    }
    
    for (int i=0; i<o; ++i)
    {
        for (int j=0; j<p; ++j)
        {
            cout<<zap[i][j]<<' ';
            outt<<zap[i][j]<<' ';
        }
        cout<<endl;
        outt<<endl;
    }
    
    for (int i=0; i<o; ++i)
    {
        delete[] array[i];
    }
    
    for (int i=0; i<o; ++i)
    {
        delete[] zap[i];
    }
    
    delete[] sum;
    return 0;
}
