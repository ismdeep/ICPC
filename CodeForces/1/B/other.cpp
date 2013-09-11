#include <algorithm>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

string rxcy_to_excel(string numeration) {
    int row, column;
    bool exact = false;
    stringstream ss(numeration);

    ss.get();
    ss >> row;
    ss.get();
    ss >> column;

    ss.str(string());
    ss.clear();

    while (column > 0) {
        char c = 'A' + --column % 26;

        ss << c;

        if (column < 26) break;

        column /= 26;
    }

    string col = ss.str();
    reverse(col.begin(), col.end());

    ss.str(string());
    ss.clear();

    ss << col;
    ss << row;

    return ss.str();
}

string excel_to_rxcy(string numeration) {
    int i, row = 0, column;
    locale loc;
    stringstream ans;

    for (i = 0; !isdigit(numeration.at(i), loc); i++) {
        row *= 26;
        row += numeration.at(i) - 'A' + 1;
    }

    ans << "R" << numeration.substr(i) << "C" << row;

    return ans.str();
}

int main(int argc, char ** argv) {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        if (line.at(0) == 'R' and line.at(1) < 'A' and line.find('C') != string::npos) {
            cout << rxcy_to_excel(line) << endl;
        } else {
            cout << excel_to_rxcy(line) << endl;
        }
    }

    return 0;
}


