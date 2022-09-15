#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>
#include <iomanip>
#include "Data.h"
using namespace std;

int menus(int menu) {
    int option;
    if(menu == 1) {
        cout << "Types of Data \n" 
        "1.Integers \n" 
        "2.Strings \n" 
        "3.Chars \n" 
        "4.Doubles \n";
        cout << "Option: ";
        cin >> option;
        cout << endl;
        return option;
    }
    else {
        cout << "Overall Functions \n" 
        "1.Change data type \n" 
        "2.Display vector \n" 
        "3.Randomize vector data \n" 
        "4.Sorting Algorithm: Exchange Sort\n" 
        "5.Sorting Algorithm: Selection Sort\n" 
        "6.Sorting Algorithm: Bubble Sort\n"
        "7.Sorting Algorithm: Insertion Sort\n"
        "8.Sorting Algorithm: Merge Sort\n"
        "9.Sorting Algorithm: Quick Sort \n"
        "10.Searching Algorithm: Sequential Search \n"
        "11.Searching Algorithm: Binary Search \n"
        "0.End program \n";
        cout << "Option: ";
        cin >> option;
        cout << endl;
        return option;
    }
}

template<class T>
void create(vector<T> &elements,int length) {
    Data base_object;
    elements.assign(length,base_object);
    srand(time(NULL));
    for(int c = 0;c < length;c++) {
        int num = 1 + rand() % 100;
        int size = 2 + rand() % 10;
        string str = "";
        for(int iC = 0;iC < size;iC++) {
            char character = 'a' + rand() % 26;
            str += character;
        }
        char c_char = 'A' + rand() % 26;
        int lower_base = rand() % 11;
        int upper_base = 11 + rand() % 101; 
        double lower = lower_base;
        double upper = upper_base;
        uniform_real_distribution<double> unif(lower,upper);
        default_random_engine ran_engine;
        double random_double = unif(ran_engine);
        Data object(num,str,c_char,random_double);
        elements[c] = object;  
    }
}

template<class T>
void display(vector<T> elements,int length,int data_type) {
    for(int c = 0;c <= length;c++) {
        elements[c].displayData(data_type);
        string separation = (c != length) ? " " : "\n";
        cout << separation;
    }
    cout << endl;
}

template<class T>
void exchange(vector<T> &elements,int length,int data_type) {
    int comparisons = 0,exchanges = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int c1 = 0;c1 < length;c1++) {
        for(int c2 = 0;c2 < length - 1;c2++) {
            comparisons++;
            if(data_type == 1) {
                if(elements[c2].int_number > elements[c2 + 1].int_number) {
                    exchanges++;
                    swap(elements[c2],elements[c2 + 1]);
                }
            }
            else if(data_type == 2) {
                if(elements[c2].s_string > elements[c2 + 1].s_string) {
                    exchanges++;
                    swap(elements[c2],elements[c2 + 1]);
                }
            }
            else if(data_type == 3) {
                if(elements[c2].character > elements[c2 + 1].character) {
                    exchanges++;
                    swap(elements[c2],elements[c2 + 1]);
                }
            }
            else {
                if(elements[c2].double_number > elements[c2 + 1].double_number) {
                    exchanges++;
                    swap(elements[c2],elements[c2 + 1]);
                }
            }
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << setw(35) << setfill('-') << "" << endl;
    cout << "Execution time: " << time.count() << " nanoseconds" << endl << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of exchanges: " << exchanges << endl;
    cout << setw(35) << setfill('-') << "" << endl;
}

template<class T>
void selection(vector<T> &elements,int length,int data_type) {
    int comparisons = 0, exchanges = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int c1 = 0;c1 < length;c1++) {
        int position = c1;
        if(data_type == 1) {
            int min = elements[c1].int_number;
            for(int c2 = c1 + 1;c2 < length;c2++) {
                comparisons++;
                if(elements[c2].int_number < min) {
                    min = elements[c2].int_number;
                    position = c2;
                }
            }
            exchanges++;
            swap(elements[c1],elements[position]);
        }
        else if(data_type == 2) {
            string min = elements[c1].s_string;
            for(int c2 = c1 + 1;c2 < length;c2++) {
                comparisons++;
                if(elements[c2].s_string < min) {
                    min = elements[c2].s_string;
                    position = c2;
                }
            }
            exchanges++;
            swap(elements[c1],elements[position]);
        }  
        else if(data_type == 3) {
            char min = elements[c1].character;
            for(int c2 = c1 + 1;c2 < length;c2++) {
                comparisons++;
                if(elements[c2].character < min) {
                    min = elements[c2].character;
                    position = c2;
                }
            }
            exchanges++;
            swap(elements[c1],elements[position]);
        }     
        else {
            double min = elements[c1].double_number;
            for(int c2 = c1 + 1;c2 < length;c2++) {
                comparisons++;
                if(elements[c2].double_number < min) {
                    min = elements[c2].double_number;
                    position = c2;
                }
            }
            exchanges++;
            swap(elements[c1],elements[position]);
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << setw(35) << setfill('-') << "" << endl;
    cout << "Execution time: " << time.count() << " nanoseconds" << endl << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of exchanges: " << exchanges << endl;
    cout << setw(35) << setfill('-') << "" << endl;   
}

template<class T>
void bubble(vector<T> &elements,int length,int data_type) {
    int comparisons = 0, exchanges = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int c1 = length - 1;c1 >= 0;c1--) {
        for(int c2 = 0;c2 < c1;c2++) {
            comparisons++;
            if(data_type == 1) {
                if(elements[c1].int_number < elements[c2].int_number) {
                    swap(elements[c1],elements[c2]);
                    exchanges++;
                }
            }
            else if(data_type == 2) {
                if(elements[c1].s_string < elements[c2].s_string) {
                    swap(elements[c1],elements[c2]);
                    exchanges++;
                }
            }
            else if(data_type == 3) {
                if(elements[c1].character < elements[c2].character) {
                    swap(elements[c1],elements[c2]);
                    exchanges++;
                }
            }
            else {
                if(elements[c1].double_number < elements[c2].double_number) {
                    swap(elements[c1],elements[c2]);
                    exchanges++;
                }
            }
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << setw(35) << setfill('-') << "" << endl;
    cout << "Execution time: " << time.count() << " nanoseconds" << endl << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of exchanges: " << exchanges << endl;
    cout << setw(35) << setfill('-') << "" << endl;   
}

template<class T>
void insertion(vector<T> &elements,int length,int data_type) {
    int comparisons = 0,exchanges = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int c1 = 1;c1 < length;c1++) {
        int auxiliar = c1;
        bool comparison = false;
        while(!comparison && auxiliar > 0) {
            if(data_type == 1) {
                if(elements[auxiliar].int_number < elements[auxiliar - 1].int_number) {
                    swap(elements[auxiliar],elements[auxiliar - 1]);
                    auxiliar--;
                    exchanges++;
                }
                else {
                    comparison = true;
                }
                comparisons++;
            }
            else if(data_type == 2) {
                if(elements[auxiliar].s_string < elements[auxiliar - 1].s_string) {
                    swap(elements[auxiliar],elements[auxiliar - 1]);
                    auxiliar--;
                    exchanges++;
                }
                else {
                    comparison = true;
                }
                comparisons++;
            }
            else if(data_type == 3) {
                if(elements[auxiliar].character < elements[auxiliar - 1].character) {
                    swap(elements[auxiliar],elements[auxiliar - 1]);
                    auxiliar--;
                    exchanges++;
                }
                else {
                    comparison = true;
                }
                comparisons++;
            }
            else {
                if(elements[auxiliar].double_number < elements[auxiliar - 1].double_number) {
                    swap(elements[auxiliar],elements[auxiliar - 1]);
                    auxiliar--;
                    exchanges++;
                }
                else {
                    comparison = true;
                }
                comparisons++;
            }
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << setw(35) << setfill('-') << "" << endl;
    cout << "Execution time: " << time.count() << " nanoseconds" << endl << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of exchanges: " << exchanges << endl;
    cout << setw(35) << setfill('-') << "" << endl;   
}

template<class T>
void merge(vector<T> &elements,int low,int mid,int high,int data_type,int &comparisons,int &exchanges) {
    int l_part = mid - low + 1;
    int r_part = high - mid;
    vector<T> l_elements;
    vector<T> r_elements;
    for(int c = 0;c < l_part;c++) {
        l_elements.push_back(elements[low + c]);
    }
    for(int c = 0;c < r_part;c++) {
        r_elements.push_back(elements[mid + 1 + c]);
    }
    int left = 0;
    int right = 0;
    int general = low;
    while(left < l_part && right < r_part) {
        if(data_type == 1) {
            if(l_elements[left].int_number <= r_elements[right].int_number) {
                elements[general] = l_elements[left];
                exchanges++;
                left++;
            }
            else {
                elements[general] = r_elements[right];
                exchanges++;
                right++;
            }
            general++;
        }
        else if(data_type == 2) {
            if(l_elements[left].s_string <= r_elements[right].s_string) {
                elements[general] = l_elements[left];
                exchanges++;
                left++;
            }
            else {
                elements[general] = r_elements[right];
                exchanges++;
                right++;
            }
            general++;
        }    
        else if(data_type == 3) {
            if(l_elements[left].character <= r_elements[right].character) {
                elements[general] = l_elements[left];
                exchanges++;
                left++;
            }
            else {
                elements[general] = r_elements[right];
                exchanges++;
                right++;
            }
            general++;
        }  
        else {
            if(l_elements[left].double_number <= r_elements[right].double_number) {
                elements[general] = l_elements[left];
                exchanges++;
                left++;
            }
            else {
                elements[general] = r_elements[right];
                exchanges++;
                right++;
            }
            general++;
        }
        comparisons++;  
    }
    while(left < l_part) {
        elements[general] = l_elements[left];
        left++;
        general++;
        exchanges++;
    }
    while(right < r_part) {
        elements[general] = r_elements[right];
        right++;
        general++;
        exchanges++;
    }
}

template<class T>
void mergeSort(vector<T> &elements,int low,int high,int data_type,int &comparisons,int &exchanges) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(elements,low,mid,data_type,comparisons,exchanges);
        mergeSort(elements,mid + 1,high,data_type,comparisons,exchanges);
        merge(elements,low,mid,high,data_type,comparisons,exchanges);
    }
}

template<class T>
int partition(vector<T> &elements,int low,int high,int data_type,int &comparisons,int &exchanges) {
    int initial = (low - 1);
    for (int c = low; c < high; c++)  
    {  
        if(data_type == 1) {
            int pivot = elements[high].int_number;
            if (elements[c].int_number < pivot) {  
            initial++;  
            swap(elements[initial], elements[c]); 
            exchanges++; 
            }  
        }
        else if(data_type == 2) {
            string pivot = elements[high].s_string;
            if (elements[c].s_string < pivot) {  
            initial++;  
            swap(elements[initial], elements[c]); 
            exchanges++; 
            }  
        }
        else if(data_type == 3) {
            char pivot = elements[high].character;
            if (elements[c].character < pivot) {  
            initial++;  
            swap(elements[initial], elements[c]);  
            exchanges++;
            }  
        }
        else {
            double pivot = elements[high].double_number;
            if (elements[c].double_number < pivot) {  
            initial++;  
            swap(elements[initial], elements[c]);
            exchanges++;  
            }  
        }
        comparisons++;
    }  
    exchanges++;
    initial++;
    swap(elements[initial], elements[high]);  
    return (initial); 
}

template<class T>
void quickSort(vector<T> &elements, int low, int high,int data_type,int &comparisons,int &exchanges)  
{  
    if (low < high)  
    {  
        int pivot_location = partition(elements, low, high,data_type,comparisons,exchanges);  
        quickSort(elements, low, pivot_location - 1,data_type,comparisons,exchanges);  
        quickSort(elements, pivot_location + 1, high,data_type,comparisons,exchanges);  
    }  
} 

template<class T>
int seqSearchInt(vector<T> elements,int length,int element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int position= -1;
    for(int c = 0;c < length;c++) {
        if(elements[c].int_number == element) {
            position = c;
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Execution time: " << time.count() << endl;
    if(position != -1) {
        return position;
    }
    else {
        throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
    }
}

template<class T>
int seqSearchStr(vector<T> elements,int length,string element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int position= -1;
    for(int c = 0;c < length;c++) {
        if(elements[c].s_string == element) {
            position = c;
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Execution time: " << time.count() << endl;
    if(position != -1) {
        return position;
    }
    else {
        throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
    }
}

template<class T>
int seqSearchChar(vector<T> elements,int length,char element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int position= -1;
    for(int c = 0;c < length;c++) {
        if(elements[c].character == element) {
            position = c;
            break;
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Execution time: " << time.count() << endl;
    if(position != -1) {
        return position;
    }
    else {
        throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
    }
}

template<class T>
int seqSearchDouble(vector<T> elements,int length,double element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int position= -1;
    for(int c = 0;c < length;c++) {
        if(elements[c].double_number == element) {
            position = c;
            break;
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Execution time: " << time.count() << endl;
    if(position != -1) {
        return position;
    }
    else {
        throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
    }
}

template<class T>
int binarySearchInt(vector<T> elements,int length,int element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int sup,inf,mid;
    inf = 0;
    sup = length;
    mid = sup / 2;
    while(elements[mid].int_number != element && inf != sup) {
        if(element > elements[mid].int_number) {
            inf = mid + 1;
            mid = inf + ((sup - inf) / 2);
        }
        else {
            sup = mid - 1;
            mid = sup - ((sup - inf) / 2);
        }
    }
    if(elements[mid].int_number == element) {
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> time = finish - start;
        cout << "Execution time: " << time.count() << endl << endl;
        return mid;
    }
    throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n\n");
}

template<class T>
int binarySearchStr(vector<T> elements,int length,string element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int sup,inf,mid;
    inf = 0;
    sup = length;
    mid = sup / 2;
    while(elements[mid].s_string != element && inf != sup) {
        if(element > elements[mid].s_string) {
            inf = mid + 1;
            mid = inf + ((sup - inf) / 2);
        }
        else {
            sup = mid - 1;
            mid = sup - ((sup - inf) / 2);
        }
    }
    if(elements[mid].s_string == element) {
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> time = finish - start;
        cout << "Execution time: " << time.count() << endl << endl;
        return mid;
    }
    throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
}

template<class T>
int binarySearchChar(vector<T> elements,int length,char element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int sup,inf,mid;
    inf = 0;
    sup = length;
    mid = sup / 2;
    while(elements[mid].character != element && inf != sup) {
        if(element > elements[mid].character) {
            inf = mid + 1;
            mid = inf + ((sup - inf) / 2);
        }
        else {
            sup = mid - 1;
            mid = sup - ((sup - inf) / 2);
        }
    }
    if(elements[mid].character == element) {
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> time = finish - start;
        cout << "Execution time: " << time.count() << endl << endl;
        return mid;
    }
    throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
}

template<class T>
int binarySearchDouble(vector<T> elements,int length,double element,int data_type) {
    auto start = chrono::high_resolution_clock::now();
    int sup,inf,mid;
    inf = 0;
    sup = length;
    mid = sup / 2;
    while(elements[mid].double_number != element && inf != sup) {
        if(element > elements[mid].double_number) {
            inf = mid + 1;
            mid = inf + ((sup - inf) / 2);
        }
        else {
            sup = mid - 1;
            mid = sup - ((sup - inf) / 2);
        }
    }
    if(elements[mid].double_number == element) {
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> time = finish - start;
        cout << "Execution time: " << time.count() << endl << endl;
        return mid;
    }
    throw runtime_error("_ERROR_ \nThe element you're looking for doesn't appear to exist on the vector \nPlease try again \n");
}

int main() {
    vector<Data> elements;
    string str_data;
    int length,data_type,option,comparisons,exchanges,int_data,position;
    char char_data;
    double double_data;
    cout << "Enter de length of the vector: ";
    cin >> length;
    cout << endl;
    create(elements,length);
    data_type = menus(1);
    do {
        option = menus(2);
        switch (option) {
        case 0:
            cout << "Thanks for using the different algorithms for sorting and searching \n";
            break;
        case 1:
            cout << "Please enter new data type: ";
            data_type = menus(1);
            cout << "New data type has been established \n\n";
            break;
        case 2:
            cout << "Vector: \n";
            display(elements,length - 1,data_type);
            cout << endl;
            break;
        case 3:
            create(elements,length);
            cout << "All data has now been randomized \n\n";
            break;
        case 4:
            exchange(elements,length,data_type);
            cout << endl;
            break;
        case 5:
            selection(elements,length,data_type);
            break;
        case 6:
            bubble(elements,length,data_type);
            break;
        case 7:
            insertion(elements,length,data_type);
            break;
        case 8:
            comparisons = 0;
            exchanges = 0;
            mergeSort(elements,0,length - 1,data_type,comparisons,exchanges);
            cout << setw(35) << setfill('-') << "" << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            cout << "Number of exchanges: " << exchanges << endl;
            cout << setw(35) << setfill('-') << "" << endl << endl;   
            break;
        case 9:
            comparisons = 0;
            exchanges = 0;
            quickSort(elements,0,length - 1,data_type,comparisons,exchanges);
            cout << setw(35) << setfill('-') << "" << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            cout << "Number of exchanges: " << exchanges << endl;
            cout << setw(35) << setfill('-') << "" << endl << endl;  
            break;
        case 10:
            cout << "Please enter the element you're looking for: ";
            if(data_type == 1) {
                cin >> int_data;
                cout << endl;
                try {
                    position = seqSearchInt(elements,length,int_data,data_type);
                    cout << "The element " << int_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else if(data_type == 2) {
                cin >> str_data;
                cout << endl;
                try {
                    position = seqSearchStr(elements,length,str_data,data_type);
                    cout << "The element " << str_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else if(data_type == 3) {
                cin >> char_data;
                cout << endl;
                try {
                    position = seqSearchChar(elements,length,char_data,data_type);
                    cout << "The element " << char_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else {
                cin >> double_data;
                cout << endl;
                try {
                    position = seqSearchDouble(elements,length,double_data,data_type);
                    cout << "The element " << double_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            break;
        case 11:
            cout << "Please enter the element you're looking for: ";
            if(data_type == 1) {
                cin >> int_data;
                cout << endl;
                try {
                    position = binarySearchInt(elements,length,int_data,data_type);
                    cout << "The element " << int_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else if(data_type == 2) {
                cin >> str_data;
                cout << endl;
                try {
                    position = binarySearchStr(elements,length,str_data,data_type);
                    cout << "The element " << str_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else if(data_type == 3) {
                cin >> char_data;
                cout << endl;
                try {
                    position = binarySearchChar(elements,length,char_data,data_type);
                    cout << "The element " << char_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            else {
                cin >> double_data;
                cout << endl;
                try {
                    position = binarySearchDouble(elements,length,double_data,data_type);
                    cout << "The element " << double_data << " was found in position number " << position << endl;
                }
                catch(runtime_error error) {
                    cout << error.what() << endl;
                }
                cout << endl;
            }
            break;
        default:
            cout << "_ERROR_ \nAn unexisting option was selected, please try again \n\n";
            break;
        }
    } while (option != 0);
    return 0;
}