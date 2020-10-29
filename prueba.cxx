#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int main(){
    string prueba = "datos bog hoy ya";
    vector<string> datos1;
    cout << datos1.size() << endl;
    vector<string> datos = split(prueba, " ");

    for(int i = 0; i<datos.size(); i++){
        cout << datos.at(i)<<endl;

    }
    for(int i = 0; i<prueba.size(); i++){
        cout << prueba[i] << endl;
    }
    cout<<prueba[0]+";"+prueba[1]<<endl;

}