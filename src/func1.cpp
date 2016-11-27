#include "func1.h"
void print(vector<int> exp)
{
	vector<int>::iterator item = exp.begin();
	if (exp.size()==0)
	{
		cerr << "empty vector";
	}
	else
	{
		while(item != exp.end())
		{
			cout << *item <<"\t";
			item++;
		}
		cout <<"\n";
	}
}

vector<int> Solution::addTwoVector(vector<int>& v1, vector<int>& v2)
{
	vector<int>::iterator ptr1 = v1.begin();
	vector<int>::iterator ptr2 = v2.begin();
	vector<int> suma;

	int fla = 0;
	int rest = 0;
	int sum = 0;

	while (ptr1 != v1.end() && ptr2 != v2.end())
	{
		sum = *ptr1 + *ptr2 + fla;
		rest = sum %10;
		if(sum>=10)
			fla = 1;	
		else
			fla = 0;
		suma.push_back(rest);
		ptr1 ++;
		ptr2 ++;
	}
	if (ptr1 != v1.end())
	{
			while((ptr1!= v1.end()) && (ptr2 == v2.end()))
			{
				if ((*ptr1 == 9) &&(ptr1+1)!=v1.end() && fla == 1)
				{
					suma.push_back(0);
					fla =1;
				}
				else if ((*ptr1 == 9) &&(ptr1+1)==v1.end() && fla==1)
				{
					suma.push_back(0);
					suma.push_back(1);
					break;
				}
				else
				{
					suma.push_back(*ptr1+fla);
					fla = 0;
				}
				ptr1++;
			}
	}
	else
	{
			while((ptr2!= v2.end()) && (ptr1 == v1.end()))
			{
				if ((*ptr2 == 9) &&(ptr2+1)!=v2.end()&& fla==1)
				{
					suma.push_back(0);
					fla =1;
				}
				else if ((*ptr2 == 9) &&(ptr2+1)==v2.end()&&fla==1 )
				{
					suma.push_back(0);
					suma.push_back(1);
					break;
				}
				else
				{
					suma.push_back(*ptr2+fla);
					fla = 0;
				}
				ptr2++;
			}
	}
	return suma;
}

List Solution::addTwoNumbers(List l1, List l2)
{
	if(l1==NULL)
		return l2;
	else if(l2 == NULL)
		return l1;
	List phead = new Node;
	vector<int> list1;
	vector<int> list2;

	while (l1 != NULL)
	{
		list1.push_back(l1->val);
		l1 = l1->next;
	}
	while(l2 != NULL)
	{
		list2.push_back(l2->val);
		l2 = l2->next;
	}
	vector<int> ret = addTwoVector(list1,list2);
	MyList* res = new MyList;
	res->Init(ret);
	res->traverse();
	return res->GetList();
}