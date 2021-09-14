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
		default:
				exit(0);
		}
	}while(chon !=0);
	return 0;
}

