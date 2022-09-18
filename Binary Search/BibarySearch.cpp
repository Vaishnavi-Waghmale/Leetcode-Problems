#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    //int mid = (start + end) / 2;
    
    int mid = start + ((end-start)/2)

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }
        // going to right start= mid+1
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        // going to left  end = mid-1
        else
        {
            end = mid - 1;
        }
        //mid = (start + end) / 2;  this can give error if our start and end both values are  2^31-1 hence use this
        
        mid = start + ((end-start)/2)
    }
    return -1;
}

int main()
{

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int index = binarySearch(odd, 5, 8);

    cout << index;

    return 0;
}
