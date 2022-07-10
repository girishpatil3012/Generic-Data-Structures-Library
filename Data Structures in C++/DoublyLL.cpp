#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct node<T> *Head;
        int Count;
    
    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int CountNode();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = NULL;
        temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = NULL;
        temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct node<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}

// Write your main function(Entry Point Function) here