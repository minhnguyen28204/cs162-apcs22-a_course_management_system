#include <string>
#include <fstream>
using namespace std;

bool ChangeUserPass(int ID, string curpass, string newpass){
    ifstream ifs("Data/data.dat");
    bool is_changed = false;
    int cnt = 0;
    string* arrpass;
    arrpass = new string[10005];
    int* arrid;
    arrid = new int[10005];
    int id;
    string temp;
    while (ifs >> id >> temp){
        arrid[cnt] = id;
        arrpass[cnt] = temp;
        if (id==ID && temp==curpass){
            is_changed = true;
            arrpass[cnt] = newpass;
        }
        cnt++;
    }
    ifs.close();
    ofstream ofs("Data/data.dat");
    for(int i=0; i<cnt; i++){
        ofs << arrid[i] << ' ' << arrpass[i] << '\n';
    }
    ofs.close();
    delete[] arrid;
    delete[] arrpass;
    return is_changed;
}
