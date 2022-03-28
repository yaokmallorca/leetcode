// Example program
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;
// using TP = tuple<int, string, int, int>;
using TP = pair<int, pair<string, std::vector<int> > >;

int main()
{
    // priority_queue< tuple<int, string, int, int>, greater<> > pq;
    priority_queue<TP, vector<TP>, greater<>>pq; 
    pq.push({2, {"LU", {3, 1}}});
    pq.push({0, {"LU", {1, 1}}});
    pq.push({0, {"R",  {1, 3}}});
    pq.push({2, {"U",  {3, 3}}});
    
    while (!pq.empty()) {
        // auto [d, s, x, y] = pq.top(); pq.pop();
        // cout << d << ", " << s << ", " << x << ", " << y << endl;
        auto item = pq.top(); pq.pop();
        cout << item.first << ", " << 
                item.second.first << ", " << 
                item.second.second[0] << ", " << 
                item.second.second[1] << endl;
    }    
    return 0;
}
