# 线性表

[TOC]

## 1. 顺序表

* 存储结构：逻辑上相邻，物理上也相邻；
* 查找元素的时候，可以根据首地址与单位元素的大小直接计算得出，数量级为O(1)。

### 1.1 实现方式

1. 静态分配（不举例，静态数组）

   使用静态数组实现，一旦确定大小就不能改变。

2. 动态分配（初始化为静态数组，通过malloc函数对空间进行扩张）

   使用malloc和free函数进行容量上的伸缩，实现动态的调整顺序表的大小

### 1.2 特点

1. 随机访问
2. 存储密度高，内存中连续大片的存储
3. 拓展容量不方便
4. 插入、删除等操作不方便

### 1.3 动态分配方式
#### 插入操作

1. 将插入位置后面的所有元素后移一位
2. 将元素插入
**此种方法，时间复杂度为O(n)**

```C++
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
```
#### 删除操作
1. 依次将删除位置的后继元素往前覆盖
**此种方法，时间复杂度为O(n)**

```C++
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
```

#### 查找操作

1. 按照所给的键值在线性表中查找
2. 找到后返回下标

```c++
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
```

### 1.4 总结

**优点**

* 存储密度大：各个元素相邻（结点本身所占存储量/结点结构所占存储量）
* 可以随机存取表中任一元素

**缺点**

* 在执行删除和查找操作时，需要大量的移动操作
* 浪费存储空间（申请的空间可能用不完）
* 实质上属于静态的存储形式，元素的个数不能实现真正意义上的自由扩充

## 2. 链表

* 存储结构：使用物理位置的任意存储单元来存放元素
* 逻辑上相邻的元素，物理上可能不相邻；元素直接的存储地址可能连续也可能不连续

### 2.1 实现方式

​	每一个节点包括两个部分：数据域和指针域

​	**数据域**：记录元素的值

​	**指针域**：记录元素的下一个或上一个元素的地址（逻辑结构的表示）

​	对于第一个元素（**首元结点**）的位置，使用只包含指针域的**头结点**指向第一个元素

​	对于最后一个元素，其指针域置为空（NULL、0）

### 2.2 特点

1. 存储位置任意
2. 顺序存取：访问时只能通过头指针进入链表，再通过每一个结点的指针域依次访问其余结点

### 2.3 单链表（带头结点）

​	每个结点只含有一个指针域的链表。

#### 初始化

​	构造一个空表，头结点指针域为空

* 生成新节点作头结点，用头指针L指向头结点
* 将头结点的指针域置空

**算法描述**

```C++
bool InitList(Linklist &L) {
    //requier memory
    L = (Linklist)malloc(sizeof(Lnode));
    //set the next pointer to NULL
    L->next = NULL;
    cout << "---initialized" << endl; 
    return true;
}
```

#### 判断链表是否为空

​	链表中无元素，**头指针和头结点（若有）依然存在**。

* 直接判断头结点指针域是否为空

**算法描述**

```c++
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
```

#### 销毁单链表

​	链表销毁之后，链表在内存中消失。

* 从头指针开始，依次释放所有的结点

**算法描述**

```c++
void DestroyList(Linklist &L) {
    Linklist p;
    while(L) {
        p = L;
        L = L->next;
        free(p);
    }
}
```

#### 清空单链表

​	**与销毁区分开**，清空后链表依然存在于内存中，但是链表中没有元素，成为空链表。

* 从首元结点开始依次释放所有结点，并将头结点置空

**算法描述**

```c++
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
```





