#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        
        /*
        ~LinkedList() = default;
        default destructor wont work with linkedlist class.
        with default destructor, it will only delete head, tail and length. all the other nodes will remain.
        */
       ~LinkedList(){
        
        Node* temp= head;
        while(head){
            delete temp;
            head=head->next;
            temp=head;
        }

        delete head;
        delete tail;
        length=0;

       }

        void printList(){
            Node* temp = head;
            while(temp){ //temp!=nullptr
                cout << temp->value <<endl;
                temp = temp->next;
            }
        }

        Node* getHead(){
            return head;
        }
        Node* getTail(){
            return tail;
        }

        int getLength(){
            return length;
        }


};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(4);
    
    cout << "Head is: " << (myLinkedList->getHead())->value <<endl; 
    cout << "Tail is: " << (myLinkedList->getTail())->value <<endl; 
    cout << "Length of linked list is: " << (myLinkedList->getLength()) <<endl; 

    delete myLinkedList;

    return 0;
       
}

