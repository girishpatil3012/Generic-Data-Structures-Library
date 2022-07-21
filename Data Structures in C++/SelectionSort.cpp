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
        void SelectionSortI();      // increasingly sorted data
        void SelectionSortD();      // decreasingly sorted data
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
void Sorting<T>::SelectionSortI()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template<class T>
void Sorting<T>::SelectionSortD()
{
    int i = 0, j = 0, max_index = 0, temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        max_index = i;
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[max_index] < Arr[j])
            {
                max_index = j;
            }
        }
        if(i != max_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[max_index];
            Arr[max_index] = temp;
        }
    }
}

int main()
{
    int iSize = 0;

    cout<<"Enter size of array : "<<endl;
    cin>>iSize;

    Sorting<char> *ptr = new Sorting<char>(iSize);
    ptr->Accept();
    ptr->Display();
    ptr->SelectionSortD();
    ptr->Display();

    return 0;
}