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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

int main(){
    int i,k,b,n,t;
    ll z;
    cin>>k>>b>>n>>t;
    z=1;
    for(i=0;z<=t;i++) z=z*k+b;
    cout<<max(n-i+1,0);
    return 0;
}
