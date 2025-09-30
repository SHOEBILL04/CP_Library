#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define For(start, end) for(int i = (start); i < (end); i++)
#define no "NO"
#define yes "YES"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define len(x) (ll)x.size()
using ull = unsigned long long;
const long long INF = 1000000000000000000ll;
typedef pair<int, int>ii;
typedef vector<int>vi;
typedef vector<pair<ll, ll>>vll;
typedef vector<ll>vl;
typedef vector<ii> vii;
int dx[] = {-1,1, 0, 0, -1,-1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll gen_random(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rng);}
const unsigned int MOD = 1000000007;
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T binpow(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
//__builtin_popcount(num)
//stringstream ss(s) //can take input as ss >> x;
//ll gcd(ll A, ll B) { return __gcd(A, B); }
//ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

struct DSU
{
	map<int, int>parent;
	map<int, int>nxt;
	map<int, int>rank;
	int num_com = 0, max_com = 0;
	int find(int x)
	{
		auto it = parent.find(x);
		if(it==parent.end())
		{
			parent[x] = x;
			rank[x] = 1;
			return x;
		}
		if(it->second == x) return x;
		return it->second = find(it->second);
	}
	int get_next(int x)
	{
		auto it = nxt.find(x);
		if(it==nxt.end())return x;
		return it->second = get_next(it->second);
	}
	bool merge(int u, int v)
	{
		int ulp_u =  find(u);
		int ulp_v = find(v);
		if(ulp_u==ulp_v)return false;
		num_com++;
		if(ulp_u>ulp_v)swap(ulp_u, ulp_v);
		parent[ulp_v] = ulp_u;
		rank[ulp_u] = rank[ulp_u]+rank[ulp_v];
		max_com = max(max_com, rank[ulp_u]);
		return true;
	}
	void remove_idx(int x)
	{
		nxt[x] = x+1;
	}
};
void solve() 
{
	DSU ds;
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		ds.merge(u, v);
		cout << n-ds.num_com << " " << ds.max_com << endl;
	}
}
 
int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout); 

	ll TC = 1;
//	cin >> TC;
    while (TC--) 
    {
        solve();
    }
}
