// 2d array code

#include <iostream>
using namespace std;
int main()
{
    int arr[3][3], i, j;
    cout << "provide array elements";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "\t" << arr[i][j];
        }
        cout << endl;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// 1d array

#include <iostream>
using namespace std;

int main()
{
    int size;

    
    cout << "Enter the size of the array: ";
    cin >> size;

    
    int* arr = new int[size];

    
    cout << "Provide " << size << " integers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

   
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    delete[] arr;

    return 0;
}
