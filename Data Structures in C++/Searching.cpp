#include<iostream>
using namespace std;

template<class T>
class Searching
{
    private:
        T *Arr;
        int iSize;

    public:
        Searching(int);
        void Accept();
        void Display();
        T LinearSearch(T);
        T BidirectionalSearch(T);  
        T BinarySearchI(T); // sorted array in increasing order
        T BinarySearchD(T);  // sorted array in decreasing order
};

template<class T>
Searching<T>::Searching(int a)
{
    iSize = a;
    Arr = new T[iSize];
}

template<class T>
void Searching<T>::Accept()
{
    cout<<"Enter elements of array : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void Searching<T>::Display()
{
    cout<<"Elements of array are : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"  ";
    }
    cout<<endl;
}

template<class T>
T Searching<T>::LinearSearch(T No)
{
    int i = 0;

    for(i = 0; i < this->iSize; i++)
    {
        if(this->Arr[i] == No)
        {
            break;
        }
    }
    if(i == iSize)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template<class T>
T Searching<T>::BidirectionalSearch(T No)
{
    int iStart = 0;
    int iEnd = iSize-1;
    int iPos = -1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == No)
        {
            iPos = iStart;
            break;
        }
        else if(Arr[iEnd] == No)
        {
            iPos = iEnd;
            break;
        }
        iStart++;
        iEnd--;
    }
    return iPos;
}

template<class T>
T Searching<T>::BinarySearchI(T No)
{
    int iStart = 0, iMiddle = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMiddle = (iStart + iEnd) / 2;

        if(Arr[iMiddle] == No)
        {
            break;
        }

        if(No > Arr[iMiddle])
        {
            iStart = iMiddle + 1;
        }
        if(No < Arr[iMiddle])
        {
            iEnd = iMiddle - 1;
        }
    }
    if(Arr[iMiddle] == No)
    {
        return iMiddle;
    }
    else
    {
        return -1;
    }
}

template<class T>
T Searching<T>::BinarySearchD(T No)
{
    int iStart = 0, iMiddle = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMiddle = (iStart + iEnd) / 2;

        if(Arr[iMiddle] == No)
        {
            break;
        }

        if(No > Arr[iMiddle])
        {
            iEnd = iMiddle - 1;
        }
        if(No < Arr[iMiddle])
        {
            iStart = iMiddle + 1;
        }
    }
    if(Arr[iMiddle] == No)
    {
        return iMiddle;
    }
    else
    {
        return -1;
    }
}


int main()
{
    int iSize = 0 , iValue = 0;

    cout<<"Enter size of array : "<<endl;
    cin>>iSize;

    Searching <int>sobj(iSize);
    sobj.Accept();
    sobj.Display();

    cout<<"Enter a number to search : "<<endl;
    cin>>iValue;

    int iRet = sobj.BinarySearchD(iValue);
    if(iRet == -1)
    {
        cout<<"Element is not present in array"<<endl;
    }
    else
    {
        cout<<"Element is present in array at index : "<<iRet<<endl;
    }
    
}