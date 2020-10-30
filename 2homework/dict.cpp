#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>


void loadDict(int argc, char *argv[]){

    std::ifstream file;
    int count = 0;


    if(argc > 2){
        file.open(argv[2]);
    }
    if(argc == 2){
        file.open("dictionary.txt");
    }

    if(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            if(line.find(':') != std::string::npos){
                count++;
            }
        }
    }
    file.close();

    if(argc > 2){
        std::cout << argv[2] << " has " << count << " words\n";
    }
    else{
        std::cout << "dictionary.txt has " << count << " words\n";
    }
    
}


void pSearch(int argc, char *argv[]){
    std::cout << "Hello!\n";
}



int main(int argc, char* argv[]){


    if(argc > 1){
        if(strcmp(argv[1], "-d") == 0){
            loadDict(argc, argv);
            if(argc > 3){
                if(strcmp(argv[3], "-p") == 0){
                    pSearch(argc, argv);
                }
                
            }
        }
        else{
            std::cout << "No\n";
        }
    }
    else{
        std::cout << "Proper usage is: " << argv[0] << " <switch> <filename>\n";
    }

    

}