#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int countNodesInLoop(Node *head){     // it will return loop lenght
    if(head==NULL)return 0;
    Node *fast=head;
    Node *slow=head;
    
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow && fast!=NULL);


    if(fast==NULL)return 0;

    int count=1;
    fast=fast->next;
    while(slow!=fast){
        fast=fast->next;
        count++;
    }
    return count;
}

Node *makeLLlooped(Node *head,Node *tail,int pos){ // create loop in LL
    if(pos==0)return head;
    Node *walk=head;
    for(int i=1;i<pos;i++){
        walk=walk->next;
    }
    tail->next=walk;
    return head;
    
}

int main(){
    int n;cin>>n;  // length of linked list
    
    int num;cin>>num;    // will hold entries of linked list
    Node *head=NULL;     // head pointer of ll
    Node *tail=NULL;     // tail of ll
    head=tail=new Node(num);

    for(int i=1;i<n;i++){
        cin>>num;
        tail->next =new Node(num);
        tail=tail->next;
    }
    // LL has been created
    int pos;                  // position of where to make loop
    cin>>pos;
    head=makeLLlooped(head,tail,pos);  
    // LL has been looped

    cout<<countNodesInLoop(head)<<endl;

}