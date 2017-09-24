vector<vector<int>> g(n);
vector<char> used(n, false);
vector<int> arr(n);

void dfs(int v)
{
	used[v] = true;
	for (auto to: g[v]){
		if (!used[to])
			dfs(to);
	}
	arr.push_back(v);
}

reverse(arr.begin(), arr.end());