
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <cstring>

using namespace std;
const unsigned int MAX_CAPACITY = 2;



struct Student
{
    string name;
    string groupId;
    float srZn;
    map<string, int> ratings;
};

//void sort_name(vector<Student> &st){
//    //vector <string> mas ;
//    for ( auto it=st.begin();it != st.end() ; ++it){
//        if (strcmp(it->name.c_str(), ((it+1)->name).c_str())>0 && (it+1)!=st.end()){
//            swap(*it,*(it+1));
//        }

//    }
    //for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
    //    cout << it1->name << " " << it1->groupId << endl;
    //    for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
   //         cout << it->first << " - " << it->second << endl;
   //     }
  //  }
  //  for (unsigned  int i=0 ; i< MAX_CAPACITY; i++){
  //      if (strcmp(st[i].name.c_str(), st[i+1].name.c_str())>0){
  //          swap(st[i], st[i+1]);
  //      }
  //  }
//}

void good_mark(vector<Student> &st){
    int m = 0;
    bool test;
    for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
        test=true;
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            if( it->second < 5 ){
                test=false;
                break;
            }
        }
        if (test==true) {
            m++;
        }
    }
    cout << "count of people who is having only exellent mark = " << m <<endl;

}

void bad_mark(vector<Student> &st){
    int k=0;
    for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            if (it->second == 2) {
                k++;
                break;
            } else {
                continue;
            }
        }
    }
    cout << "count of people who is having a bad mark = " << k <<endl;
}

//void sort_average(vector<Student> &st) {
//    for ( auto it=st.begin();it != st.end() ; ++it){
//        if ((it->srZn > (it+1)->srZn) && (it+1)!=st.end()){
//            swap(*it,*(it+1));
//        }

   // for (unsigned  int i=0 ; i< MAX_CAPACITY; i++){
   //     if ( st[i].srZn > st[i+1].srZn ) {
   //         swap(st[i] , st[i+1]);
  //      }
 //   }
//}

void exellent_math (vector<Student> &st) {
    vector<Student> exlents;
    for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            if (it->first == "math" && it->second == 5) {
                exlents.push_back(*it1);
            }
        }
    }
    for (auto it1 = exlents.begin(); it1 != exlents.end(); ++it1) {
        cout << it1->name << " " << it1->groupId << endl;
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            cout << it->first << " - " << it->second << endl;
        }
    }
}

void good_polit(vector <Student> &st){
    for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            if (it->first == "polit"  ||  it->first == "politologia") {
                it->second = 4;
            }
        }
    }
    for (auto it1 = st.begin(); it1 != st.end(); ++it1) {
        cout << it1->name << " " << it1->groupId << endl;
        for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
            cout << it->first << " - " << it->second << endl;
        }
    }
}

void Menu()
{
    cout << "1. print :" << endl;
    cout << "2. sort by name " << endl;
    cout << "3. sort by average mark" << endl;
    cout << "4. count of people who is having a bad mark" << endl;
    cout << "5. count of people who is having only exellent"<< endl;
    cout << "6. 5 in math and print "<< endl;
    cout << "7. good for polit "<< endl;
}


int main() {
    vector<Student> students;
    Student *student;
    int menu = 0;
    //int *mas = new int[7];
    string n, str;
    int ch = 0;
    for (unsigned int i = 0; i < MAX_CAPACITY; ++i) {
        student = new Student();
        cin >> student->name;
        cin >> student->groupId;
        int proverka = 0 ;
        int j = 0;
        // student->srZn=0;
        do {
            cin >> str;
            if (str != "end") {
                cin >> ch;
                proverka += ch;
                j++;
                student->ratings.insert(pair<string, int>(str, ch));
            }
        } while (str != "end");
        float sr=0;
        sr = (float) proverka / j;
        //student.ratings[n]=ch;
        student->srZn = sr;
        students.push_back(*student);
        cout << "information about " << i + 1 << " student is filled " << endl<;
        //cout << student ->srZn;
    }
    while (true) {
        Menu();
        cin >> menu;
        switch (menu) {
            case 1:
                for (auto it1 = students.begin(); it1 != students.end(); ++it1) {
                    cout << it1->name << " " << it1->groupId << endl;
                    for (auto it = it1->ratings.begin(); it != it1->ratings.end(); ++it) {
                        cout << it->first << " - " << it->second << endl;
                    }
                }
                break;
            case 2:
                sort(students.begin(), students.end(), [](const Student &s1, const Student &s2){
                    return s1.name < s2.name;
                });
                //sort_name(students);
                break;
            case 3:
                sort(students.begin(), students.end(), [](const Student &s1, const Student &s2){
                    return s1.srZn > s2.srZn;
                });
                //sort_average(students);
                break;
            case 4:
                bad_mark(students);
                break;
            case 5:
                good_mark(students);
                break;
            case 6:
                exellent_math(students);
                break;
            case 7 :
                good_polit(students);
                break;
            default:
                cout << "error command" << endl;
        }
    }
    return 0;
}
