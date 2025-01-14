#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *create_node(struct node *head,int i){
	struct node *p;
	p=(struct node *) malloc(sizeof(struct node));
	printf("Enter the data of node[%d]:",i);
	scanf("%d",&p->data);
	p->next=NULL;
	struct node *ptr;
	if(head==NULL){
		head=p;
		ptr=head;
		return (head);
	}
	else{
		ptr->next=p;
		ptr=p;
		return (head);
	}
}
struct node *insert_first(struct node *head,int data){
	struct node *p=head->next;
	struct node *ptr;
	ptr=(struct node *) malloc(sizeof(struct node));
	while(p->next!=head){
		p=p->next;
	}
	ptr->data=data;
	p->next=ptr;
	ptr->next=head;
	return(ptr);
}
struct node *insert_index(struct node *head,int index,int data){
	int i=0;
	struct node *ptr;
	ptr=(struct node *) malloc(sizeof(struct node));
	struct node *p=head;
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return(head);

}
void traversal(struct node *head){
    int i=1;
	struct node *ptr=head;
    do{
        printf("Element[%d]:%d\n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }while(ptr!=head);
}
int main(){
	int n,i,new,index;
	struct node *head=NULL;
	printf("Enter number of node want to create:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		head=create_node(head,i+1);
	}
	//connect circular
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=head;
	traversal(head);

	head=insert_first(head,56);
	traversal(head);
	/*printf("Enter index for insertion:");
	scanf("%d",&index);
	printf("Enter number for insertion:");
	scanf("%d",&new);
	head=insert_index(head,index,new);
	printf("\nLinked list after insertion:\n");
	traversal(head);*/
	return 0;
}

