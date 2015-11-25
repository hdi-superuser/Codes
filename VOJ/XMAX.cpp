#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

bool cmp(ll a, ll b){
    return a>b;
}

ll a[maxn];
int n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    ll maxv=0;
    FOR(i,1,n){
        scanf("%lld",&a[i]);
        maxv=max(maxv,a[i]);
    }
    sort(a+1,a+n+1,cmp);
    ll bit=1;
    while(bit*2<=maxv) bit<<=1;
    for(int i=1; bit!=0; bit>>=1){
        int j=i;
        while(j<=n && (a[j]&bit)==0) j++;
        if(j>n) continue;
        swap(a[i],a[j]);
        FOR(j,1,n) if(j!=i && a[j]&bit) 
        a[j]^=a[i];
        i++;
    }
    
    ll res=0;
    FOR(i,1,n) res^=a[i];
    
    cout<<res<<endl;
    //getch();
    return 0;
}
        
    
