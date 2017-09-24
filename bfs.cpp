vector<vector<int>> g(n);
vector<int> d(n, inf); // inf = (int)(1e9)
vector<int> p(n, -1);

void bfs(int start)
{
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while(q.size()){
		int v = q.front(); q.pop();
		for (auto to: g[v]){
			if (d[to] > d[v] + 1){
				d[to] = d[v] + 1;
				p[to] = v;
				q.push(to);
			}
		}
	}
}