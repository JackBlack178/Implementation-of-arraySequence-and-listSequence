//
// Created by Ilyas on 31.10.2021.
//

#ifndef SORTING_SORT_H
#define SORTING_SORT_H
#include "sequence.h"
#include "string"
#include "vector"
#include "sorting.h"
#include <functional>
using namespace std;


class timeInfo{
private:

    std::chrono::time_point<std::chrono::high_resolution_clock> time;

public:
    timeInfo(): time(std::chrono::high_resolution_clock::now()) {}


    void reset() {
        time = std::chrono::high_resolution_clock::now();
    }

    double getTime(){
//
        return std::chrono::duration_cast<std::chrono::duration<double,std::ratio<1>>>(std::chrono::high_resolution_clock::now() - time).count();
    }

};



template <class T>
class SortObject : private timeInfo{
private:
    std::function<sequence<T>*(sequence<T>* , int, int, int cmp(T,T))> Sort;
    std::string NameOfSort;
    double time;
    int (*comparer)(int, int);





public:
    SortObject(std::string s, std::function<sequence<T>*(sequence<T>* , int, int, int cmp(T,T))> newSort, int cmp(T,T)) {
        NameOfSort = s;
        Sort = newSort;
        comparer = cmp;
    }

    sequence<T>* sort(sequence<T>*seq){
        reset();
        auto res = Sort(seq,0,seq->getLength(), comparer);
        time = getTime();
        return res;
    }

    double getSortTime(){
        return time;
    }

};



#endif //SORTING_SORT_H
