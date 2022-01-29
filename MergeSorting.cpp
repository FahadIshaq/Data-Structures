//NAME: FAHAD ISHAQ
//REG. NO: FA20-BCS-017
//QUESTION: MERGE SORT

#include <iostream>
using namespace std;

void Merge(int store , int left , int mid , int right);

void display(int arr[],int size)
{
    for(int i = 0 ; i<=size-1 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Merge(int arr [], int left , int mid , int right)
{
    
    int n1 = mid-left+1;
    int n2 = right -mid;
    int temp1 [n1];
    int temp2 [n2];

    for(int i = 0 ; i<n1; i++ ){
        temp1 [i] = arr[left+i];  
    }

    for(int j = 0; j<n2; j++ ){
        temp2 [j] = arr[mid+1+j];  
    }

    int i = 0 ;
    int j = 0;
    int k = left;

    while (i<n1 && j<n2)
    {
        if(temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            i++;
        }
        else
        {
            arr[k]=temp2[j];
            j++;
        }
        k++;   
    }

    while (i < n1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void MergeSort(int store [], int left , int right)
{
    if(left>=right)
    return;

    int mid = (left+right-1)/2;
    MergeSort(store,left,mid);
    MergeSort(store,mid+1,right);
    Merge(store,left,mid,right);
    
}

int main(){
    	int opt;
	cout<<"Enter the Size of the array: ";
	int size;
	cin>>size;
	int arr[size];
	int k=0;

	do{
		cout<<"\nENTER 1 To INSERT VALUES IN THE ARRAY: "<<endl;
		cout<<"ENTER 2 To SORT VALUES"<<endl;
		cout<<"ENTER YOUR OPTION: ";
		
		cin>>opt;
		switch(opt){
		
			case 1:
				{
					if (k==size){
						cout<<"ARRAY IS FULL"<<endl;
					}
					else{
				for (int i=0; i<size; i++){
				cout<<"Enter Value "<<i+1<<" :";
				cin>>arr[i];
				k++;
				}
			}
				break;
			}
			
			case 2:
				{
					cout<<"\t\t\t\tBEFORE SORTING"<<endl;
					display(arr,size);
					cout<<"\n\t\t\t\tAFTER SORTING"<<endl;
				MergeSort(arr,0,size-1);
					display(arr,size);			
				
			}
		}
				
				
		
	}while (opt!=0);

	
    
    
}
