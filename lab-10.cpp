#include<iostream>
using namespace std;

int main(){
	
	int heap[100];
	int lenght = 0;
	int i,p,r;
	int X = 5;
	int var;
	cout << "Command List: " << endl << "\t Enter 1 for insert." << endl << "\t Enter 2 for display." << endl << "\t Enter 3 for remove."<< endl << "\t Enter 0 for exit." << endl;
	
	while(X!=0){
		cout << "Your Command: \t";
		cin >> X;
		
		if(X==0){
			cout << "Bye-Bye";
		}
		else if(X==1){
			cout << "Enter value: \t ";
			if(lenght==0){
				cin >> heap[0];
				lenght++;
			}
			else{
				cin >> heap[lenght];
				lenght++;
				i = lenght - 1;
				p =  (i - 1)/2;
				while(i!=0 && heap[i] >= heap[p]){
					r = heap[i];
					heap[i] = heap[p];
					heap[p] = r;
					i = p;
					p =  (i - 1)/2;
				}
			}
		}
		else if(X==2){
			for(int k=0;k<lenght;k++){
				cout << heap[k] << "     ";
			}
		}
		else if(X==3){
			if(lenght==0)
				cout << "No element";
			else if(lenght==1)
				heap[0] = 0;
				lenght--;
			else{
				i = lenght - 1;
				heap[0] = heap[i];
				heap[i] = 0
				lenght--;
				p = 0;
				while(i!=0 && heap[i] >= heap[p]){
                                }
                        }

				
			}
			
		}
		else{
			cout << "Wrong Command...";
		}

	}
	return 0;
}
