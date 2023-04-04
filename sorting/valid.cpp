#include <iostream> 

int main (void) {
   // The following code is for handling IO
   freopen("sorted.txt", "r", stdin);
   const int arr_size = 50000;
   int arr[arr_size];
   for(int i = 0; i < arr_size; i++) std::cin >> arr[i];
   
   int current = arr[0], answer = 1;
   for(int i = 1; i < arr_size && answer; i++) {
      if(arr[i] < current) answer = 0;
      current = arr[i];
   }
   if (answer) std::cout << "List is sorted\n";
   else std::cout << "List is NOT sorted\n";
}
