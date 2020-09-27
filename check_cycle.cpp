#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define vec vector<ll>
#define vec1 vector<vector ll>>
#define set set<ll>
#define mset multiset<ll>
#define pair pair<ll>
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
}*head,*last;
void create(int *a,int n)
{
	struct node *p;
	head = new struct node;
	head->data = a[0];
	last = head;
	for(int i=1;i<n;i++)
	{	
		p = new struct node;
		p->data =a[i];
		last->next=p;
		last = p;
	}
	last->next=head;
}
void display()
{
	struct node *p;
	p=head->next;
	cout<<head->data<<"->";
	while(p!=head)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<endl;
}
void loop()
{
  struct node *p,*q;  
  p=head->next; //assigning p as next of  head node
  p=p->next;     //assigning P ahead of q to check coincidence 
  q=head; //assigning q as head node
  while(p!=q)
    {
    p=p->next; //assigning p as next of p
    q=q->next; //assigning p as next of p
    if(q->next!=NULL)
      {
        p=p->next; //moving p ahead of q
      }
     }
  if(p->data==q->data)
      {
      cout<<"LOOP exists"<<endl;  
      }
   else cout<<"Linear linked list"<<endl;   
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n=5;
    int a[5]={1,2,3,4,5};
    create(a,5);
    display();
    loop();
    return 0;
}
