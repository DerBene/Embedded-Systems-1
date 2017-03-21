#include "../includes/OptParser.h"
#include <iostream>

bool CmdLineOptParser::Parse(int argc, char* argv[]){

    if(argc > 1 ){
        bool evaluator = true;
        for(int i=1; i<=argc; i++){
            char* checkForFlag = argv[i];

            if('-' == *checkForFlag){
                printf("flag: %s\n", checkForFlag);
            }else{
                printf("not a flag \n");
            }
            //ToDo

        }

        return evaluator;

    }else{
        return false;
    }
}

bool CmdLineOptParser::Option(const char C, const char * info) {


    //ToDo
    return true;
}




