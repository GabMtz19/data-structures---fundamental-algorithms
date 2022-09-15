#include <iostream>
using namespace std;

struct Data {
    int int_number;
    string s_string;
    char character;
    double double_number;
    Data();
    Data(int,string,char,double);
    void displayData(int);
};

Data::Data() {
    int_number = 0;
    s_string = "N/A";
    character = '-';
    double_number = 0.0;
}

Data::Data(int numero,string s_string,char character,double num_double) {
    int_number = numero;
    this->s_string = s_string;
    this->character = character;
    double_number = num_double;
}

void Data::displayData(int data_type) {
    if(data_type == 1) {
        cout << "[" << int_number << "]";
    }
    else if(data_type == 2) {
        cout << "[" << s_string << "]";
    }
    else if(data_type == 3) {
        cout << "[" << character << "]";
    }
    else {
        cout << "[" << double_number << "]";
    }
}