#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

double f(double x,double y)
{
    return x*x+y*y;
}

void rungeKuttaMethod()
{
    double x0,y0,xn,yn,k1,k2,k3,k4,k,intv,h;
    cout<<"for the format y(x0)=y0 enter the value of:\n";
    cout<<"x0 = ";
    cin>>x0;
    cout<<"y0 = ";
    cin>>y0; //given y0 for x0
    cout<<"enter the value of for which you want the value y:\n";
    cin>>xn; //finding the value of yn for xn
    cout<<"enter the interval which will be used to calculate jump distance: ";
    cin>>intv;
    h=(xn-x0)/intv;
    for(int i=1; i<=intv; i++)
    {
        k1=h*(f(x0,y0));
        k2=h*(f((x0+h/2),(y0+k1/2)));
        k3=h*(f((x0+h/2),(y0+k2/2)));
        k4=h*(f((x0+h),(y0+k3)));
        k=(k1+2*k2+2*k3+k4)/6;
        yn=y0+k;
        y0=yn;
        x0+=i*h;
    }
    cout<<"At x = "<<xn<<"   y = "<<yn<<endl;
}


void swap_rows(float a[10][20],int row1,int row2,int n)
{
    for(int j=1; j<=2*n; j++)
    {
        swap(a[row1][j],a[row2][j]);
    }
}

void matrixInversion()
{
    int n,i,j,k;
    float pivot,factor;
    cout<<"Enter the size of the square matrix:";
    cin>>n;
    float a[10][20];
    cout<<"Enter the elements of the matrix:\n";
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
        for(j=n+1; j<=2*n; j++)
        {
            (j==i+n)?a[i][j]=1.0:a[i][j]=0.0;
        }
    }

    for(i=1; i<=n; i++)
    {
        if(a[i][i]==0.0)
        {
            bool sw=false;
            for(int row=i+1; row<=n; row++)
            {
                if(a[row][i]!=0.0)
                {
                    swap_rows(a,i,row,n);
                    sw=true;
                    break;
                }
            }
            if(!sw)
            {
                cout<<"Matrix is singular and can't be inverted!\n";
                return;
            }
        }
        pivot=a[i][i];
        for(j=1; j<=2*n; j++)
        {
            a[i][j]/=pivot;
        }

        for(j=1; j<=n; j++)
        {
            if(i!=j)
            {
                factor=a[j][i];
                for(k=1; k<=2*n; k++)
                {
                    a[j][k]-=factor*a[i][k];
                }
            }
        }
    }

    cout<<"The inverse matrix is:\n";
    for(i=1; i<=n; i++)
    {
        for(j=n+1; j<=2*n; j++)
        {
            cout<<setw(5)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void last()
{

    int c;
    cout<<"Input 1 for rungeKuttaMethod\n";
    cout<<"Input 2 for matrix inversion\n";
    cin>>c;
    switch(c)
    {
    case 1:
    rungeKuttaMethod();
    break;
    case 2:
    matrixInversion();
    break;
    }
    return 0;
}

