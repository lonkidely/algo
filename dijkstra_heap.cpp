vector<vector<pair<int, int>>> g(n);
vector<int> d(n, inf);
vector<int> p(n, -1);

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue <pair<int, int>> q;
	q.push(mp(0, start));
	while (q.size()) {
		int v = q.top().second, cur_d = -q.top().first;
		q.pop();
		if (d[v] < cur_d) continue;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first, len = g[v][i].second;
			if (d[to] > d[v] + len) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push(mp(-d[to], to));
			}
		}
	}
}