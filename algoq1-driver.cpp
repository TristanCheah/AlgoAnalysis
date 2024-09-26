#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

struct Hospital {
    int remainingSlots;
    char id;
    std::vector<int> prefList;
    
};
struct Student {
    bool engaged;
    int id;
    std::vector<char> prefList;
    std::vector<char> notProposedTo;
    char assignedTo;
};
int main(int argc, char* argv[]) {
    //if (argc < 2) {
    //    std::cout << "Usage: ./algoq1.out input-text-file" << std::endl;
    //    return 0;
    //}
    //std::ifstream ifs{ argv[1] };
    //if (!ifs) { // file opened? NO - then abort program
    //    std::cerr << "Cannot open input file \"" << argv[1] << "\"" << std::endl;
    //    return 0;
    //}

    //std::cout << ifs.rdbuf() << "\n";

    //Question 1a

    //THIS WILL BE DONE BY TEXT INPUT
    Hospital C;
    C.id = 'C';
    C.prefList.push_back(5);
    C.prefList.push_back(1);
    C.prefList.push_back(2);
    C.prefList.push_back(4);
    C.prefList.push_back(3);

   

    C.remainingSlots = 2;

    Hospital M;
    M.id = 'M';
    M.prefList.push_back(5);
    M.prefList.push_back(3);
    M.prefList.push_back(1);
    M.prefList.push_back(2);
    M.prefList.push_back(4);

    M.remainingSlots = 2;

    std::vector<Hospital> hVector;

    hVector.push_back(M);
    hVector.push_back(C);

    std::vector<Student> sVector;
    for (int i = 1; i < 6; i++) {
        Student s;
        s.id = i;
        s.engaged = false;
        if (i < 4) {
            s.prefList.push_back('C');
            s.prefList.push_back('M');
        }
        else {
            s.prefList.push_back('M');
            s.prefList.push_back('C');
        }
        s.notProposedTo = s.prefList;
        sVector.push_back(s);
    }

    //THIS WILL BE DONE BY TEXT INPUT
    std::vector<Student>::iterator currentStudent = sVector.begin();

    //HOSPITALS ARE MEN
    while (true) {
        if (currentStudent->engaged == false && currentStudent->notProposedTo.size() > 0) {
            for (int i = 0; i < currentStudent->notProposedTo.size(); i++) {
                char id = currentStudent->notProposedTo[i];
                std::vector<Hospital>::iterator hospital = std::find_if(hVector.begin(), hVector.end(), [id](Hospital h) {
                    return h.id == id;
                    });
                std::vector<Student>::iterator student = std::find_if(sVector.begin(), sVector.end(),
                    [currentStudent](Student s) {
                    return s.id ==  currentStudent->id;
                    });

                if (hospital->remainingSlots > 0) {
                    student->engaged = true;
                    student->assignedTo = id;
                    hospital->remainingSlots--;
                    currentStudent->notProposedTo.erase(currentStudent->notProposedTo.begin() + i);
                    break;
                }
                else {
                    //currently engaged
                    //check if the hospital prefers this student
                    //Find position of all currently engaged students
    
                    int myIndex = -1;
                    if (student != sVector.end()) {
                        //find same id 
                        myIndex = student - sVector.begin();
                    }
                    for (const Student& compareStudent : sVector) {
                        if (compareStudent.assignedTo == hospital->id) {
                            //find position and compare
                            auto it = find_if(sVector.begin(), sVector.end(), [compareStudent](const Student& s) {
                                return s.id == compareStudent.id;
                                });
                            if (it != sVector.end())
                            {
                                // calculating the index 
                                // of K 
                                int index = it - sVector.begin();
                                if (myIndex < index) {
                                    break;
                                }

                            }
                        }
                    }
                }
            }

        }

        std::vector<Student>::iterator freeStudent = std::find_if(sVector.begin(), sVector.end(), [](Student s) {
            return s.engaged == false && s.notProposedTo.size() > 0;
            });
        if (freeStudent != sVector.end()) {
            currentStudent = freeStudent;
        }
        else {
            break;
        }
    }
    return 0;
}