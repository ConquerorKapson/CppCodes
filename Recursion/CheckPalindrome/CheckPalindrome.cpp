#include <iostream>
using namespace std;
bool checkPalindrome(string str, int i, int j)
{
    if (str[i] != str[j])
    {
        return false;
    }

    checkPalindrome(str, i + 1, j - 1);
    return true;
}

int main()
{
    while (true)
    {
        string str;
        cout << "Enter your string : ";
        cin >> str;
        string result = checkPalindrome(str, 0, str.length() - 1) ? "It is a Palindrome" : "Not a palindrome";
        cout << str << " : " << result<<endl<<endl;
    }
    return 0;
}