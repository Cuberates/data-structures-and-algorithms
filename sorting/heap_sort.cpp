// Nguyen Xuan Viet Duc
// Affiliation: VNU University of Information Technology
// MIT License applies.

#include <iostream> 

void swap (int &a, int &b) {
   int temp = a;
   b = a;
   a = temp;
}

void make_heap (int arr[], int arr_size, int root) {
   int left_child = (2 * root) + 1,
       right_child = (2 * root) + 2,
       greatest = root;
   // The following code find the node with the maximum value
   if(left_child < arr_size && arr[left_child] > arr[root]) 
      greatest = left_child;
   if(right_child < arr_size && arr[right_child] > arr[root]) 
      greatest = right_child;
   
   // If the greatest node is not the root node
   // Then we swap its value with the root's value
   // And recursively 'heapify' the subtree rooted at greatest
   if(greatest != root) {
      swap (arr[root], arr[greatest]);
      make_heap (arr, arr_size, greatest);
   }
}

void heap_sort (int arr[], int arr_size) {
   // The following code builds the Max Heap by 'heapifying' all subtree 
   int non_leaf_nodes = (arr_size / 2) - 1; 
   for(int r = non_leaf_nodes - 1; r >= 0; r--) 
      make_heap (arr, arr_size, r);
   // Heapifying the root element to get highest root
   for (int n = arr_size - 1; n >= 0; n--) {
      swap (arr[0], arr[n]);
      make_heap (arr, n, 0);
   }
}

int main (void) {
   // The following code is for handling IO
   freopen("unsorted.txt", "r", stdin);
   freopen("sorted.txt", "w", stdout);
   const int arr_size = 50000;
   int arr[arr_size];
   for(int i = 0; i < arr_size; i++) std::cin >> arr[i];
   heap_sort (arr, arr_size);
   for(int i = 0; i < arr_size; i++) std::cout << arr[i] << "\n";
}