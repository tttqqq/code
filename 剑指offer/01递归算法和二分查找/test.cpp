// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	//从某一行中查找元素是否存在，运用二分查找
	bool FindElementFromOneLine(int target, int low, int high, vector<int> &oneLine) {
		if (low > high) {
			return false;
		}
		int midle = (low + high) / 2;
		
		if (target == oneLine[midle]) {
			return true;
		}
		else if (target > oneLine[midle]) {
			low = midle + 1;
			return FindElementFromOneLine(target, low, high, oneLine);
		}
		else {
			high = midle - 1;
			return FindElementFromOneLine(target, low, high, oneLine);
		}
	}



	bool Find(int target, vector<vector<int> > array) {
		int lenth = array.size();
		if (0 == lenth) {
			return false;
		}

		int oneLineLenth = array[0].size();
		if (0 == oneLineLenth) {
			return false;
		}
		cout << "lie:" << lenth << "hang:" << oneLineLenth << endl;
		
		for (int i = 0; i < lenth; i++) {
			if (array[i][0] <= target && array[i][oneLineLenth - 1] >= target) {
				if (true == FindElementFromOneLine(target, 0, oneLineLenth - 1, array[i])) {
					return true;
				}
			}
		}
		return false;
	}
	vector<vector<int> > array;
};



int main()
{
	Solution obj;
	vector<int> vecTmp;
	for (int i = 0; i < 3; i++) {
		vecTmp.clear();
		for (int j = 0; j < 3; j++) {
			vecTmp.push_back(i+j*2);
		}
		obj.array.push_back(vecTmp);
	}

	if (true == obj.Find(6, obj.array)) {
		cout << "find it!" << endl;
	}
	else
	{
		cout << "not find the target" << endl;
	}
    return 0;
}

