#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
	int size;
	int used;
	int *arr;
};

void dump(struct array *array)
{
	int idx;

	for (idx = 0; idx < array->used; idx++)
		printf("[%02d]: %08d\n", idx, array->arr[idx]);
}

void alloc(struct array *array)
{
	array->arr = (int *)malloc(array->size * sizeof(int));   // 返回值是指针，指向第一个位置
}

int insert(struct array *array, int elem)
{
	int idx;
	if (array->used >= array->size)  // 确定数组是否已满
		return -1;

	for (idx = 0; idx < array->used; idx++) {  // 查找到 <= elme 的位置停下
		if (array->arr[idx] > elem)
			break;
	}

	if (idx < array->used)  // 将大于 elem 的多个数值后移
		// void* memmove( void* dest, const void* src, std::size_t count );
		memmove(&array->arr[idx+1], &array->arr[idx],
			(array->used - idx) * sizeof(int));

	array->arr[idx] = elem;  // 将当面位置存入新的 elme
	array->used++;  // 数组占用数量增加
	return idx;
}

int myDelete(struct array *array, int idx)
{
	if (idx < 0 || idx >= array->used)
		return -1;

	memmove(&array->arr[idx], &array->arr[idx+1],  // 指移动内存，不真正删除数据
		(array->used - idx) * sizeof(int));
	array->used--;
	return 0;
}

int search(struct array *array, int elem)
{
	int idx;

	for (idx = 0; idx < array->used; idx++) {
		if (array->arr[idx] == elem)
			return idx;
		if (array->arr[idx] > elem)
			return -1;
	}

	return -1;
}

int main()
{
	int idx;
	struct array ten_int = {10, 0, NULL};  // 构建第一个数组数据 {数组大小，当前数组数据个数，数组内存第一个位置的指针}

	alloc(&ten_int);  // 给第一个数组数据分配空间，空间大小为 ten_int->size × int
	if (!ten_int.arr)  
		return -1;
	insert(&ten_int, 1);  // 按从小到大顺序，将 1 插入到数组
	insert(&ten_int, 3);  // 按从小到大顺序，将 3 插入到数组
	insert(&ten_int, 2);  // 按从小到大顺序，将 2 插入到数组
	printf("=== insert 1, 3, 2\n");
	dump(&ten_int);

	idx = search(&ten_int, 2);
	printf("2 is at position %d\n", idx);
	idx = search(&ten_int, 9);
	printf("9 is at position %d\n", idx);

	printf("=== myDelete [6] element \n");
	myDelete(&ten_int, 6);
	dump(&ten_int);
	printf("=== myDelete [0] element \n");
	myDelete(&ten_int, 0);
	dump(&ten_int);
	return 0;
}