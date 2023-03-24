#ifndef __DOUBLY_LINKED_LIST_HPP
#define __DOUBLY_LINKED_LIST_HPP
#include <functional>


template < class T >
struct DLLNode{
    T data;
    DLLNode < T > *pNext;
    DLLNode < T > *pPrev;
    DLLNode(const T &d = T());
    DLLNode(const DLLNode < T > &Node);
};

template < class T >
struct DLinkedList{
    DLLNode < T > *Head;
    int ListSize = 0;
    DLinkedList();
    DLinkedList(const DLinkedList &List);
    ~DLinkedList();
    void push_front(const T &d);
    void pop_front();
    bool isEmpty();
    void remove(const std::function < bool(T) > &equalK);
    int size();
};

#include "DoublyLinkedList.cpp"

#endif // __DOUBLY_LINKED_LIST_HPP