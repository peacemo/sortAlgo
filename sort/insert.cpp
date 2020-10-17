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

int main() {

    clock_t startTime, endTime;
    vector<int> seq = createSeq();
    showSeq(seq);
    cout << "----------------" << endl;
    startTime = clock();
    insertSort(seq);
    endTime = clock();
    cout << "----------------" << endl;
    showSeq(seq);
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");
    return 0;

}