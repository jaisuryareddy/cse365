/**
 * Author: Deven Pile
 * Class: CSE365 
 * Assignment: Homework 2 My Dictionary
**/

#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <unistd.h>



/**
 * Loads dictionary file into a map
 * 
 * If no file is specified, defaults to dictionary.txt stored
 * in program folder
 * 
 * @param argc count of command line args
 * @param argv char array of command line args
 * @return map contianing the lines from dictionary.txt
 * 
 **/
std::map<int, std::string> loadDict(int argc, char *argv[]){
    std::map<int, std::string> dict;
    std::fstream file;
    std::string line;
    //std::cout << "Argc: " << argc << "\n";
    if( argc > 2 ){
        if(strcmp(argv[1], "-d") == 0){
            //std::cout << "Hereeee\n";
            file.open(argv[2]);
        }
        if(strcmp(argv[1], "-p")== 0){
            file.open("dictionary.txt");
        }
        if(strcmp(argv[1], "-s") == 0){
            file.open("dictionary.txt");
        }
        //std::cout << "Here\n";
    }
    else if( argc == 2 || argc == 1){
        file.open("dictionary.txt");
    }
    else{
        file.open("dictionary.txt");
    }

    if(file.is_open()){
        int counter = 0;
        while(std::getline(file, line)){
            dict.insert(std::pair<int, std::string>(counter, line));
            counter++;
            //std::cout << counter << "\n";
        }
    }
    file.close();
    return dict;
}


/**
 * Counts number of words in dictionary
 * Prints total
 * 
 * @param dict map containing the dictionary
 * @param argc count of command line args
 * @param argv char array of command line args
 * @return void
**/
void countWords(std::map<int, std::string> dict, int argc, char *argv[]){
    std::map<int, std::string>::iterator itr;
    int count = 0;
    for( itr = dict.begin(); itr != dict.end(); ++itr){
        if(itr -> second.find(':') != std::string::npos){
            count++;
        }
    }

    if(argc > 2 && strcmp(argv[1], "-d") == 0){
        std::cout << argv[2] << " has " << count << " words\n";
    }
    else{
        std::cout << "dictionary.txt has " << count << " words\n";
    }
    

}

/**
 * Creates a substring from the begining of a string to the 
 * specified char in the string
 * 
 * @param element string to create a substring of
 * @param c char to end search at
 * @return Returns the substring
**/

std::string findSub(std::string element, char c){
    std::size_t pos = element.find(c);
    return element.substr(0, pos);
}

/**
 * Searches each word for a specified prefix
 * 
 * The code:
 * auto res = std::mismatch(search.begin(), search.end(), itr -> second.begin());
 * and 
 * if(res.first == search.end()){
 * 
 * is adapted from Nim on stack overflow
 * https://stackoverflow.com/questions/7913835/check-if-one-string-is-a-prefix-of-another
 * 
 * @param dict Map containing the dictionary
 * @param argc count of command line args
 * @param argv char array of command line args
 * @return void
 * 
**/
void pSearch(std::map<int, std::string> dict, int argc, char* argv[]){
    std::map<int, std::string>::iterator itr;
    std::string word;
    
    if(strcmp(argv[1], "-p") == 0){
        if(argc > 3){
            if(strcmp(argv[3], "-n") == 0){
                int counter = 0;
                int count = std::stoi(argv[4]);
                if(count > dict.size()){
                    count = dict.size();
                }
                for(itr = dict.begin(); itr != dict.end(); ++itr){
                    word = findSub(itr -> second, ':');
                    std::string search = argv[2];
                    auto res = std::mismatch(search.begin(), search.end(), itr -> second.begin());
                    if(res.first == search.end()){
                        if(counter < count){
                            std::cout << itr -> second << "\n";
                            counter++;
                        }
                    }
                }
            }
        }
        else{
            for(itr = dict.begin(); itr != dict.end(); ++itr){
                word = findSub(itr -> second, ':');
                std::string search = argv[2];
                auto res = std::mismatch(search.begin(), search.end(), itr -> second.begin());
                if(res.first == search.end()){
                    std::cout << itr -> second << "\n";
                }
            }
        }
    }
    else if(strcmp(argv[3], "-p") == 0){
        if(argc > 5){
            if(strcmp(argv[5], "-n") == 0){
                int counter = 0;
                int count = std::stoi(argv[6]);
                if(count > dict.size()){
                    count = dict.size();
                }
                for(itr = dict.begin(); itr != dict.end(); ++itr){
                    word = findSub(itr -> second, ':');
                    std::string search = argv[4];
                    auto res = std::mismatch(search.begin(), search.end(), itr -> second.begin());
                    if(res.first == search.end()){
                        if(counter < count){
                            std::cout << itr -> second << "\n";
                            counter++;
                        }

                    }
                    //std::cout << word << "\n";
                }
            }
        }
        else{
            for(itr = dict.begin(); itr != dict.end(); ++itr){
                word = findSub(itr -> second, ':');
                std::string search = argv[4];
                auto res = std::mismatch(search.begin(), search.end(), itr -> second.begin());
                if(res.first == search.end()){
                    std::cout << itr -> second << "\n";
                }
            }
        }
        
    }
}


/**
 * Writes dictionary map back out to file it was loaded from
 * 
 * @param dict map containing the dictionary
 * @param argv char array of command line arguments
 * @return void 
 * 
**/
void writeFile(std::map<int, std::string> dict, char *argv[]){
    std::ofstream file;
    if(strcmp(argv[1], "-d") == 0){
        file.open(argv[2]);
    }
    else{
        file.open("dictionary.txt");
    }
    std::map<int, std::string>::iterator itr;

    if(file.is_open()){
        for(itr = dict.begin(); itr != dict.end(); ++itr){
            file << itr -> second << "\n";
        }

    }
    file.close();

}


/**
 * Searches for a specified word and replaces it with another specified word
 * Similar to Find and Replace from word processors (not as fancy tho!)
 * 
 * @param dict map containing the dictionary
 * @param argc count of command line arguments
 * @param argv char array of command line arguments
 * @return void
 * 
**/
void wordReplace(std::map<int, std::string> dict, int argc, char *argv[]){
    std::map<int, std::string>::iterator itr;
    std::string word;
    if( argc <= 5 ){
        if(strcmp(argv[1], "-s") == 0){
            for(itr = dict.begin(); itr != dict.end(); ++itr){
                itr -> second = std::regex_replace(itr -> second, std::regex(argv[2]), argv[4]);
            }
        }
    }
    else if(argc == 7){
        for(itr = dict.begin(); itr != dict.end(); ++itr){
            itr -> second = std::regex_replace(itr -> second, std::regex(argv[4]), argv[6]);
        }
    }
    writeFile(dict, argv);

}

/**
 * Opens specified file in a text editor defined by user following 
 * the format /bin/<program>
 * 
 * if no file is specified, defaults to dictionary.txt stored in program 
 * folder
 * 
 * @param argc count of command line arguments
 * @param argv char array of command line arguments
 * @return void
**/
void spawnEditor(int argc, char* argv[]){


    if(argc > 3){
        char* args[] = {argv[2], argv[3], NULL};
        execv(args[0], args);
    }
    if(argc == 3){
        char defaultFile[] = "dictionary.txt";
        char *args[] = {argv[2], defaultFile, NULL};
        execv(args[0], args);
    }

}


/**
 * Main method of the program
 * contains logic for deciding what to do with command line agruments
 * 
 * @return int 
**/
int main(int argc, char* argv[]){
    std::map<int,std::string> dict;
    if(argc > 1){
        if(strcmp(argv[1], "-d") == 0){
            dict = loadDict(argc, argv);
            countWords(dict, argc, argv);
            
            if(argc > 3){
                if(strcmp(argv[3], "-p") == 0){
                    pSearch(dict, argc, argv);
                }
                if(strcmp(argv[3], "-s") == 0){
                    wordReplace(dict, argc, argv);
                }
                
            }
        }
        if(strcmp(argv[1],"-p") == 0){
            //std::cout << "Here!!\n";
            dict = loadDict(argc, argv);
            countWords(dict, argc, argv);
            pSearch(dict, argc, argv);

        }
        if(strcmp(argv[1], "-s") == 0){
            std::cout << "HERE\n";
            dict = loadDict(argc, argv);
            countWords(dict, argc, argv);
            wordReplace(dict, argc, argv);

        }
        if(strcmp(argv[1], "-v") == 0){
            spawnEditor(argc, argv);
        }
        else{
            //std::cout << "No\n";
        }
    }
    else if(argc == 1){
        dict = loadDict(argc, argv);
        countWords(dict, argc, argv);
    }
    else{
        std::cout << "Proper usage is: " << argv[0] << " <switch> <filename>\n";
    }

    

}