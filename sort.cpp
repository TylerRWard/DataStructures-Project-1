#include "sort.hpp"
using namespace std;

void bubble(string* arr, int n){

    bool swapped;
    for(int i = 0; i < n-1; ++i)
    {
        swapped = false;
        for(int j = 0; j < n-i-1; ++j){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)break;
    }
}

void merge(string* arr, int left, int right){
    if(left>= right) return;

    int mid=left + (right -left)/2;
    merge(arr, left, mid);
    merge(arr, mid+1, right);

    int n1 = mid -left +1;
    int n2 = right -mid;
    string* L = new string[n1];
    string* R = new string[n2];

    for(int i =0; i < n1; i++)
        L[i] = arr[left+i];
    for(int j = 0; j<n2; j++)
        R[j] = arr[mid+1+j];

    int i = 0; int j=0;int k=left;
    while(i<n1 && j <n2){
        if(L[i]<=R[j])arr[k++]=L[i++];
        else arr[k++] = R [j++];
    }

    while(i < n1) arr[k++]= L[i++];
    while(j<n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;

}

void quick(string* arr, int low, int high){
    if(low < high){
        string pivot = arr[high];
        int i = low -1; 

        for (int j = low; j <= high -1; j++){
            if (arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        int pi = i+1;

        quick(arr, low, pi-1);
        quick(arr, pi+1, high);
    }
}

void heapify (string* arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < n && arr[l]> arr[largest]) largest = l;
    if (l < n && arr[r]> arr[largest]) largest = r;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap(string* arr, int n){
    for(int i = n/2 -1; i >=0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i,0);
    }
}
