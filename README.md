# 常用内排序算法C++实现

[TOC]

## 基于交换的排序

### 冒泡排序

基本思想：第一趟排序，从前往后两两比较相邻的元素的值，如果是逆序，则交换，知道所有的元素比较完。此时，最后一个元素就已经排好序。往后每一趟，除去已排好元素，执行相同的步骤，最多n-1趟即可完成排序。

空间复杂度：O(1)

时间复杂：O(n^2)

稳定性：稳定

代码实现：

```c++
void bubbleSort(vector<int>&seq) {

    int temp = 0;
    int flag = 1;
    for(int i = 0; i < seq.size() - 1; i++) {
        flag = 0;
        for(int j = 0; j < seq.size() - 1 - i; j++) {
            if(seq[j] > seq[j+1]) {
                swap(seq[j], seq[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
        showSeq(seq);
    }

}
```



### 快速排序

基本思想：基于分治的思想，选取一个基准元素对序列进行划分，划分之后，基准元素的左边全比它小，右边全比它大（此时可以认为该基准元素已经处于其最终位置啦）。再对其左右的子表进行划分。最后划分完成后，序列就已经有序。

空间复杂度：O(1)

时间复杂度：O(nlogn)

稳定性：不稳定

代码实现：

```c++
int partition(vector<int> &seq, int low, int high) {

    int temp = seq[low]; //将待排元素的第一个作为枢轴，对元素进行划分，小的在左边，大的在右边
    while(low < high) { //左标和右标逐个往中间收拢寻找符合的元素
        while(low < high && seq[high] >= temp) --high; //寻找目前位于右端但是小于枢轴的元素，找到后停止
        seq[low] = seq[high]; //将比枢轴小的元素放到左边
        while(low < high && seq[low] < temp) ++low; //寻找目前位于左端但是大于枢轴的元素，找到后停止
        seq[high] = seq[low];
    }
    seq[low] = temp; //此时low和high相遇，位于待排元素的中间位置，将枢轴的值存入
    return low; //返回枢轴的最终位置

}

void quickSort(vector<int> &seq, int low, int high) {
    
    int pivot = 0;
    if(low < high) {
        pivot = partition(seq, low, high); //划分操作
        showSeq(seq);
        quickSort(seq, low, pivot-1); //对子表进行递归划分，当递归结束时，序列便已经有序
        quickSort(seq, pivot+1, high);
    }

}
```



## 基于选择的排序

### 简单选择排序

基本思想：每次从待排序序列中选取最小（或最大）的元素，将其放到已排子序列的末尾（即将其与待排序列的首元素交换一下）。

空间复杂度：O(1)

时间复杂度：O(n^2)

稳定性：不稳定

代码实现：

```c++
void selectSort(vector<int> &seq, int n) {

    int smallest = -1;//保存最小元素的下标
    int i, j;
    for(i = 0; i < n-1; i++) {
        smallest = i;//以当前待排序序列的首元素为最小值
        for(j = i+1; j < n; j++) {//从待排序元素中逐个遍历找出最小的元素
            if(seq[j] < seq[smallest]) smallest = j;//扫描到更小的元素则记下其下标
        }
        //将最小值交换到待排序列之首（已排序列之尾）
        int temp = seq[i];
        seq[i] = seq[smallest];
        seq[smallest] = temp;
        //每一趟输出一次结果
        showSeq(seq);
    }

}
```



### 堆排序

## 基于插入的排序

### 直接插入排序

基本思想：每次将一格待排序的记录按其关键字的大小插入到序列前端已排好序的子序列中，直到全部记录插入完成。

空间效率：仅使用了常数个辅助单元，因而空间复杂度为O(1)。

时间效率：每趟排序选择一个数字向前插入，共执行n-1趟，每一趟的插入过程在寻找插入位置时平均用时为O(n)。因此，时间复杂度为O(n^2)

稳定性：稳定

实现代码：

```c++
void insertSort(vector<int> &seq) {

    int temp = 0; //哨兵元素
    int i = 0, j = 0;
    for(i = 1; i < seq.size(); i++) { //初始时以第一个元素作为有序序列，从第二个元素开始比较
        if (seq[i] < seq[i-1]) { //如果该元素小于其前驱，则将其插入有序表
            temp = seq[i]; //将该元素的值赋值给哨兵
        
            for(j = i-1; (temp < seq[j]) && (j >= 0); --j) { //从后往前查找插入的位置(注意j的大小，不要溢出到负值)
                seq[j+1] = seq[j]; //每次移动都发生一次交换
            }
            
            seq[j+1] = temp; //将哨兵值赋值到插入位置
        }
        showSeq(seq);
    }

}
```



### 折半插入排序

基本思想：与直接插入排序基本思想相同，只是在选取插入位置时使用二分查找。

复杂度：时间复杂度，空间复杂度都与直接插入排序相同。

代码实现：仅给出二分查找算法的代码

```c++
int binarySearch(vector<int> seq, int low, int high, int target) {
    
    while(low < high) {
        mid = (low + high)/2;
        if(seq[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return low;
    
}
```

