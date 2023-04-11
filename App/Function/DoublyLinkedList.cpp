#ifndef __DOUBLY_LINKED_LIST_CPP
#define __DOUBLY_LINKED_LIST_CPP
#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

//DLLNode
template < class T >
DLLNode<T>::DLLNode(const T &d) : data(d), pNext(nullptr), pPrev(nullptr) {}
template < class T >
DLLNode<T>::DLLNode(const DLLNode < T > &Node) : data(Node.data), pNext(Node.pNext), pPrev(Node.pPrev)  {}

//DLinked List
template < class T >
DLinkedList<T>::DLinkedList() : Head(nullptr), ListSize(0) {}
template < class T >
DLinkedList<T>::DLinkedList(const DLinkedList &List){
    DLLNode < T > *Tail = Head = nullptr;
    for (DLLNode < T > *cur = List.Head; cur; cur = cur->pNext){
        if (Tail){
            Tail->pNext = new DLLNode < T > (cur->data);
            Tail->pNext->pPrev = Tail;
            Tail = Tail->pNext;
        }
        else{
            Head = Tail = new DLLNode < T > (cur->data);
        }
        ListSize++;
    }
}
template < class T >
DLLNode<T>* DLinkedList<T>::GetByValue(const T &d){
    if (Head==nullptr) return nullptr;
    DLLNode < T > *cur = Head;
    while (cur){
        if (cur->data==d) return cur;
        cur=cur->pNext;
    }
    return nullptr;
}
template < class T >
void DLinkedList<T>::push(const T &d){
    ListSize++;
    
    if (Head){
        DLLNode < T > *cur = Head;
        while (cur){
            if (cur->data > d){
                DLLNode < T > *prevCur = cur->pPrev;
                DLLNode < T > *NN = new DLLNode<T>(d);
                NN->pNext = cur;
                NN->pPrev = prevCur;
                if (prevCur) prevCur->pNext = NN;
                else Head = NN;
                cur->pPrev = NN;
                return;
            }
            else if (cur->pNext==nullptr){
                DLLNode < T > *NN = new DLLNode<T>(d);
                NN->pPrev = cur;
                NN->pNext = nullptr;
                cur->pNext = NN;
                return;
            }
            else cur = cur->pNext;
        }
    } else {
        Head = new DLLNode < T > (d);
        Head->pPrev = nullptr;
        Head->pNext = nullptr;
    }
}

template < class T >
void DLinkedList<T>::push_descending(const T &d){
    ListSize++;
    
    if (Head){
        DLLNode < T > *cur = Head;
        while (cur){
            if (!(cur->data > d)){
                DLLNode < T > *prevCur = cur->pPrev;
                DLLNode < T > *NN = new DLLNode<T>(d);
                NN->pNext = cur;
                NN->pPrev = prevCur;
                if (prevCur) prevCur->pNext = NN;
                else Head = NN;
                cur->pPrev = NN;
                return;
            }
            else if (cur->pNext==nullptr){
                DLLNode < T > *NN = new DLLNode<T>(d);
                NN->pPrev = cur;
                NN->pNext = nullptr;
                cur->pNext = NN;
                return;
            }
            else cur = cur->pNext;
        }
    } else {
        Head = new DLLNode < T > (d);
        Head->pPrev = nullptr;
        Head->pNext = nullptr;
    }
}
template < class T>
void DLinkedList<T>::push_back(const T &d){
    ListSize++;
    if (Head==nullptr) {
        Head = new DLLNode < T > (d);
        return;
    }
    DLLNode<T> *cur = Head;
    while (cur->pNext){
        cur=cur->pNext;
    }
    DLLNode<T> *tmp = new DLLNode<T> (d);
    cur->pNext = tmp;
    tmp->pPrev = cur;
}
template < class T >
DLLNode<T>* DLinkedList<T>::front(){
    return Head;
}
template < class T >
DLLNode<T>* DLinkedList<T>::back(){
    DLLNode<T> *cur = Head;
    while (cur->pNext) cur=cur->pNext;
    return cur;
}
template < class T >
void DLinkedList<T>::pop_front(){
    if (isEmpty()) return;
    ListSize--;
    DLLNode < T > *cur = Head;
    Head = Head->pNext;
    if (Head) Head->pPrev=nullptr;
    delete cur;
}
template < class T >
void DLinkedList<T>::pop_back(){
    if (isEmpty()) return;
    ListSize--;
    DLLNode < T > *cur = Head;
    while (cur->pNext) cur=cur->pNext;
    if (cur->pPrev) cur->pPrev->pNext = nullptr;
    else Head=nullptr;
    delete cur;
}
template < class T >
bool DLinkedList<T>::isEmpty(){
    return size() == 0;
}
template < class T >
void DLinkedList<T>::remove(const T &d){
    if (isEmpty()) return;
    if (Head->data == d){
        pop_front();
    }
    else{
        DLLNode < T > *cur = Head;
        while (cur->pNext && !(cur->pNext->data==d)) cur = cur->pNext;
        if (cur->pNext){
            DLLNode < T > *N = cur->pNext;
            cur->pNext = N->pNext;
            cur->pNext->pPrev = cur;
            delete N;
            ListSize--;
        }
    }
}
template < class T >
int DLinkedList<T>::size(){
    return ListSize;
}
template < class T >
void DLinkedList<T>::Delete(){
    while (!isEmpty()) pop_front();

}
template < class T >
DLinkedList<T>::~DLinkedList(){
    if (isEmpty()) return;
    while (!isEmpty()) pop_front();
}

#endif // __DOUBLY_LINKED_LIST_CPP
