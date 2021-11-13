//
// Created by Ilyas on 10.10.2021.
//

#ifndef SORTING_MENU_H
#define SORTING_MENU_H
#include "Person.h"
#include "arraySequence.h"
#include "iostream"
#include "printFunction.h"
#include "sorting.h"
#include "test.h"
#include <ctime>
#include <chrono>
#include "chrono"
#include "Sort.h"


using namespace std;







float randomFloatNumber() {
    return (float)randomIntNumber() + (float)randomIntNumber()/(float)randomIntNumber();
}

Person randomPerson() {
    Person person{randomIntNumber(), randomIntNumber() % 200};
    return person;
}


template <typename T>
T createNumberManually(){
    int number;
    cin >> number;
    return number;
}

Person createPersonManually(){
    Person person{};
    int ID, age;
    cout << "Enter ID\n";
    cin >> ID;
    cout << "Enter age\n";
    cin >> age;
    person.ID = ID;
    person.age = age;
    return person;

}

int getNumberInRange(int down, int up){
    while(true){
        int number;
        cin >> number;
        if (number <= up and number >= down)
            return number;
    }
}



template<class T>
void createArrayAutomatically(arraySequence<arraySequence<T>*>* array, T func()){
    auto* newArray = new arraySequence<T>;
    int length = randomLength();
    for (int i = 0; i < length; i++){
        newArray->append(func());
    }
    array->append(newArray);
}

template<class T>
void createArrayManually(arraySequence<arraySequence<T>*>* array, T createElement()){
    int length = randomIntNumber();
    cout << "Enter a length in the range from 1 to 100" << endl;
    length = getNumberInRange(1,100);
    auto* newArray = new arraySequence<T>;
    for (int i = 0; i <  length; i++){
        cout << "[" << i << "] element =" << endl;
        newArray->append(createElement());

    }
    array->append(newArray);

}


void createArray(arraySequence<arraySequence<int>*> *arrayInt, arraySequence<arraySequence<float>*> *arrayfloat, arraySequence<arraySequence<Person>*> *arrayPerson){
    int manageNumber;
    cout << "Would you like to create an array automatically or manually?" << endl;
    cout << "Enter 1 - To create automatically" << endl;
    cout << "Enter 2 - To create manually" << endl;
    cout << "Enter 3 - To cancel" << endl;
    manageNumber = getNumberInRange(1,3);
    int type;
    if (manageNumber == 3)
        return;

    printTypes();
    type = getNumberInRange(1,4);

    if (manageNumber == 1){
        switch(type){
            case 1:createArrayAutomatically(arrayInt, randomIntNumber);return;;
            case 2:createArrayAutomatically(arrayfloat, randomFloatNumber);return;;
            case 3:createArrayAutomatically(arrayPerson, randomPerson);return;;
            default:return;
        }
    }

    switch(type){
        case 1: createArrayManually(arrayInt, createNumberManually);return;
        case 2: createArrayManually(arrayfloat, createNumberManually);return;
        case 3: createArrayManually(arrayPerson, createPersonManually);return;
        default:return;
    }
}




template<class T>
void deleteArraySpecificType(arraySequence<arraySequence<T>*>* array, void print(T)){
    if (array->getLength() == 0){
        cout << "There is no array with this type" << endl;
        return;
    }

    for (int i = 0; i < array->getLength(); i++){
        cout << "Array [" << i << "] :" << endl;
        for (int j = 0; j < array->get(i)->getLength(); j++){
            print(array->get(i)->get(j));
        }
    }

    int index;
    printDelete();
    index = getNumberInRange(-1,array->getLength() - 1);
    if (index == -1){
        return;
    }
    array->pop(index);

}


void deleteArray(arraySequence<arraySequence<int>*> *arrayInt, arraySequence<arraySequence<float>*> *arrayFloat, arraySequence<arraySequence<Person>*> *arrayPerson){
    printTypes();
    int type = getNumberInRange(1,4);
    switch(type){
        case 1:deleteArraySpecificType(arrayInt, printNumber);return;
        case 2:deleteArraySpecificType(arrayFloat, printNumber);return;
        case 3:deleteArraySpecificType(arrayPerson, printPerson);return;
        default:return;
    }
}

template<class T>
void sortArraySpecificType(arraySequence<arraySequence<T>*>* array, void print(T), int cmp(T, T)){
    if (array->getLength() == 0){
        cout << "There is no array with this type" << endl;
        return;
    }

    for (int i = 0; i < array->getLength(); i++){
        cout << "Array [" << i << "] :" << endl;
        for (int j = 0; j < array->get(i)->getLength(); j++){
            print(array->get(i)->get(j));
        }
        cout << endl;
    }

    int index;
    printSort();
    index = getNumberInRange(-1,array->getLength() - 1);
    if (index == -1){
        return;
    }
    printSortFunctions();
    int sortNumber = getNumberInRange(1,4);
    arraySequence<T>* newArray;

    switch(sortNumber){
        case 1:newArray = new arraySequence<T>(bubbleSort(array->get(index), 0, array->get(index)->getLength(), cmp));break;
        case 2:newArray = new arraySequence<T>(quickSort(array->get(index), 0, array->get(index)->getLength(), cmp));break;
        case 3:newArray = new arraySequence<T>(insertionSort(array->get(index), 0, array->get(index)->getLength() , cmp));break;
        default:return;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < newArray->getLength(); i++){
        print(newArray->get(i));
    }
    cout << endl;
    sortMenu();
    sortNumber = getNumberInRange(1,3);
    if (sortNumber == 1){
        delete newArray;
        return;
    }

    if (sortNumber == 2){
        array->append(newArray);
    }

    if (sortNumber == 3){
        array->pop(index);
        if (array->getLength()-1>= index){
            array->insert(newArray, index);
            return;
        }
        array->append(newArray);

    }
}

void sort(arraySequence<arraySequence<int>*> *arrayInt, arraySequence<arraySequence<float>*> *arrayFloat, arraySequence<arraySequence<Person>*> *arrayPerson){
    printTypes();
    int type = getNumberInRange(1,4);
    switch(type){
        case 1:sortArraySpecificType(arrayInt, printNumber, isNumberBigger);return;
        case 2:sortArraySpecificType(arrayFloat, printNumber, isNumberBigger);return;
        case 3:sortArraySpecificType(arrayPerson, printPerson, isPersonBigger);return;
        default:return;
    }
}

void launchTest(){
    cout << "Array tests" << endl;
    arrayTests();
    cout << "Sorting tests" << endl;
    sortingTests();
}

template <typename T>
arraySequence<T>* randomArray(T func()){
    auto* array = new arraySequence<T>;
    for (int i = 0; i < randomLength() ; i++){
        array->append(func());
    }
    return array;
}

template <typename T>
arraySequence<T>* randomArraySpecificLength(T func(), int length){
    auto* array = new arraySequence<T>;
    for (int i = 0; i < length ; i++){
        array->append(func());
    }
    return array;
}


void printInfoSortingArrays(double durationBubbleSort, double durationQuickSort, double durationInsertionSort, int number){
    cout << "sort int arrays"<< endl;
    cout << "Bubble sort average time : " << durationBubbleSort * 1000 / number << " ms" << endl;
    cout << "Quick sort average time : " << durationQuickSort * 1000 / number <<  " ms" << endl;
    cout << "Insertion sort average time : " << durationInsertionSort * 1000 / number<< " ms" << endl;
}



void sortingLotsOfArrays(int number, int length){

    arraySequence<arraySequence<int>>arrays;
    for (int i = 0; i < number; i++){
        arrays.append(randomArraySpecificLength(randomIntNumber, length));
    }

    SortObject<int> bubbleSortObject("Bubble Sort", bubbleSort<int>, isNumberBigger);
    SortObject<int> quickSortObject("Quick Sort", quickSort<int>, isNumberBigger);
    SortObject<int> insertionSortObject("Insertion Sort", insertionSort<int>, isNumberBigger);

    double bubbleSortDuration = 0;
    double quickSortDuration = 0 ;
    double insertionSortDuration = 0;


    timeInfo time;
    time.reset();
    for (int i = 0; i < number; i++)
        bubbleSortObject.sort(&arrays.get(i));
//    bubbleSortDuration = bubbleSortDuration + time.getTime();
    bubbleSortDuration = time.getTime();
//    bubbleSortObject.getSortTime();



    time.reset();
    for (int i = 0; i < number; i++)
//         quickSortObject.sort(&arrays.get(i));
    quickSort(*arrays.get(i), 0, arrays.get(i).getLength(), isNumberBigger);
//    quickSortDuration = quickSortDuration + time.getTime();
   quickSortDuration = time.getTime();



    time.reset();
    for (int i = 0; i < number; i++)
        insertionSortObject.sort(&arrays.get(i));
    insertionSortDuration = time.getTime();
    time.reset();

    printInfoSortingArrays(bubbleSortDuration, quickSortDuration, insertionSortDuration, number);

}



void menu(){
    arraySequence<arraySequence<int>*> arrayInt;
    arraySequence<arraySequence<float>*> arrayFloat;
    arraySequence<arraySequence<Person>*> arrayPerson;
    int manageNumber;
    while(true){
        printMenu();
        manageNumber = getNumberInRange(1,7);
        switch (manageNumber) {
            case 1:
                createArray(&arrayInt, &arrayFloat, &arrayPerson);break;
            case 2: printAll(&arrayInt, &arrayFloat, &arrayPerson);break;
            case 3: sort(&arrayInt, &arrayFloat, &arrayPerson);break;
            case 4: deleteArray(&arrayInt, &arrayFloat, &arrayPerson);break;
            case 5: sortingLotsOfArrays(10, 10000);break;
            case 6: launchTest(); break;
            default:return;
        }
    }




}

#endif //SORTING_MENU_H
