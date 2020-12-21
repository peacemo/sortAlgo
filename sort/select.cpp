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

int main() {

    clock_t startTime, endTime;
    vector<int> seq = createSeq();
    showSeq(seq);
    cout << "----------------" << endl;
    startTime = clock();
    selectSort(seq, seq.size());
    endTime = clock();
    cout << "----------------" << endl;
    showSeq(seq);
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");

    return 0;

}