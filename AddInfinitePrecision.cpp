#include<iostream>
#include<list>
#include<cmath>
using  namespace std;
int add(list<int>::iterator l1_beg,list<int>::iterator l1_end,list<int>::iterator l2_beg,list<int>::iterator l2_end,list<int> &dest)
{
	if(l1_beg == l1_end || l2_beg == l2_end)
	{
		return 0;
	}else
	{
		int s = *l1_beg + *l2_beg;
		s+= add(++l1_beg,l1_end,++l2_beg,l2_end,dest);
		dest.push_front(s%10);
		return s/10;
	}
}
void display(list<int>::iterator beg,list<int>::iterator end)
{
	while(beg!=end)
	{
		cout<<*beg++<<" ";
	}
	cout<<"\n";
}
int addOverflow(list<int>::iterator beg,int n,list<int> &dest,int overFlow)
{
	if(n==0) return overFlow;
	else {
		int partialOver = *beg;
		partialOver+=addOverflow(++beg,--n,dest,overFlow);
		dest.push_front(partialOver%10);
		return partialOver/10;
	}

}
int main()
{
	int a[]={9,3,4,2,3};
	int b[]={9,8,9,9,0};
	list<int> l1(a,a+5);
	list<int> l2(b,b+5);
	list<int> dest;
	list<int>::iterator l1_beg = l1.begin();
	list<int>::iterator l1_end = l1.end();
	list<int>::iterator l2_beg = l2.begin();
	list<int>::iterator l2_end = l2.end();

	int s1 = l1.size();
	int s2 = l2.size();
	if(s1>s2)
	{
		while(s1>s2)
		{
			l1_beg++;
			--s1;
		}
	}else
	{
		while(s2>s1)
		{
			l2_beg++;
			--s2;
		}
	}
	//Add the list part of the 2 lists
	int overflow = add(l1_beg,l1_end,l2_beg,l2_end,dest);
	s1 = l1.size();
	s2 = l2.size();
	//Now add the overflow integer to the list
	if(s1>s2)dest.push_front(addOverflow(l1.begin(),s1-s2,dest,overflow));
	if(s2>s1)dest.push_front(addOverflow(l2.begin(),s2-s1,dest,overflow));
	else if (overflow)dest.push_front(overflow);

	//Display properly
	int dest_size = dest.size();
	while(dest_size>s1)
	{
		cout<<"  ";
		dest_size--;
	}
	dest_size = dest.size();
	display(l1.begin(),l1.end());
	while(dest_size>s2)
	{
		cout<<"  ";
		dest_size--;
	}
	display(l2.begin(),l2.end());
	cout<<"-------------------------------"<<"\n";
	display(dest.begin(),dest.end());


}
