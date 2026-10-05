#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int comp = 0;

vector<int> LPS(string pattern){
int m = pattern.length();
vector<int> lps(m);
int j= 0;
int i =1;

while(i<m){
    if (pattern[i] == pattern[j]){
        j=j+1;
        lps[i] = j;
        i=i+1;
    }      
    else{
        if(j!=0){
            j=lps[j-1];
        }
        else{
            lps[i] = 0;
            i=i+1;
        }
    }

}
return lps;
}


void KmpFind(string line, string pattern){
int n=line.length();
int m = pattern.length();
vector<int> lps = LPS(pattern);
int i= 0;//iterator for line
int j =0;//iterator for pattern

while(i<n){//iterator < length
    if(line[i] == pattern[j]){
        i = i+1;
        j=j+1;
    }
    if(j==m){
        cout<<"found the pattern at index:"<<i-1<<"\n here's the line:'"<<line<<"'\n";
    }
    else{
        if (i<n && pattern[j]!=line[i]){
            if(j!=0){
                j=lps[j-1];
            }   
            else{
                i=1+1;
            }
        }
        else{
            i=i+1;
        }
    }
}

}

int main()
{
    string fileName,inp;
    cout<<"enter file name to be searched\n";
    cin>>fileName;
    cout<<"enter the query to be searched\n";
    cin.ignore();
    getline(cin,inp);

    ifstream inFile(fileName);
    string line;
    int i=0;
    while(getline(inFile,line)){
       KmpFind(line,inp);
    }
    cout<<"no of comparisions:"<<comp<<endl;
    inFile.close();
    return 0;
}

