#include<iostream>
using namespace std;
#include<math.h>

int* radix_sort(int A[], int n, int d){
	int* B = new int[n];
	int* C = new int[10];
	for(int i=0; i<10; i++)
		C[i] = 0;
	for(int i=0; i<d; i++){
		int a = pow(10,i);
		
		for(int j=0; j<n; j++)
			C[(A[j]/a)%10]++;
		
		
		for(int j=1; j<10; j++)
			C[j] = C[j-1] + C[j];
		for(int j=n-1; j>=0; j--){
			B[C[(A[j]/a)%10]-1] = A[j];
			C[(A[j]/a)%10]--;
		}
		for(int j=0; j<n; j++)
		    A[j] = B[j];
		
		for(int j=0; j<10; j++)
			C[j] = 0;
	}
	return A;
}
void print(int arr[], int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	        cout<<endl;
}
int main(){
	int arr[7] = {329, 457, 657, 839, 436, 720, 355};
	int* result = radix_sort(arr, 7, 3);
        print(result, 7);
	}
