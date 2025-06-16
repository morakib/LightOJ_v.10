#include <iostream>  
#include <cmath>    
int i;
void findpos(long long n){
    long long root=ceil(sqrt(n));
    long long square=root*root;
    long long diff=square-n;
    long long row,col;
    if(root %2==0){ // even root
        if(diff<root){
            row=root;
            col=1+diff;
        }else{
            row= n- (root-1)*(root-1);
            col=root;
        }
    }else{ // odd root
        if(diff<root){
            row=1+diff;
            col=root;
        }else{
            row=root;
            col=n- (root-1)*(root-1);
        }
    }   
    cout<<"Case "<<i<<": "<<row<<" "<<col<<endl;
}
int main(){
    int  t;
    cin>>t;
    for(i=1;i<=t;i++){
        long long n;
        cin>>n;
        findpos(n);
    }
}
