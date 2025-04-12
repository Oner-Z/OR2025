#include <bits/stdc++.h>
using namespace std;

const int max_num = 20;
const int max_charge = 33;
const int max_power = 3;
const int min_charge = max_charge * 0.1;
const int dt = 15;
const float high = 0.8135;
const float low = 0.351;
const float normal = 0.4883;

vector<string> read(void){
    ifstream fs;
    fs.open("T7.csv",ios::in);
    if(!fs.is_open()){
        cout << "未找到文件" << endl;
        return {};
    }
    vector<string> data;
    string temp;
    while (getline(fs,temp)){
        data.push_back(temp);
    }
    vector<string> row;
    for(auto it = data.begin() + 1; it != data.end(); it++){
        istringstream istr(*it);
        string str;
        
        while (getline(istr,str,',')){
            if(!str.empty()){
                row.push_back(str);
            }
        }
    }
    return row;
}
int timediff(int h1, int m1, int h2, int m2){
    int t1 = (23 - h1) * 60 + (60 - m1);
    int t2 = h2 * 60 + m2;
    return (t1 + t2) / 15; 
}

struct car{
    int time;
    double initial_charge;
    double distance;
}car[105];

int main(){
    vector<string> data = read();
    if(!data.empty()){ 
        int j = 1;
        for(int i = 0;i < 600;i++){
                int h1, m1, h2, m2;
                h1 = atoi(data[i].c_str());
                m1 = atoi(data[i + 1].c_str());
                h2 = atoi(data[i + 2].c_str());
                m2 = atoi(data[i + 3].c_str());
                cout << h1 << " " << m1 << " " << h2 << " " << m2 << endl;
                car[j].time = timediff(h1,m1,h2,m2);
                car[j].initial_charge = atof(data[i + 4].c_str());
                car[j].distance = atof(data[i + 5].c_str());
                cout << car[j].initial_charge << " " << car[j].distance << endl;
                i += 5;
                j++;
        }
    }
    return 0;
}