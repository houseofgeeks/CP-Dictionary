#include<bits/stdc++.h>
using namespace std;
int extendedEuclidean(int a,int b,int &x,int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int gcd = extendedEuclidean(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return 0;
}
int main(){
    int a = 60,b=4,x,y;
    int gcd= extendedEuclidean(a,b,x,y);
    cout<<gcd<<endl;
    return 0;
}

//ax + by = gcd and (b%a)x1 + ay1 = gcd (by Euclidean Algorithm) 
//solving these equations we get x = y1 -(b/a)*x1 and y = x1
