#include <iostream>
using namespace std;
class Node {
   public:
    Node* next;
    int data;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};
void insertAtFront(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL && tail == NULL) {
        head = temp;
        tail = temp;
        tail->next = head;
    } else {
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
}
void deleteAtEnd(Node*& head, Node*& tail) {
    if (head == NULL && tail == NULL) {
        cout << "!! EMPTY LIST !!" << endl;
        return;
    } else if (head->next == head) {
        // Only one node is present
        delete (head);
        delete (tail);
        head = NULL;
        tail = NULL;
        return;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        // Now temp is pointing node before tail
        temp->next = head;
        delete (tail);
        tail = temp;
    }
}
void printList(Node*& head, Node*& tail) {
    if (head == NULL && tail == NULL) {
        cout << "!! EMPTY LIST !!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != tail) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice;
    cout << "1.Insert at front \n";
    cout << "2.Delete from end \n";
    cout << "3.Print \n";
    cout << "4.Break" << endl;
    cout << "Enter choice:";
    cin >> choice;
    while (choice != 4) {
        if (choice == 1) {
            int val;
            cout << "Enter roll number:";
            cin >> val;
            insertAtFront(head, tail, val);
        } else if (choice == 2) {
            deleteAtEnd(head, tail);
        } else {
            printList(head, tail);
        }
        cout << "Enter choice:";
        cin >> choice;
    }

    return 0;
}
