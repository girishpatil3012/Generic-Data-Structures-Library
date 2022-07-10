#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class Stack
{
    private:
        struct node<T> *Head;
        int Count;

    public:
        Stack();
        void Push(T);
        void Pop();
        void Display();
        int CountElements();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
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
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void Stack<T>::Pop()
{
    T no;
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
void Stack<T>::Display()
{
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }
    else
    {
        cout<<"Elements of Stack are : "<<endl;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

template<class T>
int Stack<T>::CountElements()
{
    return Count;
}

// Write your main function(Entry Point Function) here