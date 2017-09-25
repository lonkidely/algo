vector<vector<pair<int, int>>> g(n);
vector<int> d(n, inf);
vector<int> p(n, -1);

void dijkstra(int start)
{
	d[start] = 0;
	set <pair<int, int>> q;
	q.insert(mp(0, s));
	while (q.size()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for (int i = 0; i < g[v].size(); ++i){
			int to = g[v][i].first, len = g[v][i].second;
			if (d[to] > d[v] + len){
				q.erase(mp(d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert(mp(d[to], to));
			}
		}
	}
}