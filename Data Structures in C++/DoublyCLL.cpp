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
class DoublyCLL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;
    
    public:
        DoublyCLL();
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
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;

    Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

template<class T>
void DoublyCLL<T>::Display()
{
    struct node<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Circular Linked List are : "<<endl;

    do 
    {
        cout<<"|"<<temp->data<<"| <->";
        temp = temp->next;
    }while(temp != Tail->next);
    cout<<endl;
}

template<class T>
int DoublyCLL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::InsertAtPosition(T no, int ipos)
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
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPosition(int ipos)
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