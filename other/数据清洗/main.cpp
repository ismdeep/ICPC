// project name : 数据清洗
// file name : main.cpp

#include <iostream>
#include "Node.h"
using namespace std;


int main()
{
    Node *head = new Node();
    
    Node *newNode = new Node();
    newNode->value = 12;
    newNode->next = head;
    head = newNode;
    
    newNode = new Node();
    newNode->value = 23;
    newNode->next = head;
    head = newNode;
    
    Node *current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    
    return 0;
}

// end 
// ism 

