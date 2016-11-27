#ifndef __FUNC1_H__
#define __FUNC1_H__

#include <vector>
#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

typedef struct Node {
	int val;
	Node* next;
	Node() {}
	Node(int x)
	{
		val = x;
		next = NULL;
	}
}*List;


class MyList{
private:
	List pHead;
public:
	MyList()    
	{
		this->pHead = NULL;
	}
	~MyList()    
	{
		while (this->pHead != NULL)
		{
			List pTemp = pHead->next;
			delete pHead;
			pHead = pTemp;
		}
	}
	void Init()      
	{
		int a;
		char answer;
		List pTail, pNew;
		do 
		{
			cout << "Input Node value: ";
			cin >>a;
			if (pHead == NULL)
			{
				pHead = new Node;
				pHead->val =a;
				pHead->next = NULL;
				pTail = pHead;
			}
			else
			{
				pTail = pHead;
				while (pTail->next != NULL)
				{
					pTail = pTail->next;
				}
				pNew = new Node;
				pNew->val = a;
				pNew->next = NULL;
				pTail->next = pNew;
				pTail = pTail->next;
			}
			cout <<"Continue ? Y/N" <<endl;
			cin >>answer;
		} while (answer == 'Y' || answer == 'y');
	}
	List GetList()
	{
		return pHead;
	}
	int Init(vector<int>& v)
	{
		List pTail = pHead;
		List pNew;
		vector<int>::iterator v1 =  v.begin();
		if (v.size() == 0)
		{
			return -1;
		}
		while (v1 != v.end())
		{
			if (pHead == NULL)
			{
				pHead = new Node;
				pHead->val = *v1;
				pHead->next = NULL;
				pTail = pHead;
			}
			else
			{
				pTail = pHead;
				while (pTail->next != NULL)
				{
					pTail = pTail->next;
				}
				pNew = new Node;
				pNew->val = *v1;
				pNew->next = NULL;
				pTail->next = pNew;
				pTail = pTail->next;
			}
			v1++;
		}
		return 0;
	}
	int GetNodeCut()
	{
		int cnt=0;
		List pTemp = pHead;
		while (pTemp != NULL)
		{
			cnt ++;
			pTemp = pTemp->next;
		}
		return cnt;
	}

	void Add(int val)    
	{
		if (pHead == NULL)
		{
			pHead = new Node;
			pHead->val = val;
			pHead->next = NULL;
		}
		else
		{
			List pTemp = pHead;
			while (pTemp->next != NULL)
			{
				pTemp = pTemp->next; 
			}
			List pNew = new Node;
			pNew->val = val;
			pNew->next = NULL;
			pTemp->next = pNew;
		}
	}
	int DelNode(int k)
	{
		List p1,p2,pTemp;
		if (pHead == NULL)
		{
			return -1;
		}
		if(k<0 || k > this->GetNodeCut()-1)
		{
			return -1;
		}
		if (this->GetNodeCut() == 1)
		{
			delete pHead;
			pHead = NULL;
			return 0;
		}
		if (k == 0)
		{
			pTemp = pHead;
			pHead = pTemp->next;
			delete pTemp;
			return 0;
		}
		if (k == this->GetNodeCut()-1)
		{
			pTemp = pHead;
			while (pTemp->next->next != NULL)
			{
				pTemp = pTemp->next;
			}
			p1 = pTemp->next;
			pTemp->next = NULL;
			delete p1;
			return 0;
		}
		p1 = pHead;
		int i = 0;
		while (i<k-1)
		{
			p1 = p1->next;
			i++;
		}
		p2 = p1->next;
		pTemp = p2->next;
		p2->next = NULL;
		p1->next = pTemp;
		delete p2;
		return 0;
	}
	int InsertNode(int val, int k)
	{
		if (pHead == NULL)
		{
			return -1;
		}
		if (k<0 || k>this->GetNodeCut()-1)
		{
			return -1;
		}
		if(k == this->GetNodeCut()-1)
			this->Add(val);

		List p1, p2, pTemp;

		if (k==0)
		{
			pTemp = pHead;
			p1 = new Node;
			p1->val = val;
			p1->next = NULL;
			pHead = p1;
			p1->next = pTemp;
			return 0;
		}
		p1 = pHead;
		int i=0;
		while(i< k-1)
		{
			p1 = p1->next;
			i++;
		}
		p2 = p1->next;
		pTemp = new Node;
		pTemp->val = val;
		pTemp->next = NULL;
		p1->next = pTemp;
		pTemp->next = p2;
		return 0;
	}
	int FindNode(int val)     
	{
		List pTemp;
		pTemp = pHead;
		int i=0;
		while (pTemp != NULL)
		{
			if (pTemp->val == val)
			{
				return i;
			}
			pTemp = pTemp->next;
			i++;
		}
		return -1;
	}
	void traverse()
	{
		List pTemp = pHead;
		while (pTemp != NULL)
		{
			cout	<< pTemp->val << "\t";
			pTemp = pTemp->next;
		}
		cout << endl;
	}
	void	SortList()
	{
		int n = this->GetNodeCut();
		List p1, p2;
		for(int i =0; i< n-1; i++)
		{
			p1 = pHead;
			for (int j = 0; j< n-i-1; j++)
			{
				p2 = p1->next;
				if (p1->val < p2->val)
				{
					int temp = p1->val;
					p1->val = p2->val;
					p2->val = temp;
				}
				p1 = p1->next;
			}
		}
	}
};

void print(vector<int> exp);

class Solution 
{
public:
	List	addTwoNumbers(List l1, List l2);
	vector<int> addTwoVector(vector<int>& v1, vector<int>& v2);
};



#endif