const int maxn = (int)(1e5 + 10);

int arr[maxn];
int tree[maxn];
int n = 0;

inline int f(int i){
	return (i & (~(i + 1))) + 1;
}

void inc(int idx, int val)
{
	for (int i = idx; i < n; i += f(i))
		tree[i] += val;
}

int sum(int idx)
{
	int result = 0;
	for (int i = idx; i >= 0; i -= f(i))
		result += tree[i];
	return result;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}