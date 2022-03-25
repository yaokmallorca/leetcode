#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

class Solution
{
public:
	double minmaxGasDistGreedy(std::vector<int>& gasStops, int K) {
		priority_queue< pair<double, int> > pq;
		for (int i = 1; i < gasStops.size(); ++i) {
			/* code */
			pq.push({gasStops[i] - gasStops[i-1], 1});
		}
		for (int i = 0; i < K; ++i) {
			/* code */
			double space = pq.top().first;
			int num = pq.top().second;
			pq.pop();
			double space_org = space * num;
			double new_space = space_org / (num + 1);
			pq.push({new_space, num + 1});
		}
		return pq.top().first;
	}

	double minmaxGasDist(std::vector<int> gasStops, int K) {
		double left = 0, right = 1e8;
		while (right - left > 1e-6) {
			double mid = left + (right - left) / 2.f;
			if (isOK(mid, K, gasStops)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return left;
	}

private:
	bool isOK(double mid, int K, std::vector<int> stops) {
		int cnt = 0, n = stops.size();
		for (int i = 0; i < n-1; ++i) {
			/* code */
			cnt += (stops[i+1] - stops[i]) / mid;
		}
		return cnt <= K;
	}
};

int main(int argc, char const *argv[])
{
	// std::vector<int> gasStops = {10, 19, 25, 27, 56, 63, 70, 87, 96, 97};
	std::vector<int> gasStops = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	Solution s;
	cout << s.minmaxGasDist(gasStops, 9) << endl;


	return 0;
}