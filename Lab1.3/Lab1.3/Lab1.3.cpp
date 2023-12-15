#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b;
    cout << "Enter the coordinates of the school (a, b): ";
    cin >> a >> b;
    int n;
    cout << "Enter the number of houses (n): ";
    cin >> n;
    double SumaD = 0.0;
    for (int i = 0; i < n; i++) {
        double x, y;
        cout << "Enter the coordinates of the house " << i + 1 << " (x, y): ";
        cin >> x >> y;
        double distance = sqrt((x - a) * (x - a) + (y - b) * (y - b));
        SumaD += distance;
    }
    double averageD = SumaD / n;
    cout << "Average distance from houses to school: " << averageD << endl;

    return 0;
}