// common binary tree operations
#include <cstdio>
#include <algorithm>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *left;
	Node *right;

	Node(T data);
	~Node();
	static void preorder(Node<T> *node, void (*visit)(Node*));
	static void inorder(Node<T> *node, void (*visit)(Node*));
	static void postorder(Node<T> *node, void (*visit)(Node*));
	int height();
	Node *insert_leftmost(T data);
	Node *insert_rightmost(T data);
	Node *insert_left(T data);
	Node *insert_right(T data);
};

template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}

template <typename T>
Node<T>::~Node()
{
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}

template <typename T>
int Node<T>::height()
{
	if (this == nullptr || (left == nullptr && right == nullptr))
		return 0;

	return 1 + max(left->height(), right->height());
}

template <typename T>
void Node<T>::preorder(Node<T> *node, void (*visit)(Node*))
{
	if (node == nullptr)
		return;

	visit(node);
	preorder(node->left, visit);
	preorder(node->right, visit);
}

template <typename T>
void Node<T>::inorder(Node<T> *node, void (*visit)(Node*))
{
	if (node == nullptr)
		return;

	inorder(node->left, visit);
	visit(node);
	inorder(node->right, visit);
}

template <typename T>
void Node<T>::postorder(Node<T> *node, void (*visit)(Node*))
{
	if (node == nullptr)
		return;

	postorder(node->left, visit);
	postorder(node->right, visit);
	visit(node);
}

template <typename T>
Node<T> *Node<T>::insert_leftmost(T data)
{
	auto n = new Node(data);
	auto p = this;
	while (p->left != nullptr)
		p = p->left;
	p->left = n;
	
	return n;
}

template <typename T>
Node<T> *Node<T>::insert_rightmost(T data)
{
	auto n = new Node(data);
	auto p = this;
	while (p->right != nullptr)
		p = p->right;
	p->right = n;

	return n;
}

template <typename T>
Node<T> *Node<T>::insert_left(T data)
{
	left = new Node(data);
	return left;
}

template<typename T>
Node<T> *Node<T>::insert_right(T data)
{
	right = new Node(data);
	return right;
}

void test_order_traversal()
{
	auto n = new Node<int>(1);
	auto t = n->insert_rightmost(2);
	t = t->insert_rightmost(5);
	t->insert_rightmost(6);
	t = t->insert_leftmost(3);
	t = t->insert_rightmost(4);

	auto f = [](Node<int> *n)
	{
		printf("%d ", n->data);
	};
	Node<int>::preorder(n, f);
	printf("\n");

	Node<int>::postorder(n, f);
	printf("\n");

	Node<int>::inorder(n, f);
	printf("\n");

	delete n;
}

void test_height()
{
	auto n = new Node<int>(4);
	auto l = n->insert_left(2);
	auto r = n->insert_right(6);
	l->insert_left(1);
	l->insert_right(6);
	r->insert_left(5);
	r->insert_right(7);
	printf("%d\n", n->height());
	delete n;

	n = new Node<int>(3);
	l = n->insert_left(2);
	r = n->insert_right(5);
	l->insert_left(1);
	r->insert_left(4);
	r = r->insert_right(6);
	r->insert_right(7);
	printf("%d\n", n->height());
	delete n;
}

int main()
{
	test_order_traversal();
	test_height();
	return 0;
}
