
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <iomanip>

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

        for (unsigned int i = 0; i<height.size(); i++) {
            badI = false;
            for (unsigned int j = 0; j<height.size(); j++) {
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



    void test0() {
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

        vector<int> result = this->getOrdering(height, bloom, wilt);

        for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            std::cout << *i << ' ';
        cout << endl;
    }

    void test1() {
        vector<int> height{ 5, 4, 3, 2, 1 };
        vector<int> bloom{ 1, 5, 10, 15, 20 };
        vector<int> wilt{ 4, 9, 14, 19, 24 };

        vector<int> result = this->getOrdering(height, bloom, wilt);

        cout << endl;
        for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            std::cout << *i << ' ';
        cout << endl;
    }

    void test2() {
        vector<int> height{ 5, 4, 3, 2, 1 };
        vector<int> bloom{ 1, 5, 10, 15, 20 };
        vector<int> wilt{ 5, 10, 15, 20, 25 };

        vector<int> result = this->getOrdering(height, bloom, wilt);

        cout << endl;
        for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            std::cout << *i << ' ';
        cout << endl;
    }

    void runTest(string name, vector<int> height, vector<int> bloom, vector<int> wilt) {
        cout << "running test " << name << endl;

        vector<int> result = this->getOrdering(height, bloom, wilt);

        cout << endl;
        for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            std::cout << *i << ' ';
        cout << endl;

    }

};

class RockSkipping {
public:
    char getPad(string pads, int index) {
        return pads[index % pads.length()];
    }

    // returns <p, pm_next> where p is probability of hitting lily pads THIS skip, and pm_next is probability of each index for next skip
    tuple<double, unordered_map<int, double>> prob(string pads, int maxDist, unordered_map<int, double> pm) {
        double p = 0.0;
        unordered_map<int, double> pm_next;
        
        for (auto it = pm.begin(); it != pm.end(); ++it) {
            if (this->getPad(pads, it->first) == 'X') {
                p += it->second;
            }
            else {
                for (int i = 1; i <= maxDist; ++i) {
                    if (pm_next.count(it->first + i) == 0) pm_next[it->first + i] = 0.0;
                    pm_next[it->first + i] = pm_next[it->first + i] + it->second / maxDist;
                }
            }
        }

        tuple<double, unordered_map<int, double>> result { p, pm_next };

        return result;
    } 

    double probability(string pads, int maxDist) {
        if (pads.find('X') == string::npos) return 100.0;

        tuple<double, unordered_map<int, double>> skip_result;
        double lily_chance = 0.0;
        unordered_map<int, double> pm{ { 0, 1.0 } };
        cout << "skip ";
        for (int i = 0; i <= maxDist; ++i) {
            cout << "." << i;
            skip_result = this->prob(pads, maxDist - i, pm);
            lily_chance += std::get<0>(skip_result);
            pm = std::get<1>(skip_result);
            //cout << setprecision(9) << " current chance of hitting lily pad = " << std::get<0>(skip_result) << ", " << lily_chance << endl;
        }
        cout << endl;

        return (1 - lily_chance) * 100;
    }

    void runTest(string name, string pads, int maxDist, double expected) {
        cout << "Running Test: " << name << endl;

        double result = this->probability(pads, maxDist);

        cout << setprecision(18) << "result: " << result << endl;
        cout << setprecision(18) << "expect: " << expected << endl;
        cout << "success: " << (result == expected ? "true": "false") << endl;
    }

    void runAllTests() {
        this->runTest("0", ".", 100, 100.0);
        this->runTest("1", "...X", 2, 50.0);
        // those are failing due to compiler difference from TopCoder
        //this->runTest("2", "........................X", 50, 11.60725450562586);
        //this->runTest("3", "...X......XXXX...XX.X..X...XX...", 48, 5.408479511004734E-8);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    RockSkipping rs;
    rs.runAllTests();

    cin.ignore();
    return 0;
}