
//algorithm
mergeSort(arr, left, right)
 if left > right 
 return
 mid = (left+right)/2
 mergeSort(arr, left, mid)
 mergeSort(arr, mid+1, right)
 merge(arr, left, mid, right)
end


//IMPLEMENTATION
 void mergeSort(int arr[], int start, int right) {
 if (start < right) {
 int mid = (start + right) / 2;
 mergeSort(arr, start, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, start, mid, right);
 }
 }
 void merge(int arr[], int start, int mid, int end) {
 int len1 = mid - start + 1;
 int len2 = end - mid;
 
int leftArr[len1], rightArr[len2];
 
for (int i = 0; i < len1; i++)
 leftArr[i] = arr[start + i];
for (int j = 0; j < len2; j++)
 rightArr[j] = arr[mid + 1 + j];
  int i, j, k;
 i = 0;
 j = 0;
 k = start;
 while (i < len1 && j < len2) {
 if (leftArr[i] <= rightArr[j]) {
 arr[k] = leftArr[i];
 i++;
 } else {
 arr[k] = rightArr[j];
 j++;
 }
 k++;
 }
 
 while (i < len1) {
 arr[k] = leftArr[i];
 i++;
 k++;
 }
 while (j < len2) {
 arr[k] = rightArr[j];
 j++;
 k++;
 }
}
