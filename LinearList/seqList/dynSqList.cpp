#include <stdio.h>
#include <stdlib.h>

#define InitSize 5 //the size of the original List

typedef struct {
	int *data; //point to the first address of the sqList
	int maxSize; //the maxSize of the whole List
	int length; //current length of the List
} SqList; //a dynamic sqList


/**
*SqList &L: the list need to be initialized
*/
void InitList(SqList &L) {
	//request some memory of the size "InitSize"
	L.data = (int *)malloc(InitSize * sizeof(int));
	//set current size to 0
	L.length = 0;
	//set maxSize to InitSize
	L.maxSize = InitSize;
}

/**
*SqList &L: the Sqlist need to be appended
*int len: the extra size needed
*/
void IncreaseSizeOfList(SqList &L, int len) {
	//a temp pointer point to the original datas, then copy to the new bigger size List
	int *p = L.data; 
	//request a new memory of the size "maxSize + len"
	L.data = (int *)malloc((L.maxSize + len) * sizeof(int));
	//copy the original List to the new List
	for(int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	//set the maxSize of the List to the added value
	L.maxSize = L.maxSize + len;
	//release the original memory
	free(p);

	printf("**************Appened\n");
}

/**
*SqList &L
*int loc: the location into which the value is gonna be insert
*int val: the value of the inserted ele
Time complexity: O(n)
*/
bool InsertList(SqList &L, int loc, int val) {

	if(loc < 1 || loc > L.length + 1) {
		printf("Check the location!");
		return false;
	}

	if(L.length == L.maxSize) {
		IncreaseSizeOfList(L, 5);
	}

	for(int i = L.length - 1; i >= loc -1; i--) {
		L.data[i + 1] = L.data[i];
	}

	L.data[loc - 1] = val;

	L.length = L.length + 1;

	return true;
}

/**
*SqList &L
*int key: the target key value of the element 
*note: return the location of the element which is equal to the key value
*Time complexity: O(n)
*/
int LocateEle(SqList &L, int key) {
	//traverse the sqList to find the location of the element whose value is equal to "key"
	for(int i = 0; i < L.length; i++) {
		if(L.data[i] == key) {
			return i + 1;
		}
	}
	
	printf("Cannot locate the element.\n");
	return -1;
}

/**
*int loc: the loction of the deleted elem
*int deletedVal: the value of the deleted elem
*Time complexity: O(n)
*/
bool DeleteList(SqList &L, int loc, int &deletedVal) {
	//judge if the loc is legal
	if(loc < 1 || loc > L.length) {
		return false;
	}

	deletedVal = L.data[loc - 1];

	for(int j = loc; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}

	L.length = L.length - 1;

	return true;
}

int main() {
	SqList L;

	//initialize the List and print the size.
	InitList(L);

	//test

	//insert
	InsertList(L, 1, 100);
	InsertList(L, 2, 200);
	InsertList(L, 3, 300);
	printf("----------------\nInsert 100, 200, 300 into the first 3 locations\n");
	for(int i = 0; i < L.length; i++){
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	InsertList(L, 2, 400);	
	printf("----------------\nInsert 400 into the 2nd location\n");
	for(int i = 0; i < L.length; i++){
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	InsertList(L, 3, 500);	
	printf("----------------\nInsert 500 into the 3rd location\n");
	for(int i = 0; i < L.length; i++){
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	InsertList(L, 4, 600);	
	printf("----------------\nInsert 500 into the 3rd location\n");
	for(int i = 0; i < L.length; i++){
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	printf("----------------\nLocate 600 in the List\n");
	int res = LocateEle(L, 600);
	printf("Loc: %d\n", res);
	printf("----------------\nLocate 456 in the List\n");
	res = LocateEle(L, 456);
	printf("Loc: %d\n", res);

	printf("----------------\nDelete the 2nd elementt\n");
	int deletedVal = 0;
	DeleteList(L, 2, deletedVal);
	printf("deletedVal: %d\n", deletedVal);
	for(int i = 0; i < L.length; i++){
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	//test

	
	return 0;
}
