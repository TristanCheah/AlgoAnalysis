#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

struct Hospital{
    int remainingSlots;
    char id;
    std::vector<int> prefList;
    std::vector<int> notProposedTo;
};
struct Student{
    bool engaged;
    int id;
    std::vector<char> prefList;
    char assignedTo;
};
int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cout << "Usage: ./algoq1.out input-text-file" << std::endl;
        return 0;
    }
    std::ifstream ifs {argv[1]};
    if (!ifs) { // file opened? NO - then abort program
        std::cerr << "Cannot open input file \"" << argv[1] << "\"" << std::endl;
        return 0;
    }

    std::cout << ifs.rdbuf() << "\n";

    //Question 1a

    //THIS WILL BE DONE BY TEXT INPUT
    Hospital C;
    C.id = 'C';
    C.prefList.push_back(5);
    C.prefList.push_back(1);
    C.prefList.push_back(2);
    C.prefList.push_back(4);
    C.prefList.push_back(3);

    C.notProposedTo = C.prefList;

    C.remainingSlots = 2;

    Hospital M;
    M.id = 'M';
    M.prefList.push_back(5);
    M.prefList.push_back(3);
    M.prefList.push_back(1);
    M.prefList.push_back(2);
    M.prefList.push_back(4);

    C.notProposedTo = M.prefList;
    M.remainingSlots = 2;

    std::vector<Hospital> hVector;

    hVector.push_back(M);
    hVector.push_back(C);
    //THIS WILL BE DONE BY TEXT INPUT
    std::vector<Hospital>::iterator it = hVector.begin();
//HOSPITALS ARE MEN
    while(hVector.size() > 0){
        std::cout << it->id << " Remaining Slots: " << it->remainingSlots << "\n";
        
        it->remainingSlots--;
        if (it->remainingSlots == 0){
            hVector.erase(it);
            it = hVector.begin();
        }
    }
    
    


    return 0;
}