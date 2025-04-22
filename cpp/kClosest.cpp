#include "base.h"

class Compare {
    public:
        vector<int> pointOfOrigin = {0, 0};
        double calculateEuclideandistance(vector<int> &point1, vector<int> &point2) {
            return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
        }
        double calculateEuclideandistanceWithOrigin(vector<int> &point1) {
            return calculateEuclideandistance(point1, pointOfOrigin);
        }
        bool operator()(vector<int> &a, vector<int> &b)
        {
            double firstPointDistFromOrigin = calculateEuclideandistanceWithOrigin(a);
            double secondPointDistFromOrigin = calculateEuclideandistanceWithOrigin(b);
            if (firstPointDistFromOrigin >= secondPointDistFromOrigin) {
                return true;
            }
            return false;
        }
};

class Solution
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
        {
            priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
            vector<vector<int>> closest;
            for (int i = 0; i < points.size(); i++)
            {
                pq.push(points[i]);
            }
            int size = points.size() - k;

            while (!pq.empty() && pq.size() != size)
            {
                closest.push_back(pq.top());
                pq.pop();
            }
            
            return closest;
        }
};
void printPoints(const vector<vector<int>> &points)
{
    cout << "[";
    for (size_t i = 0; i < points.size(); ++i)
    {
        cout << "[" << points[i][0] << "," << points[i][1] << "]";
        if (i < points.size() - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    Solution solution;

    // Compare compare;
    // vector<int> test = {1, 3};
    // cout << "test should be " << " 3.16228" << " and is  is " << compare.calculateEuclideandistanceWithOrigin(test) << endl;
    // Test Case 1
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    vector<vector<int>> expected1 = {{-2, 2}};
    vector<vector<int>> result1 = solution.kClosest(points1, k1);

    cout << "Test Case 1:\n";
    cout << "points = ";
    printPoints(points1);
    cout << ", k = " << k1 << "\nExpected Output: ";
    printPoints(expected1);
    cout << "\nActual Output: ";
    printPoints(result1);
    cout << "\n\n";

    // Test Case 2
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    vector<vector<int>> expected2 = {{3, 3}, {-2, 4}}; // Order may vary
    vector<vector<int>> result2 = solution.kClosest(points2, k2);

    cout << "Test Case 2:\n";
    cout << "points = ";
    printPoints(points2);
    cout << ", k = " << k2 << "\nExpected Output: ";
    printPoints(expected2);
    cout << "\nActual Output: ";
    printPoints(result2);
    cout << "\n\n";

    // Test Case 3
    vector<vector<int>> points3 = {{2, 2}, {2, 2}, {2, 2}};
    int k3 = 2;
    vector<vector<int>> expected3 = {{2, 2}, {2, 2}};
    vector<vector<int>> result3 = solution.kClosest(points3, k3);

    cout << "Test Case 3:\n";
    cout << "points = ";
    printPoints(points3);
    cout << ", k = " << k3 << "\nExpected Output: ";
    printPoints(expected3);
    cout << "\nActual Output: ";
    printPoints(result3);
    cout << "\n";

    return 0;
}
