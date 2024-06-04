#include<iostream>

using namespace std;

class Vector{

    private:
        int size {0};
        int* arr = nullptr;

    public:
	Vector (int size): size(size){
	if(size<0){
		size = 1;
	}
	arr = new int [size] {};
	}
  
    ~Vector ()
    {
      delete [] arr;
      arr = nullptr;
    }


    void set(int idx, int val){
          arr[idx] = val;
        }
    
    void print(){
	for(int i = 0; i<size; i++){
	cout<<arr[i];
	}
    }
};




int main()
{
  int n = 5;
  Vector v(n);
  for (int i = 0; i< n; ++i) {
    v.set(i,i);
  }  

//   v.push_back(15);
//   v.push_back(17);
//   v.push_back(19);
//   v.print();
//   v.insert(2, 0);
    cout<<"hello from test";
  v.print();

    return 0;
}
