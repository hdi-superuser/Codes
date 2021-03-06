#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=250007;

int IT[maxn*4],n;
set<pii> line[maxn];

void update(int i, int l, int r, int s, int f, int v){
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i] += v;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,v); update(i*2+1,mid+1,r,s,f,v);
}

int get(int i, int l, int r, int p){
    if(p<l || p>r) return 0;
    int res = IT[i];
    if(l==r) return res;
    int mid=(l+r)/2;
    return res + get(i*2,l,mid,p) + get(i*2+1,mid+1,r,p);
}


void add_line(int v, int l, int r){
    if(line[v].empty()){
        line[v].insert(pii(l,r));
        update(1,1,n,l,r,1);
//        cout<<v<<": add " <<l<<"-"<<r<<endl;
        return;
    }
    set<pii>::iterator it = line[v].lower_bound(pii(l,-1));
    vector<pii> delList;
    if(it != line[v].begin()){
        --it;
        if(it->second >= l){
            if(r <= it->second) return;
            delList.pb(*it);
            l = it->first;
        }
        ++it;
    }
    while(it != line[v].end() && it->second <= r){
        delList.pb(*it);
        ++it;
    }
    if(it != line[v].end() && it->first <= r){
        delList.pb(*it);
        r = it->second;
    }


    for(int i=0; i<sz(delList); ++i){
        pii p = delList[i];
        line[v].erase(p);
        update(1,1,n,p.first,p.second,-1);
//        cout<<v<<": del " <<p.first<<"-"<<p.second<<endl;
    }

    update(1,1,n,l,r,1);
    line[v].insert(pii(l,r));
//    cout<<v<<": add " <<l<<"-"<<r<<endl;

}

int main(){
//    freopen("input.txt","r",stdin);

    int m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){
        int t,l,r,v;
        scanf("%d",&t);
        if(t==0){
            scanf("%d%d%d",&l,&r,&v);
            add_line(v,l,r);
        }else{
            scanf("%d",&v);
            printf("%d\n",get(1,1,n,v));
        }
    }
    return 0;
}

