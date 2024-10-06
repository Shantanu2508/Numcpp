#include  <cstring>
#include  <vector>
#include  <assert.h>
#include  <iostream>
using namespace std;

#ifndef NUMCPP_H
#define NUMCPP_H
#define unsigned int uint
class Numcpp {
public:
  class Array {
    private:
    int* data;
    size_t len;
    
    public:
    Array(size_t size, int init_val = 0); // init array of length size and with some init val, eg: NumCPP::Array arr(5,0);
    Array(std::initializer_list<int> init_list); // init array using initializer list, arr({1,2,3,4,5});
    Array(const Numcpp::Array& other);//Copy constructor
    ~Array(); //destructor
    Numcpp::Array& operator=(const Numcpp::Array& other); //overload = operator to copy values from another numcpp array
    Numcpp::Array operator+(const Numcpp::Array& other) const ;      //Overload + operator to add two NumCpp::Array
    Numcpp::Array operator-(const Numcpp::Array& other) const;      //Overload - operator to add two NumCpp::Array
    size_t size(); //get array size
    int& operator[](size_t index);    //Overload [] operator to fetch element using index, like arr[i]
    void print(); //print numcpp array

    //Overload + operator to add two NumCpp::Array
    //Overload - operator to add two NumCpp::Array
  };
  template <typename T, typename... Args>
  //array creation functions
  void zeros(T& mat,Args... args);
  void* ones(size_t size);
  void* arange(int range);
  void* linspace(int interval[2]);
  void* eye(int size);
  void* random(int size);

  //array reshape and manipulation
  void reshape(int* mat_ptr,uint row, uint col);
  void transpose(int* mat_ptr);
  void flatten(int* mat_ptr);
  void concatenate(int* mat_ptr1, int* mat_ptr, int axis); //concatenate two arrays along a specified axis
  void split(int* mat_ptr, int row1, int col1);
};
#endif
