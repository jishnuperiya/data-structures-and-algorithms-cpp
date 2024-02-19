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

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }
        
        // We will use this method to test append to an empty list
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
            length = 0;
        }
        void append(int value){
            Node* newNode = new Node(value);
            if (length==0){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
                
            }
            length++;
        }

        //   +====================================================+
        //   |                 WRITE YOUR CODE HERE               |
        //   | Description:                                       |
        //   | - Write code to append 'value' to the list         |
        //   | - Return type: void                                |
        //   |                                                    |
        //   | Tips:                                              |
        //   | - Consider edge cases like empty lists             |
        //   | - Remember to update the length                    |
        //   | - Check output from Test.cpp in "User logs"        |
        //   +====================================================+

}; 


