#include<stdio.h>
#include<stdlib.h>

struct BST {
	int number;
	struct BST *right;
	struct BST *left;
}*root=NULL;

struct BST *intial (int value);
struct BST *insert (struct BST *root,int value);
struct BST *del (struct BST *root,int value);
void inorder (struct BST *root);
void preorder (struct BST *root);
void postorder (struct BST *root);
int size (struct BST *root);
int height (struct BST *root);
int max (struct BST *root);
int min (struct BST *root);
void cleartree (struct BST *root);
void leaves (struct BST *root);
int oneChild (struct BST *root);

int main () {
	while (1) {
		int value,x;
		printf ("1.Insert\n2.Delete\n3.In-order\n4.Pre-order\n5.Post-order\n6.Size\n7.Height\n8.Maximum\n9.Minimum\n10.Clear the tree\n11.Leaves\n12.Print the nodes with one child\n13.Exit\n");
		scanf ("%d",&x);
		switch (x) {
			case 1: {
				printf ("Enter a number to insert it:\n");
				scanf ("%d",&value);
				root=insert(root,value);
				break;
			}
			case 2: {
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
					printf ("Your tree in-order:\n");
					inorder(root);
				}
				break;
			}
			case 4: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("Your tree pre-order:\n");
					preorder(root);
				}
				break;
			}
			case 5: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("Your tree post-order:\n");
					postorder(root);
				}
				break;
			}
			case 6: {
				int x=size(root);
				if (x==0) printf ("The tree is empty\n");
				else printf ("The size of the tree is:%d\n",x);
				break;
			}
			case 7: {
				int x=height(root);
				if (x==0) printf ("The tree is empty\n");
				else printf ("The height of the tree is:%d\n",x);
				break;
			}
			case 8: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("The maximum element in the tree:%d\n",max(root));
				}
				break;
			}
			case 9: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("The minimum element in the tree:%d\n",min(root));
				}
				break;
			}
			case 10: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					cleartree(root);
					root=NULL;
				}
				break;
			}
			case 11: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("The leaves is:\n");
					leaves(root);
				}
				break;
			}
			case 12: {
				if (root==NULL) printf ("The tree is empty\n");
				else {
					printf ("The number of nodes with one child is:%d\n",oneChild(root));
				}
				break;
			}
			case 13:exit(0); break;
		}
		printf ("___________________________________________________\n");
	}
}

struct BST *intial (int value) {
	struct BST *p=(struct BST *)malloc(sizeof(struct BST));
	p->number=value;
	p->left=NULL;
	p->right=NULL;
	return p;
}

struct BST *insert (struct BST *root,int value) {
	if (root==NULL) root=intial(value);
	else {
		if (value<root->number)
			root->left=insert(root->left,value);
		else
			root->right=insert(root->right,value);
	}
	return root;
}

struct BST *del (struct BST *root,int value) {
	struct BST *p,*q;
	if (root!=NULL) {
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
	else printf ("No element found\n");
	return root;
}

void inorder (struct BST *root) {
	if (root==NULL) return;
	else {
		inorder(root->left);
		printf ("%d\n",root->number);
		inorder(root->right);
	}
}

void preorder (struct BST *root) {
	if (root==NULL) return;
	else {
		printf ("%d\n",root->number);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder (struct BST *root) {
	if (root==NULL) return;
	else {
		postorder(root->left);
		postorder(root->right);
		printf ("%d\n",root->number);
	}
}

int size (struct BST *root) {
	if (root==NULL) return 0;
	else return 1+size(root->left)+size(root->right);
}

int height (struct BST *root) {
	if (root==NULL) return 0;
	else {
		int a=height(root->left);
		int b=height(root->right);
		if (a>b) return a+1;
		else return b+1;
	}
}

int max (struct BST *root) {
	while (root->right!=NULL) {
		root=root->right;
	}
	return root->number;
}

int min (struct BST *root) {
	while (root->left!=NULL) {
		root=root->left;
	}
	return root->number;
}

void cleartree (struct BST *root) {
	if (root!=NULL) {
		cleartree(root->left);
		cleartree(root->right);
		free(root);
	}
}

void leaves (struct BST *root) {
	if (root!=NULL) {
		leaves(root->left);
		leaves(root->right);
		if (root->left==root->right) printf ("%d\n",root->number);
	}
}

int oneChild (struct BST *root) {
	if (root==NULL || (root->left==NULL && root->right==NULL)) return 0;
	return 1+oneChild(root->left)+oneChild(root->right);
}
