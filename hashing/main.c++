#include <iostream>
#include <list>
using namespace std;
class Hash {
    int size;
    list<int> *hashTable;

   public:
    Hash(int data) {
        this->size = data;
        hashTable = new list<int>[size];
    }
    int hashFunction(int val) {
        return (val % size);
    }
    void insert(int key) {
        int index = hashFunction(key);
        hashTable[index].push_back(key);
    }

    void search(int key) {
        int index = hashFunction(key);
        list<int>::iterator i;
        for (i = hashTable[index].begin(); i != hashTable[index].end(); i++) {
            if (*i == key)
                break;
        }
        if (i != hashTable[index].end()) {
            cout << "Element found" << endl;
        } else {
            cout << "Element not found" << endl;
        }
    }
    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << i;
            for (auto x : hashTable[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
};
int main() {
    int n;
    cout << "Enter size of table:";
    cin >> n;
    Hash h1(n);
    int choice;
    cout << " 1.Insert element" << endl;
    cout << " 2.Search element" << endl;
    cout << " 3.Print hash table" << endl;
    cout << " 4.Stop" << endl;
    cout << "Enter choice:";
    cin >> choice;
    while (choice != 4) {
        if (choice == 1) {
            int value;
            cout << "Enter value:";
            cin >> value;
            h1.insert(value);
        } else if (choice == 2) {
            int value;
            cout << "Enter value for searching:";
            cin >> value;
            h1.search(value);
        } else if (choice == 3) {
            h1.printTable();
        }
        cout << "Enter choice:";
        cin >> choice;
    }

    return 0;
}