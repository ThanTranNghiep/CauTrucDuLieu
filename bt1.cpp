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
void initList(list& l)
{
	l.head=NULL;
	l.tail=NULL;
}
node* CreateNode(int value)
{
	node *a= new node();
	if(a!=NULL)
	{
		a->Data=value;
		a->next=NULL;
	}
	return a;
}
void insertFist(list &l,node* x)
{
	if(l.head ==NULL)
	{
		l.head=x;
		return;
	}
	x->next=l.head;
	l.head=x;
	return;
}
void DeleteHead(list &l)
{
	if(l.head==l.tail)
	{
		l.head=l.tail=NULL;
		return;
	}
	node* i=l.head->next;
	free(l.head);
	l.head=i;
	return;
}
void DelAfter(list &l,int value)
{
	if(l.head ==l.tail && l.head !=NULL)
	{
		printf("\nDanh sach co 1 phan tu");
		return;
	}
	if(l.head == NULL)
	{
		printf("\nLinked is empty !");
		return;
	}
	node *i=l.head;
	while (i->Data != value )
	{
		i=i->next;
	}
	node *a=i->next;
	i->next=i->next->next;
	free(a);
}
void addAfter(list &l,int value,node*x)
{
	node *i=l.head;
	while (i->Data != value )
	{
		i=i->next;
	}
	x->next=i->next;
	i->next=x;
}
void case1(list &l)
{
	int temp;
	printf("\nNhap: ");
	scanf("%d",&temp);
	node *a = CreateNode(temp);
	insertFist(l,a);
}
void case2(list l)
{
	node *i =l.head;
		while (i!=NULL)
		{
			printf("%4d",i->Data);
			i=i->next;
		}
}
void case4(list &l)
{
	int value;
	printf("\nNhap value: ");
	scanf("%d",&value);
	DelAfter(l,value);
}
void case5(list &l)
{
	int value,pos;
	printf("Insert  : ");
	scanf("%d",&value);
	printf(" pos : ");
	scanf("%d",&pos);
	node *x = CreateNode(value);
	addAfter(l,pos,x);
}
bool Find(list l,int pos)
{
	node*i=l.head;
	while (i!=NULL)
	{
		if(i->Data == pos)
			return true;
		i=i->next;
	}
	return false;
}
void Sort(list &l){
	node*i ;
	node*j ;
	for(i=l.head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->Data > j->Data)
			{
				node*a;
				a->Data=i->Data;
				i->Data=j->Data;
				j->Data=a->Data;
			}
		}
	}
}
int main(){
	list l;
	int chon;
	initList(l);
	do{
		system("cls");
		printf("\n0.Thoat");
		printf("\n1.Them phan tu");
		printf("\n2.xuat danh sach");
		printf("\n3.Xoa phan tu dau danh sach");
		printf("\n4.Xoa phan tu phia sau p");
		printf("\n5.Them phan tu sau p");
		printf("\n6.Tim kiem");
		printf("\n7.Sap xep tang dan");
		printf("\nChon: ");
		scanf("%d",&chon);
	
		switch (chon)
		{
		case 1:
			case1(l);
			break;
		case 2:
			case2(l);
			system("pause");
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
		case 6:
			int pos;
			printf("Nhap so can tim: ");
			scanf("%d",&pos);
			if(Find(l,pos)==true)
			{
					printf("\nTim thay !");
			}
			else
			{
				printf("\nKhong tim thay !");
			}
			system("pause");
			break;
		case 7:
			Sort(l);
			system("pause");
			break;
		default:
				exit(0);
		}	
	}while(chon !=0);
	return 0;
}

