#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Function to parse date and time string into time_t
time_t parseDateTime(const string& datetime) {
    tm tm = {};
    istringstream ss(datetime);
    ss >> get_time(&tm, "%T %d %m %Y"); // HH:MM:SS DD MM YYYY format
    if (ss.fail()) {
        throw runtime_error("Failed to parse date and time.");
    }
    return mktime(&tm);
}

// Function to calculate the difference in days between two time_t values
int daysDifference(time_t start, time_t end) {
    return static_cast<int>((end - start) / (60 * 60 * 24)); // Convert seconds to days
}

void n_months_old() 
{ 
    time_t now = time(nullptr);
    // Open FIle pointers 
    fstream fin, fout; 
  
    // Open the existing file 
    fin.open("file_data_csv.csv", ios::in); 
  
    // Create a new file to store the non-deleted data 
    fout.open("new.csv", ios::out); 
  
    
    int N_months=6, access_times, row_size, N_days=6*30;
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

        string file_datetime = row[1];
        time_t file_time = parseDateTime(file_datetime);
        int days_old = daysDifference(file_time, now);

        //string to char array
        const int length = file_path.length();
        char* char_array = new char[length + 1]; 
        strcpy(char_array, file_path.c_str()); 
        
    
        if (days_old>N_days) {
            cout << "File " << file_path << " is more than " << N_months << " old.\n";
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
    n_months_old();
}
