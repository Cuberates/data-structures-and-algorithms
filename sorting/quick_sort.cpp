// Nguyen Xuan Viet Duc
// Affiliation: VNU University of Information Technology
// MIT License applies.

#include <iostream> 

void swap (int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

int partition (int arr[], int low, int high) {
   int pivot = arr[low]; // Using the leftmost element as the pivot
   int i = low, j = high;
   while (i < j) {
      // Increase i until arr[i] >= pivot and decrease j until arr[j] < pivot
      while(arr[i] <= pivot) i++;
      while(arr[j] >  pivot) j--;
      // Swap arr[j] and arr[i]
      if(i < j)
         swap(arr[j], arr[i]);
   }
   swap(arr[low], arr[j]);
   return j;
}

void quick_sort (int arr[], int low, int high) { 
   if(low < high) {
      int pi = partition (arr, low, high);
      quick_sort (arr, low, pi - 1);  // Doing quick_sort on the left half of the partition
      quick_sort (arr, pi + 1, high);  // Doing quick_sort on the right half of the partition
   }
}

// Time : O(nlog(n))
// Space : O(1)

int main (void) {
   // The following code is for handling IO
   freopen("unsorted.txt", "r", stdin);
   freopen("sorted.txt", "w", stdout);
   const int arr_size = 50000;
   int arr[arr_size];
   for(int i = 0; i < arr_size; i++) std::cin >> arr[i];
   quick_sort (arr, 0, arr_size - 1);
   for(int i = 0; i < arr_size; i++) std::cout << arr[i] << "\n";
}
