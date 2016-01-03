#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define rep(i, n) for (int i=0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

///Node is defined as :
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
	int ht;
} node;

#define height(x) (x == NULL? -1: x->ht)
#define bf(x) (height(x->left)-height(x->right))
#define update(x) x->ht = max(height(x->left), height(x->right))+1;


node * lr_ll(node * x, node * y, node * z) {
	x->left = z;
	y->right = z->left;
	z->left = y;
	update(y);
	update(z);
	update(x);
	return x;
}
node * rl_rr(node * x, node * y, node * z) {
	x->right = z;
	y->left = z->right;
	z->right = y;
	update(y);
	update(z);
	update(x);
	return x;
}
node * ll_m(node * x, node * z, node * y) {
	x->left = z->right;
	z->right = x;
	update(x);
	update(z);
	return z;
}
node * rr_m(node * x, node * z, node * y) {
	x->right = z->left;
	z->left = x;
	update(x);
	update(z);
	return z;
}

stack<node *> search(node * root, int val) {
	node * p = root;
	stack<node *> S;
	while (p != NULL) {
		S.push(p);
		if (val <= p->val) {
			p = p->left;
		} else {
			p = p->right;
		}
	}
	return S;
}

node * make_node(int val) {
	node * v = new node;
	v->val = val;
	v->left = NULL;
	v->right = NULL;
	update(v);
	return v;
}

node * insert(node * root,int val) {
	stack<node*> S = search(root, val);
	node * r = make_node(val);
	while (!S.empty()) {
		node * x = S.top();
		S.pop();
		if (r->val <= x->val) {
			x->left = r;
		} else {
			x->right = r;
		}
		update(x);
		// cout << char(x->val) << " " << char(r->val) << endl;;
		if (bf(x) == 2) {
			if (bf(x->left) < 0) {
				x = lr_ll(x, x->left, x->left->right);
				r = ll_m(x, x->left, x->left->left);
			} else {
				r = ll_m(x, x->left, x->left->left);
			}
		} else if (bf(x) == -2) {
			if (bf(x->right) > 0) {
				x = rl_rr(x, x->right, x->right->left);
				r = rr_m(x, x->right, x->right->right);
			} else {
				r = rr_m(x, x->right, x->right->right);
			}
		} else {
			r = x;
		}
	}
	return r;
}

void show (node *r) {
	if (r == NULL) {
		return;
	}
	cout << "(" << char(r->val) << ", " << r->ht << ")";
	cout << "{";
	show(r->left);
	show(r->right);
	cout << "}";
}

int main () {
	node * r = NULL;
	rep(i, 5) {
		r = insert(r, 'a'+i);
		// show(r);
		// cout << "OK" << endl;
	}
	return 0;
}
