#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addF(Node*&, float);
void addT(Node*&, float);
void delNode(Node*&);
void insNode(Node*&);
void delAll(Node*&);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;     
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            addF(head,tmp_val);
        }
        else { // its a second or subsequent node; place at the head
            addT(head, tmp_val);
        }
    }
    output(head);

    // deleting a node
    delNode(head);

    // insert a node
    insNode(head);

    // deleting the linked list
    delAll(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addF(Node*& head, float val) {
    Node * tempNode = new Node;
    tempNode->value = val;
    tempNode->next = nullptr;
    head = tempNode;
}

void addT(Node*& head, float val) {
    Node * tempNode = new Node;
    tempNode->next = head;
    tempNode->value = val;
    head = tempNode;
}

void delNode(Node*& head) {
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

void insNode(Node*& head) {
    int count = 0;
    int entry;
    Node * current = head;
    Node *prev = head;
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void delAll(Node*& head) {
    Node * current = head;
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}