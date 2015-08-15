#include <iostream>
using namespace std;

void quickSort(int* a, int start, int end) {
    
    if(a == NULL)   return;
    
    if(end - start == 1) {
        if(a[start] > a[end]) {
            int tmp = a[start];
            a[start] = a[end];
            a[end] = tmp;
        }
    }
    else if(end - start > 1) {
        int key = a[start];
        int left = start;
        int right = end;
        
        while(left < right) {
            while(left < right && a[right] >= key)
                right--;
            a[left] = a[right];
            while(left < right && a[left] <= key)
                left++;
            a[right] = a[left];
        }
        a[left] = key;
        
        quickSort(a, start, left);
        quickSort(a, left + 1, end);
    }
    
}
void merge(int* a, int* tmp, int start, int mid, int end) {
    for(int i = start; i < end + 1; i++)
        tmp[i] = a[i];
    int i = start, j = mid + 1, k = start;
    while(i < mid  + 1 && j < end + 1) {
        if(tmp[i] < tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while(i < mid + 1) a[k++] = tmp[i++];
    while(j < end + 1) a[k++] = tmp[j++];
}
void mergeSort(int* a, int* tmp, int start, int end) {
    if(a == NULL || start >= end) return ;
    
    if(start < end)
    {
        int mid = (start + end)>>1;
        mergeSort(a, tmp, start, mid);
        mergeSort(a, tmp, mid + 1, end);
        merge(a, tmp, start, mid, end);
    }
}
void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
}
void percolateDown(int* a, int size, int pos) {
    int child = (pos<<1) + 1;
    if(child > size - 1) return;
    if(child + 1 < size && a[child] < a[child + 1]) child++;
    
    if(a[pos] < a[child]) {
        swap(a[pos], a[child]);
        percolateDown(a, size, child);
    }
}
void heapSort(int* a, int size) {
    if(a == NULL || size < 2)  return;
    
    for(int i = size/2 - 1; i > -1; i--)
        percolateDown(a, size, i);
    
    for(int i = size - 1; i > -1; i--) {
        swap(a[i], a[0]);
        percolateDown(a, i, 0);
    }
}
void insertionSort(int* a, int size) {
    if(a == NULL || size < 2) return;
    
    int i, j;
    for(i = 1; i < size; i++) {
        int tmp = a[i];
        for(j = i; j - 1 >= 0 && a[j - 1] > tmp ; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}
void shellSort(int* a, int size, int k) {
    if(a == NULL || size < 2 || k > size - 1) return;
    
    for(int increment = k; increment > 0; increment = (increment>>1)) {
        int i, j;
        for(i = increment; i < size; i++) {
            int tmp = a[i];
            for(j = i; j - increment >= 0 && a[j - increment] > tmp; j -= increment)
                a[j] = a[j - increment];
            a[j] = tmp;
        }
    }
}
void bucketSort(int* a, int size, int bucketNum) {
    if(a == NULL || size < 2) return;
    
    int* tmp = new int[size];
    memcpy(tmp, a, size * sizeof(int));
    int* count = new int[bucketNum];
    memset(count, 0, bucketNum * sizeof(int));
   
    int max = tmp[0];
    int min = tmp[0];
    for(int i = 1; i < size; i++) {
        if(tmp[i] > max)
            max = tmp[i];
        if(tmp[i] < min)
            min = tmp[i];
    }
    for(int i = 0; i < size; i++)
        count[(tmp[i] - min)* (bucketNum - 1)/ (max - min)]++;
    
    for(int i = 1; i < bucketNum; i++)
        count[i] += count[i - 1];
    
    int* count1 = new int[bucketNum];
    memcpy(count1, count, bucketNum * sizeof(int));
    
    for(int i = size - 1; i > -1; i--) {
        a[count[(tmp[i] - min)* (bucketNum - 1)/ (max - min)]- 1] = tmp[i];
        count[(tmp[i] - min)* (bucketNum - 1)/ (max - min)]--;
    }
    delete []count;
    
    int start = 0, len = count1[0];
    for(int i = 0; i < bucketNum; i++) {
        cout<<endl;
        for(int i = 0; i < size; i++)
            cout<<a[i]<<" ";
        
        insertionSort(a + start, len);
        start = count1[i];
        if(i + 1 < bucketNum) len = count1[i + 1] - count1[i];
    }
    
    delete []count1;
    delete []tmp;
}
void countingSort(int* a, int size, int k) { //k is the size of vector
    if(a == NULL || size < 2) return;
    
    int* count = new int[k];
    memset(count, 0, k * sizeof(int));
    int* tmp = new int[size];
    memcpy(tmp, a, size * sizeof(int));
    
    for(int i = 0; i < size; i++)
        count[tmp[i] % k]++;
    for(int i = 1; i < k; i++)
        count[i] += count[i - 1];
    for(int i = size - 1; i > -1; i--) {
        a[count[tmp[i] % k] - 1] = tmp[i];
        count[tmp[i] % k]--;
    }
    delete []count;
    delete []tmp;
}
void radixSort1(int* a, int size, int radix, int digit) { //use counting sort inside this function
    int* tmp = new int[size];
    memcpy(tmp, a, size * sizeof(int));
    int* tmp1 = new int[size];
    memcpy(tmp1, a, size * sizeof(int));
    int* count = new int[radix];
    memset(count, 0, radix * sizeof(int));
    
    for(int i = 0; i < size; i++) {
        for(int d = 0; d < digit; d++)
            tmp[i] /= radix;
        count[tmp[i] % radix]++;
    }
    
    for(int i = 1; i < radix; i++)
        count[i] += count[i - 1];
    
    for(int i = size - 1; i > -1; i--) {
        a[count[tmp[i] % radix] - 1] = tmp1[i];
        count[tmp[i] % radix]--;
    }
    
    delete []tmp;
    delete []tmp1;
    delete []count;
}
void radixSort(int* a, int size, int radix, int digit){
    if(a == NULL || size < 2) return;
    
    for(int i = 0; i < digit; i++)
        radixSort1(a, size, radix, i);
}
void selectionSort(int* a, int size) {
    if(a == NULL || size < 2) return;
    for(int i = 0; i < size - 1; i++) {
        int min = a[i];
        int pos = i;
        for(int j = i + 1; j < size; j++) {
            if(a[j] < min) {
                min = a[j];
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}
int main() {
    
    int a[] = {3, 5, 3, 7, 1, 8, 2, 13, 10, 0};
    int n = sizeof(a)/sizeof(int);
    
    cout<<"before sorting:"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    
 //   quickSort(a, 0, n - 1);
 //   int* tmp = new int(n);
 //   mergeSort(a, tmp, 0, n - 1);
 //   heapSort(a, n);
 //   insertionSort(a, n);
 //   shellSort(a, n, 3);
 //   countingSort(a, n, 15);
 //   radixSort(a, n, 10, 2);
 //   selectionSort(a, n);
    bucketSort(a, n, 5);
    
    cout<<"\nafter sorting:"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    
    return 0;
}
