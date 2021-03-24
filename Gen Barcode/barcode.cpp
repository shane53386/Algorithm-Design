#include <iostream>
#include <vector>

using namespace std;

void generate(string &s, int n, int start) {
    if (n == 0){
        cout << s << "\n";
    } else {
        for (int i = start; i < s.size()-n+1; i++) {
            string tmp = s;
            tmp.replace(i,1,"1");
            generate(tmp, n-1, i+1);
        }
    }
}

int main() {
    int A,B;
    cin >> A >> B;
    string s = "";
    for (int i = 0; i < B; i++){
        s += "0";
    }
    generate(s,A,0);
    return 0;
}