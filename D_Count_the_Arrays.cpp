// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long mod=998244353,inf=(9e17),MAX=2e5+5;
int n,m,i,j;


// A GooDProblem on Combinatorics- https://codeforces.com/contest/1312/problem/D
/*
calculate the number of arrays such that:

each array contains n elements; and each element is an integer from 1 to m;
for each array, there is exactly one pair of equal elements;
for each array a, there exists an index i such that the array is 
strictly ascending before the i-th element and strictly descending 
after it (formally, it means that aj<aj+1, if j<i, and aj>aj+1, if j≥i).
*/


// Factorial Computation
int poww(const int &a,int b,const int &m=mod)
    {if(b==0)return 1;
            int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 

int fact[MAX]; int invfac[MAX];

int mod_inv(int a,int m){
    a=a%m;
    return poww(a,m-2,m)%mod;
}

int ncr(int n,int r){
    if(r>n)return 0;
    int a=fact[n],b=invfac[r],c=invfac[n-r];
    return (a*((b*c)%mod))%mod;   
}

void count_fact(){

    int i,x=1;
    fact[0]=1; invfac[0]=1;
    for(i=1;i<MAX;i++)
    {
        x=(x*i)%mod;
        fact[i]=x;
        invfac[i]=mod_inv(fact[i],mod);
    }
}

void solve()
{
    cin>>n>>m;

    if(n<=2)
    {
        if(n==2)n=0;
        cout<<n;    return;
    }

    int ans=ncr(m,n-1); // Chosing n-1 elements to create n size array (2 repeating in this)
    ans%=mod;
    // Among n-1 the max not can be pair so time to chose among n-2 by fixing pair at left and right
    int arrangement=0;
    for(int i=1;i<=n-2;i++)
    {
        (arrangement+=ncr(n-3,i-1))%=mod;  // -1 for maxi -2 for pair so left numbers n-3 which have only one
        // Permutaion which is in increasing order on left side
    }
    (ans*=arrangement)%=mod;
    // Do the Above method for all (n-2) pair optin available
    ans*=(n-2); ans%=mod;
    cout<<ans;
}

signed main(){
   
//  Remember Someone out there is working 10x harder than you rn..
//    Chasing after the same goals...
//       So get up and go fucking work harder towards your goals.
    count_fact();
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
/* TODO_problems:
*/