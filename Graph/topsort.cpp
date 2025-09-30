#define N 1e5;
vector<bool>vis(N);
vector<ll>ts;
vector<pair<int, int>>adj[N];
void topsort(ll u)
{
	vis[u] = true;
	for(auto &[v, w]==false)
	{
		topsort(v);
	}
	ts.push_back(u);
}


