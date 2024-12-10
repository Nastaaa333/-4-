#include <iostream>
#include <stdio.h>
using namespace std;

unsigned lengthStroki(char* Arr) {
    int length = 0;

    while (Arr[length]) {
        length++;
    }

    return length;
}


int deleteZnak(char* arr, char znak, char* newarr) {
    int count = 0;
    int index = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == znak) {
            count++;
            if (count <= 1) {
                newarr[index] = arr[i];
                index++;
            }
        }
        else {
            newarr[index] = arr[i];
            index++;
            count = 0;
        }
        newarr[index] = '\0';
    }

    return 1;
}

int deleteTochka(char* arr, char znak, char* newarr, int newlength) {
    int count = 0;
    int index = 0;
    for (int i = 0; i < newlength; i++) {
        if (arr[i] == znak) {
            count++;
            if (count <= 3) {
                newarr[index] = arr[i];
                index++;
            }
        }
        else {
            newarr[index] = arr[i];
            index++;
            count = 0;
        }
        newarr[index + 1] = '\0';
    }

    return 1;
}

int BookvaMal(char* arr, int newlength) {
    const int bookva = 32;

    if (arr[0] >= 97 and arr[0] <= 122)
        arr[0] -= bookva;

    for (int i = 1; i < newlength - 2; i++) {
        if (arr[i] == ' ' and arr[i - 1] == '.' and arr[i + 1] >= 97 and arr[i + 1] <= 122) {
            arr[i + 1] -= bookva;
        }

        if (arr[i] == ' ' and arr[i - 1] != '.' and arr[i + 1] >= 65 and arr[i + 1] <= 90) {
            arr[i + 1] += bookva;
        }

        if (arr[i] != ' ' and (arr[i - 2] != '.' and arr[i - 1] != '.') and arr[i] >= 65 and arr[i] <= 90)
            arr[i] += bookva;
    }
    return 1;
}
int Number(char* arr, char* newarr, int newlength) {
    int index = 0;
    for (int i = 0; i<newlength; i++) {
        if (arr[i] < 48 or arr[i]>57) {
            newarr[index] = arr[i];
            index++;
        }
        newarr[index + 1] = '\0';
    }

    return 1;
}

int Number2(char* arr, char* podstroka,char* newarr) {
    int length1 = lengthStroki(arr);
    int length2 = lengthStroki(podstroka);
    int count = 0;
    int index = 0;

    for (int i = 0; i <= length1 - length2; i++) {
        for (int j = 0; j < length2; j++) {
            if (arr[i + j] != podstroka[j]) {
                newarr[index] = arr[i + j];
                index++;
                break;
            }
        }
        newarr[index + 1] = '\0';
        
    }

    return 1;
}

int linearSearch(char* arr, char* podstroka) {
    int length1 = lengthStroki(arr);
    int length2 = lengthStroki(podstroka);
    int count = 0;

    for (int i = 0; i <= length1 - length2; i++) {
        int j;
        for (j = 0; j < length2; j++) {
            if (arr[i + j] != podstroka[j])
                break;
        }

        if (j == length2)
            count++;
    }

    return count;
}


int main() {
    int const length = 100;
    char stroka[length];
    char newstroka[length];
    int newlength;

    cout << "Enter the line: " << endl;
    cin.getline(stroka, length);
    cin.sync();


    char Znak1[length];
    deleteZnak(stroka, ' ', Znak1);

    char Znak2[length];
    deleteZnak(Znak1, ',', Znak2);

    char Znak3[length];
    deleteZnak(Znak2, '!', Znak3);

    char Znak4[length];
    deleteZnak(Znak3, '?', Znak4);

    char Znak5[length];
    deleteZnak(Znak4, '/', Znak5);

    char Znak6[length];
    deleteZnak(Znak5, ':', Znak6);

    char Znak7[length];
    deleteZnak(Znak6, ';', Znak7);

    char Znak8[length];
    deleteZnak(Znak7, '(', Znak8);

    char Znak9[length];
    deleteZnak(Znak8, ')', Znak9);

    char Znak10[length];
    deleteZnak(Znak9, '[', Znak10);

    char Znak11[length];
    deleteZnak(Znak10, ']', Znak11);

    char Znak12[length];
    deleteZnak(Znak11, '-', Znak12);

    char Znak13[length];
    deleteZnak(Znak12, '\"', Znak13);

    int newlength2 = lengthStroki(Znak5);
    deleteTochka(Znak5, '.', newstroka, newlength2);

    BookvaMal(newstroka, newlength2);


    cout << "Your line: " << endl << newstroka << endl;

    char newstroka2[length];
    Number(newstroka, newstroka2, newlength2);

    cout << "Your line: " << endl << newstroka2 << endl;

    cout << "Enter a set of letters or numbers: " << endl;
    char posled[length];
    cin.getline(posled, length);
    cin.sync();
    int posledlength = lengthStroki(posled);
    char newstroka3[length];

    Number2(newstroka, posled, newstroka3);
    cout << "Your line: " << endl << newstroka3 << endl;

    cout << "Linear Search: " << endl;
    char podstroka[length];
    cin.getline(podstroka, length);
    cin.sync();
    int count = linearSearch(newstroka,podstroka );
    cout << count << " substrings were found" << endl;

}
