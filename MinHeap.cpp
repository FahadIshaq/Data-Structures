#include <iostream>
using namespace std;
class minHeap{
	public:
		int *arr;  //pointer to arrat of elements
		int capacity; //max possible size of heap
		int size;  //current number of elements in heap


		minHeap(int c){
			size=0;
			capacity=c;
			arr=new int[c];
		}

		//Linear Searching the value
		void search(int val){
			for (int i=0; i<size; i++){
				if (arr[i]==val){
					cout<<"\n\t\tVALUE FOUND\n"<<endl;
					
					return;
				}

			}
			cout<<"\n\t\tVALUE NOT FOUND"<<endl<<endl;
		}
		bool isEmpty(){
			if (size==0){
			
				return true;
			}else{
				return false; 
				
			}
		}
		void display(){
			if (isEmpty()){
				cout<<"\n\t\tMIN HEAP IS EMPTY"<<endl;
			}else{
			
			
			for (int i=0; i<size; i++){
				cout<<arr[i]<<"\t";
				cout<<endl;
			}
}
		}
		int parent(int i){
			return (i-1)/2;

		}

		int swap(int &x, int &y){
			int temp=x;
			x=y;
			y=temp;

		}
		int extractMin(){
		if (size<=0){
            return  INT_MAX;

		}
		if (size==1){
            size--;
            return arr[0];

		}

		int root=arr[0];
		arr[0]=arr[size-1];
		size--;
		return  root;
		}
		
		int left(int i){
			return (2*i+1);
			
			
		}
		int right(int i){
			return (2*i+2);
			
		}


		void insert(int k){
			if (size==capacity){
				cout<<"\n\t\tARRAY IS FULL\tNO SPACE\n"<<endl;
				return;
			}else{
			


				//firstly insert the value at the end.
				size++;
				int i=size-1;
				arr[i]=k;


				//fix the min heap property if it is not fixed.

				while (i!=0 && arr[parent(i)>arr[i]]){
					swap(arr[i],arr[parent(i)]);
					i=parent(i);

				}




			}
		}
	void decreaseKey(int i, int val){
			arr[i]=val;
			while(i!=0 && arr[parent(i)]>arr[i]){
				swap(arr[i], arr[parent(i)]);
				i=parent(i);

			}

		}

		void deleteValue(int k){
			decreaseKey(k, INT_MIN);
			extractMin();
			
		}


};

int main(){

	int opt;
	int s;
	cout<<"Enter the Size of the Min Heap: ";
	cin>>s;

	minHeap obj(s);


	do{
		cout<<"Press 1 to Insert in the Heap"<<endl;
		cout<<"Press 2 to Search in the Heap"<<endl;
		cout<<"Press 3 to Delete from the Heap"<<endl;
		cout<<"Press 4 to Get Min from the Heap"<<endl;
		cout<<"Press 5 to Display the Heap Tree"<<endl;
		cout<<"Press 0 to Exit"<<endl;

		cin>>opt;

		switch(opt){
			case 1:
				cout<<"\t\tINSERTION OPERATION"<<endl;
				cout<<"Enter Value to INSERT in the Heap Tree: ";
				int val;
				cin>>val;
				obj.insert(val);


				break;

			case 2:
				cout<<"\t\tSEARCH OPERATION"<<endl;
				cout<<"Enter Value to Search in the Min Heap: ";
				int value;
				cin>>value;
				obj.search(value);
				break;
			case 3:
				cout<<"\t\tDELETE OPERATION"<<endl;
				cout<<"Enter Value to Delete: ";
				int valu;
				cin>>valu;
				obj.deleteValue(valu);

				break;
			case 4:
				cout<<"\t\tGET MINIMUM VALUE"<<endl;
               cout<< obj.extractMin()<<endl;
               
                

				break;
		
			case 5:
				cout<<"\t\tDISPLAY MEHTHOD"<<endl;
				obj.display();

				break;

		}





	}
	while(opt!=0);








	return 0;

}
