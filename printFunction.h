//
// Created by Ilyas on 10.10.2021.
//

#ifndef SORTING_PRINTFUNCTION_H
#define SORTING_PRINTFUNCTION_H
#include "iostream"
using namespace std;

template <typename T>
void printArray(arraySequence<T> *array, void print(T)){
    cout << "Array consists of " << array->getLength() << " numbers\n";
    for (int i = 0; i < array->getLength(); i++)
        print(array->get(i));
    cout << endl;
}


template <typename T>
void printNumber(T number){
    cout << number << " ";
}

void printPerson(Person person){
    cout << "ID: " << person.ID << "  Age: " << person.age << endl;
}

void printTypes(){
    cout << "Choose one type from" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - float" << endl;
    cout << "Enter 3 - Person" << endl;
    cout << "Enter 4 - Cancel" << endl;
}

void printMenu(){
    cout << "Enter 1 - To create an Array" << endl;
    cout << "Enter 2 - To print all arrays" << endl;
    cout << "Enter 3 - To sort an array" << endl;
    cout << "Enter 4 - To delete an array" << endl;
    cout << "Enter 5 - To run a lot of sorts and compare average and total time " << endl;
    cout << "Enter 6 - To launch tests" << endl;
    cout << "Enter 7 - To quit" << endl;

}

void printDelete(){
    cout << "Enter -1 - To cancel" << endl;
    cout << "Enter index - To delete an array " << endl;
}

void printSort(){
    cout << "Enter -1 - To cancel" << endl;
    cout << "Enter index - To choose array for sorting " << endl;
}

void printSortFunctions(){
    cout << "Enter 1 - Bubble Sort" << endl;
    cout << "Enter 2 - Quick Sort" << endl;
    cout << "Enter 3 - Insertion Sort" << endl;
    cout << "Enter 4 - To cancel" << endl;
}

void sortMenu(){
    cout << "Enter 1 - To quit(Array will be deleted)" << endl;
    cout << "Enter 2 - To save this array" << endl;
    cout << "Enter 3 - To replace the array" << endl;
}



void printAll(arraySequence<arraySequence<int>*> *arrayInt, arraySequence<arraySequence<float>*> *arrayfloat, arraySequence<arraySequence<Person>*> *arrayPerson){
    cout << "Number of int arrays " << arrayInt->getLength() << endl;
    for(int i = 0; i < arrayInt->getLength(); i++){
        cout << i + 1 << " array:" << endl;
        for (int j = 0; j < arrayInt->get(i)->getLength(); j++){
            cout << arrayInt->get(i)->get(j) << " ";
        }
        cout << endl;
    }

    cout << "Number of float arrays " << arrayfloat->getLength() << endl;
    for(int i = 0; i < arrayfloat->getLength(); i++){
        cout << i + 1 << " array:" << endl;
        for (int j = 0; j < arrayfloat->get(i)->getLength(); j++){
            cout << arrayfloat->get(i)->get(j) << " ";
        }
        cout << endl;
    }

    cout << "Number of person arrays " << arrayPerson->getLength() << endl;
    for(int i = 0; i < arrayPerson->getLength(); i++){
        cout << i + 1 << " array:" << endl;
        for (int j = 0; j < arrayPerson->get(i)->getLength(); j++){
            printPerson(arrayPerson->get(i)->get(j));
        }
        cout << endl;
    }
}



#endif //SORTING_PRINTFUNCTION_H
