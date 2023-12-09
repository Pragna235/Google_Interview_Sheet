#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMinDistance' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY center
 *  2. INTEGER_ARRAY destination
 */

long getMinDistance(vector<int> center, vector<int> destination) {
    long n = center.size();
    sort(center.begin(),center.end());
    sort(destination.begin(),destination.end());
    
    long sum = 0;
    for(long i=0;i<n;i++){
        sum += abs(center[i]-destination[i]);
    }
    return sum;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string center_count_temp;
    getline(cin, center_count_temp);

    int center_count = stoi(ltrim(rtrim(center_count_temp)));

    vector<int> center(center_count);

    for (int i = 0; i < center_count; i++) {
        string center_item_temp;
        getline(cin, center_item_temp);

        int center_item = stoi(ltrim(rtrim(center_item_temp)));

        center[i] = center_item;
    }

    string destination_count_temp;
    getline(cin, destination_count_temp);

    int destination_count = stoi(ltrim(rtrim(destination_count_temp)));

    vector<int> destination(destination_count);

    for (int i = 0; i < destination_count; i++) {
        string destination_item_temp;
        getline(cin, destination_item_temp);

        int destination_item = stoi(ltrim(rtrim(destination_item_temp)));

        destination[i] = destination_item;
    }

    long result = getMinDistance(center, destination);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
