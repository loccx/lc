#include <iostream>

using namespace std;

/* 1 1 1 0 0
 * 1 0 1 0 0
 * 0 0 1 1 0
 * 0 0 1 1 0
 * 0 1 1 0 0 */ 

void flood_fill(vector<vector<int>>& image, int x, int y, int col, int originalColor) {
    if (image[x][y] == originalColor) {
        image[x][y] = col;
        if (x < int(image.size()) - 1) flood_fill(image, x + 1, y, col, originalColor);
        if (y < int(image[0].size()) - 1) flood_fill(image, x, y + 1, col, originalColor);
        if (x > 0) flood_fill(image, x - 1, y, col, originalColor);
        if (y > 0) flood_fill(image, x, y - 1, col, originalColor);
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1, 0, 0, 1},
                                 {1, 0, 1, 0, 0, 1},
                                 {0, 0, 1, 1, 0, 1},
                                 {0, 0, 1, 1, 0, 1},
                                 {0, 1, 1, 0, 0, 0}};

    // outputs the current grid
    cout << "current grid:\n";
    for (auto col : image) {
        for (auto row : col) {
            cout << row << " ";
        }
        cout << '\n';
    }

    int x, y;
    do {
        cout << "input x and y: (input is 1-based)\n";
        cin >> x >> y;
        if (x < 1 || y < 1 || x > int(image[0].size()) || y > int(image.size())) {
            cout << "input must be greater than 0 and within bounds of the map: x <= " << image[0].size() << " and y <= " << image.size() << '\n';
        }
    } while (x < 1 || y < 1 || x > int(image[0].size()) || y > int(image.size()));

    int originalCol = image[y-1][x-1];

    // takes the user input for the current color
    int col;
    cout << "what color? (input number)\n";
    cin >> col;

    flood_fill(image, y-1, x-1, col, originalCol);

    // outputs the current grid
    cout << "current grid:\n";
    for (auto col : image) {
        for (auto row : col) {
            cout << row << " ";
        }
        cout << '\n';
    }

    return 0;
}
