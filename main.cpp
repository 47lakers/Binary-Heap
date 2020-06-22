//
//  main.cpp
//  Binary Heap
//
//  Created by Ira Xavier Porchia on 6/15/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector{
private:
    T *_arr;
    int _capacity, _current;
public:
    Vector(){
        _arr = new T[1];
        _capacity = 1;
        _current = 0;
    }
    
    ~Vector(){
        delete[] _arr;
        _arr = nullptr;
        _capacity = 0;
        _current = 0;
    }
    
    void push(T data){
        T *temp = nullptr;
        if(_current == _capacity){
            temp = new T[2 * _capacity];
            for(int i = 0; i < _capacity; i++){
                temp[i] = _arr[i];
            }
            delete[] _arr;
            _capacity *= 2;
            _arr = temp;
        }
        _arr[_current] = data;
        _current++;
    }
    
    void pop(){
        _current--;
    }
    
    void print(){
        for (int i = 0; i < _current; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl << endl;
    }
    
    int size(){
        return _current;
    }
    
    bool empty(){
        return size() == 0;
    }
    
    int get(int index){
        return _arr[index];
    }
    
    void swap(int a, int b){
        int temp = _arr[a];
        _arr[a] = _arr[b];
        _arr[b] = temp;
    }
    
};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class minHeap{
private:
    Vector<int> v;
    
    int parent(int i);
    
    int leftChild(int i);
    
    int rightChild(int i);
    
    void heapifyDown(int i);
    
    void heapifyUp(int i);
    
public:
    void insert(int data);
    
    int extract();
    
    int peek();
    
    void print();
    
};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class maxHeap{
    private:
        Vector<int> v;
        
        int parent(int i);
        
        int leftChild(int i);
        
        int rightChild(int i);
        
        void heapifyDown(int i);
        
        void heapifyUp(int i);
        
    public:
        void insert(int data);
        
        int extract();
        
        int peek();
        
        void print();
    
};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int minHeap::parent(int i){
    return (i - 1)/2;
}

int maxHeap::parent(int i){
    return (i - 1)/2;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int minHeap::leftChild(int i){
    return 2 * i + 1;
}

int maxHeap::leftChild(int i){
    return 2 * i + 1;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int minHeap::rightChild(int i){
    return 2 * i + 2;
}

int maxHeap::rightChild(int i){
    return 2 * i + 2;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void maxHeap::heapifyDown(int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    if(left < v.size() && v.get(left) > v.get(i)){
        largest = left;
    }
    if(right < v.size() && v.get(right) > v.get(largest)){
        largest = right;
    }
    if(largest != i){
        v.swap(i, largest);
        heapifyDown(largest);
    }
}

void minHeap::heapifyDown(int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;
    if(left < v.size() && v.get(left) < v.get(i)){
        smallest = left;
    }
    if(right < v.size() && v.get(right) < v.get(smallest)){
        smallest = right;
    }
    if(smallest != i){
        v.swap(i, smallest);
        heapifyDown(smallest);
    }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void minHeap::heapifyUp(int i){
    if(i && v.get(parent(i)) > v.get(i)){
        v.swap(i, parent(i));
        heapifyUp(parent(i));
    }
}

void maxHeap::heapifyUp(int i){
    if(i && v.get(parent(i)) < v.get(i)){
        v.swap(i, parent(i));
        heapifyUp(parent(i));
    }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void minHeap::insert(int data){
    v.push(data);
    int index = v.size() - 1;
    heapifyUp(index);
}

void maxHeap::insert(int data){
    v.push(data);
    int index = v.size() - 1;
    heapifyUp(index);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void minHeap::print(){
    v.print();
}

void maxHeap::print(){
    v.print();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int minHeap::extract(){
    if(v.size() == 0){
        cout << "Error" << endl << endl;
        return -1;
    }
    int val = v.get(0);
    v.swap(0, v.size() - 1);
    v.pop();
    heapifyDown(0);
    return val;
}

int maxHeap::extract(){
    if(v.size() == 0){
        cout << "Error" << endl << endl;
        return -1;
    }
    int val = v.get(0);
    v.swap(0, v.size() - 1);
    v.pop();
    heapifyDown(0);
    return val;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int minHeap::peek(){
    if(v.size() == 0){
        cout << "Error" << endl << endl;
        return -1;
    }
    cout << v.get(0) << endl << endl;
    return v.get(0);
}

int maxHeap::peek(){
    if(v.size() == 0){
        cout << "Error" << endl << endl;
        return -1;
    }
    cout << v.get(0) << endl << endl;
    return v.get(0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main(int argc, const char * argv[]) {
    minHeap tree;
    tree.insert(60);
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(20);
    tree.insert(100);
    tree.insert(200);
    tree.print();
    tree.extract();
    tree.print();
    tree.extract();
    tree.print();
    tree.peek();
    maxHeap max;
    max.insert(60);
    max.insert(50);
    max.insert(40);
    max.insert(30);
    max.insert(20);
    max.insert(100);
    max.insert(200);
    max.print();
    max.extract();
    max.print();
    max.extract();
    max.print();
    max.peek();
    return 0;
};
