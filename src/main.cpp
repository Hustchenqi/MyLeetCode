#include "func1.h"

int main()
{	
	Solution sample;
	int arr1[5] = {2,5,3,2,4};
	int arr2[7] = {1,7,6,7,6,9,9};
	vector<int> v1(arr1, arr1+5);
	vector<int> v2(arr2, arr2+7);
	print(v1);
	print(v2);
	print(sample.addTwoVector(v2, v1));

	MyList l1, l2;
	l1.Init(v1);
	l2.Init(v2);
	List result = sample.addTwoNumbers(l1.GetList(), l2.GetList());
	cout <<endl;
	cout<<"Hello World!" <<endl;
	return 0;
}