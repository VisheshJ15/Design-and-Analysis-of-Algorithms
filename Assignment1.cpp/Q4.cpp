#include <iostream>
#include <algorithm>
using namespace std;
int Maxsubarray(int A[],int p,int q) {
    if (p==q) {
        return max(A[p],0);
    }
    int m=(p+q)/2;
    int maxL=Maxsubarray(A,p,m);
    int maxR = Maxsubarray(A,m+1, q);
    int sum=0;
    int maxmidl=0;
    for (int i=m;i>=p;i--) {
        sum += A[i];
        maxmidl = max(maxmidl,sum);
    }
    sum = 0;
    int maxmidr = 0;
    for (int j=m+1;j<=q;j++) {
        sum += A[j];
        maxmidr=max(maxmidr,sum);
    }
    int maxmid=maxmidl+maxmidr;
    return max(max(maxL,maxR),maxmid);
}
int main() {
    int arr[] = {-2,-5,6,-2,-3,1,5,-6};;
    int result = Maxsubarray(arr,0,7);
    cout<<result;
}
