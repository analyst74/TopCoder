#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Fragile2 {
    int countConnectedComponents(vector <string> & graph) {
        int result = 0;
        vector<int> counted;

        for (int i = 0; i < graph.size(); ++i) {
            result += findAllConnectedVertices(graph, i, counted);
        }

        return result;
    }

    // return 0 if i is already counted, 1 if i is not
    int findAllConnectedVertices(vector <string> & graph, int i, vector <int> & counted) {
        if (find(counted.begin(), counted.end(), i) == counted.end()) {
            counted.push_back(i);

            for (int j = 0; j < graph.size(); ++j) {
                if (graph[i][j] == 'Y') findAllConnectedVertices(graph, j, counted);
            }

            return 1;
        }

        return 0;
    }

    vector <string> cull(vector <string> graph, int i, int j) {
        graph.erase(graph.begin() + i);
        for (int a = 0; a < graph.size(); ++a) {
            graph[a].erase(j, 1);
        }
        return graph;
    }

public:

    int countPairs(vector <string> graph) {
        int result = 0;
        int originalSize = countConnectedComponents(graph);
        vector<string> temp;

        for (int i = 0; i < graph.size(); ++i) {
            for (int j = i + 1; j < graph.size(); ++j) {
	            temp = cull(graph, i, j);
                if (countConnectedComponents(temp) > originalSize) ++result;
            }
        }

        return result;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Fragile2 *obj;
	int answer;
	obj = new Fragile2();
	clock_t startTime = clock();
	answer = obj->countPairs(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"NYNN","YNYN","NYNY","NNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"NYNNNN","YNYNNN","NYNNNN","NNNNYN","NNNYNY","NNNNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"NNN","NNN","NNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"NYNYNNYYNN","YNNNYNYYNN","NNNNYNNNYN","YNNNYYNNNN","NYYYNNNNYN","NNNYNNNNYN","YYNNNNNNNN","YYNNNNNNYN","NNYNYYNYNY","NNNNNNNNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"NNNYNNYNNNNNNNYYNNNY","NNNNNNNNYNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNN","YNNNNNNNNNYNNNNNNNNN","NNNNNNNYNNNNNYNNNNYN","NNNNNNNNNNNNNNNNYNNY","YNNNNNNNNNNNNYYYNYNN","NNNNYNNNNNNNNYYNNNNN","NYNNNNNNNYNNNNNNNNNN","NNNNNNNNYNNNYNNNNNYN","NNNYNNNNNNNNNNYNNNNN","NNNNNNNNNNNNNNNNNNNN","NNNNNNNNNYNNNNNNNYNN","NNNNYNYYNNNNNNNNNNNN","YNNNNNYYNNYNNNNNNNNN","YNNNNNYNNNNNNNNNYNNN","NNNNNYNNNNNNNNNYNYNN","NNNNNNYNNNNNYNNNYNNN","NNNNYNNNNYNNNNNNNNNN","YNNNNYNNNNNNNNNNNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 42;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"{{\"NYNNNN\", \"YNYNNN\", \"NYNNNN\", \"NNNNYN\", \"NNNYNY\", \"NNNNYN\"}}"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	all_right = KawigiEdit_RunTest(5, p0, false, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
