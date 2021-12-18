#include"iostream"
using namespace std;
#define MAXNUMBER 100;
int num[100] = { 0 };

//二叉树结构定义
struct node {
	char data;
	node* lchild, * rchild;
};

void Traverse(node* t) {
	if (t == NULL) {
		return;
	}
	Traverse(t->lchild);
	cout << t->data;
	Traverse(t->rchild);
}
//先序遍历二叉树创建
void SetBiTree(node*& t/*代表一个指针的别名*/){
	char c;
	cin >> c;
	if (c == '#') {
		t = NULL;
	}
	else {
		t = new node;
		t->data = c;
		SetBiTree(t->lchild);
		SetBiTree(t->rchild);
	}
	
}
void Levcount(node*& t,int L) {
	
	if (t) {
		if ((t->lchild != NULL && t->rchild == NULL)|| (t->lchild == NULL && t->rchild != NULL)) {
			num[L]++; 
		}


		Levcount(t->lchild, L + 1);
		Levcount(t->rchild, L + 1);
	}
	
	
}
int GetDepth(node* &t) {
	if (!t) {
		return 0;
	}
	int ld = GetDepth(t->lchild);
	int rd = GetDepth(t->rchild);
	return max(ld, rd) + 1;
}

int main() {
	node* root;
	SetBiTree(root);
	Levcount(root, 1);
	int k;
	k = GetDepth(root);
	for (int i = 1; i <= k; i++)
	{

		cout << num[i] << endl;

	}
}