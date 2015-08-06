//
//  main.cpp
//  test
//
//  Created by Yajie on 15/8/6.
//  Copyright (c) 2015年 Yajie. All rights reserved.
//

#include <iostream>
using namespace std;

void quickSort(int* a, int start, int end) {
    
    if(a == NULL)   return;
    
    if(end - start == 1)
    {
        if(a[start] > a[end])
        {
            int tmp = a[start];
            a[start] = a[end];
            a[end] = tmp;
        }
    }
    else if(end - start > 1)
    {
        int key = a[start];
        int left = start;
        int right = end;
        
        while(left < right)
        {
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
void merge(int* a, int* tmp, int start, int mid, int end)
{
    for(int i = start; i < end + 1; i++)
        tmp[i] = a[i];
    int i = start, j = mid + 1, k = start;
    while(i < mid  + 1 && j < end + 1)
    {
        if(tmp[i] < tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while(i < mid + 1) a[k++] = tmp[i++];
    while(j < end + 1) a[k++] = tmp[j++];
}
void mergeSort(int* a, int* tmp, int start, int end)
{
    if(a == NULL || start == end) return ;
    
    if(start < end)
    {
        int mid = (start + end)>>1;
        mergeSort(a, tmp, start, mid);
        mergeSort(a, tmp, mid + 1, end);
        merge(a, tmp, start, mid, end);
    }
}
void swap(int* a, int* b)
{
    int* tmp = a;
    a = b;
    b = tmp;
}
void percolate(int* a, int size, int pos)
{
    int child = (pos<<1) + 1;
    if(child > size - 1) return;
    if(child + 1 < size && a[child] < a[child + 1]) child++;
    
    if(a[pos] < a[child])
    {
        swap(a[pos], a[child]);
        percolate(a, size, child);
    }
}
void heapSort(int* a, int size)
{
    if(a == NULL || size < 2)  return;
    
    for(int i = size/2 - 1; i > -1; i--)
        percolate(a, size, i);
    
    for(int i = size - 1; i > -1; i--)
    {
        swap(a[i], a[0]);
        percolate(a, i, 0);
    }
}
int main() {
    
    int a[] = {3, 5, 3, 7, 1, 8, 2, 13, 10, 0};
    int n = sizeof(a)/sizeof(int);
    
    cout<<"before sorting:"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    
    
    //  quickSort(a, 0, n - 1);
    //  int tmp[10] = {0};
    //  mergeSort(a, tmp, 0, n - 1);
    heapSort(a, n);
    
    cout<<"\nafter sorting:"<<endl;
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    
    return 0;
}
