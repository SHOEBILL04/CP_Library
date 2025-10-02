#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct dsu
{
    vector<int> parent;
    vector<int> si;
    multiset<ll> s;
    vector<ll> pop;
    vector<int> d;

    dsu(int n, vector<int>& d) : d(d)
    {
        parent = vector<int>(n);
        si = vector<int>(n, 1);
        pop = vector<ll>(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            pop[i] = d[i];
            s.insert(d[i]);
        }
    }

    int get(int x)
    {
        if(parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void merge(int x, int y)
    {
        x = get(x);
        y = get(y);
        if(x == y) return;
        if(si[x] > si[y]) swap(x, y);
        si[y] += si[x];
        parent[x] = y;
        s.erase(s.find(pop[y]));
        pop[y] += pop[x];
        s.erase(s.find(pop[x]));
        s.insert(pop[y]);
    }

    ll get_max()
    {
        return *s.rbegin();
    }

    void reset(int x, int g)
    {
        int q = d[x];
        d[x] = g;
        x = get(x);
        s.erase(s.find(pop[x]));
        pop[x] += g - q;
        s.insert(pop[x]);
    }
};

void solve() 
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<array<int, 2>> g(m);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        g[i] = {a, b};
    }

    vector<bool> use(m, true);
    vector<array<int, 3>> query;
    for(int i = 0; i < q; i++)
    {
        char c; cin >> c;
        if(c == 'D')
        {
            int a; cin >> a; a--;
            use[a] = false;
            query.push_back({c, a, -1});
        }
        else
        {
            int a, b; cin >> a >> b; a--;
            query.push_back({c, a, d[a]});
            d[a] = b;
        }
    }

    dsu ds(n, d);
    vector<ll> ans;

    for(int i = 0; i < m; i++)
    {
        if(use[i]) ds.merge(g[i][0], g[i][1]);
    }

    reverse(query.begin(), query.end());
    for(auto &[i, j, k] : query)
    {
        ans.push_back(ds.get_max());
        if(i == 'D') ds.merge(g[j][0], g[j][1]);
        else ds.reset(j, k);
    }
    reverse(ans.begin(), ans.end());

    for(auto x : ans) cout << x << endl;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll TC = 1;
    while(TC--) solve();
}


