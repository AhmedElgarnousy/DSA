#include <iostream>

using namespace std;
// pass by value , reference
void change(int a, int &b) {
    a++;
    b++;
}
// array always pass by reference
int sum_array(int arr[], int len){
    int sum;
    for(int i =0; i<len; i++){
        sum += arr[i];
    }
    return sum;
}


// bool is_lower(string str) { // copy pass by value so its slow
// bool is_lower(string &str) { // Access , speed
bool is_lower(const string &str) { // speed ,no Access 
    for(int i = 0; i< (int)str.size(); i++) {
        bool lower = 'a'<= str[i] && str[i]<='z';

        if (!lower)
            return false;
    }
    return true;
}

int main() {
    // int a = 1, b = 2;
    // change(a, b);
    // cout<<a<<" "<<b<<"\n";

    // int arr1[] = {1, 2,3,4,5,6};
    // cout<<sum_array(arr1, 3)<<"\n";

    // cout<<is_lower("abc")<<"\n";  // temp var , copy pass by value so its slow

    string str1 ="abc";
    cout<<is_lower(str1)<<"\n";  // pass by refernece
    


    return 0;
}