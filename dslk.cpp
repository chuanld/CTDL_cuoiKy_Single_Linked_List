#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <math.h>

struct Node              
{
  	int Info;
 	Node *Next;
};

Node *MakeNode(int x)    
{
Node *P;
 	P=new Node;
P->Info=x;
P->Next=NULL;
return P;
}

void PushTop(int x,Node *&first)        
{
 	Node *P;
 	P=MakeNode(x);
 	if(first==NULL)
		first=P;
 	else
    	{
     		P->Next=first;
     		first=P;
    	}
}
//tao dslk
void MakeLinkList(Node *&first)        
{
 	int n,x;
 	cout<<"Nhap n:";
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
  		cout<<"\nNhap x:";
  		cin>>x;
  		PushTop(x,first);
 	}
}
//Xuat Danh sách liên ket ra màn hình hien thi
void PrintLinkList(Node *first)        
{
Node *R=first;
 	cout<<"DSLK=";
 	while(R!=NULL)
 	{
  		cout<<R->Info<<"->";
  		R=R->Next;
 	}
 	cout<<"NULL";
}
//Tính tong các giá tri le trong DSLK:
int SumLe(Node *first)     
{
 int TongLe=0;
 	Node *R=first;
 	while(R!=NULL)
 	{
  		if(R->Info%2==1)
    			TongLe=TongLe+R->Info;
  		R=R->Next;
 	}
 cout<<"\nTong cac gia tri le trong DSLK la:"<<TongLe;
 return TongLe;
}
//Tính trung bình cong các so nguyên to trong DSLK:
void TBCSNT(Node *first)    
{
float Tong=0,DemSNT=0,TBC;
 	Node *R=first;
 	int CheckNumber;
 	while(R!=NULL)
 	{
    		int x=R->Info;
    		if(x==2)    
       		CheckNumber=1;
    		else
    		{
     			for(int i=2;i<x;i++)
      		{
       			if(x%i!=0)
	 				CheckNumber=1;
       			else
				{
	 				CheckNumber=0;
	 				break;
				}
      		}
    		}
  		if(CheckNumber==1)
  		{
   			DemSNT++;
   			Tong=Tong+x;
  		}
  	R=R->Next;
 	}
 	TBC=1.0*Tong/DemSNT;
 	cout<<"\nTrung binh cong cac so nguyen to trong DSLK la:"<<TBC;
}
//Kiem tra có bao nhiêu phan tu chan trong DSLK:
void Count(Node *first)   
{
int Dem=0;
 	Node *R=first;
 	while(R!=NULL)
 	{
  		if(R->Info%2==0)
     			Dem++;
  		R=R->Next;
 	}
 	cout<<"\nCo "<<Dem<<" phan tu chan trong DSLK";
}
//Kiem tra DSLK có chan hay không:
void CheckChan(Node *first)  
{
 	int Check;
 	Node *R=first;
 	while(R!=NULL)
 	{
  		if(R->Info%2==0)
     			Check=1;
  		else
  		{
     			Check=0;
     			break;
  		}
  		R=R->Next;
 	}
 	if(Check==1)
   		cout<<"\nDSLK gom cac phan tu chan";
 	else
   		cout<<"\nDSLK khong chan";
}
//tim node o vi tri Q
Node *FindQ(int k,Node *first)  
{
 	int i=1;
 	Node *Q=first;
 	while(i<k&&Q!=NULL)
 	{
  		Q=Q->Next;
  		i++;
 	}
 	return Q;
}
//Chèn mot Node moi có giá tri x vào vi trí k trong DSLK:
void Insert(int x,int k,Node *&first) 
{
 	cout<<"\nNhap gia tri can chen:";
 	cin>>x;
 	cout<<"\nNhap vi tri can chen:";
 	cin>>k;
 	Node *P=MakeNode(x);
 	Node *Q=FindQ(k,first);
 	if(Q==NULL)
    		cout<<"\nDSLK rong.Khong chen";
 	else
   	{
		if(Q==first)
      	{
       		P->Next=first;
       		first=P;
      	}
    		else
      	{
       		Node *R=first;
       		while(R->Next!=Q)
	  			R=R->Next;
       		R->Next=P;
       		P->Next=Q;
      	}
   	}
}
//xoa 1 node tai vi tri k
void Delete(int k,Node *&first)   
{
 	Node *Q=FindQ(k,first);
 	if(Q==NULL)
    		cout<<"\nDSLK rong,khong the xoa.";
 	else
   	{
    		if(Q==first)
      	{
       		first=first->Next;
       		delete(Q);
      	}
    		else
      	{
       		Node *R=first;
       		while(R->Next!=Q)
	  			R=R->Next;
       		R->Next=Q->Next;
       		delete(Q);
      	}
   	}
}
//xoa gia tri am
void DeleteAm(Node *&first)  
{
 	Node *P=first;
 	int k=1;
 	if(P==NULL)
   		cout<<"\nDSLK rong,khong xoa duoc.";
 	else
 	{
  		while(P!=NULL)
			{
   			if(P->Info<0)
    			{
      			Delete(k,first);
      			P=P->Next;
    			}
   			else
    			{
      			P=P->Next;
      			k++;
    			}
  		}
 	}
}
//main
void main()
{
 	
 	int x,k;
 	Node *first=NULL;
 	
MakeLinkList(first);

 	PrintLinkList(first);
 	
SumLe(first);
 	
TBCSNT(first);

Count(first);
 	
CheckChan(first);
 	
Insert(x,k,first);
 	PrintLinkList(first);
 	
cout<<"\nNhap vi tri can xoa: ";
 	cin>>k;
 	Delete(k,first);
 	PrintLinkList(first);
 
DeleteAm(first);
 	cout<<"\nDSLK sau khi xoa cac gia tri am la: ";
 	PrintLinkList(first);

 	
}
