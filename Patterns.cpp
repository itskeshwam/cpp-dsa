#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min

using namespace std;

// 1. Square Star Pattern
void squareStarPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// 2. Right-Angled Star Pattern
void rightAngledStarPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// 3. Right-Angled Number Pattern
void rightAngledNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 4. Right-Angled Same Number Pattern
void rightAngledSameNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// 5. Inverted Right-Angled Star Pattern
void invertedRightAngledStarPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// 6. Inverted Right-Angled Number Pattern
void invertedRightAngledNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 7. Star Pyramid Pattern
void starPyramidPattern(int n) {
    for (int i = 0; i < n; i++) {
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// 8. Inverted Star Pyramid Pattern
void invertedStarPyramidPattern(int n) {
    for (int i = 0; i < n; i++) {
        // space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
            cout << "*";
        }
        // space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// 9. Diamond Star Pattern
void diamondStarPattern(int n) {
    // upper pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
    // lower inverted pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
            cout << "*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// 10. Half Diamond Star Pattern
void halfDiamondStarPattern(int n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n) stars = 2 * n - i;
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 11. Binary Number Triangle Pattern
void binaryNumberTrianglePattern(int n) {
    for (int i = 0; i < n; i++) {
        int start = (i % 2 == 0) ? 1 : 0;
        for (int j = 0; j <= i; j++) {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

// 12. Number Crown Pattern
void numberCrownPattern(int n) {
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++) {
        // numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        // space
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        // numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

// 13. Increasing Number Triangle Pattern
void increasingNumberTrianglePattern(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// 14. Increasing Letter Triangle Pattern
void increasingLetterTrianglePattern(int n) {
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 15. Inverted Letter Triangle Pattern
void invertedLetterTrianglePattern(int n) {
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 16. Same Letter Triangle Pattern
void sameLetterTrianglePattern(int n) {
    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 17. Alphabet Pyramid Pattern
void alphabetPyramidPattern(int n) {
    for (int i = 0; i < n; i++) {
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << ch;
            if (j <= breakpoint) ch++;
            else ch--;
        }
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// 18. Descending Letter Triangle Pattern
void descendingLetterTrianglePattern(int n) {
    // Assuming n=5 for 'E'
    for (int i = 0; i < n; i++) {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 19. Symmetric Void (Butterfly) Pattern
void symmetricVoidPattern(int n) {
    // Upper half
    int initialSpace = 0;
    for (int i = 0; i < n; i++) {
        // stars
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < initialSpace; j++) {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }
        initialSpace += 2;
        cout << endl;
    }
    // Lower half
    initialSpace = 2 * n - 2;
    for (int i = 1; i <= n; i++) {
        // stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < initialSpace; j++) {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        initialSpace -= 2;
        cout << endl;
    }
}

// 20. Symmetric Star (Butterfly) Pattern
void symmetricStarPattern(int n) {
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n) stars = 2 * n - i;
        // stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
        if (i < n) spaces -= 2;
        else spaces += 2;
    }
}

// 21. Hollow Square Pattern
void hollowSquarePattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// 22. Number Spiral Pattern
void numberSpiralPattern(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min({top, down, left, right}));
        }
        cout << endl;
    }
}


int main() {
    int n;
    cin >> n;

    // Uncomment the pattern function you want to run

    // squareStarPattern(n);
    // rightAngledStarPattern(n);
    // rightAngledNumberPattern(n);
    // rightAngledSameNumberPattern(n);
    // invertedRightAngledStarPattern(n);
    // invertedRightAngledNumberPattern(n);
    // starPyramidPattern(n);
    // invertedStarPyramidPattern(n);
    // diamondStarPattern(n);
    // halfDiamondStarPattern(n);
    // binaryNumberTrianglePattern(n);
    // numberCrownPattern(n);
    // increasingNumberTrianglePattern(n);
    // increasingLetterTrianglePattern(n);
    // invertedLetterTrianglePattern(n);
    // sameLetterTrianglePattern(n);
    // alphabetPyramidPattern(n);
    // descendingLetterTrianglePattern(n);
    // symmetricVoidPattern(n);
    // symmetricStarPattern(n);
    // hollowSquarePattern(n);
    // numberSpiralPattern(n);

    return 0;
}