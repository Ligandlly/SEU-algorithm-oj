#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int m = 503;
const double ma = 1.79769e+308;
double c[m][m];
double w[m][m];
double obst(double p[m], double q[m],int n)
{
	memset(c, 0, sizeof(c));
	memset(w, 0, sizeof(w));
	for (int i = 0; i <= n; i++)
	{
		c[i][i] = 0;
		w[i][i] = q[i];
	}
	for (int x = 1; x <= n; x++)
	{
		for (int i=0; i <= n - x; i++)
		{
			int j = i + x;
			c[i][j] = ma;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int k = i; k <= j; k++)
			{
				double t = w[i][j];
				if (k - 1 >= i)
				{
					t += c[i][k - 1];
				}
				if (k + 1 <= j)
				{
					t += c[k][j];
				}
				if (t < c[i][j])
				{
					c[i][j] = t;
				}
			}
		}
	}
	return c[0][n];
}
int main()
{
	int runtime;
	cin >> runtime;
	double p[m];
	double q[m];
	int n[m];
	int number;
	for (int i = 1; i <= runtime; i++)
	{
		cin >> number;
		for (int k = 1; k <= number; k++)
		{
			cin >> n[k];
		}
		for (int k = 1; k <= number; k++)
		{
			cin >> p[k];
		}
		for (int k = 0; k<= number; k++)
		{
			cin >> q[k];
		}
		cout << fixed<<setprecision(6)<<obst(p, q, number) << endl;
	}
}
