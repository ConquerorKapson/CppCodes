#include<iostream>
#include<vector>

using namespace std;

void permutationHelper(vector<int>num, vector<vector<int>>& result, int index, int lastIndex){
    if(index > lastIndex){
        result.push_back(num);
        return;
    }

    for(int i = index; i < num.size() ; i++){
        swap(num[index], num[i]);
        permutationHelper(num, result, index+1, lastIndex);

        swap(num[index], num[i]);
    }

}

void permutation(vector<int>num, vector<vector<int>>& result){
    int index = 0;
    int lastIndex = num.size() -1;
    permutationHelper(num, result, index, lastIndex);
    return;
}

int main(){
    vector<int>nums;
    vector<vector<int>>result;

    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;

    cout<<"Enter your elements : ";

    for(int i = 0 ; i < n ; i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }

    permutation(nums, result);

    for(vector<int> row : result){
        cout<<"[";
        for(int x : row){
            cout<<x<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
}