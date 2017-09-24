int power(int a, int b)
{
	if (b == 0) return 1;
	if (b & 1) return power(a, b - 1) * a;
	int tmp = power(a, b / 2);
	return tmp * tmp;
}