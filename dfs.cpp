vector<vector<int>> g(n);
vector<char> used(n, false);

void dfs(int v)
{
	used[v] = true;
	for (auto to: g[v]){
		if (!used[to])
			dfs(to);
	}
}