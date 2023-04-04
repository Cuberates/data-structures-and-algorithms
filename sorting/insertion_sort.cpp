#include <iostream> 

void swap (int &a, int &b) {
   int temp = a;
   b = a; 
   a = temp;
}

void insertion_sort (int arr[], int arr_size) {
   for(int i = 1; i < arr_size; i++) {
      int j = i - 1, current = arr[i];
      while (j >= 0 && current <= arr[j]) {
         arr[j + 1] = arr[j]; // Move the element over by one position
         j--;
      }
      arr[j + 1] = current; // The element is in its correct (sorted) place 
   }
}

int main (void) {
   // The following code is for handling IO
   freopen("unsorted.txt", "r", stdin);
   freopen("sorted.txt", "w", stdout);
   const int arr_size = 50000;
   int arr[arr_size];
   for(int i = 0; i < arr_size; i++) std::cin >> arr[i];
   insertion_sort (arr, arr_size);
   for(int i = 0; i < arr_size; i++) std::cout << arr[i] << "\n";
}
