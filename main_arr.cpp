#include <iostream>
#include <vector>
#include <random>
#include<time.h>
#include<list>

using namespace std;

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

int bubble_sort(vector<int>& v){
  bool swapped; 
  for(int i = 0; i < v.size(); i++){
    swapped = false; 
    for(int j = 0; j < v.size() - i - 1; j++){
      if(v[j] > v[j+1]){ swap(v[j], v[j+1]); swapped = true; }
    }
    if(!swapped){ break; }
  }
  return 1; 
}

int ins_sort(vector<int>& v){
  for(int i = 1; i < v.size(); i++){
    int temp = v[i];
    int j = i-1;
    while(j >= 0 && v[j] > temp){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = temp;
  }
  return 1; 
}

int sel_sort(vector<int>& v){
  for(int i = 0; i < v.size(); i++){
    int min_idx = i;
    for(int j = i+1; j < v.size(); j++){
      if(v[j] < v[min_idx]){ min_idx = j; }
    }
    if(min_idx != i){ swap(v[i], v[min_idx]); }
  }
  return 1;
}

int heapify(vector<int>& v, int size, int idx){
  // if(v.size() == 0 || 1){ return 0; }
  int largest = idx;
  int left_child_idx = 2*idx + 1;
  int right_child_idx = 2*idx + 2;
  if(left_child_idx < size && v[left_child_idx] > v[largest]){ largest = left_child_idx; }
  if(right_child_idx < size && v[right_child_idx] > v[largest]){ largest = right_child_idx; }
  if(largest != idx){
    swap(v[largest], v[idx]);
    heapify(v, size, largest);
  }
  return 1; 
}

int arr_to_heap(vector<int>& v){
  for(int i = v.size()/2; i >= 0; i--){
    heapify(v, v.size(), i);
  }
  return 1; 
}

int heap_sort(vector<int>& v){
  arr_to_heap(v);
  int curr_size = v.size();
  while(curr_size > 1){
    swap(v[0],v[curr_size-1]);
    curr_size--;
    heapify(v, curr_size, 0);
  }
  return 1; 
}

void merge(vector<int>& v, int m, int l, int r){
  vector<int> temp1, temp2;
  int size1 = m-l+1, size2 = r-m;
  for(int i = 0; i < size1; i++){ temp1.push_back(v[i+l]); }
  for(int i = 0; i < size2; i++){ temp2.push_back(v[i+m+1]); }

  int i = 0, k = 0, main_idx = l;
  while(i < size1 && k < size2){
    if(temp1[i] < temp2[k]){ v[main_idx++] = temp1[i]; i++; }
    else{ v[main_idx++] = temp2[k]; k++; }
  }

  while(i < size1){
    v[main_idx++] = temp1[i];
    i++;
  }

  while(k < size2){
    v[main_idx++] = temp2[k];
    k++;
  }
}

int merge_sort(vector<int>& v, int l, int r){
  if(l >= r){ return 0; }
  int mid = (l+r)/2;
  merge_sort(v, l, mid);
  merge_sort(v, mid+1, r);
  merge(v,mid,l,r);
  return 1; 
}

int main(){
  srand(time(0));
  vector<int> v;
  for(int i = 0; i < 500000; i++){
    v.push_back(rand());
  }
  // bubble_sort(v);
  // cout<<"\nwithtout sort: ";
  // for(int i = 0; i < v.size(); i++)
    // cout<<v[i]<<" ";
  cout<<"\nafter sorting: ";
  // ins_sort(v);
  // sel_sort(v);
  // merge_sort(v, 0, v.size()-1);
  heap_sort(v);
  for(int i = 0; i < v.size(); i++)
    cout<<v[i]<<" ";
  return 0; 
}