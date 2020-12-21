#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

int getRandomNumber() {

	int RandomNumber;
	RandomNumber = rand() % 100 + 1;
	return RandomNumber;

}

void showSeq(vector<int> seq) {

    for (vector<int>::const_iterator iter = seq.begin();iter != seq.end(); iter++) {
        cout << (*iter) << " ";
    }
    cout << endl;

}

vector<int> createSeq() {

    int length = 0;
    int temp = 0;
    vector<int>seq;

    cout << "输入待排序元素个数: ";
    cin >> length;

    srand((unsigned)time(NULL));//set random seed
    for(int i = 0; i < length; i++){
        temp = getRandomNumber();
        seq.push_back(temp);
    }

    return seq;

}

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

int main() {

    clock_t startTime, endTime;
    vector<int> seq = createSeq();
    showSeq(seq);
    cout << "----------------" << endl;
    startTime = clock();
    quickSort(seq, 0, seq.size()-1);
    endTime = clock();
    cout << "----------------" << endl;
    showSeq(seq);
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");

    return 0;

}

/**
 * 这个快排的划分方式需要用到辅助空间存枢轴，还可以使用另外的原地
 * 划分的方式：
 *      以第一个元素为枢轴，从尾端旗标开始搜索比枢轴小的元素，搜索到
 *      后等待首端旗标开始搜索比枢轴大的元素，搜索到之后与尾端的旗标
 *      进行交换，以此反复直至两个旗标相遇。最后将旗标的值与枢轴
 *      交换。
*/