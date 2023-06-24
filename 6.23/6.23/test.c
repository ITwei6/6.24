#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void _MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)
		return;
	//���зָ�
	int mid = (begin + end) / 2;
	//[begin  mid][mid+1 end]
	//���ϵķָ�ֱ���ֳ�һ����������ʱ
	_MergeSort(a, begin, mid, temp);
	//�������䲻�Ϸָ�
	_MergeSort(a, mid + 1, end, temp);
	//�������䲻�Ϸָ�

	//�ߵ����������һ������������
	//���������Ǻϲ�����������

	//��[begin mid] ��[mid+1 end]�ϲ���һ����������
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1,end2 = end;
	int i = begin;
	//�ϲ������������еĳ��÷���
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
//	//�ϲ� +����  
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
//�ǵݹ���ʽ�Ĺ鲢�㷨
void _MergeSortNor(int* a, int n, int* temp)
{
	
	int gap = 1;
	//gap�Ǳ�ʾÿ�ι鲢�ĸ���
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
			//�����ֿ�����ʽ ��1��ֱ�ӵ�ȫ���鲢���һ������������ǹ鲢��һ�ξͿ�����ȥ
          //�鲢һ���ֿ���һ����
		}
		gap *= 2;
		printf("\n");
	}

}
//void _MergeSortNor(int* a, int n, int* temp)
//{
//
//	int gap = 1;
//	//gap�Ǳ�ʾÿ�ι鲢�ĸ���
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
//			//�������һ������ķ������Ǳ����ȡ������·��
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