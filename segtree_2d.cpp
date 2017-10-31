const int maxn = (int)(1e3 + 100);
const int maxm = (int)(1e3 + 100);

int arr[maxn][maxm];
int t[4 * maxn][4 * maxm];
int n = 0, m = 0;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
	if (ly == ry){
		if (lx == rx)
			t[vx][vy] = arr[lx][ly];
		else
			t[vx][vy] = t[2 * vx + 1][vy] + t[2 * vx + 2][vy];
	}
	else{
		int my = (ly + ry) / 2;
		build_y(vx, lx, rx, 2 * vy + 1, ly, my);
		build_y(vx, lx, rx, 2 * vy + 2, my + 1, ry);
		t[vx][vy] = t[vx][2 * vy + 1] + t[vx][2 * vy + 2];
	}
}

void build_x(int vx, int lx, int rx)
{
	if (lx != rx){
		int mx = (lx + rx) / 2;
		build_x(2 * vx + 1, lx, mx);
		build_x(2 * vx + 2, mx + 1, rx);
	}
	build_y(vx, lx, rx, 0, 0, m - 1);
}

int sum_y(int vx, int vy, int tl_y, int tr_y, int ly, int ry)
{
	if (ly > tr_y || tl_y > ry)
		return 0;
	if (ly <= tl_y && tr_y <= ry)
		return t[vx][vy];
	int tm_y = (tl_y + tr_y) / 2;
	return sum_y(vx, 2 * vy + 1, tl_y, tm_y, ly, ry) + sum_y(vx, 2 * vy + 2, tm_y + 1, tr_y, ly, ry);
}

int sum_x(int vx, int tl_x, int tr_x, int lx, int rx, int ly, int ry)
{
	if (lx > tr_x || tl_x > rx)
		return 0;
	if (lx <= tl_x && tr_x <= rx)
		return sum_y(vx, 0, 0, m - 1, ly, ry);
	int tm_x = (tl_x + tr_x) / 2;
	return sum_x(2 * vx + 1, tl_x, tm_x, lx, rx, ly, ry) + sum_x(2 * vx + 2, tm_x + 1, tr_x, lx, rx, ly, ry);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int y, int val)
{
	if (ly == ry){
		if (lx == rx){
			t[vx][vy] += val;
		}
		else
			t[vx][vy] = t[2 * vx + 1][vy] + t[2 * vx + 2][vy];
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y(vx, lx, rx, 2 * vy + 1, ly, my, y, val);
		else
			update_y(vx, lx, rx, 2 * vy + 2, my + 1, ry, y, val);
		t[vx][vy] = t[vx][2 * vy + 1] + t[vx][2 * vy + 2];
	}
}

void update_x(int vx, int lx, int rx, int x, int y, int val)
{
	if (lx != rx){
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x(2 * vx + 1, lx, mx, x, y, val);
		else
			update_x(2 * vx + 2, mx + 1, rx, x, y, val);
	}
	update_y(vx, lx, rx, 0, 0, m - 1, y, val);
}