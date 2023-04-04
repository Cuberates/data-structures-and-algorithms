#include <iostream> 

void swap (int &a, int &b) {
   int temp = a; 
   a = b;
   b = temp;
}

void selection_sort (int arr[], int arr_size) {
   // The algorithm find the maximum (or minimum or else) element of the array's suffix (right half)
   // And swap it with an element in the prefix of the array (left half)
   // This yields an overall O(n^2) time complexity

   for(int i = 0; i < arr_size - 1; i++) {
      // hello tuppings'
      int min_index = i;
      for(int j = i + 1; j < arr_size; j++) {
         if(arr[j] < arr[min_index]) {
            min_index = j;
         }
      }
      swap (arr[i], arr[min_index]);
   }
   
}

int main (void) {
   // The following code is for handling IO
   freopen("unsorted.txt", "r", stdin);
   freopen("sorted.txt", "w", stdout);
   const int arr_size = 50000;
   int arr[arr_size];
   for(int i = 0; i < arr_size; i++) std::cin >> arr[i];
   selection_sort (arr, arr_size);
   for(int i = 0; i < arr_size; i++) std::cout << arr[i] << "\n";
}
