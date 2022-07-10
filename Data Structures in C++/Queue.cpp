#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class Queue
{
    private:
        struct node<T> *Head;
        int Count;

    public:
        Queue();
        void Enqueue(int);
        void Dequeue();
        void Display();
        int CountElements();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(int no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next != NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void Queue<T>::Dequeue()
{
    int no = 0;
    struct node<T> *temp = NULL;
    temp = Head;

    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        no = Head->data;
        delete Head;
        Head = NULL;        // VIMP
    }
    else
    {
        no = Head->data;
        Head = temp->next;
        delete temp;
    }
    cout<<"Removed elements is : "<<no<<endl;
    Count--;
}

template<class T>
void Queue<T>::Display()
{
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else
    {
        cout<<"Elements of Queue are : "<<endl;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

template<class T>
int Queue<T>::CountElements()
{
    return Count;
}

// Write your main function(Entry Point Function) here