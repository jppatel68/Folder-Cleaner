#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Function to calculate the hash value of a string
size_t hashString(const string& str) {
    hash<string> hasher;
    return hasher(str);
}

// Function to compute the hash value of a file
size_t computeFileHash(const string& filename) {
    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    return hashString(content);
}

// Function to group files based on their content
unordered_map<size_t, vector<string>> groupFilesByContent(const vector<string>& filenames) {
    unordered_map<size_t, vector<string>> groups;
    for (const auto& filename : filenames) {
        size_t hash = computeFileHash(filename);
        groups[hash].push_back(filename);
    }
    return groups;
}


void redundant_delete() 
{ 
    // Open FIle pointers 
    fstream fin, fout; 
  
    // Open the existing file 
    fin.open("file_data_csv.csv", ios::in); 
  
    // Create a new file to store the non-deleted data 
    fout.open("new.csv", ios::out); 
  
    
    int row_size;
    string line, word, word2, temp;
    vector<string> filenames;
    map<string, string> mp;
  
    while (getline(fin, line)) {
         
        stringstream s(line);

        getline(s, word, ',');
        getline(s, word2);

        mp[word]=word2;
        
        filenames.push_back(word);
    }

    unordered_map<size_t, vector<string>> fileGroups = groupFilesByContent(filenames);

        for (const auto& pair : fileGroups) 
        {
            const vector<string>& files = pair.second;
            cout << "Group with same content:\n";
            cout << files[0] << endl;

            temp=files[0];
            fout << temp << ',' << mp[temp] <<endl;


            for (int i = 1; i < files.size(); i++){
                temp=files[i];
                cout << files[i] << endl;
                const int length = temp.length();
                char* char_array = new char[length + 1]; 
                strcpy(char_array, temp.c_str());
                remove(char_array);
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
    redundant_delete();
}
