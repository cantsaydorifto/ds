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
void push(Node*& head, int val) {
    Node* temp = new Node(val);

    if (head == NULL) {
        head = temp;
        cout << val << " pushed successfully" << endl;
    } else if (head != NULL) {
        temp->next = head;
        head = temp;
        cout << val << " pushed successfully" << endl;
    } else {
        cout << "!!STACK OVERFLOW!!" << endl;
    }
}
void pop(Node*& head) {
    if (head == NULL) {
        cout << "!!STACK UNDERFLOW!!" << endl;
    } else {
        Node* temp = head->next;
        cout << head->data << " deleted successfully" << endl;
        delete head;
        head = temp;
    }
}

void peek(Node*& head) {
    if (head == NULL) {
        cout << "!!EMPTY STACK!!" << endl;
    } else {
        cout << "Top element is " << head->data << endl;
    }
}
int main() {
    Node* head = NULL;

    int choice;
    cout << " 1:Push" << endl;
    cout << " 2:Pop" << endl;
    cout << " 3:Peek" << endl;
    cout << " 4:STOP" << endl;
    cout << "Enter choice:";
    cin >> choice;
    while (choice != 4) {
        if (choice == 1) {
            int element;
            cout << "Enter element:";
            cin >> element;
            push(head, element);
        } else if (choice == 2) {
            pop(head);
        } else if (choice == 3) {
            peek(head);
        }
        cout << "Enter choice:";
        cin >> choice;
    }

    return 0;
}
