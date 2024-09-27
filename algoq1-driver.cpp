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

    std::reverse(C.prefList.begin(), C.prefList.end());

    C.remainingSlots = 2;

    Hospital M;
    M.id = 'M';
    M.prefList.push_back(5);
    M.prefList.push_back(3);
    M.prefList.push_back(1);
    M.prefList.push_back(2);
    M.prefList.push_back(4);

    std::reverse(M.prefList.begin(), M.prefList.end());

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
            bool replacedSomeone = false;
            for (int i = 0; i < currentStudent->notProposedTo.size(); i++) {
                if (replacedSomeone == true) {
                    break;
                }
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
                    auto it3 = find_if(hospital->prefList.begin(), hospital->prefList.end(), [currentStudent](char hospPrefChar) {
                        return hospPrefChar == currentStudent->id;
                        });
                    if (it3 != hospital->prefList.end()) {
                        //find same id 
                        myIndex = it3 - hospital->prefList.begin();
                    }
                    for (Student& compareStudent : sVector) {
                        if (compareStudent.assignedTo == hospital->id) {
                            //find position and compare
                            auto it = find_if(hospital->prefList.begin(), hospital->prefList.end(),
                                [compareStudent](char s) {
                                return s == compareStudent.id;
                                });
                            if (it != hospital->prefList.end())
                            {
                                // calculating the index 
                                // of K 
                                int index = it - hospital->prefList.begin();
                                if (myIndex > index) {
                                    //higher priority
                                    compareStudent.engaged = false;
                                    compareStudent.assignedTo = ' ';
                                    student->engaged = true;
                                    student->assignedTo = hospital->id;
                                    currentStudent->notProposedTo.erase(currentStudent->notProposedTo.begin() + i);
                                    replacedSomeone = true;
                                    break;
                                }
                            }
                        }
                        
                    }
                    if (replacedSomeone == false) {
                        currentStudent->notProposedTo.erase(currentStudent->notProposedTo.begin() + i);
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
    for (Student s : sVector) {
        std::cout << "{ " << s.id << ", " << s.assignedTo << " }\n";
    }

    return 0;
}