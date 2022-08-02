#include<iostream>
using namespace std;
int arr[10]={0,40,20,60,30,10,90,80,70,50};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Merge Sort
void Merge(int arr[],int lb,int m,int ub)
{
    int n1=m-lb+1,n2=ub-m;
    int k=lb;
    int arr1[n1];
    int arr2[n2];
    int i,j;
    for( i=0;i<n1;i++)
        arr1[i]=arr[lb+i];

    for( i=0;i<n2;i++)
        arr2[i]=arr[m+i+1];

    for( i=0,j=0; i<n1 && j<n2;)
    {
        if(arr1[i]<arr2[j])
            arr[k++]=arr1[i++];
        else
            arr[k++]=arr2[j++];
    }
    if(i==n1 && j<n2)
        while(j<n2)
            arr[k++]=arr2[j++];

    if(j==n2 && i<n1)
          while(i<n1)
            arr[k++]=arr1[i++];
}
void Merge_Sort(int arr[],int lb,int ub)
{
    if(lb>=ub)
        return ;

    int m=(lb+ub)/2;
    Merge_Sort(arr,lb,m);
    Merge_Sort(arr,m+1,ub);
    Merge(arr,lb,m,ub);
}
//Merge sort end
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//Quick sort start
int partitioning(int arr[],int m,int n)
{
int temp;
int x=arr[n],i=m-1;
for(int j=m;j<n;j++)
{
    if(arr[j]<=x)
    {
        i++;
        //SWAP arr[i],arr[j];
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
//swap arr[i+1],arr[n];
temp=arr[i+1];
arr[i+1]=arr[n];
arr[n]=temp;

return i+1;
}
void Quick_Sort(int arr[],int m,int n)
{
    if(m<n)
    {
        int q=partitioning(arr,m,n);
        Quick_Sort(arr,m,q-1);
        Quick_Sort(arr,q+1,n);
    }
}
//Quick sort end
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Bubble Sort start
void Bubble_Sort(int arr[],int n)
{
    int flag=0,temp;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                //Swapping
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}
//Bubble sort End
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Selection Sort start
void Selection_Sort(int arr[],int n)
{
int position;
for(int i=0;i<n;i++)
{
    position=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[position])
            position=j;
    }
    if(i!=position)
    {
        //Swap with i,position
        int temp=arr[i];
        arr[i]=arr[position];
        arr[position]=temp;
    }
}

}
//Selection Sort End
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Insertion Sort Start
void Insertion_Sort(int arr[],int n)
{
int i,key;
for(int j=0;j<=n;j++)
{
    key=arr[j];
    i=j-1;
    while(i>0 && arr[i]>key)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
}
}
//Insertion Sort End
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Main Function
int main()
{
int s,n=10;
cout<<"Choose Sorting Method"<<endl;
cout<<"1.Merge Sort \t 2.Quick Sort \t 3.Bubble Sort \t 4.Selection Sort \t 5.Insertion Sort"<<endl;
cin>>s;
switch(s)
{
    case 1: Merge_Sort(arr,0,n-1);
        break;
    case 2: Quick_Sort(arr,0,n-1);
        break;
    case 3: Bubble_Sort(arr,n-1);
        break;
    case 4: Selection_Sort(arr,n);
        break;
    case 5: Insertion_Sort(arr,n-1);
        break;
    default:
        cout<<"Invalid Entry"<<endl;
}
cout<<"Sorted array"<<endl;
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;
}
