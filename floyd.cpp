int g[n][n];

//g[i][j] = 0, where i == j
//g[i][j] = inf, where edge from i to j doesn't exist

void floyd()
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}