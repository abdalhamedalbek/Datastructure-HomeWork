#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
}*head=NULL;

struct node* insert (struct node *head);
void print (struct node *head);
void sum (struct node *head);
void avg (struct node *head);
struct node* del (struct node *head);
void num_of_nodes (struct node *head);
struct node* destroy (struct node *head);

int main () {
	while (1) {
		int x;
		printf ("1.Insert a number\n2.Print the list\n3.Calculate the sum\n4.Calculate the average\n5.Delete an element\n6.Number of nodes\n7.Destroy the list\n8.Exit\n");
		scanf ("%d",&x);
		switch (x) {
			case 1:head=insert(head); break;
			case 2:print(head); break;
			case 3:sum(head); break;
			case 4:avg(head); break;
			case 5:head=del(head); break;
			case 6:num_of_nodes(head); break;
			case 7:head=destroy(head); break;
			case 8:exit(0); break;
		}
		printf ("_______________________________________________________\n");
	}
}

struct node* insert (struct node *head) {
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf ("Enter a new number to insert it:\n");
	scanf ("%d",&newnode->data);
	if (head==NULL) {
		head=newnode;
		newnode->next=NULL;
	}
	else {
		struct node *q,*p=head;
		while (p!=NULL && p->data<newnode->data) {
			q=p;
			p=p->next;
		}
		if (p==head) {
			head=newnode;
			newnode->next=p;
		}
		else if (p==NULL) {
			q->next=newnode;
			newnode->next=NULL;
		}
		else {
			q->next=newnode;
			newnode->next=p;
		}
	}
	printf ("**DONE**\n");
	return head;
}

void print (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		struct node *p=head;
		printf ("Your list is:\n");
		while (p!=NULL) {
			printf ("%d\n",p->data);
			p=p->next;
		}
		printf ("**DONE**\n");
	}
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

struct node* del (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		int value;
		printf ("Enter a new number to delete it:\n");
		scanf ("%d",&value);
		struct node *q,*p=head;
		if (head->data==value) {
			printf ("%d deleted\n",p->data);
			head=head->next;
			free(p);
		}
		else {
			while (p!=NULL && p->data!=value) {
				q=p;
				p=p->next;
			}
			if (p!=NULL) {
				printf ("%d deleted\n",p->data);
				q->next=p->next;
				free(p);
			}
			else printf ("No element found\n");
		}
	}
	printf ("**DONE**\n");
	return head;
}

void num_of_nodes (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		struct node *p=head;
		int c=0;
		while (p!=NULL) {
			c++;
			p=p->next;
		}
		printf ("The number of nodes is:%d\n",c);
		printf ("**DONE**\n");
	}
}

struct node* destroy (struct node *head) {
	if (head==NULL) printf ("Your list is empty\n");
	else {
		struct node *p;
		while (head!=NULL) {
			p=head;
			head=head->next;
			free(p);
		}
	}
	printf ("**DONE**\n");
}
