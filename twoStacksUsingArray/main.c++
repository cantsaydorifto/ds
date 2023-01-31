#include <iostream>
using namespace std;
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

   public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    // Push in stack 1.
    void push1(int num) {
        // atleast a empty space present
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
            cout << num << " pushed successfully in stack 1" << endl;
        } else {
            cout << "!!No empty space!!" << endl;
            return;
        }
    }
    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
            cout << num << " pushed successfully in stack 2" << endl;
        } else {
            cout << "!!No empty space!!" << endl;
            return;
        }
    }
    // Pop from stack 1 and return popped element.
    void pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            cout << ans << " popped successfully from stack 1" << endl;
            return;
        } else {
            cout << "!!Empty list!!" << endl;
            return;
        }
    }
    // Pop from stack 2 and return popped element.
    void pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            cout << ans << " popped successfully from stack 2" << endl;
            return;
        } else {
            cout << "!!Empty list!!" << endl;
            return;
        }
    }
    void print() {
        cout << "Top element of stack 1:" << arr[top1] << endl;
        cout << "Top element of stack 2:" << arr[top2] << endl;
    }
};
int main() {
    int s;
    cout << "Enter size of stack:";
    cin >> s;
    TwoStack S(s);
    int choice;
    cout << " 1:Insert in Stack 1" << endl;
    cout << " 2:Insert in Stack 2" << endl;
    cout << " 3:Pop from Stack 1" << endl;
    cout << " 4:Pop from Stack 2" << endl;
    cout << " 5:Print top elements" << endl;
    cout << " 6:STOP" << endl;
    cout << "Enter choice:";
    cin >> choice;
    while (choice != 6) {
        if (choice == 1) {
            int element;
            cout << "Enter element:";
            cin >> element;
            S.push1(element);
        } else if (choice == 2) {
            int element;
            cout << "Enter element:";
            cin >> element;
            S.push2(element);
        } else if (choice == 3) {
            S.pop1();
        } else if (choice == 4) {
            S.pop2();
        } else if (choice == 5) {
            S.print();
        }
        cout << "Enter choice:";
        cin >> choice;
    }
    return 0;
}
