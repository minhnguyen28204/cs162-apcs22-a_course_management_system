#include <string>
#include <fstream>
using namespace std;

bool ChangeUserPass(string ID, string curpass, string newpass){
    string temp = "Information/" + ID + ".dat";
    ifstream ifs(temp);
    if (!ifs.is_open()){
        return false;
    }
    bool is_changed = false;
    string cur, is_stu, fn, ln, ge, db, so;
    ifs >> cur;
    if (cur ==  curpass){
        ifs >> is_stu;
        ifs >> fn;
        ifs >> ln;
        ifs >> ge;
        ifs >> db;
        ifs >> so;
        is_changed = true;
    }
    ifs.close();
    if (is_changed){
        ofstream ofs(temp);
        ofs << newpass << '\n';
        ofs << is_stu << '\n';
        ofs << fn << '\n';
        ofs << ln << '\n';
        ofs << ge << '\n';
        ofs << db << '\n';
        ofs << so << '\n';
        ofs.close();
    }
    return is_changed;
}
