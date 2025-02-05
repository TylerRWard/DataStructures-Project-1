#include <iostream>
#include <fstream>
#include "sort.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3 && argc != 4){
        cerr << "Usage: "<<argv[0] << " <input_file> <algorithm> [-print]"<<endl;
        return 1;
    }


    string inputFile = argv[1];
    string algorithm = argv[2];
    bool printFlag = (argc ==4) && (string(argv[3]) == "-print");

    ifstream inFile(inputFile);
    if (!inFile){
        cerr<<"Error: Unable to open input file."<<endl;
        return 1;
    }

    
    int N;
    if(!(inFile >> N)){
        cerr <<"Error reading count from input file."<<endl;
        return 1;
    }

    //allocate dynamic array
    string* data = new string[N];
    inFile.ignore();

    //read strings
    for (int i = 0; i < N; ++i){
        if(!getline(inFile, data[i])){
            cerr<<"Error: Input file has fewer lines than expected."<<endl;
            delete[] data;
            return 1;
        }    
    }


    //select sorting algo
    if(algorithm == "bubble"){
        bubble(data, N);
    }else if(algorithm == "merge"){
        merge(data, 0, N-1);
    }else if(algorithm =="quick"){
        quick(data,0,N-1);
    }else if(algorithm == "heap"){
        heap(data, N);
    }else if (algorithm =="sys"){
        sort(data, data+N);
    }else{
        cerr<<"Error: Invalid sorting algorithm specified"<<endl;
        delete[] data;
        return 1;
    }

    if (printFlag){
        for (int i = 0; i < N; ++i){
            cout << data[i] <<endl;
        }
    }

    delete[] data;
    return 0;
}