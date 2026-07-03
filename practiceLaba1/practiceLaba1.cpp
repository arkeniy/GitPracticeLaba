#include <iostream>
#include <vector>
using namespace std;

int main() {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    cerr << "enter number count: ";
    size_t number_count;
    cin >> number_count;

    if (number_count == 0) {
        return 0;
    }

    vector<double> numbers(number_count);
    cerr << "enter numbers: ";
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    cerr << "enter bin count: ";
    size_t bin_count;
    cin >> bin_count;

    if (bin_count == 0) {
        return 0;
    }

    double min, max;
    min = max = numbers[0];

    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }

    double bin_size = (max - min) / static_cast<double>(bin_count);

    vector<size_t> bins(bin_count);
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; j < bin_count - 1 && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }

    size_t max_count = bins[0];
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }

    vector<size_t> heights(bin_count);
    for (size_t i = 0; i < bin_count; i++) {
        if (max_count > MAX_ASTERISK) {
            heights[i] = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
        }
        else {
            heights[i] = bins[i];
        }
    }

    for (size_t i = 0; i < bin_count; i++) {
        cout << " ";

        if (bins[i] < 100) {
            cout << " ";
        }
        if (bins[i] < 10) {
            cout << " ";
        }
        cout << bins[i] << "|";

        size_t current_h = heights[i];

        for (size_t j = 0; j < current_h; j++) {
            char symbol = '*';

            bool prev_lower = false;
            bool next_lower = false;

            if (i > 0) {
                if ((heights[i - 1] < current_h) && (j == heights[i - 1])) {
                    prev_lower = true;
                }
            }


            if (i < bin_count - 1) {
                if ((heights[i + 1] < current_h) && (j == heights[i + 1])) {
                    next_lower = true;
                }
            }

            if (prev_lower && next_lower && (heights[i - 1] == heights[i + 1])) {
                symbol = 'N';
            }
            else if (prev_lower) {
                symbol = '^';
            }
            else if (next_lower) {
                symbol = 'v';
            }

            cout << symbol;
        }
        cout << endl;
    }

    return 0;
}