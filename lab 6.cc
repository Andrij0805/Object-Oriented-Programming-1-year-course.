
#include <iostream>
#include <concepts>
using namespace std;


template <typename T>
typename enable_if<is_arithmetic<T>::value, T>::type

 findMax(T arr[], int size)
{
    T maxValue = arr[0]; 

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i]; 
        }
    }

    return maxValue;
}

int main() {

    int a[] = {3, 8, 2, 10, 5};
    double b[] = {2.5, 7.1, 3.3, 9.9};
   
    cout << "Max (int): " << findMax(a, 5) << endl;
    cout << "Max (double): " << findMax(b, 4) << endl;

    return 0;
}

/*
#include <iostream>
using namespace std;

template <typename T>
class Sorter
{
private:
    T* arr;
    int size;

public:
    Sorter(T* arr, int size)
    {
        this->arr = arr;
        this->size = size;
    }

    
    void sortDescending() {
        for (int i = 0; i < size - 1; i++) 
        {
            for (int j = i + 1; j < size; j++)
            {

               
                if (arr[i] < arr[j])
                {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

int main() {
    int M[] = { 4, 1, 9, 3, 7 };
    int size = 5;
    double D[] = { 5.6,6.3,5.7,1.2,8.9 };

    Sorter<int> sorterInt(M, size);
    Sorter<double> sorterDouble(D, size);
    sorterInt.sortDescending();
    sorterDouble.sortDescending();
  
    for (int i = 0; i < size; i++)
    {
        cout << M[i] << " ";
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << D[i] << " ";
    }

    return 0;
}
*/
