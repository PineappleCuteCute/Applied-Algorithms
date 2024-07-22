#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    unordered_set<int> elements; // To track existing elements and ensure uniqueness

public:
    LinkedList() : head(nullptr) {}

    void addLast(int k) {
        if (elements.find(k) != elements.end()) return;
        elements.insert(k);
        Node* newNode = new Node(k);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addFirst(int k) {
        if (elements.find(k) != elements.end()) return;
        elements.insert(k);
        Node* newNode = new Node(k);
        newNode->next = head;
        head = newNode;
    }

    void addAfter(int u, int v) {
        if (elements.find(u) != elements.end()) return;
        Node* temp = head;
        while (temp) {
            if (temp->data == v) {
                Node* newNode = new Node(u);
                newNode->next = temp->next;
                temp->next = newNode;
                elements.insert(u);
                return;
            }
            temp = temp->next;
        }
    }

    void addBefore(int u, int v) {
        if (elements.find(u) != elements.end()) return;
        if (head && head->data == v) {
            addFirst(u);
            return;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == v) {
                Node* newNode = new Node(u);
                newNode->next = temp->next;
                temp->next = newNode;
                elements.insert(u);
                return;
            }
            temp = temp->next;
        }
    }

    void remove(int k) {
        if (elements.find(k) == elements.end()) return;
        elements.erase(k);
        if (head && head->data == k) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == k) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList list;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.addLast(value); // Initial list setup
    }
    
    string command;
    while (cin >> command) {
        if (command == "#") break;
        if (command == "addlast") {
            int k;
            cin >> k;
            list.addLast(k);
        } else if (command == "addfirst") {
            int k;
            cin >> k;
            list.addFirst(k);
        } else if (command == "addafter") {
            int u, v;
            cin >> u >> v;
            list.addAfter(u, v);
        } else if (command == "addbefore") {
            int u, v;
            cin >> u >> v;
            list.addBefore(u, v);
        } else if (command == "remove") {
            int k;
            cin >> k;
            list.remove(k);
        } else if (command == "reverse") {
            list.reverse();
        }
    }
    
    list.printList();
    
    return 0;
}
