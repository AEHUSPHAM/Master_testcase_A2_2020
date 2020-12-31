#include <fstream>
#include <string>
#include <sstream>
#include "Task_1.cpp"

using namespace std;

int main(int argc, char** argv){
    if (argc < 3){
        cout << "Usage: ./Task_1_test <lower bound> <upper bound>\n"
            << "Example: ./Task_1_test 0 20 => run testcases from test_0.txt to test_20.txt\n";
        exit(1);
    }
    
    int lower = stoi(argv[1]);
    int upper = stoi(argv[2]);
    ofstream output("result.txt");

    for (int i = lower; i <= upper; i++){
        ifstream input("test_" + to_string(i) + ".txt");
        
        if (!input.good()){
            cout << "[-] File test_" << i << ".txt does not exist.\n";
            input.close();
            exit(1);
        }

        int start, end;
        vector<Interval> lInterval;

        for (string line; getline(input,line);){
            stringstream ss(line);
            ss >> start >> end;
            lInterval.push_back(Interval(start,end));
        }

        output << "test_" << i << ": " << minPark(lInterval) << '\n';
        input.close();
    }

    output.close();
}