struct DSU
{
	map<int, int>parent;
	map<int, int>nxt;
	int find(int x)
	{
		auto it = parent.find(x);
		if(it==parent.end())
		{
			parent[x] = x;
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
		if(ulp_u>ulp_v)swap(ulp_u, ulp_v);
		parent[ulp_v] = ulp_u;
		return true;
	}
	void remove_idx(int x)
	{
		nxt[x] = x+1;
	}
};
