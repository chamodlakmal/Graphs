#include<iostream>
#include<string>

using namespace std;
class graph{
	
	private:
		static const int graphsize = 4;
		struct node{
			
			string name;
			char color;
			node * next;
		};
		
		node *adjarr[graphsize];
		
		string cities[4]={"Colombo","Galle","Matara","Gampaha"};
	public:
		graph();
		void display();	
		void addedge(string f,string s);
};

graph::graph(){
	for(int i=0;i<graphsize;i++){
		adjarr[i] = new node;
		adjarr[i]->name=cities[i];
		adjarr[i]->color='W';
		adjarr[i]->next=NULL;
	}
}

void graph::addedge(string f,string s){
	for(int i=0;i<graphsize;i++){
		if(adjarr[i]->name==f){
			node *ptr;
			node *n;
			ptr=adjarr[i];
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			n=new node;
			n->name=s;
			n->color='W';
			n->next=NULL;
			ptr->next=n;
		}
		if(adjarr[i]->name==s){
			node *ptr;
			node *n;
			ptr=adjarr[i];
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			n=new node;
			n->name=f;
			n->color='W';
			n->next=NULL;
			ptr->next=n;
		}
	}
}

void graph::display(){
	node *p;
	
	for(int i=0;i<graphsize;i++){
		p=adjarr[i];
		while(p!=NULL){
			cout<<p->name<<"\t\t";
			p=p->next;
		}
		cout<<endl;
	}
}

int main(){
	
	cout<<"Adj Ary ||\t the link list nodes"<<endl;
	cout<<"..................................."<<endl;
	graph mm;
	mm.addedge("Colombo","Gampaha");
	mm.addedge("Colombo","Galle");
	mm.addedge("Gampaha","Galle");
	mm.display();
	
	
	return 0;
}
