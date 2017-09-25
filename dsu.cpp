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
	if (v != u){
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
		r[u] += r[v];
	}
}