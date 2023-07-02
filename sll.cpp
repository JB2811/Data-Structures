#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{ int data;
  node* link;};
struct header
{ int count;
  node* front;
  node* rear;};
class SLL
{ header *queue;
  node *pred,*pnew,*temp2,*temp;
  public:
  SLL()
  { queue=new header;
    queue->count=0;
    queue->front=NULL;
    queue->rear=NULL;}
  void enqueue()
  { pnew = new node;
    if(queue->count==0)
    { cout<<"\nEnter data: ";
      cin>>pnew->data;
      queue->front=pnew;
      queue->rear=pnew;
      temp=pnew;
      queue->count++;
      cout<<"\nElement inserted";
      pnew->link=NULL;}
    else if(queue->count>0)
    { cout<<"\nEnter data: ";
      cin>>pnew->data;
      temp->link=pnew;
      temp=pnew;
      queue->rear=pnew;
      queue->count++;
      cout<<"\nElement inserted";
      pnew->link=NULL;}
    else if(pnew==NULL)
    { cout<<"\nNot possible, Memory full";}}
  void display()
  { temp=queue->front;
    if(queue->count==0)
    {cout<<"\nList is empty";}
    else{
    int l;
    cout<<"\nWith address(1 for yes and 0 for no)?: ";
    cin>>l;
    if(l==1)
    {while(temp->link!=NULL)
     { cout<<"\nData= "<<temp->data;
       cout<<"\nAddress= "<<temp->link;
       temp=temp->link;}
     cout<<"\nData= "<<temp->data;
     cout<<"\nAddress= "<<temp->link;
     cout<<"\n\nqueue Data";
     cout<<"\nCount= "<<queue->count;
     cout<<"\nLink= "<<queue->front;}
    else
    { if(queue->count>1)
      { cout<<"\nQueue SLL: ";
        while(temp->link!=NULL)
        { cout<<temp->data;
          cout<<"->";
          temp=temp->link;}
        cout<<temp->data;}
      else
      { cout<<"\nQueue SLL: ";
        cout<<temp->data;}}}}
  void dequeue()
  { if(queue->count==0)
    { cout<<"\nList is empty";}
    else if(queue->count==2)
    { temp=new node;
      temp=queue->rear;
      delete temp;
      temp=queue->front;
      int v=queue->count;
      while((v-2)>0)
      { temp=temp->link;
        v--;}
      cout<<"\nElement deleted";
      queue->count--;
      temp->link=NULL;
      queue->rear=temp;
      queue->front=queue->rear;}
    else
    { temp=new node;
      temp=queue->rear;
      delete temp;
      temp=queue->front;
      int v=queue->count;
      while((v-2)>0)
      { temp=temp->link;
        v--;}
      cout<<"\nElement deleted";
      queue->count--;
      temp->link=NULL;
      queue->rear=temp;}}
  void destroy()
  { if(queue->count==0)
    { cout<<"\nList is empty";}
    else
    { temp2=new node;
      temp=new node;
      temp=queue->front;
     while(queue->count<=0)
     { temp2=temp;
       temp=temp->link;
       delete temp2;
       queue->count--;}
     delete temp;
     cout<<"\nList destroyed";}}
void empty()
{ if(queue->front==NULL)
  { cout<<"\nList is empty";}
  else
  { cout<<"\nList is not empty";}}
void traversal()
{ if(queue->count==0)
  { cout<<"\nList is empty";}
  else{
   int k,j=1;
   temp=new node;
   pred=new node;
   cout<<"\nEnter data of the element to be searched: ";
   cin>>k;
   temp=queue->front;
   pred->link=queue->front;
   while(temp->link!=NULL)
   { if(temp->data==k)
     { cout<<"\nElement is found in the list at "<<pred->link<<"and position "<<j;}
     pred=temp;
     temp=temp->link;
     j++;}
     if(temp->link==NULL)
     { if(temp->data==k)
       { cout<<"\nSearch element is found in the list at "<<pred->link<<" and position "<<j;}}}}
void isfull()
{ pnew=new node;
  if(pnew==NULL)
  {cout<<"\nList if full";}
  else
  {cout<<"\nList is not full";}}
void retrieve()
{ if(queue->count==0)
  { cout<<"\nList is empty";}
  else{
   int kq;
   cout<<"\nEnter the target position to be retrieved(starts from 0): ";
   cin>>kq;
   if(kq>queue->count)
   {cout<<"\noverflow";}
   else
   { kq=kq-1;
     temp=new node;
     pred=new node;
     temp=queue->front;
     pred->link=queue->front;
     while(kq>=0)
     { pred=temp;
       temp=temp->link;
       kq--;}
     cout<<"\nElement at target position is "<<temp->data<<" and address "<<pred->link;}}}
void stackcount()
{ cout<<"\nStack count= "<<queue->count;}};
int main()
{ SLL s;
  int n,c;
  label:
  cout<<"\n1.enqueue 2.dequeue 3.Display Queue 4.Destroy Queue 5.is empty 6.is full 7.Traversal 8.Retrieve 9. Queue count\nEnter choice: ";
  cin>>c;
  switch(c)
  { case 1: s.enqueue();
            break;
    case 2: s.dequeue();
            break;
    case 3: s.display();
            break;
    case 4: s.destroy();
            break;
    case 5: s.empty();
            break;
    case 6: s.isfull();
            break;
    case 7: s.traversal();
            break;
    case 8: s.retrieve();
            break;
    case 9: s.stackcount();
            break;}
 cout<<"\nPress 1 to continue and 0 to exit: ";
 cin>>n;
 if(n!=0)
 { goto label;}
 return 0;}



