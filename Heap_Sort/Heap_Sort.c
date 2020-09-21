#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/// <summary>
/// 製造亂數放入陣列中
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void PutRandomNumberInArray(int* array, int* array_length) {
	//srand(time(NULL));
	for (int i = 0; i < *array_length; i++) {
		array[i] = rand() % *array_length + 1;
		//for (int j = 0; j < i; j++) {
		//	if (array[i] == array[j])  //比較值是否已經存在
		//	{
		//		/*i--;
		//		break;*/
		//		j = 0;
		//		array[i] = rand() % *array_length + 1;
		//	}
		//	//	/*while (array[i] == array[j])
		//	//	{
		//	//		j = 0;
		//	//		array[i] = rand() % *array_length + 1;
		//	//	}*/
		//}
	}


}
/// <summary>
/// 印出陣列裡的數字
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Print(int* array, int* array_length) {

	for (int i = 0; i < *array_length; i++) {
		printf("%d ", *(array + i));
	}
	printf("\n");
}
/// <summary>
/// 交換兩個位置的值
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/// <summary>
/// 把陣列調整成
/// </summary>
/// <param name="array">陣列位址</param>
/// <param name="root">第幾個為root</param>
/// <param name="array_length">陣列多長</param>
void adjust(int* array,int root, int array_length) {
	int child;
	int temp = *(array + root);
	//rootkey = root;

	child = 2 * root;
	while (child<array_length)
	{
		
		if ((child < array_length) && (*(array + child) < *(array + child + 1))&&(child !=array_length-1))
		{
			child++;
		}
		if (temp > * (array + child)) { //root比child裡的值大
			break;
		}
		else
		{
			*(array + (child / 2)) = *(array + child);
			child *= 2;
		}	
	}
	*(array + (child / 2)) = temp;

}
/// <summary>
/// 陣列調整成MaxHeap
/// </summary>
/// <param name="array">陣列位址</param>
/// <param name="array_length">陣列長度</param>
void Build_Heap(int* array, int array_length) {
	for (int i =array_length / 2; i > 0; i--) {
		adjust(array, i, array_length);
	}

}
/// <summary>
/// HeapSort
/// </summary>
/// <param name="array">陣列位址</param>
/// <param name="array_length">陣列長度</param>
void HeapSort(int* array, int array_length) {
	for (int i = (array_length-1); i > 1; i--) {
		Swap(&array[1], &array[i]);
		adjust(array, 1, i);
	}
}


/// <summary>
/// 主程式
/// </summary>
/// <returns></returns>
int main() {
	//int a = 10, b = 20;
	int A[] = { 0,26,5,77,1,61,11,59,15,48,19};

	static int B[1000000];
	int  array_lengthB = sizeof(B) / sizeof(B[0]);///B陣列有幾個元素
	int  array_length = sizeof(A) / sizeof(A[0]);///A陣列有幾個元素

	clock_t start_time, end_time;
	{
		printf("array_length=%d\n", array_length);
		Print(&A, &array_length);
		Build_Heap(&A, array_length);
		Print(&A, &array_length);
		HeapSort(&A, array_length);
		Print(&A, &array_length);
	}
	{
		PutRandomNumberInArray(&B, &array_lengthB);
		Print(&B, &array_lengthB);
		start_time = clock(); /* mircosecond */
		Build_Heap(&B, array_lengthB);
		
		HeapSort(&B, array_lengthB);
		end_time = clock();
		Print(&B, &array_lengthB);

		float total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
		printf("1000000個陣列亂數Heap_Sort需要時間: %f sec \n", total_time);
	}
	
	

}