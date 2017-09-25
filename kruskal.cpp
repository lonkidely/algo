int p[maxn];
int r[maxn];

void make_set(int v)
{
	p[v] = v;
	r[v] = 1;
}

int find_set(int v)
{
	if (p[v] == v) return v;
	return p[v] = find_set(p[v]);
}

void union_sets(int v, int u)
{
	v = find_set(v);
	u = find_set(u);
	if (v != u) {
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
		r[u] += r[v];
	}
}

struct edge {
	int v, u, w;
};

edge make_edge(int v, int u, int w) {
	edge res;
	res.v = v;
	res.u = u;
	res.w = w;
	return res;
}

bool comp(edge a, edge b) {
	return a.w < b.w;
}

vector<edge> g;

void solve()
{
	int n, m;
	cin >> n >> m;
	g.resize(m);

	for(int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		g[i] = make_edge(v, u, w);
	}

	for (int i = 0; i < n; ++i) make_set(i);

	vector<pair<int, int>> ans;
	int weight = 0;

	sort(g.begin(), g.end(), comp);

	for (int i = 0; i < m; ++i) {
		int v = g[i].v, u = g[i].u, w = g[i].w;
		v = find_set(v), u = find_set(u);
		if (v != u) {
			weight += w;
			ans.push_back(mp(v, u));
			union_sets(v, u);
		}
	}
}