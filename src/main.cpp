#include <iostream>
#include "../include/OptParser.h"

using namespace std;

int main(int argc, char **argv) {
    CmdLineOptParser parser;

    if(argc <= 1) {
        int retVal = 0;

        cout << "#### Testing a single flag '-x', should return true ####" << endl;
        char *testParams1[] = {(char *) "./programm", (char *) "-x"};
        if (parser.Parse(2, testParams1)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x test', should return true ####" << endl;
        char *testParams2[] = {(char *) "./programm", (char *) "-x", (char *) "test"};
        if (parser.Parse(3, testParams2)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-xtest', should return true ####" << endl;
        char *testParams3[] = {(char *) "./programm", (char *) "-xtest"};
        if (parser.Parse(2, testParams3)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x=test', should return true ####" << endl;
        char *testParams4[] = {(char *) "./programm", (char *) "-x=test"};
        if (parser.Parse(2, testParams4)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single flag '-?', should return false ####" << endl;
        char *testParams5[] = {(char *) "./programm", (char *) "-?"};
        if (!parser.Parse(2, testParams5)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x =test', should return true ####" << endl;
        char *testParams6[] = {(char *) "./programm", (char *) "-x", (char *) "=test"};
        if (parser.Parse(3, testParams6)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x==test', should return true ####" << endl;
        char *testParams7[] = {(char *) "./programm", (char *) "-x==test"};
        if (parser.Parse(2, testParams7)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x-test', should return true ####" << endl;
        char *testParams8[] = {(char *) "./programm", (char *) "-x-test"};
        if (parser.Parse(2, testParams8)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing a single parameter '-x   test', should return true ####" << endl;
        char *testParams9[] = {(char *) "./programm",
                               (char *) "-x", (char *) "", (char *) "", (char *) "", (char *) "test"};
        if (parser.Parse(6, testParams9)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing mixed parameters '-a -b hallo -cwelt -d=cpp', should return true ####" << endl;
        char *testParams10[] = {(char *) "./programm",
                                (char *) "-a",
                                (char *) "-b", (char *) "hallo",
                                (char *) "-cwelt",
                                (char *) "-d=cpp"};
        if (parser.Parse(6, testParams10)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing mixed parameters '-ahallo -b=welt -d cpp -a', should return true ####" << endl;
        char *testParams11[] = {(char *) "./programm",
                                (char *) "-ahallo",
                                (char *) "-b=welt",
                                (char *) "-c", (char *) "cpp",
                                (char *) "-d"};
        if (parser.Parse(6, testParams11)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing mixed parameters '-ahallo -b=w€lt -d cpp -a', should return true ####" << endl;
        char *testParams12[] = {(char *) "./programm",
                                (char *) "-ahallo",
                                (char *) "-b=w€lt",
                                (char *) "-c", (char *) "cpp",
                                (char *) "-d"};
        if (parser.Parse(6, testParams12)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing mixed parameters '-a -b hallo -cwelt -d=cpp quark', should return false ####" << endl;
        char *testParams13[] = {(char *) "./programm",
                                (char *) "-a",
                                (char *) "-b", (char *) "hallo",
                                (char *) "-cwelt",
                                (char *) "-d=cpp",
                                (char *) "quark"};
        if (!parser.Parse(7, testParams13)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        cout << "#### Testing no parameters at all, should return true ####" << endl;
        char *testParams14[] = {(char *) "./programm"};
        if (parser.Parse(1, testParams14)) {
            cout << "Test Success!" << endl;
        } else {
            cout << "Test Failed!" << endl;
            retVal++;
        }
        cout << endl;

        return retVal;
    }
    else {
        return (int) parser.Parse(argc,argv);
    }
}