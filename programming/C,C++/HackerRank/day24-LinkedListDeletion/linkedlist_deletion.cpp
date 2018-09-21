#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:        
          Node* findNode(Node* head, int data) {
              if (head == NULL) {
                  return NULL;
              }
              else if (head->data == data) {
                  return head;
              }
              else {
                  return findNode(head->next, data);
              }
          }    

          Node* remove(Node* head, Node* node) {
              Node* cur = head;
              Node* prev = NULL;
              Node* next = NULL;
              
              while (cur != node) {
                  prev = cur;
                  cur = cur->next;
              }
              
              if(cur != NULL) {
                next = cur->next;
                cur->next = NULL;
              }
              
              if(prev != NULL)
                prev->next = next;
              else
                head = next;
              
              return head;
              
          }

          Node* removeDuplicates(Node *head)
          {
            Node* cur = head;
            while(cur != NULL) {
                Node* cur2 = cur->next;
                while(cur2 != NULL) {
                    Node* duplicateNode = findNode(cur2, cur->data);
                    cur2 = cur2->next;
                
                    if (duplicateNode != NULL) {
                        head = remove(head, duplicateNode);
                        cout << "Found duplicate for data " << duplicateNode->data << endl;
                    }
                }               
                cur = cur->next;
            }
            
            return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
			
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}
