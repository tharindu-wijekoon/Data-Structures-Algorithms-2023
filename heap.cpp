#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int bigger = root; // take root as the large number
   int left = 2 * root + 1; // placing the left child
   int right = 2 * root + 2; //placing the right child

   if (left < n && arr[left] > arr[bigger]) //find the correct value for left child
      bigger = left;

   if (right < n && arr[right] > arr[bigger]) // find the correct value for right child
      bigger = right;

   if (bigger != root) { // if root is not the large number
      int temp = arr[root];
      arr[root] = arr[bigger];
      arr[bigger] = temp;
      heapify(arr, n, bigger);
   }  
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--){
         heapify(arr, n, i);
      }
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
         int temp = arr[0];
         arr[0] = arr[i];
         arr[i] = temp;
         heapify(arr, i, 0);
    }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   const int MAX = 100;
   int n;
   cout<<"Size of heap:";
   cin>>n;

   int heap_arr[MAX];

   for (int i=0;i<n;i++){
      cin>>heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
