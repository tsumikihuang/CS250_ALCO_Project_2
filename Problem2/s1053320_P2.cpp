#include<iostream>
#include <vector>

using namespace std;

/*

有N個數字，N%M後，依%值，由小至大排序輸出。

若%相同，則奇數優先於偶數，且奇數字大至小，偶數小至大

*/
void sort(vector<int>& nums, enum sort_order order);

enum sort_order {
	s2B,
	B2s
};

int main() {

	//N = 數列大小
	//M = 要mod的值
	int N, M;
	cin >> N >> M;

	int* numbers = new int[N];
	vector<int> odd_num, even_num;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp % 2 == 0)
			even_num.push_back(temp);
		else
			odd_num.push_back(temp);
	}

	sort(even_num, s2B);//將偶數由小至大排列
	sort(odd_num, B2s);//將奇數由大至小排列

	//將所有數字%M 從%=0奇數先開始輸出
	for (int mod = 0; mod < M; mod++) {
		for (int odd_i = 0; odd_i < odd_num.size(); odd_i++) {		//奇數先~
			if (odd_num[odd_i] % M == mod) {
				cout << odd_num[odd_i] << endl;
			}
		}
		for (int even_i = 0; even_i < even_num.size(); even_i++) {		//換偶數~
			if (even_num[even_i] % M == mod) {
				cout << even_num[even_i] << endl;
			}
		}
	}

    system("pause");
	return 0;
}


void sort(vector<int> &nums, enum sort_order order) {

	int* p = &nums[0];
	int* p_n = p;	//一直跑的那個

	//由小至大排序
	if (order == s2B) {
		p_n++;
		while (p < &nums[nums.size() - 1]) {
			if (*p > *p_n)
				swap(*p , *p_n);

			if (p_n == &nums[nums.size() - 1]) {
				p++;
				p_n = p;
			}
			else {
				p_n++;
			}
		}
	}
	else if (order == B2s) {
		p_n++;
		while (p < &nums[nums.size() - 1]) {
			if (*p < * p_n)
				swap(*p, *p_n);

			if (p_n == &nums[nums.size() - 1]) {
				p++;
				p_n = p;
			}
			else {
				p_n++;
			}
		}

	}
}

void swap(int &p, int &p_n) {
	int temp = p;
	p = p_n;
	p_n = temp;
}