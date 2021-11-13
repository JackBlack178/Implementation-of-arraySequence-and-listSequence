//
// Created by crake on 20.09.2021.
//

#ifndef UNTITLED_LISTSEQUENCE_H
#define UNTITLED_LISTSEQUENCE_H
#include "Sequence.h"
#include "linkedList.h"

template <class T>
class listSequence : public sequence<T>{
private:
    linkedList<T> linkedList;
public:


    listSequence() = default;


    explicit listSequence(T value) {
        linkedList.append(value);
    }

    listSequence(const listSequence<T>& newListSeq) {
        linkedList = newListSeq.linkedList;
    }

    explicit listSequence(sequence<T>* newSequence) {
        for (size_t i = 0; i < newSequence->getLength(); i++)
            linkedList.append(newSequence->get(i));

    }


    T getFirst() {
        if (linkedList.getLength() == 0)
            throw IndexOutOfRange();

        return linkedList.getFirst();
    }



    T getLast() {
        if (linkedList.getLength() == 0)
            throw IndexOutOfRange();

        return linkedList.getLast();
    }


    T get(int index) {
        return linkedList.get(index);
    }



    T&  operator [] (int  index) {
        return linkedList[index];
    }


    void set(T value, int index) {
        linkedList.set(value, index);
    }

    void swap(int index1, int index2) {
        linkedList.swap(index1, index2);
    }


    int getLength(){
        return linkedList.getLength();
    }

    void append(T value) {
        linkedList.append(value);
    }

    void prepend(T value) {
        linkedList.prepend(value);
    }

    void insert (T value, int index) {
        linkedList.insert(value, index);
    }

    T pop() {
        return linkedList.pop();
    }

    T pop(int index) {
        return linkedList.pop(index);
    }

    sequence<T>* copySequence(){
        return new listSequence<T>(*this);
    }
};

#endif //UNTITLED_LISTSEQUENCE_H
