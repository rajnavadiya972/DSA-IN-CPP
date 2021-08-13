#include <bits/stdc++.h>
using namespace std;

int binaryS(int a[], int size, int ele)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == ele)
        {
            return mid;
        }
        if (a[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// int binaryS(int arr[], int size, int element){
//     int low, mid, high;
//     low = 0;
//     high = size-1;
//     // Keep searching until low <= high
//     while(low<=high){
//         mid = (low + high)/2;
//         if(arr[mid] == element){
//             return mid;
//         }
//         if(arr[mid]<element){
//             low = mid+1;
//         }
//         else{
//             high = mid -1;
//         }
//     } 
//     return -1;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 15, 20, 35, 58, 67, 78, 89, 90, 100};
    int element = 11;
    int size = sizeof(arr) / sizeof(int);
    cout << size << endl;
    int ans = binaryS(arr, size, element);
    cout << ans << endl;
    return 0;
}