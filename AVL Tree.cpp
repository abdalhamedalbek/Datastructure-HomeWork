#include<stdio.h>
#include<stdlib.h>

struct AVL {
	int number;
	struct AVL *right,*left;
	int height;
}*root=NULL;

int Height (struct AVL *root);
int BalanceFactor (struct AVL *root);
struct AVL *rotateRight(struct AVL *root);
struct AVL *rotateLeft(struct AVL *root);
struct AVL *intial (int value);
struct AVL *insert (struct AVL *root,int value);
struct AVL *del (struct AVL *root,int value);
void preorder (struct AVL *root);

int main () {
	while (1) {
		int value,x;
		printf ("1.Insert\n2.Delete\n3.Pre-order\n4.Exit\n");
		scanf ("%d",&x);
		switch (x) {
			case 1: {
				printf ("Enter a number to insert it:\n");
				scanf ("%d",&value);
				root=insert(root,value);
				break;
			}
			case 2:{
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("Enter a number to delete it:\n");
					scanf ("%d",&value);
					root=del(root,value);
				}
				break;
			}
			case 3: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("Your tree pre-order:\n");
					preorder(root);
				}
				break;
			}
			case 4:exit(0); break;
		}
		printf ("___________________________________________________\n");
	}
}

int Height (struct AVL *root) {
	if (root==NULL) return 0;
	return root->height;
}

int BalanceFactor (struct AVL *root) {
	if (root==NULL) return 0;
    else {
        return Height(root->left)-Height(root->right);
	}
}

struct AVL *rotateRight(struct AVL *root) {
	struct AVL *p = root->left;
    struct AVL *q = p->right;
    
	p->right = root;
    root->left = q;
    
    if (Height(root->left)>Height(root->right)) root->height=1+Height(root->left);
    else root->height=1+Height(root->right);
    
    if (Height(p->left)>Height(p->right)) p->height=1+Height(p->left);
    else p->height=1+Height(p->right);
    
    return p;
}

struct AVL *rotateLeft(struct AVL *root) {
	struct AVL *p = root->right;
    struct AVL *q = p->left;
    
	p->left = root;
    root->right = q;
    
    if (Height(root->left)>Height(root->right)) root->height=1+Height(root->left);
    else root->height=1+Height(root->right);
    
    if (Height(p->left)>Height(p->right)) p->height=1+Height(p->left);
    else p->height=1+Height(p->right);
    
    return p;
}

struct AVL *intial (int value) {
	struct AVL *p=(struct AVL *)malloc(sizeof(struct AVL));
	p->number=value;
	p->left=NULL;
	p->right=NULL;
	p->height=1;
	return p;
}

struct AVL *insert (struct AVL *root,int value) {
	if (root==NULL) return intial(value);
	else {
		if (value<root->number)
			root->left=insert(root->left,value);
		else if (value>root->number)
			root->right=insert(root->right,value);
		else return root;
	}
	
	if (Height(root->left)>Height(root->right)) root->height=1+Height(root->left);
    else root->height=1+Height(root->right);
	
	int balance=BalanceFactor(root);
	
	if (balance>1 && value<root->left->number) return rotateRight(root);
	if (balance>1 && value>root->left->number) {
		root->left=rotateLeft(root);
		return rotateRight(root);
	}
	
	if (balance<-1 && value>root->right->number) return rotateLeft(root);
	if (balance<-1 && value<root->right->number) {
		root->right=rotateRight(root);
		return rotateLeft(root);
	}
	
	return root;
}

struct AVL *del (struct AVL *root,int value) {
    if (root==NULL) {
    	printf ("No element found\n");
    	return root;
	}
    else if (root!=NULL) {
    	struct AVL *q, *p;
    	if (root->number==value) {
			if (root->left==root->right) {
				free(root);
				return NULL;
			}
			else {
				if (root->left==NULL) {
					p=root->right;
					free(root);
					return p;
				}
				else if (root->right==NULL) {
					p=root->left;
					free(root);
					return p;
				}
				else {
					p=root->right;
					q=root->right;
					while (p->left!=NULL) p=p->left;
					p->left=root->left;
					free(root);
					return q;
				}
			}
		}
		if (root->number<value) root->right=del(root->right,value);
		else root->left=del(root->left,value);
	}

    if (Height(root->left)>Height(root->right)) root->height=1+Height(root->left);
    else root->height=1+Height(root->right);

    int balance=BalanceFactor(root);
	
	if (balance>1 && value<root->left->number) return rotateRight(root);
	if (balance>1 && value>root->left->number) {
		root->left=rotateLeft(root);
		return rotateRight(root);
	}
	
	if (balance<-1 && value>root->right->number) return rotateLeft(root);
	if (balance<-1 && value<root->right->number) {
		root->right=rotateRight(root);
		return rotateLeft(root);
	}
	
	return root;
}

void preorder (struct AVL *root) {
	if (root==NULL) return;
	else {
		printf ("%d\n",root->number);
		preorder(root->left);
		preorder(root->right);
	}
}
