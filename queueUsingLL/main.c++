#include <iostream>
using namespace std;
class Node {
   public:
    Node* next;
    int data;
    Node(int d) {
        this->next = NULL;
        this->data = d;
    }
};
void enqueue(Node*& head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        cout << val << " pushed successfully" << endl;
    } else if (head != NULL) {
        Node* it = head;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = temp;
        cout << val << " pushed successfully" << endl;
    } else {
        cout << "!!LIST IS FULL!!" << endl;
    }
}

void dequeue(Node*& head) {
    if (head == NULL) {
        cout << "!!EMPTY LIST!!" << endl;
    } else {
        Node* temp = head->next;
        cout << "element deleted successfully" << endl;
        delete head;
        head = temp;
    }
}
void front(Node*& head) {
    if (head == NULL) {
        cout << "!!EMPTY LIST!!" << endl;
    } else {
        cout << "Front element is " << head->data << endl;
    }
}
int main() {
    Node* head = NULL;
    int choice;
    cout << " 1:Enqueue" << endl;
    cout << " 2:Dequeue" << endl;
    cout << " 3:Front" << endl;
    cout << " 4:STOP" << endl;
    cout << "Enter choice:";
    cin >> choice;

    while (choice != 4) {
        if (choice == 1) {
            int element;
            cout << "Enter element:";
            cin >> element;
            enqueue(head, element);
        } else if (choice == 2) {
            dequeue(head);
        } else if (choice == 3) {
            front(head);
        }
        cout << "Enter choice:";
        cin >> choice;
    }
    return 0;
}
