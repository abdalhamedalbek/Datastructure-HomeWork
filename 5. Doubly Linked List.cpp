#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL;

struct node* insert (struct node *head);
void print_beginning (struct node *head);
void print_end (struct node *head);
struct node* del (struct node *head);
struct node* destroy (struct node *head);
void sum (struct node *head);
void avg (struct node *head);

int main () {
	while (1) {
		int x;
		printf ("1.Add a new node beginning\n2.Print the nodes from the beginning\n3.Print the nodes from the end\n4.Delete node from the list\n5.Destroy the list\n6.Sum\n7.Average\n8.Exit\n");
		scanf ("%d",&x);
		switch (x) {
			case 1:head=insert(head); break;
			case 2:print_beginning(head); break;
			case 3:print_end(head); break;
			case 4:head=del(head); break;
			case 5:head=destroy(head); break;
			case 6:sum(head); break;
			case 7:avg(head); break;
			case 8:exit(0); break;
		}
		printf ("___________________________________________________________\n");
	}
}

struct node* insert (struct node *head) {
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf ("Enter a number to insert it:\n");
	scanf ("%d",&newnode->data);
	struct node *q,*p=head;
	if (head==NULL) {
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else {
		while (p!=NULL && p->data<newnode->data) {
			q=p;
			p=p->next;
		}
		if (p==head) {
			head=newnode;
			newnode->prev=NULL;
			newnode->next=p;
			p->prev=newnode;
		}
		else if (p==NULL) {
			q->next=newnode;
			newnode->prev=q;
			newnode->next=NULL;
		}
		else {
			q->next=newnode;
			newnode->prev=q;
			newnode->next=p;
			p->prev=newnode;
		}
	}
	printf ("**DONE**\n");
	return head;
}

void print_beginning (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		printf ("Your list is:\n");
		while (p!=NULL) {
			printf ("%d\n",p->data);
			p=p->next;
		}
	}
	printf ("**DONE**\n");
}

void print_end (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		while (p->next!=NULL) p=p->next;
		printf ("Your list is:\n");
		while (p!=NULL) {
			printf ("%d\n",p->data);
			p=p->prev;
		}
	}
	printf ("**DONE**\n");
}

struct node* del (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		int value;
		printf ("Enter a number to delete it:\n");
		scanf ("%d",&value);
		struct node *q,*p=head;
		if (head->data==value) {
			printf ("%d deleted\n",p->data);
			head=head->next;
			head->prev=NULL;
			free(p);
		}
		else {
			while (p!=NULL && p->data!=value) {
				q=p;
				p=p->next;
			}
			if (p!=NULL) {
				if (p->next!=NULL) {
					printf ("%d deleted\n",p->data);
					q->next=p->next;
					free(p);
					p=q->next;
					p->prev=q;
				}
				else if (p->next==NULL) {
					free(p);
					q->next=NULL;
				}
			}
			else printf ("No element found\n");
		}
	}
	printf ("**DONE**\n");
	return head;
}

struct node* destroy (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p;
		while (head!=NULL) {
			p=head;
			head=head->next;
			free(p);
		}
		printf ("**DONE**\n");
	}
	return head;
}

void sum (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		struct node *p=head;
		int sum=0;
		while (p!=NULL) {
			sum+=p->data;
			p=p->next;
		}
		printf ("The sum is:%d\n",sum);
		printf ("**DONE**\n");
	}
}

void avg (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		struct node *p=head;
		int avg,c=0,sum=0;
		while (p!=NULL) {
			sum+=p->data;
			c++;
			p=p->next;
		}
		avg=sum/c;
		printf ("The average is:%d\n",avg);
		printf ("**DONE**\n");
	}
}
