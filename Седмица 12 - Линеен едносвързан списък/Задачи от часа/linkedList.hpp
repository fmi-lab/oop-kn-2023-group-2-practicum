#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include<iostream>
#include <functional>
 
template <typename T>
class LinkedList{
private:
    struct node{
        T data;
        node* next;
    };
 
    node* first;
    size_t size;
 
    void copy(const LinkedList&);
    void del();
 
public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();
    void insertLast(const T& element);
    void removeLast();
    void append(const LinkedList<T>& other);
    void reverse();
 
    template <typename U>
    U reduce(std::function<U(const T&, const U&)> operation, U nullValue) const;
 
    bool any(std::function<bool(const T&)> predicate) const;
};
 
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other){
    this->size = other.size;
    if(!other.first){
        this->first = nullptr;
        return;
    }
    this->first = new node{other.first->data, nullptr};
    node* iter = other.first->next;
    node* iter_this = this->first;
    while(iter){
        iter_this->next = new node{iter->data, nullptr};
        iter_this = iter_this->next;
        iter = iter->next; 
    }
}
 
template <typename T>
void LinkedList<T>::del(){
    while(first){
        node* next = first->next;
        delete first;
        first = next;
    }
    first = nullptr;
}
 
template <typename T>
LinkedList<T>::LinkedList():first(nullptr), size(0){}
 
 
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
    copy(other);
}
 
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    if(this!=&other){
        del();
        copy(other);
    }
    return *this;
}
 
template <typename T>
LinkedList<T>::~LinkedList(){
    del();
}
 
template <typename T>
void LinkedList<T>::insertLast(const T& element){
    if(!first){
        first = new node{element, nullptr};
        size++;
        return;
    }
    node* iter = first;
    while(iter->next){
        iter = iter->next;
    }
    iter->next = new node{element, nullptr};
    size++;
}
 
template <typename T>
void LinkedList<T>::removeLast(){
    if(!first){
        return;
    }
    if(!first->next){
        delete first;
        first = nullptr;
        size--;
        return;
    }
    node* iter = first;
    while(iter->next->next){
        iter = iter->next;
    }
    delete iter->next;
    iter->next = nullptr;
    size--;
}
 
template <typename T>
void LinkedList<T>::append(const LinkedList<T>& other){
    if(!other.first){
        return;
    }
    if(!first){
        copy(other);
        return;
    }
    node* iter = first;
    while(iter->next){
        iter = iter->next;
    }
    node* iter_other = other.first;
    while(iter_other){
        iter->next = new node{iter_other->data, nullptr};
        iter = iter->next;
        iter_other = iter_other->next;
    }
}
 
template <typename T>
void LinkedList<T>::reverse(){
    if(!first){
        return;
    }
    node* prev = nullptr;
    // node* iter = first->next;
    while(first){
        node* iter = first->next;
        first->next = prev;
        prev = first;
        first = iter;
    }
    first = prev;
}
 
template <typename T>
template <typename U>
U LinkedList<T>::reduce(std::function<U(const T&, const U&)> operation, U nullValue) const {
    node* current = first;
    while (current)
    {
        nullValue = operation(current->data, nullValue);
        current = current->next;
    }
    return nullValue;
}
 
template <typename T>
bool LinkedList<T>::any(std::function<bool(const T&)> predicate) const {
    return reduce<bool>([predicate](const T& element, const bool& res){
        return predicate(element) || res;
    }, false);
}

#endif