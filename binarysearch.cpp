#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key ;
    cout<<"Enter the key element: ";
    cin>>key;
    int result = binarySearch(arr, n, key);
    // cout << "Found at index: "<<result << endl;

     cout << (result == -1 ? "Not Found" : "Found at index " + to_string(result)) << endl;
    return 0;
}
