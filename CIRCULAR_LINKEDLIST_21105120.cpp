#include <iostream>               // Name - Abhisek meena 
using namespace std;              // Sid - 21105120    // Branch - ECE

// *************** Creating the  Node class *************

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
// ************* Function to insert a node at end on linked list ********************

void append(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){head=new_node;new_node->next=head;return;}
    while(temp->next!=head){temp=temp->next;}   
    temp->next=new_node;
    new_node->next=head;
}
// *************** Function to print elements of linked list from head to the last node *********************

void pfun(Node*&head){
    Node*temp=head;
    do{cout<<temp->data<<"->";temp=temp->next;}
    while(temp!=head);
}
int main(){
    Node*head=NULL;
    append(head,10);
    append(head,20);
    append(head,30);
    pfun(head);
}

// Question.2 - What are the practical applications of a circular linked list? (Try to find applications in your respective fields).

// 1) Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one copmlete audio list finishes playing in music player then it again starts playing from start.
// 2) Computer Networking: Circular linked list is also used in computer networking for token scheduling.
// 3) Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.
// 4) Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
