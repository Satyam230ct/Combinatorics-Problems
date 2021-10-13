// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long mod=1e9+7,inf=(9e17),MAX=2e5+5;
int n,m,i,j;

/*

Q-> You are given two integers a and m. (1≤a<m≤10^(10)).
Calculate the number of integers x such that 0≤x<m and gcd(a,m)=gcd(a+x,m).

Solution->

The Euclidean algorithm is based on the next fact: if a≥b then gcd(a,b)=gcd(a−b,b). 
So, if (a+x)≥m then gcd(a+x,m)=gcd(a+x−m,m). So we can declare that we are looking at 
m different integers x′=(a+x)modm with 0≤ x′<m, so all x′ forms a segment [0,m−1].
So, we need to find the number of x′ (0≤x′<m) such that gcd(x′,m)=gcd(a,m).

Let's denote g=gcd(a,m), then a=ga′ and m=gm′. 
So, gcd(a,m)=gcd(ga′,gm′)=g⋅gcd(a′,m′)=g or gcd(a′,m′)=1.
Since gcd(x′,m)=gcd(a,m)=g so we also can represent x′=x′′g and, therefore gcd(x′′,m′)=1.

Since 0≤x′<m, then 0≤x′′<m′ or we need to calaculate the number of x′′ (0≤x′′<m′) 
such that gcd(x′′,m′)=1. Since gcd(0,m′)=m′>1 so we can consider x′′∈[1,m′−1] 
and this is the definition of Euler's totient function φ(m′) which is the answer.

*/

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void solve()
{
    int a,m;    cin>>a>>m;
    cout<<phi(m/__gcd(a,m));
}

signed main(){
   
//  Remember Someone out there is working 10x harder than you rn..
//    Chasing after the same goals...
//       So get up and go fucking work harder towards your goals.
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
/* TODO_problems:
*/