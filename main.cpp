#include<bits/stdc++.h>
#include<SDL2\SDL.h>
using namespace std;

//represents all the sorting algos in program
void printoptions()
{    cout<<"Enter the no. for respective sorting as shown \n";
    cout<<" 1.Bubble sort \n 2.Insertion sort \n 3.Selection sort \n 4.Quick sort \n 5.Merge sort \n 6.Heap Sort\n 7.To terminate the program\n";
}

// printing the curr states of arr in all sorts
// different functions required to represent different parameters for different sorting algos

// curr_state works good for 1,2,3.
void curr_state(vector<int>&arr,int red,int blue,int n,SDL_Renderer*r)
{
    for (int i=0; i<n; i++)
    {
        if (i==red)
            SDL_SetRenderDrawColor(r,255,0,0,255);
        else if (i==blue)
            SDL_SetRenderDrawColor(r,0,0,255,255);
        else
            SDL_SetRenderDrawColor(r,0,255,0,255);
        SDL_RenderDrawLine(r,i,0,i,arr[i]);
    }
}

//this represent the curr state of heapsort
void curr_stateHeap(vector<int>&arr,int index,SDL_Renderer*r)
{
    for (int i=0; i<arr.size(); i++)
    {
        if (i==index)
            SDL_SetRenderDrawColor(r,0,0,255,255);
        else
            SDL_SetRenderDrawColor(r,0,255,0,255);
        SDL_RenderDrawLine(r,i,0,i,arr[i]);
    }
}

// as name suggests used to visualize the curr state of heap
void visualiseHeap(vector<int>&arr,int index,SDL_Renderer*r)
{
    //making kanvas
    SDL_SetRenderDrawColor(r,0,0,0,255);
    SDL_RenderClear(r);
    // drawing the curr state
    curr_stateHeap(arr,index,r);
    //streming the curr state
    SDL_RenderPresent(r);
    SDL_Delay(5);
}


//represents the final solution or result of sorted arrray
void visualiseres(vector<int>&arr,SDL_Renderer*r)
{
    for (int i=0; i<arr.size(); i++)
    {
        SDL_SetRenderDrawColor(r,0,255,0,255);
        SDL_RenderDrawLine(r,i,0,i,arr[i]);
    }

}


//general visualiser for 1,2,3,4,5(basically for better understanding this sets up the canvas for painting)
void visualise(vector<int>&arr,int i,int j,int n,SDL_Renderer * r)
{
    //making kanvas
    SDL_SetRenderDrawColor(r,0,0,0,255);
    SDL_RenderClear(r);
    // drawing the curr state
    curr_state(arr,i,j,n,r);
    //streming the curr state
    SDL_RenderPresent(r);
    SDL_Delay(5);
}


//curr state for MergeSort
void curr_statefm(vector<int>&arr,vector<int>temp,int red,int blue,int n,SDL_Renderer*r)
{
    for (int i=0; i<n; i++)
    {
        if (i==red)
            SDL_SetRenderDrawColor(r,255,0,0,255);
        else if (i==blue)
            SDL_SetRenderDrawColor(r,0,0,255,255);
        else
            SDL_SetRenderDrawColor(r,0,255,0,255);
        SDL_RenderDrawLine(r,i,0,i,arr[i]);
    }
}


// 1 call for bubblesort
void BubbleSort(vector<int>&arr,int n,SDL_Renderer *r)
{
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++ )
        {
            if (arr[i]>arr[j])
                swap(arr[i],arr[j]);

            visualise(arr,i,j,n,r);
        }
    }

}


// 2.insertion sort
void InsertionSort(vector<int>&arr,int n,SDL_Renderer *r)
{
    for (int i=1; i<n; i++)
    {
        int data=arr[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if (arr[j]<=data)
                break;
            else
                arr[j+1]=arr[j];

            visualise(arr,i,j,n,r);
        }
        arr[j+1]=data;
    }

}


//3.selection Sort
void SelectionSort(vector<int>&arr,int n,SDL_Renderer *r)
{
    for (int i=0; i<n; i++)
    {
        int miniindex=i;
        for(int j=i+1; j<n; j++)
        {
            if (arr[miniindex]>arr[j])
            {
                miniindex=j;
            }
        }
        swap(arr[i],arr[miniindex]);
        //making kanvas
        SDL_SetRenderDrawColor(r,0,0,0,255);
        SDL_RenderClear(r);
        // drawing the curr state
        curr_state(arr,i,miniindex,n,r);
        //streming the curr state
        SDL_RenderPresent(r);
        SDL_Delay(100);
    }
}


// 4.Quick Sort
int index(vector<int>&arr,int s,int e,int n,SDL_Renderer *r)
{
    int pivot=arr[s];
    int counter=0;
    for (int i=s+1; i<=e; i++)
    {
        if (arr[i]<=pivot)
            counter++;
    }
    counter=counter+s;
    visualise(arr,s,counter,n,r);
    swap(arr[s],arr[counter]);
    int i=s, j=e;
    while (i<counter && j>counter)
    {
        if (arr[i]>arr[counter] && arr[counter]>=arr[j])
        {
            visualise(arr,i,j,n,r);
            swap(arr[i],arr[j]);
            i++;
            j--;

        }
        else if (arr[i]<=arr[counter])
        {
            visualise(arr,i,j,n,r);
            i++;
        }
        else
        {
            visualise(arr,i,j,n,r);
            j--;
        }
    }
    return counter;
}

void QuickSort(vector<int>& arr,int s,int e,int n,SDL_Renderer*r)
{
    if (s>=e)
        return ;
    int i=index(arr,s,e,n,r);
    QuickSort(arr,s,i-1,n,r);
    QuickSort(arr,i+1,e,n,r);
}


// 5.Merge Sort
void Merge(vector<int>& arr,int s,int mid,int e,int n,SDL_Renderer*r)
{
    vector<int>temp=arr;
    int i=s;
    int j=mid+1;
    int k=s;
    while (i<=mid && j<=e)
    {
        if (arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
            visualise(temp,i,j,n,r);
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
            visualise(temp,i,j,n,r);
        }
    }
    while (i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
        visualise(temp,i,j,n,r);
    }
    while (j<=e)
    {
        temp[k]=arr[j];
        j++;
        k++;
        visualise(temp,i,j,n,r);

    }
    arr=temp;
}

void MergeSort(vector<int>&arr,int s,int e,int n,SDL_Renderer*r)
{
    if (s>=e)
        return ;
    int mid=(s+e)/2;
    MergeSort(arr,s,mid,n,r);
    MergeSort(arr,mid+1,e,n,r);
    Merge(arr,s,mid,e,n,r);
}


//Heap Sort
void heapify(vector<int>&arr, int n, int i,SDL_Renderer * r)
{
    int curr=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && arr[left]>arr[curr])
    {
        visualiseHeap(arr,i,r);
        curr=left;
    }
    if (right<n && arr[right]>arr[curr])
    {
        visualiseHeap(arr,i,r);
        curr=right;
    }
    if (curr!=i)
    {
        swap(arr[curr],arr[i]);
        visualiseHeap(arr,i,r);
        heapify(arr,n,curr,r);
    }
    return ;
}

//Function to build a Heap from array.
void buildHeap(vector<int>&arr, int n,SDL_Renderer *r)
{
    for (int i=n/2; i>=0; i--)
    {
        heapify(arr,n,i,r);
    }
}

//Function to sort an array using Heap Sort.
void HeapSort(vector<int>&arr, int n,SDL_Renderer * r)
{
    buildHeap(arr,n,r);
    int size=n;
    while (size>1)
    {
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,size,0,r);
    }
}

//calls the chosen function by user
void call(int op,vector<int>&a,int n)
{
    SDL_Window *w=nullptr;
    SDL_Renderer * r=nullptr;
    SDL_CreateWindowAndRenderer(100*8,100*8,0,&w,&r);
    SDL_RenderSetScale(r,800/n,800/n);
    vector<int>arr=a;
    if (op==1)BubbleSort(arr,n,r);
    if (op==2)InsertionSort(arr,n,r);
    if (op==3)SelectionSort(arr,n,r);
    if (op==4)QuickSort(arr,0,n-1,n,r);
    if (op==5)MergeSort(arr,0,n-1,n,r);
    if (op==6)HeapSort(arr,n,r);
    //making kanvas
    SDL_SetRenderDrawColor(r,0,0,0,255);
    SDL_RenderClear(r);
    // drawing the curr state
    visualiseres(arr,r);
    //streming the curr state
    SDL_RenderPresent(r);
    SDL_Delay(1);
}

int main(int argc,char* argv[])
{
    int n;
    cout<<"Enter the no. of elements in the array"<<endl;
    cin>>n;
    vector<int>arr(n);
    for (int i=0; i<n; i++)
    {
        arr[i]=1+(rand())%n;
    }
    printoptions();
    int option;
    cin>>option;
    while (option>=1 && option <=6)
    {
        call(option,arr,n);
        printoptions();
        cin>>option;
    }
}
