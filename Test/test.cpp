#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int element_to_search, int ans_at_index){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == element_to_search){
            ans_at_index = i;
            break;
        }
    }
    return ans_at_index;
}

int main(){
    int arr[7] = {8, 9, 10, 2, 4, 7, 21};
    int n = 7;
    int element_to_search = 10;
    int ans_at_index = -1;

    int ans = linearSearch(arr, n, element_to_search, ans_at_index);

    if(ans == -1){
        cout<<"NOT FOUND";
    }else{
        cout<<"Element is at Index : "<<ans;
    }
    return 0;

}