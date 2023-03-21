#ifndef __LINKED_LIST_HPP
#define __LINKED_LIST_HPP
#include <functional>

template < class T >
struct SLLNode{
    T data;
    SLLNode < T > *pNext;
    SLLNode(const T &d = T());
    SLLNode(const SLLNode < T > &Node);
};

template < class T >
struct SLLinkedList{
    SLLNode < T > *Head;
    int ListSize = 0;
    SLLinkedList();
    SLLinkedList(const SLLinkedList &List);
    ~SLLinkedList();
    void push_front(const T &d);
    void pop_front();
    bool isEmpty();
    void remove(const std::function < bool(T) > &equalK);
    int size();
};

#include "LinkedList.cpp"

#endif // __LINKED_LIST_HPP
