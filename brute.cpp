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
const unsigned int MOD = 1000000007;
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
//__builtin_popcount(num)
//stringstream ss(s) //can take input as ss >> x;
//ll gcd(ll A, ll B) { return __gcd(A, B); }
//ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

void solve() 
{
	ll n; cin >> n;
	vector<int>v;
	bool flag = false, trk = 0;;
	for(int i = 1; i<=n; i++)v.pb(i);
	int val = 0;
	do
	{
		val = 0;
		trk = 0;
		flag = false;
		for(int i = 0; i<n; i++)
		{
			val^=v[i];
			if(val==0)
			{
				flag = true;
				break;
			}
		}
		if(!flag)trk = 1;
	}
	while(next_permutation(v.begin(), v.end()) && !flag);
	if(val==0)
	{
		cout << -1 << endl;
		return;
	}
	for(auto &x: v)cout << x << " ";
	cout << endl;
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
