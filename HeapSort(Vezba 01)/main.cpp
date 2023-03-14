/* Сортирање на низа со примена на функцијата HeapSort.
 Најпрвиот чекор е да се изгради бинарно дрво(Binary Tree) од самата низа.
 При изградвање на дрвото од несортираната низа, треба да се конвертира во max heap. 
 За изведвањена max heap треба родителот(parent) да има поголема вредност од детето(child).
 Процесот се повторува се додека секој родител има поголема вредност од детето.
 Нареден чекор е извршување на heap sort. Со ова јазолот со најголемата вредност
 ќе се избрише, а на неговото место ќе дојди јазолот со најмалата вредност. Нареден чекор
 е да се извшри повторно сортирање на дрвото(heapify function) и повторно max heap со притоа
најголемиот јазол да се избрише а на неговото место да дојди јазолот со најмала вредност.
Процесот се повторува се дури не се подреди низата.*/ 
#include <iostream>
using namespace std;

void FillArray (int arr[], int n) 
{
    cout << "Vnesi gi broevite: ";
    int number = 0;
    for (int i = 0; i < n; i++) 
        {
        cin >> number;
        arr[i] = number;
        }
    }  



void heapify(int arr[], int N, int i)
{
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;


if (l < N && arr[l] > arr[largest])
largest = l;


if (r < N && arr[r] > arr[largest])
largest = r;


if (largest != i) {
swap(arr[i], arr[largest]);


heapify(arr, N, largest);
}
}


void heapSort(int arr[], int N)
{


for (int i = N / 2 - 1; i >= 0; i--)
heapify(arr, N, i);

for (int i = N - 1; i > 0; i--) {


swap(arr[0], arr[i]);


heapify(arr, i, 0);
}
}


void printArray(int arr[], int N)
{
for (int i = 0; i < N; ++i)
cout << arr[i] << " ";
cout << "\n";
}

int main()
{
    int  n;
    cout <<"Kolku broja sakate da ima vasata niza?\n";
    cin >>n;
    int arr[n];
    int N = sizeof(arr) / sizeof(arr[0]);
    FillArray(arr, n);
    heapSort(arr, N);

    cout << "Sortinata niza: \n";
    printArray(arr, N);
}

