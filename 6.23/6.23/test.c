#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void _MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)
		return;
	//进行分割
	int mid = (begin + end) / 2;
	//[begin  mid][mid+1 end]
	//不断的分割直到分成一个有序序列时
	_MergeSort(a, begin, mid, temp);
	//将左区间不断分割
	_MergeSort(a, mid + 1, end, temp);
	//将右区间不断分割

	//走到这里表明是一个有序序列了
	//接下来就是合并有序序列了

	//将[begin mid] 和[mid+1 end]合并成一个有序序列
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1,end2 = end;
	int i = begin;
	//合并两个有序序列的常用方法
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
}
//
//void _MergeSort(int* a, int begin, int end, int* temp)
//{
//	if (begin >= end)
//		return;
//	int mid = (begin + end) / 2;
//	_MergeSort(a, begin, mid, temp);
//
//	_MergeSort(a, mid + 1, end, temp);
//	//合并 +拷贝  
	/*int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}*/
//
//	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
//}
//非递归形式的归并算法
void _MergeSortNor(int* a, int n, int* temp)
{
	
	int gap = 1;
	//gap是表示每次归并的个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;
		
			if (end1 >= n )
			{
				break;
			}
			if (begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			printf("[%d %d][%d %d]", begin1, end1, begin2, end2);
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[j++] = a[begin1++];
				}
				else
				{
					temp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				temp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[j++] = a[begin2++];
			}
	
			memcpy(a + i, temp + i, sizeof(int)*(end2 - i + 1));
			//有两种拷贝方式 ，1，直接等全部归并完后一把梭哈，或者是归并完一次就拷贝回去
          //归并一部分拷贝一部分
		}
		gap *= 2;
		printf("\n");
	}

}
//void _MergeSortNor(int* a, int n, int* temp)
//{
//
//	int gap = 1;
//	//gap是表示每次归并的个数
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int j = i;
//
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//				begin2 = n;
//				end2 = n - 1;
//		    }
//			else if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//			printf("[%d %d][%d %d]", begin1, end1, begin2, end2);
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					temp[j++] = a[begin1++];
//				}
//				else
//				{
//					temp[j++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				temp[j++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				temp[j++] = a[begin2++];
//			}
//
//		}
//			memcpy(a,temp,sizeof(int)*n);
//			//如果采用一把梭哈的方法，那必须采取纯修正路线
//		gap *= 2;
//		printf("\n");
//	}
//
//}
int main()
{
	int* temp = (int*)malloc(sizeof(int) * 9);
	if (temp == NULL)
	{
		perror("malloc");
	}
	int a[] = { 8,6,4,5,3,2,7,1, 9};
	_MergeSortNor(a, 9,temp);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
}

//
//void MergeSort(int* a, int n)
//{
//
//	int n = sizeof(n) / sizeof(a[0]);
//	int* temp = (int*)malloc(sizeof(int) * n);
//	if (temp == NULL)
//	{
//		perror("malloc");
//	}
//	_MergeSort(a, 0, n - 1, temp);
//
//}
//int main()
//{
//	int a[] = { 8,6,4,5,3,2,7,1 };
//
//	MergeSort(a,8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}