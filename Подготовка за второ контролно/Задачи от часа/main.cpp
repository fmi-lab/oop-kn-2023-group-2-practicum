#include <iostream>
 
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& _data = T(), Node* _next = nullptr) : data(_data), next(_next) {}
};
 
template <typename T>
void reverse(Node<T>*& start) {
    Node<T>* prev = nullptr;
    while (start != nullptr)
    {
        Node<T>* next = start->next;
        start->next = prev;
        prev = start;
        start = next;
    }
    start = prev;
}
 
template <typename T>
void print(Node<T>* start) {
    Node<T>* curr = start;
    while (curr != nullptr)
    {
        std::cout<<curr->data<<' ';
        curr = curr->next;
    }
    std::cout<<'\n';
}
 
template <typename T>
void destroy(Node<T>*& list) {
    while (list) // list != nullptr
    {
        Node<T>* next = list->next;
        delete list;
        list = next;
    }
    list = nullptr;
}
 
template <typename T>
void swap(Node<T>*& list, int a, int b) {
 
}
 
int main() {
    Node<int>* list = new Node<int>(2, new Node<int>(4, new Node<int>(3, new Node<int>(1, new Node<int>(2)))));
    print(list);
    reverse(list);
    print(list);
    destroy(list);
    return 0;
}