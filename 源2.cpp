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
					l += x - 1, x = 1;//�����Լ��ҹ����ҵ���һ�㣬��y=1ʱ��xֻҪ��x-1�����ܱ��1�ˣ���סҪ��x��Ϊ1���������������裩
				else
					l += x / y, x %= y;//������������Ϊһʱ��������̼���l�У�x��ֵ��Ҫ�ı��x%y����

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