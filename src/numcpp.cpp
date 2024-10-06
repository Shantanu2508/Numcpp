#include  "numcpp.h"


//#######################################################
// NUMCPP ARRAY FUNC DEF                                #                                       
//#######################################################

// init array of length size and with some init val, eg: NumCPP::Array arr(5,0);
Numcpp::Array::Array(size_t size, int init_val) : len(size){
  data = new int[size];
  for(size_t i = 0; i < size; i++) data[i] = init_val;
}

//init array using initializer list, eg NumCpp::Array arr({1,2,3,4,5}); 
Numcpp::Array::Array(std::initializer_list<int> init_list) : len(init_list.size()){
  data = new int[len];
  size_t i = 0;
  for(int value : init_list) data[i++] = value;
}

//Copy constructor
Numcpp::Array::Array(const Numcpp::Array& other) : len(other.len){
	data = new int[len];
	for(size_t i = 0; i < len; i++) data[i] = other.data[i];
}

//Destructor
Numcpp::Array::~Array(){
  delete[] data;
}

//Overlaod = operator, in-place
Numcpp::Array& Numcpp::Array::operator=(const Numcpp::Array& other) {      
	delete[] data;
	len = other.len;
	data = new int[len];
	for(size_t i = 0; i < len; i++) data[i] = other.data[i];
	return *this;
}

//Get array size
size_t Numcpp::Array::size(){
  return len;
}

//Overload [] operator to fetch element using index, like arr[i]
int& Numcpp::Array::operator[](size_t index){
  if(index >= len) throw std::out_of_range("index out of range");
  return data[index];
}

//Overload + operator to add two NumCpp::Array
Numcpp::Array Numcpp::Array::operator+(const Numcpp::Array& other) const{
  if(len != other.len) throw std::invalid_argument("Arrays must be of same size");
  Numcpp::Array res(len);
  for(size_t i = 0; i < len; i++) res.data[i] = data[i]+other.data[i];
  return res;
}
//Overload - operator to add two NumCpp::Array
Numcpp::Array Numcpp::Array::operator-(const Numcpp::Array& other) const{
  if(len != other.len) throw std::invalid_argument("Arrays must be of same size");
  Numcpp::Array res(len);
  for(size_t i = 0; i < len; i++) res.data[i]= data[i]-other.data[i];
  return res;
}

//print NumCpp::Array
void Numcpp::Array::print(){
  for(size_t i = 0; i < len; i++) std::cout << data[i] << " ";	      
  std::cout << std::endl;
}

//#######################################################

/*template <typename T,typename... Args>
void NumCpp::zeros(T &mat, Args... args) {
  vector<size_t> dim = {static_cast<size_t>(args)...};
  if(dim.size() == 1){
    mat.resize(dim[0],0);
  }
  else if(dim.size() == 2){
    mat.resize(dim[0], std::vector<int>(dim[1], 0));
  }
  else{
    //TODO: Handle more than 2D case
    assert(0);
  }
}
void* NumCpp::ones(int size) {
  int arr[size];
  memset(arr,1,sizeof(arr));
  void* ret = &arr;
  return ret;
}

void* NumCpp::arange(int range){
   int arr[range];
   for(int i = 0; i < range; i++){
      arr[i] = i;
   }
   void* ret = &arr;
   return ret;
}
void* NumCpp::linspace(int interval[2]){
   int size = interval[1]-interval[0]+1;
   int arr[size];
   for(int i = interval[0]; i <= interval[1]; i++) {
      arr[i] = i;
   }
   void* ret = &arr;
   return ret;
}
void* NumCpp::eye(int size){
   int arr[size][size];
   memset(arr,0,sizeof(arr));
   for(int i = 0; i < size; i++) arr[i][i] = 1; 
   void* ret = &arr;
   return ret;
}
void* NumCpp::random(int size){
   void* ret;
   return ret;
};*/

int main(){
   Numcpp::Array arr(5);
   Numcpp::Array b({1,2,3,4,5,6});
   Numcpp::Array c({10,20,30,40,50,60});
   Numcpp::Array res = b-c;
   res.print();
   return 0;
}
