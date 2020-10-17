/**
*static sqList
*InitList: innitialize the sqList; 
*/
#include <stdio.h>
#define MAXSIZE 10

typedef struct {
	int data[MAXSIZE];  //the max size of the elements: 10
	int length; //to store the current length of the sqList
} SqList;


/**
*SqList &L: the List need to be initialize
*Time complexity: O(n)
*/
void InitList(SqList &L) {
	for(int i = 0; i < MAXSIZE; i++) {  //traverse the sqlist and set the value of every element to 0;
		L.data[i] = -1;
	}
	L.length = 0;  //set the val "length" to 0

	//test
	for(int j = 0; j < 5; j++) {
		L.data[j] = j + 1;
		L.length = L.length + 1;
	}
	//test
} 

/**
*SqList &L: the being insert List
*int loc: the location of the insert ele
*int val: the value of the insert ele
*Time complexity:O(n)
*/
bool ListInsert(SqList &L, int loc, int val) {

	//if the list is full, failed to insert
	if(L.length == MAXSIZE) {
		printf("The list is full now!\n");
		return false;
	}

	//if the insert loction is smaller than the head and bigger than the tail,
	//failed to insert
	if(loc < 1 || loc > L.length) {
		printf("Illegal location!\n");
		return false;
	}

	//move the every last ele to the next loction
	for(int i = L.length; i >= loc; i--) {
		L.data[i] = L.data[i - 1];
	}
	
	//insert the ele to the target loction
	L.data[loc - 1] = val;
	L.length = L.length + 1;

	return true;
}

/**
*ListDelete
*SqList &L;
*int loc: location of the ele being deleted
*int &deletedVal: the value of the ele being deleted 
*Time complexity: O(n)
*/
bool ListDelete(SqList &L, int loc, int &deletedVal) {
	//if the delete loction is smaller than the head and bigger than the tail,
	//failed to delete
	if(loc < 1 || loc > L.length) {
		printf("Illegal location!\n");
		return false;
	}

	//get the value of the deleted ele
	deletedVal = L.data[loc - 1];

	//move the ele behind the target ele forward for 1 loc
	for(int i = loc; i < L.length; i++) {
		L.data[i - 1] = L.data[i];
	}

	L.length = L.length - 1;

	return true;
}

int main() {
	SqList L;
	int deletedVal = -1;
	InitList(L);

	//test
	printf("Original list: \n");
	for(int i = 0; i < L.length; i++) {
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	//insert test
	ListInsert(L, 2, 100);
	printf("insert 100 into loc 2: \n");
	for(int i = 0; i < L.length; i++) {
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	//delete test
	ListDelete(L, 2, deletedVal);
	printf("delete loc 2: \n");
	for(int i = 0; i < L.length; i++) {
		printf("data[%d] = %d\n", i, L.data[i]);
	}
	//test

	return 0;
}
