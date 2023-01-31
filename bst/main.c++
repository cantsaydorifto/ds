#include <iostream>
#include <queue>
using namespace std;
class Node {
   public:
    int data;
    Node* left;
    Node* right;

   public:
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node*& root, int d) {
    // Base Case
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
Node* min(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
Node* max(Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
Node* deleteNode(Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child : left
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 1 child : right
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child : either take min from right or max from left
        if (root->left != NULL && root->right != NULL) {
            int mini = min(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
        return root;
    } else {
        root->left = deleteNode(root->left, x);
        return root;
    }
}
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = NULL;
    int choice;
    cout << " 1:Insert node" << endl;
    cout << " 2:Print postorder traversal" << endl;
    cout << " 3:Print inorder traversal" << endl;
    cout << " 4:Print preorder traversal" << endl;
    cout << " 5:Delete node" << endl;
    cout << " 6:STOP" << endl;
    cout << "Enter choice:";
    cin >> choice;
    while (choice != 6) {
        if (choice == 1) {
            int element;
            cout << "Enter data:";
            cin >> element;
            insertIntoBST(root, element);
        } else if (choice == 2) {
            cout << "Postorder:";
            postOrder(root);
            cout << endl;

        } else if (choice == 3) {
            cout << "inorder:";
            inOrder(root);
            cout << endl;
        } else if (choice == 4) {
            cout << "Preorder:";
            preOrder(root);
            cout << endl;
        } else if (choice == 5) {
            int element;
            cout << "Enter element to be deleted:";
            cin >> element;
            deleteNode(root, element);
            cout << endl;
        } else {
            cout << "Wrong Input" << endl;
        }
        cout << "Enter choice:";
        cin >> choice;
    }

    return 0;
}
