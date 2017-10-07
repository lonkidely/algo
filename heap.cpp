const int maxn = (int)(2e5 + 10);


class heap
{
private:
	vector<int> h;
	int size = 0;
public:
	heap() {
		h.resize(maxn);
	}
	void push(int val)
	{
		h[size] = val;
		siftUp(size);
		size++;
	}
	void siftUp(int v)
	{
		if (v > 0 && h[v] > h[(v - 1) / 2]) {
			swap(h[v], h[(v - 1) / 2]);
			siftUp((v - 1) / 2);
		}
	}
	void siftDown(int v)
	{
		if (v * 2 + 1 >= size)
			return;
		int idx = 0;
		if (v * 2 + 2 == size || h[v * 2 + 1] > h[v * 2 + 2])
			idx = v * 2 + 1;
		else
			idx = v * 2 + 2;
		if (h[idx] > h[v]) {
			swap(h[v], h[idx]);
			siftDown(idx);
		}
	}
	int front()
	{
		int res = h[0];
		swap(h[0], h[--size]);
		siftDown(0);
		return res;
	}
};