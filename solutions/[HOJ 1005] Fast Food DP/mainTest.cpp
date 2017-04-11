
//============ACCEPTED BY : HOJ=============
//============TIME : 0.50s=========
//============MEMORY : 1588 K======
//============TIME COMPLEXITY : O(n^2)==
//============SPACE COMPLEXITY : O(n^2)=
//============DATE : 2017-04-11 10:48:18========
#include <iostream>

#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution{
public:
	int solve(int *A,int len,int k)
	{
		this->klen = k;
		this->len = len;
		this->A = A;
		S= new int[len *k];//S[i][k],  i*k + ...
		one = new int[len * len];
		acc = new int[len * len];
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
			{
				if(i==j)one[i*len + j]=0;
				else one[i*len + j]=-1;
				if(j<k)S[i*k + j]=-1;
				if(i==j)acc[i*len + j]=A[j];
				else acc[i*len + j]=acc[i*len + j -1] + A[j];
			}
		if (k==1)return getOne(0,len-1);
		else return lessSolve(0,len-1,k);
	}
	void solveEnd()
	{
		delete [] S;
		delete []one;
		delete[] acc;
	}
	int lessSolve(int i,int j,int k)//k==0 means 1
	{
		int index1 = i*klen + k;
		if(S[index1]==-1)
		{
			int min=-1;
			for(int zd=i;zd<=j-k+1;zd++)
			{
				int oneval;
				if(k-1>1)
				{
					oneval=lessSolve(zd+1,j,k-1);
				}else{
					int onebase = (zd+1)*len + j;
					if(one[onebase]==-1)
					{
						one[onebase]=getOne(zd+1,j);
					}
					oneval=one[onebase];
				}
				int thisval=oneval + getOne(i,zd);
				if(min==-1 || min>thisval)min=thisval;

			}
			S[index1]=min;
		}
		return S[index1];
	}
	int getOne(int i,int j)
	{
		if(one[i*len + j]!=-1)return one[i*len + j];
		if(i==j)return A[i];
		int min=-1;
		for(int k=i;k<=j;k++)
		{
			int formern=k-i,lattern=j-k;
			int thisval = (lattern>0?acc[(k+1)*len + j]:0) - (formern>0?acc[i*len + k-1]:0) - (lattern - formern)*A[k];
			if(min == -1 || min > thisval)min=thisval;
		}
//		std::cout << "one["<<i<<","<<j<<"]"<<min << std::endl;
		one[i*len + j]=min;
		return min;
	}
	int *S;
	int *one;
	int *acc;

	int *A;
	int len;
	int klen;
};

void testFastFood()
{
//	int A[]={5,6,12,19,20,27};//7+8+15=30
//	//result is 8
//	int k=3;
//
	int A[200]={5,6,7,8,20,40,60,80,100,102,104,106,108,110};
	for(int i=1;i<200;i++)
		A[i]=A[i-1]+2;
	int k=30;
//	k=15 result is 1330

	Solution s;
	int min=s.solve(A,sizeof(A)/sizeof(A[0]),k);
	std::cout << "min is "<< min << std::endl;
}

void testFastFood_HOJ(int argc,char *argv[])
{
	Solution s;
	int istart=1;
	int chaini=1;
	while(istart < argc)
	{
		int n=atoi(argv[istart]),k=atoi(argv[istart+1]);
		istart+=2;
		if(n==0 && k==0)break;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=atoi(argv[istart++]);
		}

		int min=s.solve(arr, n, k);

		std::cout << "Chain "<<(chaini++)<<std::endl;
		std::cout << "Total distance sum = "<<min<<std::endl;

		delete[] arr;
		delete[] s.S;
	}
}

/**
 * 0.53 ms
 */
void testFastFood_HOJ_INPUT()
{
	Solution s;
	int chaini=1;
	while(true)
	{
		int n,k;
		std::cin >> n >> k;
		if(n==0 && k==0)break;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
			std::cin >> arr[i];

		int min=s.solve(arr, n, k);

		std::cout << "Chain "<<(chaini++)<<std::endl;
		std::cout << "Total distance sum = "<<min<<std::endl<<std::endl;

		delete[] arr;
		s.solveEnd();
	}
}
