#include <iostream>
#include <stdlib.h> 
using namespace std;

typedef struct Lnode {
    int data;
    struct Lnode *next;
}Lnode, *Linklist;

bool InitList(Linklist &L) {
    //requier memory
    L = (Linklist)malloc(sizeof(Lnode));
    //set the next pointer to NULL
    L->next = NULL;
    //test

    for(int i = 1; i <= 5; i++) {
        Lnode *p = (Linklist)malloc(sizeof(Lnode));
        p->data = i * 100;
        p->next = L->next;
        L->next = p;
    }
    
    //end test
    cout << "---initialized" << endl; 
    return true;
}

bool IsEmpty(Linklist &L) {
    //not empty
    if(L->next) {
        cout << "---not empty" << endl;
        return false;
    }
    //empty
    cout << "---empty" <<endl;
    return true;
}

void DestroyList(Linklist &L) {
    Linklist p;
    //end condition: L == NULL
    while(L) {
        p = L;
        L = L->next;
        free(p);
    }
}

void ClearList(Linklist &L) {
    Linklist p, q;
    p = L->next;//keep the head node
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    cout << "---List cleared!" <<endl;
}

void PrintList(Linklist &L) {
	int count = 0;
    Lnode *p = L->next;
    while(p) {
        cout << "Data[" << count << "] = "<< p->data << endl;
        p = p->next;
        count++;
    }
}
    
int main() {
    Linklist L;
    InitList(L);
    PrintList(L);
    IsEmpty(L);
	ClearList(L);
    IsEmpty(L);
    return 0;
}
