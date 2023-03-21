#ifndef __LINKED_LIST_CPP
#define __LINKED_LIST_CPP


#include "LinkedList.hpp"

//SLLNode
template < class T >
SLLNode<T>::SLLNode(const T &d) : data(d), pNext(nullptr) {}
template < class T >
SLLNode<T>::SLLNode(const SLLNode < T > &Node) : data(Node.data), pNext(Node.pNext) {}

//SLLinked List
template < class T >
SLLinkedList<T>::SLLinkedList() : Head(nullptr), ListSize(0) {}
template < class T >
SLLinkedList<T>::SLLinkedList(const SLLinkedList &List){
    SLLNode < T > *Tail = Head = nullptr;
    for (SLLNode < T > *cur = List.Head; cur; cur = cur->pNext){
        if (Tail){
            Tail->pNext = new SLLNode < T > (cur->data);
            Tail = Tail->pNext;
        }
        else{
            Head = Tail = new SLLNode < T > (cur->data);
        }
        ListSize++;
    }
}
template < class T >
void SLLinkedList<T>::push_front(const T &d){
    if (Head){
        SLLNode < T > *NN = new SLLNode < T > (d);
        NN->pNext = Head;
        Head = NN;
    }
    else{
        Head = new SLLNode < T > (d);
    }
    ListSize++;
}
template < class T >
void SLLinkedList<T>::pop_front(){
    if (isEmpty()) return;
    ListSize--;
    SLLNode < T > *cur = Head;
    Head = Head->pNext;
    delete cur;
}
template < class T >
bool SLLinkedList<T>::isEmpty(){
    return size() == 0;
}
template < class T >
void SLLinkedList<T>::remove(const std::function < bool(T) > &equalK){
    if (isEmpty()) return;
    if (equalK(Head->data)){
        pop_front();
    }
    else{
        SLLNode < T > *cur = Head;
        while (cur->pNext && !equalK(cur->pNext->data)) cur = cur->pNext;
        if (cur->pNext){
            SLLNode < T > *N = cur->pNext;
            cur->pNext = N->pNext;
            delete N;
            ListSize--;
        }
    }
}
template < class T >
int SLLinkedList<T>::size(){
    return ListSize;
}
template < class T >
SLLinkedList<T>::~SLLinkedList(){
    while (!isEmpty()) pop_front();
}

#endif // __LINKED_LIST_CPP
