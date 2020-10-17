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

int main() {

    int length = 0;
    clock_t startTime, endTime;
    vector<int> seq = createSeq();
    showSeq(seq);
    cout << "----------------" << endl;
    startTime = clock();
    bubbleSort(seq);
    endTime = clock();
    cout << "----------------" << endl;
    showSeq(seq);
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");

    return 0;

}