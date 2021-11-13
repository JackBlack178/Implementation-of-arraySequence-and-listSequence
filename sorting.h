//
// Created by crake on 04.09.2021.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H
#include "Person.h"
#include "sequence.h"


template<typename T>
sequence<T>* bubbleSort(sequence<T> *seq, int start, int end, int cmp(T, T)){

    sequence<T> *newArray = seq->copySequence();


    int length = newArray->getLength();

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (cmp(newArray->get(j), newArray->get(j + 1))) {
                newArray->swap(j,j+1);
            }
        }
    }
    return newArray;
}


template<typename T>
sequence<T>* quickSort(sequence<T> *seq, int start, int end, int cmp(T, T)){

    sequence<T> *newSeq = seq->copySequence();
    quickSortPrivate(newSeq, start, end - 1, cmp);
    return newSeq;


}

template<typename T>
void quickSortPrivate(sequence<T> *seq, int start, int end, int cmp(T, T)){
    int i = start;
    int j = end;
    T centerElement = seq->get((i+j)/2);



    while (i <= j)
    {

        while (cmp(centerElement, seq->get(i)))
            i++;
        while (cmp(seq->get(j), centerElement))
            j--;
        if (i <= j)
        {
            seq->swap(i,j);
            i++;
            j--;
        }
    }
    if (j > start)
        quickSortPrivate(seq, start, j, cmp);
    if (i < end)
        quickSortPrivate(seq, i, end, cmp);
}



template<typename T>
sequence<T>* insertionSort(sequence<T> *seq, int start, int end, int cmp(T, T)){
    int i, j;
    T key;
    sequence<T> *newSeq = seq->copySequence();
    for (i = 1; i < end; i++)

    {
        key = newSeq->get(i);
        j = i - 1;

        while (j >= 0 && cmp(newSeq->get(j), key))
        {
            newSeq->set(newSeq->get(j),j+1);
            j = j - 1;
        }
        newSeq->set(key,j+1);
    }
    return newSeq;
}


#endif //SORTING_SORTING_H
