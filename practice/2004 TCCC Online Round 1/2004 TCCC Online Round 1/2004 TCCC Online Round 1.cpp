// 2004 TCCC Online Round 1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class FlowerGarden {
public:
    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
        vector <int> result;

        while (height.size() > 0) {
            int tallestIndex = this->getNext(height, bloom, wilt);
            
            int next = height[tallestIndex];
            height.erase(height.begin() + tallestIndex);
            bloom.erase(bloom.begin() + tallestIndex);
            wilt.erase(wilt.begin() + tallestIndex);

            result.push_back(next);
        }

        return result;
    }

    int getNext(vector <int> height, vector <int> bloom, vector <int> wilt) {
        if (height.size() == 1)
            return 0;

        int tallestIndex = -1;
        bool badI;

        for (int i = 0; i<height.size(); i++) {
            badI = false;
            for (int j = 0; j<height.size(); j++) {
                if (i == j) continue;

                if (height[i] > height[j] && bloom[i] <= wilt[j] && wilt[i] >= bloom[j]) {
                    badI = true;
                    break;
                }
            }

            if (badI == false && (tallestIndex == -1 || height[tallestIndex] < height[i])) {
                // cout << "tallestIndex = " << tallestIndex << " ";
                // cout << "i = " << i << " " << height[i] << endl;
                tallestIndex = i;
            }
        }

        // cout << "found tallestIndex " << tallestIndex << " " << height[tallestIndex] << endl;
        return tallestIndex;
    }
};

void test0() {
    FlowerGarden fg;

    vector<int> height;
    height.push_back(5);
    height.push_back(4);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);

    vector<int> bloom;
    bloom.push_back(1);
    bloom.push_back(1);
    bloom.push_back(1);
    bloom.push_back(1);
    bloom.push_back(1);

    vector<int> wilt;
    wilt.push_back(365);
    wilt.push_back(365);
    wilt.push_back(365);
    wilt.push_back(365);
    wilt.push_back(365);

    vector<int> result = fg.getOrdering(height, bloom, wilt);

    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;
}

void test1() {
    FlowerGarden fg;

    vector<int> height{ 5, 4, 3, 2, 1 };
    vector<int> bloom{ 1, 5, 10, 15, 20 };
    vector<int> wilt{ 4, 9, 14, 19, 24 };

    vector<int> result = fg.getOrdering(height, bloom, wilt);

    cout << endl;
    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;
}

void test2() {
    FlowerGarden fg;

    vector<int> height{ 5, 4, 3, 2, 1 };
    vector<int> bloom{ 1, 5, 10, 15, 20 };
    vector<int> wilt{ 5, 10, 15, 20, 25 };

    vector<int> result = fg.getOrdering(height, bloom, wilt);

    cout << endl;
    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;
}

void runTest(string name, vector<int> height, vector<int> bloom, vector<int> wilt) {
    cout << "running test " << name << endl;

    FlowerGarden fg;

    vector<int> result = fg.getOrdering(height, bloom, wilt);

    cout << endl;
    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Hello World" << endl;
    test0();
    test1();
    test2();
    runTest("3", { 5, 4, 3, 2, 1 }, {1, 5, 10, 15, 20}, {5, 10, 14, 20, 25});

    cin.ignore();
    return 0;
}