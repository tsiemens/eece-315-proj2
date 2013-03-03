#include<iostream>
#include<fstream>
#include<string>

int main(){
	using namespace std;
	string filename;
	ifstream infile;

	cout<<"Please enter workload filename"<<endl;
	cin>>filename;

	infile.open(filename.c_str());
	if(infile.is_open())
		cout<<"open success"<<endl;
	else
		cout<<"File not found"<<endl;

	infile.close();
	return 0;

}
