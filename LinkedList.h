#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include "Node.h"


class LinkedList
{
    private:
        Node *head, *tail;

        Node* getNodeData(int data){
            Node *current = head;
            while(current != NULL){
                if(current->Data == data)
                    return current;
                current = current->next;
            }
            return NULL;
        }

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        ///Insert a new node at the end
        void add(int data){
            Node *newNode = new Node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        ///Display all list data
        void display(){
            Node *current = head;
            if(current == NULL){
                cout<<"\nEmpty List\n";
                return;
            }
            while(current != NULL){
                cout<<current->Data<<"\t";
                current = current->next;
            }
            cout<<endl;
        }

        ///Insert after given node
        void insertAfter(int data, int insertedData){
            Node *insertedAfter = new Node(insertedData);
            Node *current = head;
            Node *temp = NULL;
            if(current == NULL){    ///Case of Empty List
                head = insertedAfter;
                tail = insertedAfter;
                return;
            }
            else if((current == tail) && (current->Data == data)){   ///Case of Single Node List (its data is the data we're inserting after)
                head->next = insertedAfter;
                tail = insertedAfter;
                tail->prev = head;
                return;
            }
            else{   ///Case of Multiple Nodes
                while(current != NULL){
                    if(current->Data == data){
                        if(current == tail){    ///Case of Insertion after Tail
                            current->next = insertedAfter;
                            insertedAfter->prev = current;
                            tail = insertedAfter;
                            return;
                        }
                        else{   ///Case of Insertion in between nodes (no corner cases)
                            temp = current->next;
                            current->next = insertedAfter;
                            temp->prev = insertedAfter;
                            insertedAfter->next= temp;
                            insertedAfter->prev=current;
                            return;
                        }
                    }
                    current = current->next;
                }
            }
            cout<<"\nYou're to trying to insert after non-existing element"<<endl;
        }

        ///Insert before given node
        void insertBefore(int data, int insertedData){
            Node *insertedBefore = new Node(insertedData);
            Node *current = head;
            Node *temp = NULL;
            if(current == NULL){    ///Case of Empty List
                head = insertedBefore;
                tail = insertedBefore;
                return;
            }
            else if((current == tail) && (current->Data == data)){   ///Case of Single Node List (its data is the data we're inserting after)
                head = insertedBefore;
                head->next = current;
                tail = current;
                tail->prev = insertedBefore;
                return;
            }
            else{   ///Case of Multiple Nodes
                while(current != NULL){
                    if(current->Data == data){
                        if(current == tail){    ///Case of Insertion before Tail
                            temp = current->prev;
                            tail->prev = insertedBefore;
                            insertedBefore->prev = temp;
                            insertedBefore->next = tail;
                            temp->next =insertedBefore;
                            return;
                        }
                        else{   ///Case of Insertion in between nodes (no corner cases)
                            temp = current->prev;
                            current->prev = insertedBefore;
                            temp->next = insertedBefore;
                            insertedBefore->prev= temp;
                            insertedBefore->next=current;
                            return;
                        }
                    }
                    current = current->next;
                }
            }
            cout<<"\nYou're to trying to insert before non-existing element"<<endl;
        }

        int getCount(){
            int nodeCount = 0;
            Node *current = head;
            if(current == NULL){
                return nodeCount;
            }
            else if(current == tail){
                return ++nodeCount;
            }
            else{
                while(current != NULL){
                    nodeCount++;
                    current = current->next;
                }
                return nodeCount;
            }
        }

        int getDataByIndex(int indx){
            int indxData = 0;
            int currIndx = 0;
            Node *current = head;
            if(current == NULL){
                cout<<"\nEmpty List\n";
                return 0;
            }
            else{
                while(current != NULL){
                    if(indx == currIndx){
                        return current->Data;
                    }
                    currIndx++;
                    current = current->next;
                }
            }
            if(indx > currIndx){
                cout<<"\nIndex out of range\n";
            }
        }

};

#endif // LINKEDLIST_H
