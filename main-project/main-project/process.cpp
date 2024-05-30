#include "processing.h"
#include <vector>
#include <string>
using namespace std;
string process(vector<Talk*>& array) {
    double max_duration = 0.0;
    int max_index = -1;

    for (size_t i = 0; i < array.size(); ++i) {
        const Talk* talk = array[i];
        double duration = (talk->end_h - talk->start_h) + (talk->end_m - talk->start_m) / 60.0;
        if (duration > max_duration) {
            max_duration = duration;
            max_index = static_cast<int>(i);
        }
    }

    if (max_index != -1) {
        Talk* longest_talk = array[max_index];
        int longest_hours = longest_talk->end_h - longest_talk->start_h;
        int longest_minutes = longest_talk->end_m - longest_talk->start_m;

        return to_string(longest_hours) + ":" + to_string(longest_minutes);
    }
    else {
        return "Нет данных о докладах.";
    }
}
