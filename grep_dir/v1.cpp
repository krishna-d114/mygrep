#include<iostream>
#include<fstream>
#include<string>


using namespace std;
int main(){
    string Filename;
    string inp;
    cout<<"enter file name\n";
    cin>>Filename;
    cout<<"enter word\n";
    cin>>inp;

    ifstream inFile(Filename);
    
    if(!inFile.is_open()){
        cerr<<"Error reading into file!"<<endl;
        return 1;
    }
    string line;
    int i=0;
    while(getline(inFile,line)){
        i++;
        if(line.find(inp)!= string::npos){
            cout<<"line "<<i<<" ' "<<line<<" ' "<<endl;
        }
    }

    inFile.close();
    return 0;
}