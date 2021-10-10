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
        std::vector <std::pair <std::string, double>> frequency;
        for (auto i : words) {
            frequency.emplace_back(make_pair(i.first, (double) i.second / count));
        }
        std::sort (frequency.rbegin(), frequency.rend());
        for (auto i : frequency) {
            out << i.first << "," << words[i.first] << "," << i.second << "\n";
        }
        out.close();
        return 1;
    }
}
