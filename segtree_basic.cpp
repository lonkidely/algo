int t[4 * maxn];
int arr[maxn];
 
void build(int v, int tl, int tr)
{
    if (tl == tr) {
        t[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}
 
int query(int v, int tl, int tr, int l, int r)
{
    if (l > tr || r < tl)
        return 0;
    if (l <= tl && r >= tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return query(2 * v + 1, tl, tm, l, r) + query(2 * v + 2, tm + 1, tr, l, r);
}
 
void update(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr) {
        t[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(2 * v + 1, tl, tm, pos, val);
    else
        update(2 * v + 2, tm + 1, tr, pos, val);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
 
}