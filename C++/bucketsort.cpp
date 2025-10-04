#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;

// Function to perform bucket sort
void bucketSort(vector<float> &arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1. Create n empty buckets
    vector<vector<float>> buckets(n);

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // assuming arr[i] in range [0,1)
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original array: ";
    for (float num : arr) cout << num << " ";
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
