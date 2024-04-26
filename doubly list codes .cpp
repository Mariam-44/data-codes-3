#include <iostream>
using namespace std;

template<class T>
struct Node {
    T value;
    Node* prev;
    Node* next;
};

template<class T>
class DoummyHeadDoublyLinkedList {

private:
    Node<T>* head;

public:
    DoummyHeadDoublyLinkedList() {
        head = new Node<T>;
        head->next = head;
        head->prev = head;
    }
    void Print() {

        Node<T>* current = head->next;
        while (current != head) {
            cout << current->value <<" ";
            current = current->next;

        }
        cout << "\n";

    }

    void Insert(T target) {
        Node<T>* current = head->next;

        Node<T>* newNode = new Node<T>;
        newNode->value = target;

        while (current != head) {
            if (current->value < target)
                current = current->next;
            else
                break;
        }

        newNode->next = current;
        newNode->prev = current->prev;

        current->prev = newNode;
        newNode->prev->next = newNode;
    }

    int counter() {
        int c = 0;
        Node<T>* current = head->next;
        while (current != head) {
            c++;
            current = current->next;

        }
        return c;
    }

    Node<T>* SearchByIndex(int k) {//time=O(n+k) Space=O(1) --> n=number of elements in the list k= index iteration
        int c = counter();
        Node<T>* cur = head->prev;
        Node<T>* p = nullptr;
        k = c - k;
        for (int i = 0; i < k;++i) {
            cur = cur->prev;
        }
        p = cur;
        return p;
    }

    void Reverese() { //time= O(n) Space=O(1)
        Node<T>* cur = head->next;
        Node<T>* p = nullptr;
        while (cur != head) {
            p = cur->prev;
            cur->prev = cur->next;
            cur->next = p;
            cur = cur->prev;
        }
        p = head->prev;
        head->prev = head->next;
        head->next = p;
      
    }
};



int main() {
    DoummyHeadDoublyLinkedList<int> list;

    list.Insert(5);
    list.Insert(10);
    list.Insert(3);
    list.Insert(2);

    cout << "Original List:" << endl;
    list.Print(); 
   cout<< list.SearchByIndex(4)->value<<"\n";
    list.Reverese();
    list.Print();
   
}