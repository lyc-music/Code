#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define F first
#define S second
vector<vector<pair<int,int>>> g(100100);
int par[100100],ld[100100][31],lu[100100][31],vd[100100][31],vu[100100][31],w[100100];

void dfs(int nd){
    for(auto x:g[nd]){
        if(!par[x.F]&&x.F!=1){
            par[x.F]=nd;
            w[x.F]=x.S;
            dfs(x.F);
        }
    }
}

void ddfs(int nd,int b){
    multiset<pair<int,int>> st;
    ld[nd][b]=0;
    vd[nd][b]=nd;
    for(auto x:g[nd]){
        //if(b==2&&x.F==5)cout<<"hi "<<ld[5][2]<<'\n';
        if(par[x.F]==nd){
            ddfs(x.F,b);
            if(((1LL<<b)&(x.S))){
                if(ld[x.F][b]+1>ld[nd][b]){
                    ld[nd][b]=1+ld[x.F][b];
                    vd[nd][b]=vd[x.F][b];
                }
                st.insert({ld[x.F][b]+1,vd[x.F][b]});
            }
        }
    }
    st.insert({0,nd});
    for(auto x:g[nd]){
        if(par[x.F]==nd&&((1LL<<b)&(x.S))){
            st.erase(st.find({ld[x.F][b]+1,vd[x.F][b]}));
            auto it=st.end();
            it--;
            lu[x.F][b]=1+(it->F);
            vu[x.F][b]=(it->S);
            st.insert({ld[x.F][b]+1,vd[x.F][b]});
        }
    }
}

void udfs(int nd,int b){
    if(lu[nd][b]<lu[par[nd]][b]+1&&((1LL<<b)&(w[nd]))){
        lu[nd][b]=lu[par[nd]][b]+1;
        vu[nd][b]=vu[par[nd]][b];
    }
    else if(((1LL<<b)&(w[nd]))==0){
        lu[nd][b]=0;
        vu[nd][b]=nd;
    }
    for(auto x:g[nd]){
        if(par[x.F]==nd)udfs(x.F,b);
    }
}

void solve(int ttt){
    int n;
    cin>>n;
    bool found[n+1];
    for(int i=0;i<=n;i++){
        par[i]=0;
        for(int b=0;b<31;b++){
            lu[i][b]=0;
            ld[i][b]=0;
            vu[i][b]=1;
        }
        found[i]=0;
        g[i].clear();
    }
    w[1]=0;
    for(int i=1;i<n;i++){
        int u,v,x;
        cin>>u>>v>>x;
        g[u].pb({v,x});
        g[v].pb({u,x});
    }
    dfs(1);
    //for(int i=1;i<=n;i++)cout<<par[i]<<' ';cout<<endl;
    for(int b=0;b<31;b++){
        ddfs(1,b);
        udfs(1,b);
    }
    pair<int,int> ans[n+1];
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(found[x]){
            cout<<ans[x].F<<' '<<ans[x].S<<'\n';
            continue;
        }
        int an=0,u=-1,v1=-1;
        for(int b=0;b<31;b++){
            vector<pair<int,int>> v;
            for(auto y:g[x]){
                if(par[y.F]==x&&((1LL<<b)&(y.S))){
                    v.pb({ld[y.F][b],vd[y.F][b]});
                }
            }
            int nd=x;
            if(v.empty()&&lu[nd][b]==0)continue;
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            int ans1=lu[nd][b]+ld[nd][b],u2=vd[nd][b],v2=vu[nd][b];
            if(1<(int)v.size()&&v[0].F+v[1].F+2>ans1){
                ans1=v[0].F+v[1].F+2;
                u2=v[0].S;v2=v[1].S;
            }
            if(ans1>an){
                an=ans1;
                u=u2;
                v1=v2;
            }
        }
        found[x]=1;
        ans[x]={u,v1};
        cout<<u<<' '<<v1<<'\n';
    }
    for(int i=1;i<=n;i++){
        //for(int j=0;j<=2;j++)cout<<i<<' '<<j<<' '<<ld[i][j]<<' '<<vd[i][j]<<' '<<lu[i][j]<<' '<<vu[i][j]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //prepare();
    int ttt=1;
    int tt;cin>>tt;for(int ttt=1;ttt<=tt;ttt++)
    solve(ttt);
}