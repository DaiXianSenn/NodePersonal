#include"iostream"
using namespace std;
//�������ṹ����
struct node {
	char data;
	node* lchild, * rchild;
};
//����������������� ��ע���β��е�ȡ��ַ����
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
//������� ����������
void Traverse(node* t) {
	if (t==NULL) {
		return;
	}
	Traverse(t->lchild);
	cout << t->data;
	Traverse(t->rchild);
}
//���������������ݹ麯��ʵ��
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