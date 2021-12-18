#include"iostream"
#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int n, x, y, p = 1, l, r;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		l = r = 0;
		while (x != 1 || y != 1) {
			if (x > y) {
				if (y == 1)
					l += x - 1, x = 1;//可以自己找规律找到这一点，当y=1时，x只要走x-1步就能变成1了，记住要把x复为1（跳出的条件所需）
				else
					l += x / y, x %= y;//当俩个数都不为一时，将其的商加入l中，x的值需要改编成x%y的数

			}
			else if (x < y) {
				if (x == 1)
					r += y - 1, y = 1;
				else
					r += y / x, y %= x;
			}
		}
		cout << "Scenario #" << (p++) << ":" << l << " " << r << endl;
	}
	return 0;
}