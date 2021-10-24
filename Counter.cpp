//
// Created by Darya on 03.10.2021.
//
#include "Counter.h"

int Counter::Count (std::string fin) {
    std::ifstream in(fin);
    if (!in) {
        return 0;
    } else {
        count = 0;
        while(std::getline(in, str)) {
            for (char& c : str) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                    word+=c;
                } else {
                    words[word]++;
                    count++;
                    word.clear();
                }
            }
        }
        in.close();
        return 1;
    }
}

int Counter:: Output (std::string fout) {
    std::ofstream out(fout);
    if (!out) {
        return 0;
    } else {
        std::list <std::pair <double, std::string>> wordList;
        std::map <std::string, int> :: iterator itW;
        for (auto itW = words.begin(); itW != words.end(); itW++) {
            wordList.emplace_back(std::make_pair(itW->second, itW->first));
        }
        wordList.sort();
        std::list <std::pair <double, std::string>>::iterator it;
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
            out << it->second << "," << it->first << "," << it->first*100/count << "\n";
        }
        out.close();
        return 1;
    }
}
