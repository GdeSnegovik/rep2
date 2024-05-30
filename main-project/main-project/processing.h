//processing.h
#pragma once
#include <vector>
#include <string>
using namespace std;
struct Talk {
    int start_h;
    int start_m;
    int end_h;
    int end_m;
    char last_name[30];
    char first_name[30];
    char middle_name[30];
    char theme[30];
};
string process(vector<Talk*>& array);