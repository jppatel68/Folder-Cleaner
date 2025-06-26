#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isFileEmpty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

void empty_delete() 
{ 
    // Open FIle pointers 
    fstream fin, fout; 
  
    // Open the existing file 
    fin.open("file_data_csv.csv", ios::in); 
  
    // Create a new file to store the non-deleted data 
    fout.open("new.csv", ios::out); 

    string line, file_path, word2; 
    
    vector<string> row; 
  

    while (getline(fin, line)) { 
  
        row.clear(); 
         
        stringstream s(line); 
  
        getline(s, file_path, ',');
        getline(s, word2);

        //string to char array
        const int length = file_path.length();
        char* char_array = new char[length + 1]; 
        strcpy(char_array, file_path.c_str()); 
        
    
        if (isFileEmpty(file_path)) {
            cout << "File " << file_path << " is empty\n";
            remove(char_array);
        }
        else {
            fout << file_path << ',' << word2 << endl;
        }
    }

    fin.close(); 
    fout.close();

    // removing the existing file 
    remove("file_data_csv.csv"); 
  
    // renaming the new file with the existing file name 
    rename("new.csv", "file_data_csv.csv"); 
}

int main(){
    empty_delete();
}

