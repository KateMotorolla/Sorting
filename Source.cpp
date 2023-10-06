#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int count = 0, countS = 0;
	for (int i = 0;i < n-1;i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[min])
			{ 
				min = j;
				countS++;
			}
		}
		swap(arr[i], arr[min]);
	}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void BubbleSort(int arr[],int n)
{
	int count = 0, countS = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n-1;j++)
		{ 
			count++;
			if (arr[j] > arr[j+1])
			{ 
				countS++;
				swap(arr[j], arr[j+1]);
			}
		}
	}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void InsertionSort(int arr[], int n)
{
	int count = 0, countS = 0;
	for (int i = 1;i < n ;i++)
	{
		for (int j = i - 1;j >= 0;j--)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				countS++;
				swap(arr[j], arr[j + 1]);
			}
			else break;
		}
	}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void BinaryInput(int arr[], int n)
{
	int count = 0, countS = 0;
	for (int i = 1;i < n;i++)
	{
		int l = 0, r = i;
		while (r > l)
		{
			count++;
			int j = (l + r) / 2;
			if (arr[i] < arr[j])
				r = j;
			else
				l = j + 1;	
		}
		for (int j = i - 1;j >= l;--j)
		{ 
			countS++;
			swap(arr[j], arr[j + 1]);
		}
	}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void SheikerSort(int arr[], int n)
{
	int count = 0, countS = 0;
	int l = 0, r = n-1,k=0;
		while (l != r)
		{
			for (int i = l;i < r;i++)
			{
				if (arr[i] > arr[i + 1])
				{
					swap(arr[i], arr[i + 1]);
					countS++;
					k = i;
				}
				count++;
			}
			r = k;
			for (int j = r;j > l;j--)
			{
				if (arr[j] < arr[j - 1])
				{ 
					countS++;
					swap(arr[j],arr[j-1]);
					k = j;
				}
				count++;
			}
			l = k;
		}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void LogDescent(int arr[], int n, int i,int& count,int& countS)
{
	
	if (i > n / 2 - 1)
		return;
	int max_index = 2 * i + 1;
	count++;
	if (2 * i + 2 < n && arr[max_index] < arr[2 * i + 2])
		max_index = 2 * i + 2;
	count++;
	if (arr[i] < arr[max_index])
	{ 
		countS++;
		swap(arr[i], arr[max_index]);
		LogDescent( arr, n,  max_index,count,countS);
	}
}
void HeapSort(int arr[], int n)
{
	int count = 0, countS = 0;
	int k = n / 2 - 1;
	for (int i = k;i >= 0;i-- )
	{
		LogDescent(arr, n, i,count,countS);
	}
	for (int i = 0; i < n; i++)
	{
		swap(arr[0], arr[n - i - 1]);
		LogDescent(arr, n - i, i, count, countS);
		countS++;
	}
	
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void ShellSort(int arr[], int n) 
{
	int count = 0, countS = 0;
	int temp; int h = 0;
	while (h < n / 3)
		h = 3 * h + 1;
	for (int k = h;k > 0;k = (k - 1) / 3)
	{
		for (int i = k;i < n;i++)
		{
			temp = arr[i];
			int j;
			for ( j = i;j >= k;j -= k)
			{
				count++;
				if (temp < arr[j - k])
				{ 
					swap(arr[j], arr[j - k]);
					countS++;
				}
				else
					break;
			}
			arr[j] = temp;
		}
	}
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}

void QuickSort1(int* first, int* last,int& count,int& countS)
{
	
	int dist = last - first;
	if (dist == 1)
		return;
	count++;
	if (*(last - 1) < *first)
	{
		countS++;
		swap(*(last - 1), *first);
	}
	int pivot = *(last - 1);
	int* wall = first; 
	bool state = false; 
	for (int* i = first + 1; i != last - 1; ++i)
	{
		count++;
		if (state && pivot > *i)
		{
			countS++;
			swap(*i, *(wall + 1));
			++wall;
		}
		else if (!state && pivot > *i)
			++wall;
		else
			state = true;
	}
	QuickSort1(first, wall + 1, count, countS);
	QuickSort1(wall + 1, last, count, countS);
}

void QuickSort(int arr[], int n)
{
	int count = 0, countS = 0;
	QuickSort1(arr, arr + n, count, countS);
	cout << "Comparison - " << count << " " << "Swap - " << countS << endl;
}
void ArrayInit(int arr1[], int arr2[], int arr_rand[], int n)
{
	for (int i = 0;i < n;i++) 
	{
		arr1[i] = i;
	}
	for (int i = 0;i < n;i++) 
	{
		arr2[i] = n - 1 - i;
	}
	arr_rand[0] = rand() % 200;
	for (int i = 1;i < n;i++)
	{
		int x = rand() % 200;
		while (find(arr_rand, arr_rand + i, x) != arr_rand + i)
		{
			x = rand() % 200;
		}
		arr_rand[i] = x;
	}
}

void main()
{
	const int n=200;
	int arr1[n],arr2[n],arr_rand[n];
	int count = 0,countS = 0;
	cout << "SelectionSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " <<endl;
	SelectionSort(arr1, n);
	cout << "Reverse array: "<<endl;
	SelectionSort(arr2, n);
	cout << "Random array: "<< endl;
	SelectionSort(arr_rand, n);

	cout << endl << "BubbleSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	BubbleSort(arr1, n);
	cout << "Reverse array: " << endl;
	BubbleSort(arr2, n);
	cout << "Random array: " << endl;
	BubbleSort(arr_rand, n);

	cout << endl << "InsertionSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	InsertionSort(arr1, n);
	cout << "Reverse array: " << endl;
	InsertionSort(arr2, n);
	cout << "Random array: " << endl;
	InsertionSort(arr_rand, n);

	cout << endl << "BinaryInput: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	BinaryInput(arr1, n);
	cout << "Reverse array: " << endl;
	BinaryInput(arr2, n);
	cout << "Random array: " << endl;
	BinaryInput(arr_rand, n);

	cout << endl << "SheikerSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	SheikerSort(arr1, n);
	cout << "Reverse array: " << endl;
	SheikerSort(arr2, n);
	cout << "Random array: " << endl;
	SheikerSort(arr_rand, n);

	cout << endl << "HeapSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	HeapSort(arr1, n);
	cout << "Reverse array: " << endl;
	HeapSort(arr2, n);
	cout << "Random array: " << endl;
	HeapSort(arr_rand, n);

	cout << endl << "ShellSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	ShellSort(arr1, n);
	cout << "Reverse array: " << endl;
	ShellSort(arr2, n);
	cout << "Random array: " << endl;
	ShellSort(arr_rand, n);

	cout << endl << "QuickSort: " << endl;
	ArrayInit(arr1, arr2, arr_rand, n);
	cout << "Sort array: " << endl;
	QuickSort(arr1,n);
	cout << "Reverse array: " << endl;
	QuickSort(arr2,n);
	cout << "Random array: " << endl;
	QuickSort(arr_rand,n);
	
}
