#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

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


void question1a() {
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
                        return s.id == currentStudent->id;
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
}
struct Worksite {
    int remainingSlots;
    int id;
    std::vector<int> prefList;

};
struct Staff {
    bool engaged;
    int id;
    int salary;
    std::vector<std::pair<int,int>> distanceFromWorksites;
    std::vector<int> prefList;
    std::vector<int> notProposedTo;
    int assignedTo;
};
void question1b() {

  //Question 1b
    std::vector<Staff> sVector;
    for (int i = 1; i < 9; i++) {
        Staff s;
        s.id = i;
        s.engaged = false;      
        s.notProposedTo.push_back(1);
        s.notProposedTo.push_back(2);
        s.notProposedTo.push_back(3);
        s.notProposedTo.push_back(4);
        s.notProposedTo.push_back(5);
        sVector.push_back(s);
    }

    //pair is distance/worksite id
    sVector[0].salary = 1000;
    sVector[0].distanceFromWorksites.push_back(std::pair<int,int>(5, 1));
    sVector[0].distanceFromWorksites.push_back(std::pair<int, int>(3, 2));
    sVector[0].distanceFromWorksites.push_back(std::pair<int, int>(6, 3));
    sVector[0].distanceFromWorksites.push_back(std::pair<int, int>(4, 4));

    sVector[1].salary = 1200;
    sVector[1].distanceFromWorksites.push_back(std::pair<int, int>(4, 1));
    sVector[1].distanceFromWorksites.push_back(std::pair<int, int>(3, 2));
    sVector[1].distanceFromWorksites.push_back(std::pair<int, int>(6, 3));
    sVector[1].distanceFromWorksites.push_back(std::pair<int, int>(5, 3));

    sVector[2].salary = 1300;
    sVector[2].distanceFromWorksites.push_back(std::pair<int, int>(2, 1));
    sVector[2].distanceFromWorksites.push_back(std::pair<int, int>(5, 2));
    sVector[2].distanceFromWorksites.push_back(std::pair<int, int>(3, 3));
    sVector[2].distanceFromWorksites.push_back(std::pair<int, int>(4, 4));

    sVector[3].salary = 900;
    sVector[3].distanceFromWorksites.push_back(std::pair<int, int>(10, 1));
    sVector[3].distanceFromWorksites.push_back(std::pair<int, int>(9, 2));
    sVector[3].distanceFromWorksites.push_back(std::pair<int, int>(8, 3));
    sVector[3].distanceFromWorksites.push_back(std::pair<int, int>(7, 4));

    sVector[4].salary = 800;
    sVector[4].distanceFromWorksites.push_back(std::pair<int, int>(15, 1));
    sVector[4].distanceFromWorksites.push_back(std::pair<int, int>(2, 2));
    sVector[4].distanceFromWorksites.push_back(std::pair<int, int>(1, 3));
    sVector[4].distanceFromWorksites.push_back(std::pair<int, int>(8, 4));

    sVector[5].salary = 1000;
    sVector[5].distanceFromWorksites.push_back(std::pair<int, int>(8, 1));
    sVector[5].distanceFromWorksites.push_back(std::pair<int, int>(11, 2));
    sVector[5].distanceFromWorksites.push_back(std::pair<int, int>(6, 3));
    sVector[5].distanceFromWorksites.push_back(std::pair<int, int>(4, 4));

    sVector[6].salary = 2000;
    sVector[6].distanceFromWorksites.push_back(std::pair<int, int>(10, 1));
    sVector[6].distanceFromWorksites.push_back(std::pair<int, int>(5, 2));
    sVector[6].distanceFromWorksites.push_back(std::pair<int, int>(7, 3));
    sVector[6].distanceFromWorksites.push_back(std::pair<int, int>(13, 4));

    sVector[7].salary = 1500;
    sVector[7].distanceFromWorksites.push_back(std::pair<int, int>(3, 1));
    sVector[7].distanceFromWorksites.push_back(std::pair<int, int>(2, 2));
    sVector[7].distanceFromWorksites.push_back(std::pair<int, int>(1, 3));
    sVector[7].distanceFromWorksites.push_back(std::pair<int, int>(7, 4));

    std::sort(sVector.begin(), sVector.end(), [](Staff first,
        Staff second) {
            return first.salary > second.salary;
        });
    for (Staff& s : sVector) {
        std::sort(s.distanceFromWorksites.begin(), s.distanceFromWorksites.end(), [](std::pair<int,int> first, 
            std::pair<int, int> second) {
                return first.first > second.first;
            });
    }


  //THIS WILL BE DONE BY TEXT INPUT
    std::vector<Worksite> wVector;
    for (int i = 0; i < 5; i++) {
        Worksite ws;
        ws.id = i + 1;
        //construct preference list
        for (Staff s : sVector) {
            ws.prefList.push_back(s.id);
        }
        ws.remainingSlots = 2;
        wVector.push_back(ws);
    }
    //THIS WILL BE DONE BY TEXT INPUT
    std::vector<Staff>::iterator currentStaff = sVector.begin();

    //HOSPITALS ARE MEN
    while (true) {
        if (currentStaff->engaged == false && currentStaff->notProposedTo.size() > 0) {
            bool replacedSomeone = false;
            for (int i = 0; i < currentStaff->notProposedTo.size(); i++) {
                if (replacedSomeone == true) {
                    break;
                }
                int id = currentStaff->notProposedTo[i];
                std::vector<Worksite>::iterator worksite = std::find_if(wVector.begin(), wVector.end(), [id](Worksite h) {
                    return h.id == id;
                    });
                std::vector<Staff>::iterator student = std::find_if(sVector.begin(), sVector.end(),
                    [currentStaff](Staff s) {
                        return s.id == currentStaff->id;
                    });

                if (worksite->remainingSlots > 0) {
                    student->engaged = true;
                    student->assignedTo = id;
                    worksite->remainingSlots--;
                    currentStaff->notProposedTo.erase(currentStaff->notProposedTo.begin() + i);
                    break;
                }
                else {
                    //currently engaged
                    //check if the hospital prefers this student
                    //Find position of all currently engaged students

                    int myIndex = -1;
                    auto it3 = find_if(worksite->prefList.begin(), worksite->prefList.end(), [currentStaff](int hospPrefChar) {
                        return hospPrefChar == currentStaff->id;
                        });
                    if (it3 != worksite->prefList.end()) {
                        //find same id 
                        myIndex = it3 - worksite->prefList.begin();
                    }
                    for (Staff& compareStudent : sVector) {
                        if (compareStudent.assignedTo == worksite->id) {
                            //find position and compare
                            auto it = find_if(worksite->prefList.begin(), worksite->prefList.end(),
                                [compareStudent](int s) {
                                    return s == compareStudent.id;
                                });
                            if (it != worksite->prefList.end())
                            {
                                // calculating the index 
                                // of K 
                                int index = it - worksite->prefList.begin();
                                if (myIndex > index) {
                                    //higher priority
                                    compareStudent.engaged = false;
                                    compareStudent.assignedTo = ' ';
                                    student->engaged = true;
                                    student->assignedTo = worksite->id;
                                    currentStaff->notProposedTo.erase(currentStaff->notProposedTo.begin() + i);
                                    replacedSomeone = true;
                                    break;
                                }
                            }
                        }

                    }
                    if (replacedSomeone == false) {
                        currentStaff->notProposedTo.erase(currentStaff->notProposedTo.begin() + i);
                    }
                }
            }
        }
        std::vector<Staff>::iterator freeStudent = std::find_if(sVector.begin(), sVector.end(), [](Staff s) {
            return s.engaged == false && s.notProposedTo.size() > 0;
            });
        if (freeStudent != sVector.end()) {
            currentStaff = freeStudent;
        }
        else {
            break;
        }
    }
    for (Staff s : sVector) {
        std::cout << "{ Staff ID: " << s.id << ", Assigned To: " <<  s.assignedTo << " }\n";
    }
}
int main(int argc, char* argv[]) {
   // question1a();
    question1b();
    return 0;
}