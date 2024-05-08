#include <iostream>
void traverse(int*,int);
int heapify(int*,int,int);


// int swap (int *num1, int* num2){
// 	int temp = *num1;
// 	*num1 = *num2;
// 	*num2 = temp;
// }

int heapSort(int*arr, int size) {
	for (int i = size/2 -1; i >=0; i--){
		heapify(arr,size,i);
	}
	int temp;	
	for (int i = size-1; i>0; i--){
		std::swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}

};


int  heapify (int *arr, int size, int root) {
	int largest = root;
	int l = 2*root+1;
	int r = 2*root+2;
	int temp;
	if ( l < size && arr[largest] < arr[l]){
		largest = l;
	}
	if (r < size && arr[largest] < arr[r]){
		largest =r;

	}
	if (root != largest){
		std::swap(arr[largest], arr[root]);
		heapify(arr, size, largest);
	}	

}


void traverse (int *arr, int size) {
	for (int i =0; i < size; i++){

		std:: cout << arr[i] << " ";
	}
	std:: cout << std:: endl;
}


int main () {
	int arr[8] = {5,2,7,4,9,6,10,3};
	traverse(arr,8);
	std:: cout << "after heap_sort " << std:: endl;
	heapSort(arr,8);

	traverse(arr,8);
	

}
