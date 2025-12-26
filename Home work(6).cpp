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
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf ("Enter a number to insert it:\n");
	scanf ("%d",&newnode->data);
	if (head==NULL) {
		head=newnode;
		head->next=head;
	}
	else {
		struct node *last,*q,*p=head;
		while (p->next!=head) p=p->next;
		last=p;
		p=head;
		while (p->next!=head && p->data<newnode->data) {
			q=p;
			p=p->next;
		}
		if (p==head && p->data>newnode->data) {
			head=newnode;
			newnode->next=p;
			last->next=head;
		}
		else if (p->next!=head) {
			q->next=newnode;
			newnode->next=p;
		}
		else {
			if (p->next==head && p->data>newnode->data) {
				q->next=newnode;
				newnode->next=p;
			}
			else if (p->next==head && p->data<newnode->data) {
				p->next=newnode;
				newnode->next=head;
			}
		}
	}
	printf ("**DONE**\n");
	return head;
}

void print (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		printf ("The list is:\n");
		do {
			printf ("%d\n",p->data);
			p=p->next;
		}while (p!=head);
		printf ("**DONE**\n");
	}
}

void sum (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		int sum=0;
		do {
			sum+=p->data;
			p=p->next;
		}while(p!=head);
		printf ("The sum is:%d\n",sum);
		printf ("**DONE**\n");
	}
}

void avg (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		int avg,sum=0,c=0;
		do {
			c++;
			sum+=p->data;
			p=p->next;
		}while(p!=head);
		avg=sum/c;
		printf ("The average is:%d\n",avg);
		printf ("**DONE**\n");
	}
}

struct node* del (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		int value;
		printf ("Enter a number to delete it:\n");
		scanf ("%d",&value);
		struct node *last,*q,*p=head;
		while (p->next!=head) p=p->next;
		last=p;
		p=head;
		if (head->data==value) {
			if (head->next==head) {
				printf ("%d deleted\n",head->data);
				free(head);
				return NULL;
			}
			else {
				printf ("%d deleted\n",p->data);
				head=head->next;
				free(p);
				last->next=head;
			}
		}
		else {
			while (p->next!=head && p->data!=value) {
				q=p;
				p=p->next;
			}
			if (p->next!=head && p->data==value) {
				printf ("%d deleted\n",p->data);
				q->next=p->next;
				free(p);
			}
			else if (p->next==head && p->data==value) {
				printf ("%d deleted\n",p->data);
				q->next=head;
				free(p);
			}
			else printf ("No element found\n");
		}
	}
	printf ("**DONE**\n");
	return head;
}

void num_of_nodes (struct node *head) {
	if (head==NULL) printf ("The list is empty so the number of nodes is 0\n");
	else {
		struct node *p=head;
		int c=0;
		do {
			c++;
			p=p->next;
		}while(p!=head);
		printf ("The number of nodes is:%d\n",c);
		printf ("**DONE**\n");
	}
}

struct node* destroy (struct node *head) {
	if (head==NULL) printf ("The list is empty\n");
	else {
		struct node *p=head;
		printf ("The list is destroyed\n");
		do {
			head=head->next;
			free(p);
			p=head;
		}while(p!=head);
		printf ("**DONE**\n");
	}
}
