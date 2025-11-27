#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
using namespace std;

int main() {
    srand(time(0)); 

    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    vector<int> a(n);

   
    for_each(a.begin(), a.end(), [](int& x) {
        x = rand() % 201 - 100; 
        });


    cout << "Generated array: ";
    for (int x : a) cout << x << " ";
    cout << endl;


    int sumPositive = accumulate(a.begin(), a.end(), 0, [](int sum, int x) 
        {
        return x > 0 ? sum + x : sum;
        });

    
    auto maxIt = max_element(a.begin(), a.end(), [](int x, int y)
        {
        return abs(x) < abs(y);
        });

    auto minIt = min_element(a.begin(), a.end(), [](int x, int y)
        {
        return abs(x) < abs(y);
        });

   
    int maxAbsIndex = distance(a.begin(), maxIt);
    int minAbsIndex = distance(a.begin(), minIt);

    int start = min(maxAbsIndex, minAbsIndex);
    int end = max(maxAbsIndex, minAbsIndex);

    long long product = 1;
    if (end - start <= 1) product = 0;
    else for (int i = start + 1; i < end; i++) product *= a[i];

    sort(a.begin(), a.end(), greater<int>());

    
    cout << "Sum of positive elements = " << sumPositive << endl;
    cout << "Product between min| | and max| | = " << product << endl;

    cout << "Array after sorting in descending order: ";
    for (int x : a) cout << x << " ";
    cout << endl;
}
