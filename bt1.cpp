#include<bits/stdc++.h>
struct node
{
	int Data;
	node *next;
};
struct list
{
	node *head;
	node *tail;
};
void initList(list& l){
	l.head=NULL;
	l.tail=NULL;
}
node* CreateNode(int value){
	node *a= new node();
	if(a!=NULL){
		a->Data=value;
		a->next=NULL;
	}
	return a;
}
void insertFist(list &l,node* x){
	if(l.head ==NULL){
		l.head=x;
		return;
	}
	x->next=l.head;
	l.head=x;
	return;
}
void DeleteHead(list &l){
	if(l.head==l.tail){
		l.head=l.tail=NULL;
		return;
	}
	node* i=l.head->next;
	free(l.head);
	l.head=i;
	return;
}
void DelAfter(list &l,int value){
	node *i=l.head;
	while (i->Data != value )
	{
		i=i->next;
	}
	node *a=i->next;
	i->next=i->next->next;
	free(a);
}
void addAfter(list &l,int value,node*x){
	node *i=l.head;
	while (i->Data != value )
	{
		i=i->next;
	}
	x->next=i->next;
	i->next=x;
}
void case1(list &l){
	int temp;
	printf("\nNhap: ");
	scanf("%d",&temp);
	node *a = CreateNode(temp);
	insertFist(l,a);
}
void case2(list l){
	node *i =l.head;
		while (i!=NULL)
		{
			printf("%4d",i->Data);
			i=i->next;
		}
}
void case4(list &l){
	int value;
	printf("\nNhap value: ");
	scanf("%d",&value);
	DelAfter(l,value);
}
void case5(list &l){
	int value,pos;
	printf("Insert  : ");
	scanf("%d",&value);
	printf(" pos : ");
	scanf("%d",&pos);
	node *x = CreateNode(value);
	addAfter(l,pos,x);
}
int main(){
	list l;
	initList(l);
	printf("\n0.Thoat");;
	printf("\n1.Them phan tu");
	printf("\n2.xuat danh sach");
	int chon;
	do{
		printf("\nChon: ");
		scanf("%d",&chon);
	
		switch (chon)
		{
		case 1:
			case1(l);
			break;
		case 2:
			case2(l);
			break;
		case 3:
			DeleteHead(l);
			break;
		case 4:
			case4(l);
			break;
		case 5:
			case5(l);
			break;
		default:
				exit(0);
		}
	}while(chon !=0);
	return 0;
}

