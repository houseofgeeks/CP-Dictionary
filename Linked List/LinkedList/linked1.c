#include<stdio.h>
#include<malloc.h>
struct node
{
int info;
struct node *next;
};
typedef struct node *NODE;
NODE CreateNode(NODE temp,int x);
NODE Init(NODE S);
NODE InsertL(NODE S,int x);
NODE InsertF(NODE S,int x);
NODE Insertsp(NODE S,int pos,int x);
NODE DeleteF(NODE S);
NODE Deletel(NODE S);
NODE Deletesp(NODE S,int pos);
void Display(NODE S);
int size(NODE S);
int main()
{
    int ch,x;
    int pos;
NODE S;
S=Init(S);
do
{
printf("------MENU------");
printf("\n 1.Initialization \n 2.Insert at beginning \n 3. Insert at last \n 4.Insert at specified position \n 5.Delete first \n 6.Delete last \n7.Delete sp \n8.display \n9.size \n10.exit ");
printf("enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1: S=Init(S);
       break;
case 2:printf("\n enter element to be inserted");
      scanf("%d",&x);
      S=InsertF(S,x);
       break;
case 3: printf("\n enter element to be inserted");
      scanf("%d",&x);
       S=InsertL(S,x);
       break;
case 4: printf("\n enter element to be inserted");
      scanf("%d",&x);
      printf("\n enter the position where u want to insert");
      scanf("%d",&pos);
       S=Insertsp(S,pos,x);
       break;
case 5: S=DeleteF(S);
       break;
    case 6: S=Deletel(S);
       break;
case 7:printf("\n enter the position where u want to delete");
      scanf("%d",&pos);
       S=Deletesp(S,pos);
       break;
case 8: Display(S);
       break;
case 9: size(S);
printf("\n size is %d",size(S));
       break;
case 10: printf("\n exiting");
       break;
default: printf("\n wrong choice");
   }
   }while(ch!=10);
   return 0;
}

NODE CreateNode(NODE temp,int x)
{
temp=(NODE)malloc(sizeof(struct node));
temp->info=x;
temp->next=NULL;
return(temp);
}
NODE Init(NODE S)
{
S=NULL;
return(S);
}
NODE InsertF(NODE S,int x)
{
NODE temp;
temp=CreateNode(temp,x);
if(S==NULL)
S=temp;
else
{
temp->next=S;
S=temp;
}
return(S);
}
NODE InsertL(NODE S,int x)
{
NODE temp,t;
temp=CreateNode(temp,x);
if(S==NULL)
S=temp;
else
{
for(t=S;t->next!=NULL;t=t->next);
t->next=temp;
}
return(S);
}
NODE Insertsp(NODE S,int pos,int x)
{
int i;
int l=size(S);
if(pos<1||pos>(l+1))
  {
  printf("\n INSERTION NOT POSSIBLE");
  return (S);
  }
    if(pos==1)
    {
    S=InsertF(S,x);
    return(S);
}
if(pos==l+1)
{
S=InsertL(S,x);
return(S);
}
if(pos>1 && pos<=l)
{
NODE t,temp;
temp=CreateNode(temp,x);
for(t=S,i=1;i<(pos-1);i++,t=t->next);
temp->next=t->next;
t->next=temp;
}
}
void Display(NODE S)

{
if(S==NULL)
printf("\n NOTHING TO SHOW");
else
{
NODE t;
for(t=S;t!=NULL;t=t->next)
printf(" %d",t->info);
    }
}
int size(NODE S)
{
NODE t;
int i=0;
for(t=S,i=0;t!=NULL;t=t->next,i++);
return(i);
}
NODE DeleteF(NODE S)
{
NODE t;
if(S==NULL)
printf("\n LIST IS EMPTY");
else
{
t=S;
S=S->next;
printf("\n DELETED NODE IS %d",t->info);
free(t);
}
return(S);
}
NODE Deletel(NODE S)
{
NODE t,p;
if(S==NULL)
printf("list is empty");
else
{
for(t=S;t->next!=NULL;p=t,t=t->next);
if(S->next==NULL)
S==NULL;
else
p->next=NULL;
printf(" deleteed info:%d",t->info);
free(t);
}
return(S);
}
NODE Deletesp(NODE S,int pos)
{
int i;
int l=size(S);
if(pos<1||pos>l)
{
printf(" not possible to delete");
return(S);
}
   if(pos==1)
{
S=DeleteF(S);
return(S);
     }
     if(pos==l)
{
S=Deletel(S);
return(S);
     }
     
    if(pos>1&&pos<l)
    {
    NODE t,p;
    int i;
    for(t=S,i=1;i<pos;i++,p=t,t=t->next);
    p->next=t->next;
    printf(" deleted element is %d",t->info);
    free(t);
    }
    return(S);
}






