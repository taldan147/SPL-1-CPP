#include <iostream>
#include "Session.h"

using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    Session sess(argv[1]);
    sess.getGraph();
    switch(sess.getTreeType()){

        case Cycle:
            cout << "Cycle";
            break;
        case MaxRank:
            cout<< "Max";
            break;
        case Root:
            cout<< " root";
            break;
        default:
            cout<< "shit";
    }
    sess.simulate();
    return 0;
}
