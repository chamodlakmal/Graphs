#include<iostream>
#include<string>

using namespace std;

class graph{
	private:
		struct node{
			string name;
			int id;
		};
		
		static const int size=4;
		node *array[size];
		int adjmatrix[4][4];
		string cities[4]={"Colombo","Gampaha","Galle","Matara"};
	public:
		graph();
		void addedge(int f,int s);
		void addedge(string f,string s);
		void display();
		void connection();
		
};

graph::graph(){
	for(int i=0;i<size;i++){
		array[i]=new node;
		array[i]->name=cities[i];
		array[i]->id=i;		
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
				adjmatrix[i][j]=0;
			}
		}
}

void graph::addedge(int f,int s){
	if((f>0)&&(s>0)&&(f<=size)&&(s<=size)){
		adjmatrix[f-1][s-1]=1;	
	}
	else{
		cout<<"Invalid"<<endl;
	}
	
}

void graph::addedge(string f,string s){
	int temp1=0,temp2=0;
	for(int i=0;i<size;i++){
		if(array[i]->name==f){
			temp1=i;
		}
	}
	
	for(int i=0;i<size;i++){
		if(array[i]->name==s){
			temp2=i;
		}
	}
		
		if((temp1+1)&&(temp2+1)){
			adjmatrix[temp1][temp2]=1;
			adjmatrix[temp2][temp1]=1;
			
		}
	}


void graph::display(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
				cout<<adjmatrix[i][j]<<"\t";
			}
			cout<<endl;
		}
}

void graph::connection(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				
					cout<<array[i]->name<<"--"<<array[j]->name;
					if(adjmatrix[i][j]){
							cout<<"\tCan"<<endl;
						}
					else{
							cout<<"\tCan't"<<endl;
					}	
			}
		}
}

int main(){
	graph nn;
//	nn.addedge(3,4);
//	nn.addedge(1,4);
//	nn.addedge(2,4);
//	nn.addedge(2,1);
	nn.addedge("Colombo","Gampaha");
	nn.addedge("Colombo","Galle");
	nn.addedge("Gampaha","Galle");
	nn.connection();
	nn.display();
	return 0;
}
