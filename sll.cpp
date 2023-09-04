#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{ int data;
  node* link;};
struct header
{ int count;
  node* first;};
class SLL
{ header *head;
  node *pnew,*ploc,*pred,*temp;
  public:
  SLL()
  { head=new header;
    head->count=0;
    head->first=NULL;}
  void insert()
  { pnew = new node;
    if(head->count==0)
    { cout<<"\nEnter data: ";
      cin>>pnew->data;
      head->first=pnew;
      temp=pnew;
      head->count++;
      cout<<"\nElement inserted";
      pnew->link=NULL;}
    else if(head->count>0)
    { cout<<"\nEnter data: ";
      cin>>pnew->data;
      temp->link=pnew;
      temp=pnew;
      head->count++;
      cout<<"\nElement inserted";
      pnew->link=NULL;}
    else if(&pnew==NULL)
    { cout<<"\nNot possible, Memory full";}}
  void display()
  { temp=head->first;
    if(temp->link==NULL)
    {cout<<"\nList is empty";}
    else{
    int l;
    cout<<"\nWith address(1 for yes and 0 for no)?: ";
    cin>>l;
    if(l==1)
    { while(temp->link!=NULL)
      { cout<<"\nData= "<<temp->data;
        cout<<"\nAddress= "<<temp->link;
        temp=temp->link;}
      cout<<"\nData= "<<temp->data;
      cout<<"\nAddress= "<<temp->link;
      cout<<"\n\nHeader Data";
      cout<<"\nCount= "<<head->count;
      cout<<"\nLink= "<<head->first;}
    else
    { cout<<"\nSLL: ";
      while(temp->link!=NULL)
      { cout<<temp->data;
        cout<<"->";
        temp=temp->link;}
      cout<<temp->data;}}}
  void deletenode()
  { if(head->count==0)
    { cout<<"\nList is empty";}
    else{
    ploc=new node;
    pred=new node;
    int i=0,g=0,d;
    cout<<"\nEnter the data of the element to be deleted: ";
    cin>>d;
    ploc=head->first;
    while(ploc->link!=NULL)
    { if(ploc->data==d)
      { g++;
        if(i==0)
        { head->first=ploc->link;
          delete ploc;
          head->count--;
          cout<<"\nElement deleted";
          break;}
        else
        { pred->link=ploc->link;
          delete ploc;
          head->count--;
          cout<<"\nElement deleted";
          break;}}
        pred=ploc;
        ploc=ploc->link;
        i++;}
       if(ploc->link==NULL && ploc->data==d)
       { delete ploc;
         cout<<"\nElement deleted";
         pred->link==NULL;
         head->count--;
         g++;}
       if(g==0)
       { cout<<"\nElement not found in the list";}}}
  void destroy()
  { if(head->count==0)
    { cout<<"\nList is empty";}
    else{
     ploc=new node;
     temp=new node;
     ploc=head->first;
     while(ploc->link!=NULL)
     { temp=ploc;
       ploc=ploc->link;
       delete temp;}
     delete ploc;
     cout<<"\nList destroyed";}}
void empty()
{ if(head->first==NULL)
  { cout<<"\nList is empty";}
  else
  { cout<<"\nList is not empty";}}
void traversal()
{ if(head->count==0)
  { cout<<"\nList is empty";}
  else{
   int k,j=1;
   temp=new node;
   pred=new node;
   cout<<"\nEnter data of the element to be searched: ";
   cin>>k;
   temp=head->first;
   pred->link=head->first;
   while(temp->link!=NULL)
   { if(temp->data==k)
     { cout<<"\nElement id found in the list at "<<pred->link<<"and position "<<j;}
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
{ if(head->count==0)
  { cout<<"\nList is empty";}
  else{
   int kq;
   cout<<"\nEnter the target positon to be retrieved(list starts from 0): ";
   cin>>kq;
   if(kq>head->count)
   {cout<<"\noverflow";}
   else
   { kq=kq-1;
     temp=new node;
     pred=new node;
     temp=head->first;
     pred->link=head->first;
     while(kq>=0)
     { pred=temp;
       temp=temp->link;
       kq--;}
     cout<<"\nElement at target position is "<<temp->data<<" and address "<<pred->link;}}}
void listcount()
{ cout<<"\nList count= "<<head->count;}};
int main()
{ SLL s;
  int n,c;
  label:
  cout<<"\n1.Insert 2.Delete 3.Display 4.Destroy 5.is empty 6.is full 7.Traversal 8.Retrieve 9.List count\nEnter choice: ";
  cin>>c;
  switch(c)
  { case 1: s.insert();
            break;
    case 2: s.deletenode();
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
    case 9: s.listcount();
            break;}
 cout<<"\nPress 1 to continue and 0 to exit: ";
 cin>>n;
 if(n!=0)
 { goto label;}
 return 0;}



