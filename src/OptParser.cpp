#include "../include/OptParser.h"
#include <iostream>

bool CmdLineOptParser::Parse(int argc, char* argv[]){

    //ToDo: Must return True if no parameters are given
    if(argc > 1 ){
        bool evaluator = true;
        for(int i=1; i<argc; i++){
            char* checkForFlag = argv[i];
            char printParameter;
            char *printArguments = NULL;

            if('-' == *checkForFlag){
                checkForFlag++;
                //ToDO: Validate that its a char
                printParameter = *checkForFlag;
                printf("flag: %c\t", printParameter);
                checkForFlag++;

                /*
                 * If there is a Whitespace at this point, it means it cant be of sort "-xWert" (Type 2)
                 */
                 if ( *checkForFlag == '\0') {
                     checkForFlag++;

                     /*
                      * If there is a "-" at this point, it means it was of sort "-x" (Type 1)
                      * else the following are the Arguments (Typ 3)
                      */
                     if ('-' == *checkForFlag){
                         printArguments = "bool"; //ToDo: change to smth better
                     } else {
                         i++;
                         printArguments = checkForFlag;
                     }
                 /*
                  * If there is "=" at this point its an assignment of "printparameter" to the Arguments given after "=" (Typ 4)
                  */
                 }else if('=' == *checkForFlag){
                     checkForFlag++;
                     printArguments = checkForFlag;
                 }else{
                     printArguments = checkForFlag;
                 }
            }else{
                printf("Not a valid option at this point \n");
                evaluator = false;
            }

            if(evaluator){
                Option(printParameter,printArguments);
                printf("Argument: %s\n", printArguments);
            }
        }

        return evaluator;

    }else{
        return false;
    }
}

bool CmdLineOptParser::Option(const char C, const char * info) {

    (void) C;
    (void) info;
    //ToDo
    return true;
}




