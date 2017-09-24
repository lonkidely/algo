int power(int a, int b, int mod = MOD) //MOD = (int)(1e9 + 7); (default)
{
	if (b == 0) return 1;
	if (b & 1) return power(a, b - 1, mod) * a % mod;
	int tmp = power(a, b / 2, mod);
	return tmp * tmp % mod;
}