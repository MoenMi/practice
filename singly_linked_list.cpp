/*
    Uses a singly-linked list to store a list of contacts by ID
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node() {
        next = nullptr;
        age = id = 0;
    }
    Node(Node* n, string s, int a, int identity) {
        next = n;
        age = a;
        id = identity;
        name = s;
    }
    void Print() {
        cout << name << "\t(" << age << ")\t" << id << endl;
    }
    Node* getNext() { return next; }
    string getName() { return name; }
    int getAge() { return age; }
    int getId() { return id; }
    void setNext(Node* newNext) { next = newNext; }
    void setName(Node* newName) { next = newName; }
    void setAge(Node* newAge) { next = newAge; }
    void setId(Node* newId) { next = newId; }
private:
    Node* next;
    string name;
    int age, id;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        length = 0;
    }
    LinkedList(Node* h) {
        head = h;
        length = 1;
    }
    void Print() {
        if (length == 0) {
            cout << "The contact list is empty" << endl;
        } else {
            Node* cur = head;
            for (int i = 0; i < length; i++) {
                cur->Print();
                cur = cur->getNext();
            }
        }
    }
    void addNode(Node* newNode);
    void deleteNode(int id);
    void reverse();
    void merge(LinkedList otherList);
private:
    Node* head;
    int length;
};

void LinkedList::addNode(Node* newNode) {
    // If the length of the LinkedList is 0, set the head to the newNode and return
    if (length == 0) {
        head = newNode;
        length++;
        return;
    }
    // If the new Id is less than the head Id, set the new node as the head and the old head as new head->next
    if (newNode->getId() < head->getId()) {
        newNode->setNext(head);
        head = newNode;
        length++;
        return;
    }
    Node* temp = head->getNext();
    Node* temp2 = head;
    for (int i = 1; i < length-1; i++) {
        if (newNode->getId() < temp->getId()) {
            cout << "In here" << endl;
            for (int j = 0; j < i-1; j++) temp2 = temp2->getNext();
            newNode->setNext(temp2);
            temp->setNext(newNode);
            length++;
            return;
        }
        temp = temp->getNext();
    }
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
    length++;
    return;
}

void LinkedList::deleteNode(int id) {
    int location = 0;
    Node* temp = head;
    for (int i = 0; i < length; i++) {
        if (temp->getId() == id) break;
        location++;
    }
    if (location == 0) {
        temp = head;
        head = head->getNext();
        length--;
        delete temp;
        return;
    }
    temp = head;
    for (int i = 0; i < location - 1; i++) temp = temp->getNext();
    Node* temp2 = temp;
    temp = temp->getNext();
    temp2->setNext(temp->getNext());
    delete temp;
    length--;
    return;
}

void LinkedList::reverse() {

}

void LinkedList::merge(LinkedList otherList) {
    length += otherList.length;
    Node* temp = head;
    for (int i = 0; i < otherList.length; i++) {
        addNode(temp);
        temp = temp->getNext();
    }
    return;
}

int main() {

    LinkedList list;
    list.Print();

    Node* temp = new Node(nullptr, "Michael", 19, 12172160);
    list.addNode(temp);
    temp = new Node(nullptr, "Sean", 20, 12112343);
    list.addNode(temp);
    temp = new Node(nullptr, "Andrew", 24, 23154859);
    list.addNode(temp);
    temp = new Node(nullptr, "Brett", 29, 35642321);
    list.addNode(temp);
    temp = new Node(nullptr, "Alec", 32, 44211008);
    list.addNode(temp);
    temp = new Node(nullptr, "Joseph", 8, 11258497);
    list.addNode(temp);

    list.Print();

    cout << endl;
    //list.deleteNode(23154859);

    //list.Print();

    LinkedList list2;
    temp = new Node(nullptr, "Leo", 6, 54788542);
    list2.addNode(temp);
    temp = new Node(nullptr, "Teresa", 5, 10056320);
    list2.addNode(temp);
    temp = new Node(nullptr, "Sadie", 3, 87514120);
    list2.addNode(temp);
    temp = new Node(nullptr, "John", 1, 78450060);
    list2.addNode(temp);
    temp = new Node(nullptr, "Lily", 0, 30087455);
    list2.addNode(temp);

    list2.Print();
    cout << endl;



    return 0;
}