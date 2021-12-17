#include"iostream"
using namespace std;
//二叉树结构定义
struct node {
	char data;
	node* lchild, * rchild;
};
//先序遍历创建二叉树 （注意形参列的取地址符）
void SetBiTree(node* &t) {
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
//中序遍历 遍历二叉树
void Traverse(node* t) {
	if (t==NULL) {
		return;
	}
	Traverse(t->lchild);
	cout << t->data;
	Traverse(t->rchild);
}
//交换左右字数，递归函数实现
void change(node*& t) {
	if (t->lchild == NULL && t->rchild == NULL) {
		return;
	}
	node* temp;
	temp = t->lchild;
	t->lchild = t->rchild;
	t->rchild = temp;
	if (t->lchild) {
		change(t->lchild);
	}
	if (t->rchild) {
		change(t->rchild);
	}
}
int main() {
	node* root;
	SetBiTree(root);
	Traverse(root);
	cout << endl;
	change(root);
	Traverse(root);
}