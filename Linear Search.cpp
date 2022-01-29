//NAME: FAHAD ISHAQ
//REG. NO: FA20-BCS-017
//QUESTION: BINARY SEARCH BY ITERATIVE METHOD AND BY RECURSIVE METHOD
#include <iostream>
using namespace std; 

//linear search
bool linearSearch(int arr[], int key, int size){
	for (int i=0; i<size; i++){
		if (arr[i]==key){
			return true;
			break;
		}
	}
	return false;
	
}

bool Recursion(int arr[], int key, int start, int end){
	if (start<0){
		return false;
	}
	if (arr[start]==key){
		return true;
		
	}
	if (start==end){
		return false;
		
	}
	return Recursion(arr,key,start+1, end);
	
}
int main(){
	int opt;
	cout<<"Enter the Size of the array: ";
	int size;
	cin>>size;
	int arr[size];
	int k=0;

	do{
		cout<<"ENTER 1 To INSERT VALUES IN THE ARRAY "<<endl;
		cout<<"ENTER 2 To SEARCH VALUE IN THE ARRAY (ITERARIVE METHOD) "<<endl;
		cout<<"ENTER 3 To SEARCH VALUE IN THE ARRAY (RECURSIVE METHOD) "<<endl;
		cout<<"Enter YOUR OPTION:";
		
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
				
				cout<<"Enter value to find in the array: ";
				int value;
				cin>>value;
				
			if (linearSearch(arr,value,size)==true){
				cout<<"Value Found"<<endl;
				
			}
			else{
				cout<<"Value Not Found"<<endl;
			}
				break;
			}
			case 3:
				cout<<"Enter value to find in the array: ";
				int value2;
				cin>>value2;				
				if (Recursion(arr,value2,0,size-1)==true){
					cout<<"Value Found"<<endl;
					
				}else{
					cout<<"Value Not Found"<<endl;
				}
				break;
				
			}
			
				
				
		
	}while (opt!=0);
	
	
	return 0;
	
}
