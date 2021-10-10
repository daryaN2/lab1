//
// Created by Darya on 03.10.2021.
//
#include "Counter.h"

int Counter::Count (std::string fin) {
    std::ifstream fin(fin);
    if (!fin) {
        return 0;
    } else {
        count = 0;
        while(getline(fin, str)) {
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
        fin.close();
        return 1;
    }
}

int Counter:: Output (std::string fout) {
    std::ofstream fout(fout);
    if (!fout) {
        return 0;
    } else {
        std::vector <pair <std::string, double>> frequency;
        for (auto i : words) {
            frequency.emplace_back(make_pair(i.first, (double) i.second / count));
        }
        sort (freq.rbegin(), freq.rend());
        for (auto i : frequency) {
            fout << i.first << << "," << words[i.first] << "," << i.second << "\n";
        }
        fout.close();
        return 1;
    }
}