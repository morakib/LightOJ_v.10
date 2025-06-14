#include <iostream>
using namespace std;
const int MOD=10000007;

long long hexabonacci(int a, int b, int c, int d, int e, int f, int n) {
    if(n==0) return a%MOD;
    if(n==1) return b%MOD;
    if(n==2) return c%MOD;
    if(n==3) return d%MOD;
    if(n==4) return e%MOD;
    if(n==5) return f%MOD;
    long long last6[6] = {a % MOD, b % MOD, c % MOD, d % MOD, e % MOD, f % MOD};
    for(int i=6;i<=n;i++){
        long long sum = 0;
        for(int k=0;k<6;k++){
            sum=(sum+last6[k])%MOD;
        }
        for(int k=0;k<5;k++){
            last6[k]=last6[k+1];
        }
        last6[5] = sum; 
    }
    return last6[5];
}

int main(){
    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        int a,b,c,d,e,f,n;
        cin>>a>>b>>c>>d>>e>>f>>n;
        long long res=hexabonacci(a,b,c,d,e,f,n);
        cout<<"Case "<<tc<<": "<<res%MOD<<endl;
    }
}
