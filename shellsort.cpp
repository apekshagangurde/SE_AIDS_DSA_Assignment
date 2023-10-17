#include <iostream>
using namespace std;

class Sorting {
public:
   void shell_sort(int my_arr[], int arr_len) {
      for (int gap = arr_len / 2; gap > 0; gap /= 2) {
         for (int i = gap; i < arr_len; i += 1) {
            int temp = my_arr[i];
            int  j;
            for (j = i; j >= gap && my_arr[j - gap] > temp; j -= gap)
               my_arr[j] = my_arr[j - gap];
            my_arr[j] = temp;
         }
         // Print the array after each pass
         cout << "Pass: ";
         for (int k = 0; k < arr_len; ++k)
            cout << my_arr[k] << " ";
         cout << endl;
      }
   }
};

int main() {
   int arr_len;
   cout << "Enter the number of elements: ";
   cin >> arr_len;

   int my_arr[arr_len];
   cout << "Enter the elements: ";
   for (int i = 0; i < arr_len; ++i)
      cin >> my_arr[i];

   Sorting s;
   s.shell_sort(my_arr, arr_len);

   cout << "The array, after performing shell sort is: " << endl;
   for (int i = 0; i < arr_len; ++i)
      cout << my_arr[i] << " ";
   cout << endl;

   return 0;
}
