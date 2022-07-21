#include<iostream>
using namespace std;

template<class T>
class Sorting
{
    private:
        T *Arr;
        int iSize;

    public:
        Sorting(int);
        void Accept();
        void Display();
        void InsertionSort();
};

template<class T>
Sorting<T>::Sorting(int a)
{
    iSize = a;
    Arr = new T[iSize];
}

template<class T>
void Sorting<T>::Accept()
{
    cout<<"Enter elements of array : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void Sorting<T>::Display()
{
    cout<<"Elements of array are : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"  ";
    }
    cout<<endl;
}

template<class T>
void Sorting<T>::InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}

// Write your main function here
