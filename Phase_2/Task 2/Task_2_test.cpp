#include "Task_2.cpp"

using namespace std;


int main(int argc, char** argv){
    if (argc < 2){
        cout << "Usage 1: ./Task_2_test <lower bound> <upper bound>\n"
            << "Example: ./Task_2_test 0 20 => run testcases from test_0.txt to test_20.txt\n"
            << "Usage 2: ./Task_2_test <index>\n"
            << "Example: ./Task_2_test 20 => run testcase stored in test_20.txt only\n";
        exit(1);
    }
    
    ofstream output("result_2_2.txt");

    if (argc == 2){
        ifstream input(string("test_") + argv[1] + ".txt");

        if (!input.good()){
            cout << "[-] File test_" << argv[1] << ".txt does not exist.\n";
            input.close();
            exit(1);
        }

        BusParking BP;

        output << "test_" << argv[1] << ": \n";
        int cnt = 0;
        int start, end;
        string opt;

        for (string line; getline(input,line);){
            stringstream ss(line);
            ss >> opt;

            if (opt == "[+]"){
                ss >> start >> end;
                BP.add(start,end);
            }
            else if (opt == "[-]"){
                ss >> start >> end;
                BP.remove(start,end);
            }
            else{
                cnt++;
                output << BP.minPark() << ' ';

                if (cnt % 50 == 0){
                    output << '\n';
                }
            }
        }       

        output << '\n';
        input.close();
    }
    else{
        int lower = stoi(argv[1]);
        int upper = stoi(argv[2]);

        for (int i = lower; i <= upper; i++){
            ifstream input("test_" + to_string(i) + ".txt");
            BusParking BP;

            if (!input.good()){
                cout << "[-] File test_" << i << ".txt does not exist.\n";
                input.close();
                exit(1);
            }

            output << "test_" << i << ": \n";
            int cnt = 0;
            int start, end;
            string opt;

            for (string line; getline(input,line);){
                stringstream ss(line);
                ss >> opt;

                if (opt == "[+]"){
                    ss >> start >> end;
                    BP.add(start,end);
                }
                else if (opt == "[-]"){
                    ss >> start >> end;
                    BP.remove(start,end);
                }
                else{
                    cnt++;
                    output << BP.minPark() << ' ';

                    if (cnt % 50 == 0){
                        output << '\n';
                    }
                }
            }

            output << '\n';
            input.close();
        }
    }

    output.close();
}