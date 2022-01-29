//NAME: FAHAD ISHAQ
//REG. NO: FA20-BCS-017
//QUESTION: INSERTION SORT 
#include <iostream>
using namespace std; 

void InsertionSort(int arr[], int size){
 int temp ;
    for(int i = 1 ; i<=size-1;i++)
    { 
        temp = arr[i];
        for(int x = i-1 ; x >=0  ;x--)
        {
            if(arr[x]>temp)
            {
                arr[x+1]=arr[x];
                arr[x]=temp;
            }
            else
            {
                arr[x+1] = temp;
                break;
            }   
        }
    }
	
}
void display(int arr[],int size){
	for (int i=0; i<size; i++){
		cout<<arr[i]<<" ";
		
	}
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
					InsertionSort(arr,size);
					display(arr,size);
					
				
			}
		}
				
				
		
	}while (opt!=0);

	
	
	
	
	return 0;
	
}
