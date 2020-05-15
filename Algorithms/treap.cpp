#include <bits/stdc++.h>

using namespace std;

struct treap{
    int key, priority;
    treap *left, *right;
    treap(int _key, int _priority, treap *_left, treap *_right){
		this->key = _key;
		this->priority = _priority;
		this->left = _left;
		this->right = _right;
    }
};

void rotleft(treap* &n){
    treap *t = n->left;
    n->left = t->right;
    t->right = n;
    n = t;
}

void rotright(treap* &n){
    treap *t = n->right;
    n->right = t->left;
    t->left = n;
    n = t;
}

void balance(treap* &n){
    if (n->left != nullptr && n->left->priority > n->priority)
		rotleft(n);
    else if (n->right != nullptr && n->right->priority > n->priority)
		rotright(n);
}

int search(treap* n, int key){
    if (n == nullptr)
		return 0;
    if (key == n->key)
		return 1;
    if (key < n->key)
		return search(n->left, key);
    return search(n->right, key);
}

int smaller(treap* n, int key){
    if (n == nullptr)
        return -2147483648;
    if (key >= n->key)
        return max(n->key, smaller(n->right, key));
    return smaller(n->left, key);
}

int larger(treap *n, int key) {
    if (n == nullptr)
        return 2147483647;
    if (key <= n->key)
        return min(n->key, larger(n->left, key));
    return larger(n->right, key);
}

void insert(treap* &n, int key, int priority){
    if (n == nullptr){
		n = new treap(key, priority, nullptr, nullptr);
		return;
    }
    if (key < n->key)
		insert(n->left, key, priority);
    else insert(n->right, key, priority);
    balance(n);
}

void remove(treap* &n, int key){
    if (n == nullptr)
		return;
    if (key < n->key)
		remove(n->left, key);
    else if (key > n->key)
		remove(n->right, key);
    else {
		if (n->left == nullptr && n->right == nullptr){
		    delete n;
		    n = nullptr;
		    return;
		}
		int l = 0, r = 0;
		if (n->left != nullptr)
		    l = n->left->priority;
		if (n->right != nullptr)
		    r = n->right->priority;
		if (l > r)
		    rotleft(n);
		else rotright(n);
		remove(n, key);
    }
}

void inorder(treap *n, vector<int> &v) {
    if (n == nullptr)
        return;
    inorder(n->left, v);
    v.push_back(n->key);
    inorder(n->right, v);
}

void destroy(treap *&n) {
    if (n == nullptr)
        return;
    destroy(n->left);
    destroy(n->right);
    delete n;
    n = nullptr;
}

treap *root = nullptr;

int main()
{
    srand(time(NULL));
    ifstream fin ("abce.in");
    ofstream fout ("abce.out");
    int test;
    fin >> test;
    while(test--){
        int t;
        fin >> t;
        switch(t){
            case 1:{
                int key;
                fin >> key;
                insert(root, key, rand()%1000000+1);
                break;
            }
            case 2:{
                int key;
                fin >> key;
                remove(root, key);
                break;
            }
            case 3:{
                int key;
                fin >> key;
                fout << search(root, key) << "\n";
                break;
            }
            case 4:{
                int key;
                fin >> key;
                fout << smaller(root, key) << "\n";
                break;
            }
            case 5:{
                int key;
                fin >> key;
                fout << larger(root, key) << "\n";
                break;
            }
            case 6:{
                int key1, key2;
                fin >> key1 >> key2;
                vector<int> v;
                inorder(root, v);
                for (auto x : v)
                    if (x >= key1 && x <= key2)
                        fout << x << " ";
                fout << "\n";
                break;
            }
        }
    }
    destroy(root);
    return 0;
}
