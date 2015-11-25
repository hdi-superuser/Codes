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

const int maxn = 100007;

vector<int> a[maxn];
int n,k,val[maxn],root;

void getresult(int u, vector<int> &res){
	vector<int> dp(res.begin(),res.end());
	int v;
	REP(i,sz(a[u])){
		v=a[u][i];
		getresult(v,dp);
	}
	
	FORD(i,k,2){
		res[i]=max(res[i],dp[i]);
		if(res[i-1]>0) res[i]=max(res[i],res[i-1]+val[u]);
	}
	res[1]=max(val[u],dp[1]);
}

int main(){
	freopen("test.txt","r",stdin);
	
	while(scanf("%d%d",&n,&k),n){
		int u;
		FOR(i,1,n) a[i].clear();
		FOR(i,1,n){
			scanf("%d%d",&u,val+i);
			if(u==0) root=i; else a[u].pb(i);
		}
		vector<int> res(k+1,0);
		getresult(root,res);
		//FOR(i,1,k) cout<<res[i]<<endl;
		printf("%d\n",res[k]);
	}
	return 0;
}
	
	
