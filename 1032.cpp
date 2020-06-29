#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int runtime;
	int number;
	double temp;
	cin >> runtime;
	for (int i = 1; i <= runtime; i++)

	{
		double ans = 0;
		cin >> number;
		for (int j = 1; j <= number - 1; j++)
		{
			cin >> temp;
			ans += temp/100.0;
		}
		cout <<fixed<<setprecision(6)<<ans + 1 << endl;
	}
}