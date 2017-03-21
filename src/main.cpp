#include "../includes/OptParser.h"

int main(int argc, char* argv[]) {
    /*
     * wird gegeben
     */
    CmdLineOptParser tester;
    tester.Parse(argc,argv);

    return 0;
}
