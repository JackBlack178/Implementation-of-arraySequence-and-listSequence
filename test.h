//
// Created by crake on 05.09.2021.
//

#ifndef SORTING_TEST_H
#define SORTING_TEST_H
#include "arraySequence.h"
#include "sorting.h"
#include "linkedList.h"
#include "listSequence.h"
#define maxNumber 10000
#define maxLength 20

template <typename T>
int isNumberBigger(T number1, T number2){
    return number1 > number2;
}


int isPersonBigger(Person person1, Person person2){
    return person1.ID < person2.ID;
}

int randomIntNumber() {
    return rand() % maxNumber;
}



int randomLength(){
    int number;
    while(true){
        number = randomIntNumber() % maxLength;
        if (number != 0)
            return number;
    }
}

using namespace std;


void bubbleSortTest() {
    int tests = 100000;
    int errors = 0;
    for (int test = 0; test < tests; test++) {
        int length = randomLength();
        arraySequence<int> array;
        for (int i = 0; i < length; i++) {
            array.append(rand() % 10000);
        }
        arraySequence<int>sortedSequence = arraySequence<int>(bubbleSort(&array, 0, array.getLength(), isNumberBigger));



        if (sortedSequence.getLength() != length){
            errors++;
        }

        for (int i = 0; i < length - 1; i++) {
            if (isNumberBigger(sortedSequence.get(i), sortedSequence.get(i + 1))) {
                errors++;
                break;
            }
        }
    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}




void quickSortTest() {
    int tests = 100000;
    int errors = 0;
    for (int test = 0; test < tests; test++) {
        int length = randomLength();
        arraySequence<int> array;
        for (int i = 0; i < length; i++) {
            array.append(rand() % 10000);
        }
        arraySequence<int>sortedSequence = arraySequence<int>(quickSort(&array, 0, array.getLength(), isNumberBigger));


        if (sortedSequence.getLength() != length){
            errors++;
        }

        for (int k = 0; k < sortedSequence.getLength() - 1; k++) {
            if (sortedSequence.get(k) > sortedSequence.get(k + 1)) {
                errors++;
                break;
            }
        }
    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}

void insertionSortTest() {
    int tests = 100000;
    int errors = 0;
    for (int test = 0; test < tests; test++) {
        int length = randomLength();
        arraySequence<int> array;
        for (int i = 0; i < length; i++) {
            array.append(rand() % 10000);
        }
        arraySequence<int>sortedSequence = arraySequence<int>(insertionSort(&array, 0, array.getLength(), isNumberBigger));


        if (sortedSequence.getLength() != length){
            errors++;
        }

        for (int i = 0; i < length - 1; i++) {
            if (isNumberBigger(sortedSequence.get(i), sortedSequence.get(i + 1))) {
                errors++;
                break;
            }
        }
    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}

void sortingTests(){
    bubbleSortTest();
    quickSortTest();
    insertionSortTest();
}

void dynamicArrayResizeTest(){
    dynamicArray<int> array;
    int tests = 100000;
    int errors = 0;
    for (int i = 0; i < tests; i++){
        int length = rand() % 1000;
        int* arr = new int[length];
        array.resize(length);
        int number;
        for (int k = 0; k < length; k++){
            number = rand() % 10000;
            arr[k] = number;
            array[k] = number;
        }

        for (int k = 0; k < array.getLength(); k++){
            if (array[k] != arr[k]){
                errors++;
                break;
            }
        }

    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}

void dynamicArrayGetTest(){
    dynamicArray<int>array;
    int tests = 10000;
    int errors = 0;
    for (int i = 0; i < tests; i++){
        int length = rand() % 10000;
        array.resize(length);
        int* arr = new int[length];
        int number;
        for (int k = 0; k < length; k++){
            number = rand() % 1000;
            arr[k] = number;
            array[k] = number;
        }

        for (int k = 0; k < length; k++){
            if (array[k] != arr[k])
                errors++;
        }
    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}


void arraySequenceGetTest(){
    arraySequence<int>array;
    int tests = 10000;
    int errors = 0;
    for (int i = 0; i < tests; i++){
        int length = rand() % 10000;
        int* arr = new int[length];
        int number;
        for (int k = 0; k < length; k++){
            number = rand() % 1000;
            arr[k] = number;
            array.append(0);
            array[k] = number;
        }

        for (int k = 0; k < length; k++){
            if (array.get(k) != arr[k])
                errors++;
        }
    }
    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}

void arraySequenceTestResize() {
    int tests = 10000;
    int errors = 0;
    for (int j = 0; j < tests; j++) {
        arraySequence<int>array;
        int length = rand() % 1000;
        for (int i = 0; i < length; i++) {
            array.append(i*i);
        }
        if (array.getLength() != length)
            errors++;

        for (int i = 0; i < length; i++) {
            array.prepend(i);
        }

        if (array.getLength() != length * 2)
            errors++;

        for (int i = 0; i < length * 2; i++) {
            array.pop();
        }

        if (array.getLength() != 0)
            errors++;
    }

    cout << tests << " tests were passed. " << errors << " errors were revealed \n";
}

void arrayTests(){
    arraySequenceGetTest();
    arraySequenceTestResize();
    dynamicArrayGetTest();
    dynamicArrayResizeTest();
}


#endif //SORTING_TEST_H