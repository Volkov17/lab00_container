#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


struct Entity
{
    string Query;
    float Frequency;
};

using Dict = multimap<string, Entity>;

multimap<string, Entity> load(const string & filename){
        ifstream fin;
        fin.open(filename);
        if (!fin.is_open())
            cerr << "This file does not exist" << endl;
        else {
            fin.close();
            fin.open(filename);
            Dict objForTrans;
            string str1 {};
            string str2 {};
            double fl (0.0);
            Entity en;
            while(fin >> str1 >> str2 >> fl) {
                en.Query = str2;
                en.Frequency = fl;
                objForTrans.emplace(str1, en);
                cout << str1 << " " << en.Query << " " << en.Frequency << endl;
            }
            fin.close();
            cout<<endl;
            return objForTrans;

        }
}

vector<Entity> suggest(const Dict& cont, const string& current_word) {
    vector<Entity> vt;
    auto it = cont.find (current_word);
    int a = cont.count (current_word);
    for ( unsigned int i = 0 ; i < a ; ++i){
        Entity test;
        test.Query = it->second.Query;
        test.Frequency = it->second.Frequency;
        vt.push_back(test);
        it++;
    }
    sort( vt.begin(), vt.end() , [](const Entity &s1, const Entity &s2){
        return s1.Frequency  < s2.Frequency;
    });
    return vt;
}


int main()
{
    string word;
    //multimap<string, Entity> dict;
    cout << "enter your word: добрый ,спокойной ,спокойного" << endl;
    cin >> word ;
    string name = "dict.txt";
    auto dict = load(name);
    auto result = suggest(dict, word);
    cout<<" result == " ;
    for ( auto it=result.begin() ; it != result.end() ; ++it){
        cout<<"{' " << it->Query <<" '," <<it->Frequency << " },  ";
    }


}
