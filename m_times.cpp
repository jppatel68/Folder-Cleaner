#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void unaccessed_mtimes() 
{ 
  
    // Open FIle pointers 
    fstream fin, fout; 
  
    // Open the existing file 
    fin.open("file_data_csv.csv", ios::in); 
  
    // Create a new file to store the non-deleted data 
    fout.open("new.csv", ios::out); 
  
    
    int M=6, access_times, row_size;
    string line, word; 
    
    vector<string> row; 
  

    while (getline(fin, line)) { 
  
        row.clear(); 
         
        stringstream s(line); 
  
        while (getline(s, word, ',')) { 
            row.push_back(word); 
        } 
  
        int row_size = row.size(); 
        string file_path(row[0]);
        access_times = stoi(row[2]);

        //string to char array
        const int length = file_path.length();
        char* char_array = new char[length + 1]; 
        strcpy(char_array, file_path.c_str()); 
        
    
        if (access_times < M) {
            cout << "File " << file_path << " has been accessed less than " << M << " times.\n";
            remove(char_array);
            

        }
        else { 
                for (int i = 0; i < row_size - 1; i++) { 
                    fout << row[i] << ","; 
                } 
                fout << row[row_size - 1] << "\n";
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
    unaccessed_mtimes();
}


