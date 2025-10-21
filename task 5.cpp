#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int minSum(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<int> dp(triangle[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }

    return dp[0];
}




int main() {
    setlocale(LC_ALL, "rus");

    vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
    cout << "Ответ на первый пример triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]: " << minSum(triangle) << endl;
    triangle = { {-1}, {2, 3}, {1, -1, -3}, {4, 2, 1, 3} };
    cout << "Ответ на второй пример triangle = [[-1],[2,3],[1,-1,-3],[4,2,1,3]]:" << minSum(triangle) << endl;

    return 1;
}