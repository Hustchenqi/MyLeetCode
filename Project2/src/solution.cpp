#include "solution.h"

int Solution::romanToInt(string s)
{
	CharInt roman;
	int val = 0;
	string::iterator str = s.begin();
	roman.insert(make_pair('I', 1));
	roman.insert(make_pair('V', 5));
	roman.insert(make_pair('X', 10));
	roman.insert(make_pair('L', 50));
	roman.insert(make_pair('C',100));
	roman.insert(make_pair('D', 500));
	roman.insert(make_pair('M', 1000));
	while(str!= s.end()&&(str+1) != s.end())
	{
		cout << *str <<endl;
		string::iterator next = str+1;
		if (roman[*str] < roman[*next])
		{
			int temp = roman[*next] - roman[*str];
			val += temp;
			str += 2;
		}
		else
		{
			int temp = roman[*str];
			val += temp;
			str++;
		}
	}
	if(str == s.end())
	{
		return val;
	}
	if(str !=s.end() && (str+1) == s.end())
	{
		cout <<*str <<endl;
		return val+roman[*str];
	}
	return 0;
}

string Solution::intToRoman(int num)
{
	string res;
	if(num > 3999)
		return "";
	while (num != 0)
	{
		if (num >=900 && num <=3999)
		{
			checkGE900(num, res);
		}
		else if (num>= 400 && num<900)
		{
			checkGE400(num, res);
		}
		else if (num>=90 && num<400)
		{
			checkGE90(num, res);
		}
		else if (num>=40 && num <90)
		{
			checkGE40(num,res);
		}
		else if(num>=10 && num<40)
		{
			checkGE10(num, res);
		}
		else
			checkL10(num, res);
	}
	return res;
}

void checkGE900(int& num, string& res)
{
	if (num >=1000)
	{
		while (num >=1000)
		{
			num -= 1000;
			res+="M";
		}
	}
	else
	{
		num -= 900;
		res += "CM";
	}
}

void checkGE400(int& num, string& res)
{
	if (num>=400 && num<500)
	{
		num -=400;
		res += "CD";
	}
	else
	{
		num -= 500;
		res+= "D";
	}
}

void	checkGE90(int& num, string& res)
{
	if (num>=100)
	{
		while (num >=100)
		{
			num-=100;
			res+="C";
		}
	}
	else
	{
		num-=90;
		res+= "XC";
	}
}

void checkGE40(int& num, string& res)
{
	if (num>=40 && num<50)
	{
		num-=40;
		res+= "XL";
	}
	else
	{
		num -=50;
		res +="L";
	}
}

void checkGE10(int& num, string& res)
{
	while(num>=10)
	{
		num-=10;
		res+="X";
	}
}

void checkL10(int& num, string& res)
{
	switch(num)
	{
	case 1:
		res+="I";
		break;
	case 2:
		res+= "II";
		break;
	case 3:
		res+="III";
		break;
	case 4:
		res+="IV";
		break;
	case 5:
		res+="V";
		break;
	case 6:
		res+="VI";
		break;
	case 7:
		res+="VII";
		break;
	case 8:
		res+="VIII";
		break;
	case 9:
		res+="IX";
		break;
	default:
		break;
	}
	num = 0;
}