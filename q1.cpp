#include<iostream>

int main(void)
{
	int n = 0;//지도의 한 변 크기
	std::cin >> n;

	int *arr1 = new int[n];
	int *arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr1[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr2[i];
	}

	int *b1 = new int[n*n];
	//int *b2 = new int[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b1[i*n + n-j-1] = (arr1[i] % 2)|( arr2[i] % 2);
			arr1[i] = arr1[i] / 2;
		/*	b2[i*n + n - j - 1] = arr2[i] % 2;*/
			arr2[i] = arr2[i] / 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << "\"";
		for (int j = 0; j < n; j++)
			switch (b1[i*n + j])
			{
			case 0: std::cout << " "; break;
			case 1: std::cout << "#"; break;
			}
		std::cout << "\", ";
	}
	std::cout << std::endl;
	return 0;
}