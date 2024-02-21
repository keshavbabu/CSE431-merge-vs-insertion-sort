#include <bits/stdc++.h>
#include <ctime>

using namespace std;
 
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void test(int n) {
  std::clock_t start_time = std::clock();

  int mergeArr[n];
  for(int i = 0;i<n;i++){ mergeArr[i] = n - i; }
  int mergeArrSize = sizeof(mergeArr) / sizeof(mergeArr[0]);
  mergeSort(mergeArr, 0, mergeArrSize - 1);

  std::clock_t merge_time = std::clock() - start_time;
  start_time = std::clock();

  int insertionArr[n];
  for(int i = 0;i<n;i++){ insertionArr[i] = n - i; }

  int insertionArrSize = sizeof(insertionArr) / sizeof(insertionArr[0]);
  insertionSort(insertionArr, insertionArrSize);

  std::clock_t insertion_time = std::clock() - start_time;
  double mergeTimeSeconds = ((double) merge_time) / (double) CLOCKS_PER_SEC;
  double insertionTimeSeconds = ((double) insertion_time) / (double) CLOCKS_PER_SEC;
  std::cout << std::fixed << mergeTimeSeconds << " " << insertionTimeSeconds << std::endl;
}

int main() {
  vector<double> avg;
  for(int i = 5;i<200;i++){
    test(i);
  }
  return 0;
}
