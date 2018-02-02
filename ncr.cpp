#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define AIN(a, b, c) assert(b <= a && a <= c)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define clrgt rgt,mid+1,ed,s,e
#define inf (1<<29)
#define ii64 ll
#define MX 1000002

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;

typedef pair<int,int> pii;

ll dp[1000][1000];

ll ncrMODdp(int n,int r, int p)
{

    if(r==0) return 1;
    if(r==n) return 1;
    if(r>n) return 0;
    if(dp[n][r]==-1)
    {

        dp[n][r]=(ncrMODdp(n-1,r,p)%p+ncrMODdp(n-1,r-1,p)%p)%p;

    }

    return dp[n][r];
}

int ncrMODLucas(int n,int r,int p)
{
    //base case

    if(r==0) return 1;
    int ni=n%p;
    int ri=r%p;
    //rest of the digits * lastdigits
    return (ncrMODLucas(n/p,r/p,p)*ncrMODdp(ni,ri,p))%p;

}


/* Iterative Function to calculate (x^y)%p
  in O(log y) */

int power(int x, int y, int p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
int modInverse(int n, int p)
{
    return power(n, p-2, p);
}

int ncrMODFermat(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    int fac[n+1];
    fac[0] = 1;
    for (int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;
 //simple ncr formula i.e ( N! / (R!*(N-R)!) )
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

ll ncrMOD(int n,int r,int p)
{

    if(n<1000 && r<1000)
        return ncrMODdp(n,r,p);//normal
    else if(p<1000)
        return ncrMODLucas(n,r,p);//using lucus
    else
        return ncrMODFermat(n,r,p);//best

}

int main()
{
    freopen("in.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    int t,n,r,p;// must be prime.......to do calculation with lucuas
    p=1000003;
    cin>>t;
    REP(i,t){

    cin>>n>>r;
    cout<<"Case "<<i+1<<": ";
    cout<<ncrMOD(n,r,p)<<endl;

    }

    return 0;
}



