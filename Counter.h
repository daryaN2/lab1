//
// Created by Darya on 03.10.2021.
//
#ifndef LAB1_COUNTER_H
#define LAB1_COUNTER_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <utility>
#include <algorithm>

class Counter
{
public:
    int Count(std::string fin);
    int Output(std::string fout);
private:
    int count;
    std::string str;
    std::string word;
    std::map <std::string, int> words;
};
#endif //LAB1_COUNTER_H

