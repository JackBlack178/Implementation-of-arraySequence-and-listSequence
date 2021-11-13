//
// Created by crake on 20.09.2021.
//

#ifndef SORTING_LINKEDLIST_H
#define SORTING_LINKEDLIST_H

#include "indexOutOfRange.h"

template <typename T>
class element{
public:
    T data;
    element<T>* next;
    element<T>* back;
};


template <typename T>
class linkedList {
private:
    int length = 0;
    element <T> *head = nullptr;
    element <T> *end = nullptr;
public:

    linkedList() = default;


    ~linkedList() {
        element<T>* el = head;
        element<T>* el2;
        while(el) {
            el2 = el->next;
            delete el;
            el = el2;
        }
    }

    linkedList (const linkedList <T>& newList){
        length = newList.length;
        element<T> *el= newList.head;
        while(el != nullptr){
            append(el->data);
            el = el->next;
        }
    }

    void prepend(T value) {
        auto *element1 = new element<T>;
        element1->data = value;
        element1->next = nullptr;
        element1->back = nullptr;
        length++;
        if (head == nullptr){
            head = element1;
            end = element1;
            return;
        }
        element1->next = head;
        head = element1;
    }

    T& operator [] (int index) {
        if (index < 0 || index >= length)
            throw IndexOutOfRange();

        element<T> *el = head;

        T data;

        for (int i = 0; i < index; i++, el = el->next);
        return el->data;
    }

    void append(T value) {
        auto *el = new element<T>;
        el->data = value;
        el->next = nullptr;

        if (head == nullptr) {
            head = el;
            end = el;
            length = 1;
            return;
        }
        length = length + 1;
        end->next = el;
        end = el;

    }

    void swap(int index1, int index2) {
        if (index1 >= length || index2 >= length)
            throw IndexOutOfRange();

        if (index1 == index2)
            return;

        if (index1 > index2) {
            int temp = index1;
            index1 = index2;
            index2 = temp;
        }


        element<T>* el1 = head;
        for (int i = 0; i < index1; i++, el1 = el1->next);

        element<T>* el2 = head;
        for (int i = 0; i < index2; i++, el2 = el2->next);
        T temp = el1->data;
        el1->data = el2->data;
        el2->data = temp;

    }

    T getFirst() {
        if (head == nullptr) throw IndexOutOfRange();
        return head->data;
    }

    T getLast() {
        if (head == nullptr) throw IndexOutOfRange();
        return end->data;
    }

    T get(int index){
        if(head == nullptr) throw IndexOutOfRange();
        if (index >= length|| index<0 ) throw IndexOutOfRange();
        element<T> *el = head;

        for (int i = 0; i < index; i++, el = el->next);

        return el->data;
    }

    T get(size_t index) {
        if (index >= length)
            throw IndexOutOfRange();

        if (index == length - 1)
            return end->item;

        element<T>* elem = head;
        for (size_t i = 0; i < index; i++, elem = elem->next);

        return elem->item;
    }

    void set(T value, int index) {
        if (index >= length || index < 0)
            throw IndexOutOfRange();

        element<T>* elem = head;
        for (int i = 0; i < index; i++, elem = elem->next);

        elem->data = value;
    }


    int getLength() {
        return length;
    }

    void insert(T value, int index) {
        if (index < 0 || index >= length) throw IndexOutOfRange();

        if (index == 0) {
            prepend(value);
            return;
        }
        if (index == length - 1) {
            append(value);
            return;
        }

        element<T> *el = head;

        for (int i = 0; i < index - 1; i++, el = el->next);

        auto *elNew = new element<T>;
        elNew->next = el->next;
        elNew->data = value;
        el->next = elNew;
        length++;
    }

    T pop(int index) {
        if (index < 0 || index >=  length) throw IndexOutOfRange();

        element<T> *el1 = head;
        element<T> *el2 = nullptr;

        T value;

        for (int i = 0; i < index; i++, el2 = el1, el1 = el1->next);

        value = el1->data;

        if (el2 == nullptr) {
            head = el1->next;
        }
        else {
            el2->next = el1->next;
        }
        delete el1;
        length--;
        return value;
    }

    T pop(){
        return pop(length - 1);
    }
};



#endif //SORTING_LINKEDLIST_H
