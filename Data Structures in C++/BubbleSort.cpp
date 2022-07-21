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
        void BubbleSortI();     // increasingly sorted data
        void BubbleSortD();     // decreasingly sorted data
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
void Sorting<T>::BubbleSortI()
{
    int i = 0, j = 0, temp = 0;
    bool Swap = false;

    for(i = 0; i < iSize; i++)
    {
        Swap = false;
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                Swap = true;
            }
        }
        if(Swap == false)
        {
            break;
        }
        cout<<"Pass no : "<<(i+1)<<endl; 
    }
}

template<class T>
void Sorting<T>::BubbleSortD()
{
    int i = 0, j = 0, temp = 0;
    bool Swap = false;

    for(i = 0; i < iSize; i++)
    {
        Swap = false;
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                Swap = true;
            }
        }
        if(Swap == false)
        {
            break;
        }
        cout<<"Pass no : "<<(i+1)<<endl; 
    }
}

// Write your main function here
