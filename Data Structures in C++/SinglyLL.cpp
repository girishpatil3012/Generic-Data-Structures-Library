#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class SinglyLL
{
    private:
        struct node<T> *Head;
        int Count;
    
    public:
        SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
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
void SinglyLL<T>::InsertLast(T no)
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
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct node<T> *temp = Head;

        Head = Head->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct node<T> *temp = Head;

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
void SinglyLL<T>::InsertAtPosition(T no, int ipos)
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

        struct node<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPosition(int ipos)
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
        struct node<T> *temp = Head;
        struct node<T> *tempdelete = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }
}

// Write your main function(Entry Point Function) here