#include <bits/stdc++.h>

using namespace std;

int main()
{
	int p1x, p1y;
	int p2x, p2y;
	int p3x, p3y;

	cin >> p1x >> p1y;
	cin >> p2x >> p2y;
	cin >> p3x >> p3y;

	long long ccw = p1x * p2y + p2x * p3y + p3x * p1y - (p2x * p1y + p3x * p2y + p1x * p3y);

	if(ccw < 0){
		cout << -1 << endl;
	}
	else if(ccw == 0){
		cout << 0 << endl;
	}
	else{
		cout << 1 << endl;
	}

	return 0;
}