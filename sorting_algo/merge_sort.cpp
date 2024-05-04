#include <iostream>


void traverse (int *, int);
int * merge (int *arr1, int size1,  int * arr2 , int size2) {
	int i = 0;
	int j = 0;
	int *newArr = (int*)malloc(sizeof(int) *( size1+size2));
	for (int a=0; a < size1 +size2; a++){
		if ( i < size1 && j < size2) {

			if (arr1[i] >= arr2[j] ) {
				newArr[i+j] = arr2[j];
				j++;
			}else {
				newArr[i+j] = arr1[i];
				i++;
			}
		} else {
			if (i == size1){
				newArr[i+j] = arr2[j];
				j++;
			} else {
				newArr[i+j] = arr1[i];
				i++;
			}
		}
	}
	return newArr;
}

int * mergeSort (int * arr, int size) {
//	traverse(arr, size);
//	std:: cout << size - (size/2) << std:: endl;
	if (size < 2){
		return arr;
	}
	int temp1[size/2];
	int temp2[size - (size/2)];
	for  (int i =0; i<size; i++){
		if (i >= size/2){
			temp2[i - (size/2)] = arr[i];
		} else {
			temp1[i] = arr[i];
		}
	}
	//traverse(temp1,size/2);
	//traverse(temp2, size - (size/2));
	
	int *halfArr = mergeSort(temp1, size/2);
	traverse(halfArr, size/2);

//	std:: cout << "      " ;
	int *nextHalf = mergeSort(temp2, size - (size/2));
	traverse(nextHalf, size-(size/2));
	std:: cout << std:: endl;
	int * mergeArr = merge(halfArr, size/2, nextHalf, size - (size/2));
//	traverse(mergeArr, size);
//	std:: cout << std:: endl;
//	traverse(mergeArr, size);
	return mergeArr;
}


void traverse (int *arr, int size) {
	for (int i =0; i< size; i++){
		std:: cout << arr[i] << " ";
	}
	std:: cout << std:: endl;

}

int main () {
	int size = 9;
	int arr[size] = { 2, 6,3,10, 4,8,2,9,11};
	//int arr[size] = {3,7,1,6};
	//int arr2[size] = {6,2,1,5};
	//int * newArr = merge(arr,size,arr2,size);
	traverse(arr,size);
	//traverse(arr2,size);
	int *newArr = mergeSort(arr,size);
	traverse(newArr,size);
	


}
