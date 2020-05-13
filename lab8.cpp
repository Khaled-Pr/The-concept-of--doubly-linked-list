/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab8.cpp
 * Author: Khaled.Dz
 *
 * Created on October 16, 2019, 9:00 AM
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// Print details about the given list in reverse order, one Node per line
void reverseShow(Node* tail)
{
        Node* current = tail;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->prev << "   "
             << "Prev Address: " << setw(8) << current->next << "   "
             << endl;
        current = current->prev;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    // Create the first node
    Node* head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    Node* tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= size; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;
        
        // Fold it into the list
        tail->next = node;
        
        // Move the tail
        tail = node;
    }
    show(head);
    reverseShow(tail);

    // TODO: Your code for steps 2-7 here.
    
    // 1.Insert an element value of 100 to the front of the list 
    Node* tmp =new Node();
    tmp->elem=100;
    tmp->next=head;
    tmp->prev=NULL;
    head->prev=tmp;
    head=tmp;
    show(head);
    reverseShow(tail);
    
    //3.insert element with the value -99 to the back of the list
    
    Node* tmp1=new Node();
    tmp1->elem =-99;
    tmp1->prev=tail;
    tail->next=tmp1;
    tail=tmp1;
      
    show(head);
    reverseShow(tail);
    
   //4.Remove the first node from the front 
  
    Node* tmp2=head;
    head=tmp2->next;
    head->prev=NULL;
    delete tmp2;
    show(head);
    reverseShow(tail);
    //5. Remove the first node from the back
    
    Node* tmp3=tail;
    tail=tmp3->prev;
    tail->next=NULL;
    delete tmp3;
    show(head);
    reverseShow(tail);
    
   
    //6. and 7. Find the third node from the back
    ////and delete this third node;
    Node* current1=tail;
    current1->prev=tail->prev;
    Node* tmp4;
    
    //looping through our linked list
   for(int i=head->elem; i<tail->elem-1;i++){
  
       //finding the third node
        if(i==3){       
        
        //point tmp4 to our third node
        tmp4=current1;
        current1=tmp4->prev;
        current1->next=tmp4->next;
        
        tmp4->next->prev=current1;
        //to print the third element from the back
        cout<<"The third node containing : "<< tmp4->elem<<endl;
        
    
        delete tmp4;//return space to the system
        
    
        }
        else{
        current1= current1->prev;
       
        }
       
          
    
    }
   
    //Printing the results
    show(head);
    reverseShow(tail);
     
    
    
    
        
    // Clean up
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    
    return 0;
}

