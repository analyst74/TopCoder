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

class PackingBallsDiv2 {
public:
    int minPacks(vector<int> balls) {
        int result;
        if (balls.size() == 1) {
            result = balls.back();
            balls.pop_back();
            result = result / 3 + (result%3==0?0:1);
        }
        else {
            vector<int>::iterator min = min_element(balls.begin(), balls.end());
            result = *min;            
            balls.erase(min);
            for (int i=0; i<balls.size(); i++) {
            	balls[i] -= result;
            }
            
            result += this->minPacks(balls);
        }
            
        return result;
    }
    
	int minPacks(int R, int G, int B) {
        int result;
		int temp[] = {R,G,B};
		vector<int> balls (temp, temp + sizeof(temp) / sizeof(int));
        
        // 3 balls        
        vector<int>::iterator min = min_element(balls.begin(), balls.end());
        result = *min;            
        balls.erase(min);
        for (int i=0; i<balls.size(); i++) {
            balls[i] -= result;
        }
        
		return result;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!