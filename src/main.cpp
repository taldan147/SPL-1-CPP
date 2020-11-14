#include "../include/Session.h"
#include "../include/Tester.h"
#include <csignal>
#include <iostream>



using namespace std;


Tester * testGenerator;

void signalHandler(int signal){
    std::cout << "Unknown Exception! Try running generatedTest.json Manually!" << std::endl;
    exit(signal);
}

void runTest(){
    signal(SIGSEGV,signalHandler);
    srand(time(NULL));
    int testerOptionChosen = 0;

    std::cout << "---------------\r\nWelcome\r\n---------------\r\nPlease type 1 to generate tests or 2 to run tests file" << std::endl;
    cin >> testerOptionChosen ;


    if(testerOptionChosen == 2) {
        testGenerator = new Tester(2, 1);
        testGenerator->initate();
        std::cout << "----------------------\r\nTotal Passed Tests : " << testGenerator->numPassedTests
                  << "\r\nFailed Tests : " << testGenerator->numInvalidTests << "\r\n----------------------\r\n"
                  << std::endl;
        delete (testGenerator);
    }else
    if(testerOptionChosen == 1){
        std::cout << " Generating Random 10000 Tests " << std::endl;
        for(int i = 0 ;i < 10000 ; i ++)
        {
            testGenerator = new Tester(1,i);
            testGenerator->initate();
            delete(testGenerator);
        }
        std::cout << "\r\nTests Written To tests.json, have fun." << std::endl;
    }else
        std::cout << "Invalid Input" << std::endl;
}

template <class T>

void FiveRuleTestTree() {
    std::cout << "\r\n-------------------------- Tree Checks -------------------------" << std::endl;
    std::cout << "Tree Type - " << typeid(T).name() << std::endl;
    std::cout << "----------------------------------------------------------------\r\n" << std::endl;
    T * test1      = new T(5);
    T * test2      = new T(3);
    test1->addChild(*test2);
    delete(test2);

    std::cout << "------Copy Test------" << std::endl;
    T test3 = *test1; //Tree Copy Constructor Tester, It shall choose the utilize the copy constructor since it is not initialized!
    delete(test1);
    if(test1->getChildren().size () == 0 && test3.getChildren().size() == 1) {
        if(test3.getChildren()[0]->getRootLabel() == 3){
            std::cout << "Passed | Copy Constructor Test" << std::endl;
        }else
            std::cout << "Failed | Copy Constructor Test" << std::endl;
    }

    std::cout << "\r\n------Assignment Test------" << std::endl;
    T      testAssignment(5);
    testAssignment = (test3); //Assignment Constructor
    if(testAssignment.getChildren()[0]->getRootLabel()  == 3)
        std::cout << "Passed | Assignment Constructor Test " << std::endl;
    else
        std::cout << "Failed | Assignment Constructor Test " << std::endl;
    std::cout << "\r\n------Move Tests------" << std::endl;

    T testMove1(6);
    T testMove2(5);
    test2 = new T(5);
    testMove1.addChild(*test2);
    delete(test2);
    testMove2 = std::move(testMove1);
    if(testMove2.getChildren()[0]->getRootLabel() == 5 && testMove1.getChildren().size() == 0)
        std::cout << "Passed | Tree Assignment Test "<< std::endl;
    else
        std::cout << "Failed | Tree Assignment Test " << std::endl;
    testMove2 = std::move(testMove2); // Sanity check -> shouldn't trigger
    if(testMove2.getChildren()[0]->getRootLabel() == 5 )
        std::cout << "Passed | Tree Assignment Test (Sanity)" << std::endl;
    else
        std::cout << "Failed | Tree Assignment Test (Sanity) " <<std::endl;
    T testMove3(std::move(T(1337)));
    if(testMove3.getRootLabel() == 1337)
        std::cout << "Passed | Tree Assignment Constructor Test" << std::endl;
    else
        std::cout << "Failed | Tree Assignment Constructor Test" << std::endl;
    std::cout << "-----------------------\r\n\r\n\n" << std::endl;
}

int main(int argc, char** argv){
//    if(argc != 2){
//        cout << "usage cTrace <config_path>" << endl;
//        return 0;
//    }
//    Session sess(argv[1]);
//    sess.simulate();
runTest();
//
//    FiveRuleTestTree<MaxRankTree>();
//    FiveRuleTestTree<RootTree>();
    return 0;
}
