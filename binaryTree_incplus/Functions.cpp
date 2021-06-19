#include <iostream>
using namespace std;
#include "fnHeader.h"

void find(int item,Node **par, Node **loc)
{
	Node *ptr,*ptrsave;
	if(root==NULL)
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info)
	{
		*loc=root;
		*par=NULL;
		return;
	}
	if(item<root->info)
	{
		ptr=root->lchild;
	}
	else
	{
		ptr=ptr->rchild;
	}
	ptrsave=root;
	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{
			*loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
			if(item<ptr->info)
			{
				ptr=ptr->lchild;
			}
			else
			{
				ptr=ptr->rchild;
			}
		
	}
	*loc=NULL;
	*par=ptrsave;
}
void insert(int item)
{
	Node *par,*loc;
	find(item,&par,&loc);
	if(loc!=NULL)
	{
		cout<<"Data is already Present"<<endl;
		return;
	}
	Node *tmp=new Node();
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	if(par==NULL)
	{
		root=tmp;
		cout<<"Data has been stored"<<endl;
	}
	else
	{
		if(item<par->info)
		{
			par->lchild=tmp;
		}
		else
		{
			par->rchild=tmp;
		}
	}

}
void del(int item)
{
	Node *par,*loc;
	if(root==NULL)
	{
		cout<<"Root is empty"<<endl;
		return;
	}
	find(item,&par,&loc);
	if(loc==NULL)
	{
		cout<<"Item is not present in the Tree"<<endl;
		return;
	}
	if(loc->lchild==NULL&&loc->rchild==NULL)
	{
		case_a(par,loc);
	}
	else if(loc->lchild!=NULL&&loc->rchild==NULL||loc->lchild==NULL&&loc->rchild!=NULL)
	{
		case_b(par,loc);
	}
	else if(loc->lchild!=NULL&&loc->rchild!=NULL)
	{
		case_c(par,loc);
	}
	delete loc;
}
void case_a(Node *par,Node *loc)
{
	if(par==NULL)
	{
		root=NULL;
		return;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild=NULL;
			cout<<"Data hasbeen deleted from left child"<<endl;
		}
		else
		{
			par->rchild=NULL;
			cout<<"Data hasbeen deleted from right child"<<endl;
		}
	}
}
void case_b(Node *par,Node *loc)
{
	Node *child;
	if(loc->lchild!=NULL)
	{
		child=loc->lchild;
	}
	else
	{
		child=loc->rchild;
	}
	if(par==NULL)
	{
		root=child;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild=child;
		}
		else
		{
			par->rchild=child;
		}
	}
}
void case_c(Node *par,Node *loc)
{
	Node *ptr,*ptrsave,*suc,*parsuc;
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;
	if(suc->lchild==NULL&&suc->rchild==NULL)
	{
		case_a(parsuc,suc);
	}
	else
	{
		case_b(parsuc,suc);
	}
	if(par==NULL)
	{
		root=suc;
	}
	else
	{
		if(loc==par->lchild)
		{
			par->lchild=suc;
		}
		else
		{
			par->rchild=suc;
		}
	}
	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}
void preorder(Node *ptr)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void inorder(Node *ptr)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		preorder(ptr->lchild);
		cout<<ptr->info<<" ";
		preorder(ptr->rchild);
	}
}
void postorder(Node *ptr)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		preorder(ptr->lchild);
		preorder(ptr->rchild);
		cout<<ptr->info<<" ";
	}
}