#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file, vector<string> &x, vector<int> &y, vector<char> &z){
    ifstream scoretext;
    scoretext.open("name_score.txt");
    string textline;
    char name[100];
    int num1;
    int num2;
    int num3;
    int sum = 0;
   
    while(getline(scoretext,textline)){
        sscanf(textline.c_str(),"%[^:]: %d %d %d",name,&num1,&num2,&num3);
        x.push_back(name);
        sum = num1 + num2 + num3;
        y.push_back(sum);
        z.push_back(score2grade(sum));
    }
  
}

void getCommand(string &x, string &y){
    string input;
    char A[100];
    char B[100];
    cout << "Please input your command: ";
    getline(cin,input);
    sscanf(input.c_str(),"%s %[^:]",A,B);
    x = A;
    y = B;
}

void searchName(vector<string> x, vector<int> y, vector<char> z, string key){
    bool wornggrade = false;

    cout << "---------------------------------" << endl;

    for(unsigned int i=0;i < x.size();i++){
        if(key == toUpperStr(x[i])){
            cout << x[i] << "'s score = " << y[i] << endl;
            cout << x[i] << "'s grade = " << z[i] << endl;
            wornggrade = true;
        }
    }
    if(!wornggrade){
        cout << "Cannot found." << endl;
    }

    cout << "---------------------------------" << endl;

}

void searchGrade(vector<string> x, vector<int> y, vector<char> z, string key){
    bool wornggrade = false;

    cout << "---------------------------------" << endl;

    for(unsigned int i=0;i < x.size();i++){
        string n;
        n = z[i];
        if(key == toUpperStr(n)){
            cout << x[i] << " " << "(" << y[i] << ")" << endl;
            wornggrade = true;
        }
    }
    if(!wornggrade){
        cout << "Cannot found." << endl;
    }
    
    cout << "---------------------------------" << endl;

}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
