#include <iostream>
#include "array.h"

int* filter_int_even(int* arr, size_t size){
    size_t counter = 0;
    for(size_t i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            counter++;
        }
    }
    int* result = new int[counter];
    counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0){
            result[counter++] = arr[i];
        }
    }
    return result;
}
 
void print(int* arr, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;
 
}
 
template <typename T>
array<T> filter_array_even(const array<T>& arr){
    array<T> result;
    result.data = new T[arr.capacity];
    result.capacity = arr.capacity;
    result.size = 0;
    for (size_t i = 0; i < arr.size; i++)
    {
        if(arr.data[i] % 2 == 0){
            result.data[result.size++] = arr.data[i];
 
        }
    }
    return result;
}
 
template <typename T>
array<T> filter_array(const array<T>& arr, bool (*predicate)(T)) {
    array<T> result;
    result.data = new T[arr.capacity];
    result.capacity = arr.capacity;
    result.size = 0;
    for (size_t i = 0; i < arr.size; i++)
    {
        if(predicate(arr.data[i])){
            result.data[result.size++] = arr.data[i];
 
        }
    }
    return result;
}
 
bool even(int number){
    return number%2 == 0;
}
 
template <typename T, typename V>
V reduce_array(array<T> arr, V (*op)(V&, const T&), V nv){
    for (size_t i = 0; i < arr.size; i++)
    {
        nv = op(nv, arr.data[i]);
    }
    return nv;
}
 
template <typename T, typename V>
V reduce_array(array<T> arr, V (*op)(const V&, const T&), V nv){
    for (size_t i = 0; i < arr.size; i++)
    {
        nv = op(nv, arr.data[i]);
    }
    return nv;
}
 
 
int sum_func(const int& a, const int& b){
    return a+b;
}
 
int mult_func(const int& a, const int& b){
    return a*b;
}
 
int main(){
    int arr[5]={0,1,2,3,4};
    int *filtered = filter_int_even(arr, 5);
    print(filtered, 3);
    delete[] filtered;
 
    array<int> arr2;
    arr2.capacity = 5;
    arr2.data = new int[arr2.capacity]{0,1,2,3,4};
    arr2.size = 5;
 
    array<int> filtered2 = filter_array_even(arr2);
    print(filtered2.data, filtered2.size);
    delete[] filtered2.data;
 
    array<int> filtered3 = filter_array<int>(arr2, even);
    print(filtered3.data, filtered3.size);
    delete[] filtered3.data;
 
    array<int> filtered4 = filter_array<int>(arr2, [](int element) -> bool {
        return element % 2;
    });
    print(filtered4.data, filtered4.size);
    delete[] filtered4.data;
 
 
    int sum = reduce_array<int, int>(arr2, sum_func, 0);
    std::cout<<sum<<std::endl;
 
    int product = reduce_array<int, int>(arr2, mult_func, 1);
    std::cout<<product<<std::endl;
 
    array<int> arr_char;
    arr_char.data = new int[5]{68, 69, 70 , 71, 72};
    arr_char.size = 5;
    arr_char.capacity = 5;

    array<char> acc;
    acc.data = new char[5];
    acc.size = 0;
    
    acc.capacity = 5;
    array<char> res = reduce_array<int, array<char>>(arr_char, [](array<char>& str, const int& elem) -> array<char> {
        str.data[str.size++] = elem;
        return str;
    
    }, acc);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<res.data[i];
    }
 
 
    delete[] arr2.data;
}
