#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largest(vector<int>& arr) {
        // Method 1: Using built-in max_element function
        // return *max_element(arr.begin(), arr.end());
        
        // Method 2: Manual approach
        int maxElement = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }
        return maxElement;
    }
};

int main() {
    Solution solution;
    
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    
    if (n <= 0) {
        cout << "Array size should be positive!" << endl;
        return 1;
    }
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = solution.largest(arr);
    cout << "The largest element in the array is: " << result << endl;
    
    return 0;
}