#include<iostream>
#include<vector>
using namespace std;


void permutationHelper(string str, vector<string>& permutations, int index, int lastIndex){
    if(index > lastIndex){
        permutations.push_back(str);
        return;
    }


    for(int i = index ; i < str.length() ; i ++){
        swap(str[index], str[i]);
        permutationHelper(str, permutations, index+1, lastIndex);

        swap(str[index], str[i]);
    }
}


void permutation(string str, vector<string>& permutations){
    int index = 0;
    int lastIndex = str.length() - 1;

    permutationHelper(str, permutations, index, lastIndex);
    return;
}


int main(){
    string str;
    cout<<"Enter your string : ";
    cin>>str;
    vector<string>permutations;
    permutation(str, permutations);

    // sort(permutations.begin(), permutations.end());

    for(string str : permutations){
        cout<<str<<endl;
    }


    return 0;
}