//Input
//call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
//call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
//call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
//call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
//#
//?check_phone_number
//?number_calls_from 0912345678
//?number_total_calls
//?count_time_calls_from 0912345678
//?count_time_calls_from 0132465789
//#
//
//Output
//1
//2
//4
//398
//120
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Call {
    string from_number;
    string to_number;
    string date;
    string start_time;
    string end_time;
};

Call parseCall(const string& line) {
    stringstream ss(line);
    Call call;
    string a;
    ss >> a >> call.from_number >> call.to_number >> call.date >> call.start_time >> call.end_time;
    return call;
}

int timeToSeconds(const string& timeStr) {
    istringstream ss(timeStr);
    int hours, minutes, seconds;
    char colon;
    ss >> hours >> colon >> minutes >> colon >> seconds;
    return hours * 3600 + minutes * 60 + seconds;
}

bool checkPhoneNumber(const string& phoneNumber) {
    if (phoneNumber.size() != 10) {
        return false;
    }
    return phoneNumber.find_first_not_of("0123456789") == string::npos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<Call> calls;
    unordered_map<string, int> callsFromNumber;
    int a =1;
    // Read telco data
    string line;
    while (getline(cin, line) && line != "#") {
        Call call = parseCall(line);
        if (!checkPhoneNumber(call.from_number) || !checkPhoneNumber(call.to_number)) {
            a=0;
            continue;
        }
        calls.push_back(call);
        callsFromNumber[call.from_number]++;
    }

    // Perform queries
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        string queryType, phoneNumber;
        ss >> queryType >> phoneNumber;

        if (queryType == "?check_phone_number") {
            cout << a << endl;
        } else if (queryType == "?number_calls_from") {
            cout << callsFromNumber[phoneNumber] << endl;
        } else if (queryType == "?number_total_calls") {
            cout << calls.size() << endl;
        } else if (queryType == "?count_time_calls_from") {
            int totalDuration = 0;
            for (const auto& call : calls) {
                if (call.from_number == phoneNumber) {
                    totalDuration += timeToSeconds(call.end_time) - timeToSeconds(call.start_time);
                }
            }
            cout << totalDuration << endl;
        } else {
            cerr << "Invalid query type." << endl;
        }
    }

    return 0;
}
