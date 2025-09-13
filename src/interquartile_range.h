/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    //code here
    Node* first = head;
    Node* second = head->next;
    Node* third = head->next->next;
    Node* fourth = head->next->next->next;
    int count = 4;
    while (fourth != nullptr && fourth->next != nullptr && fourth->next->next != nullptr && fourth->next->next->next != nullptr && fourth->next->next->next->next != nullptr){
        first = first->next;
        second = second->next->next;
        third = third->next->next->next;
        fourth = fourth->next->next->next->next;
        count += 4;
    }
    while(fourth != nullptr){
      count += 1;
      fourth = fourth->next;
    }
  count -= 1;
  float quarter3, quarter1; 
  if(count % 2 != 0){
    int div = (count - 1) / 2;
    if(div % 2 == 0){
      quarter1 = first->value / 2.0 + first->next->value / 2.0;
      quarter3 = third->next->value/ 2.0 + third->next->next->value / 2.0;
    }else{
    quarter3 = third->next->next->next->value;
    quarter1 = first->next->value;
    }
  }else{
    int div = count / 2;
    if(div % 2 == 0){
      quarter1 = first->value / 2.0 + first->next->value / 2.0;
      quarter3 = third->value / 2.0 + third->next->value / 2.0;
    }
    else{
      quarter1 = first->next->value;
      quarter3 = third->next->next->value;
    }
  }
    return quarter3 - quarter1;   
}