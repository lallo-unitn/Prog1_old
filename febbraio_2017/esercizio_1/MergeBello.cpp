#include <fstream>
using namespace std;

void merge(int arr[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int first, int last){
	if(first<last){
	int mid = (first+last-1)/2;     //M non fa il -1
	mergeSort(arr,first,mid);
	mergeSort(arr,mid+1,last);
	merge(arr,first,mid,last);
	}
}

int main()
{
	fstream myin, myout;
    myin.open("input.txt", ios::in);
    int N;
    in >> N;
    int vett[N];
    for (int i=0; i<N; i++) {
        in >> vett[i];
    }
    mergeSort (vett, 0, N-1);
    myout.open("output.txt", ios::out);
    for (int i=0; i<N; i++) {
        out << vett[i] << " ";
    }
    return 0;
}