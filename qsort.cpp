const int maxn = (int)(1e5 + 10);
int arr[maxn];

void qsort(int l, int r)
{
    if (r - l <= 1)
        return;
    int m = arr[l + rand() % (r - l)];
    int x = l, y = l;
    for (int i = l; i < r; ++i) {
        if (arr[i] < m) {
            swap(arr[i], arr[x]);
            if (x != y) swap(arr[i], arr[y]);
            x++;
            y++;
        }
        else if (arr[i] == m) {
            swap(arr[i], arr[y]);
            y++;
        }
    }
    qsort(l, x);
    qsort(y, r);
}