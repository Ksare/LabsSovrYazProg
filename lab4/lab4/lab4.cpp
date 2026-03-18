#define _CRT_SECURE_NO_WARNINGS  // �⪫�砥� �।�०����� � ������᭮��

#include <iostream>
#include <cstring>      // ��� ���������� �㭪権 (�㭪� 1)
#include <cstdlib>      // ��� malloc/free
#include <clocale>
using namespace std;

// ����� 1: ������������� ������������ ������� 
void demonstrateLibraryFunctions() {
    cout << "\n����� 1: ������������ �������\n";

    char str1[100] = "qwerty";
    char str2[100] = "1234567890";
    char str3[100];

    cout << "��室�� ��ப�:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    // 1. strlen() - ��।������ ����� ��ப�
    cout << "1. strlen() - ����� ��ப�:\n";
    cout << "   ����� str1 = " << strlen(str1) << endl;
    cout << "   ����� str2 = " << strlen(str2) << endl << endl;

    // 2. strcpy() - ����஢���� ��ப�
    strcpy(str3, str1);
    cout << "2. strcpy() - ����஢���� str1 � str3:\n";
    cout << "   str3 = \"" << str3 << "\"\n\n";

    // 3. strcat() - �����⥭��� (�楯�����) ��ப
    strcpy(str3, str1);  // ����⠭�������� str3
    strcat(str3, str2);
    cout << "3. strcat() - �楯����� str1 + str2:\n";
    cout << "   str1 + str2 = \"" << str3 << "\"\n\n";

    // 4. strcmp() - �ࠢ����� ��ப
    cout << "4. strcmp() - �ࠢ����� ��ப:\n";
    cout << "   str1 vs str2: " << strcmp(str1, str2);
    if (strcmp(str1, str2) == 0) cout << " (��ப� ࠢ��)\n";
    else if (strcmp(str1, str2) < 0) cout << " (str1 < str2)\n";
    else cout << " (str1 > str2)\n";

    cout << "   str1 vs str1: " << strcmp(str1, str1);
    if (strcmp(str1, str1) == 0) cout << " (��ப� ࠢ��)\n";
}

// ����� 2: ���� ������� (��� �������) 

// 2.1 ��� ������� ����������� ����� ������

// ���ᮡ 1: ��१ ���稪 � �����ᠬ�
int myStrlen1(const char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

// ���ᮡ 2: ��१ 㪠��⥫� � ��䬥⨪� 㪠��⥫��
int myStrlen2(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return (int)(ptr - str);  // �� �८�ࠧ������ � int
}

// ���ᮡ 3: ��१ ४����
int myStrlen3(const char* str) {
    if (*str == '\0') return 0;
    return 1 + myStrlen3(str + 1);
}

// 2.2 ����������� ����� 
void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 2.3 ��������� ����� 
int myStrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }

    // �᫨ ���� ��ப� �����稫���, � ��㣠� ���
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

// 2.4 ������������ �����
void myStrcat(char* dest, const char* src) {
    // ���砫� ��室�� ����� ��ப� dest
    int destLen = myStrlen1(dest);

    // ��⥬ �����㥬 src � ����� dest
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';  // �����蠥� �㫥�
}

// ���������� ࠡ��� ᢮�� �㭪権 (�㭪� 2)
void demonstrateMyFunctions() {
    cout << "\n����� 2: ����������� �������\n";

    char str1[100] = "qwerty";
    char str2[100] = "1234567890";
    char str3[100];
    char str4[100];

    cout << "��室�� ��ப�:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    // ����஢���� �㭪権 �����
    cout << "1. ��।������ ����� ��ப� (�� ᯮᮡ�):\n";
    cout << "   strlen(str1) = " << strlen(str1) << " (�������筠�)\n";
    cout << "   myStrlen1(str1) = " << myStrlen1(str1) << " (�१ �������)\n";
    cout << "   myStrlen2(str1) = " << myStrlen2(str1) << " (�१ 㪠��⥫�)\n";
    cout << "   myStrlen3(str1) = " << myStrlen3(str1) << " (४����)\n\n";

    // ����஢���� ����஢����
    cout << "2. ����஢���� ��ப�:\n";
    myStrcpy(str3, str1);
    cout << "   myStrcpy(str3, str1) -> str3 = \"" << str3 << "\"\n\n";

    // ����஢���� �ࠢ�����
    cout << "3. �ࠢ����� ��ப:\n";
    cout << "   myStrcmp(str1, str2) = " << myStrcmp(str1, str2);
    if (myStrcmp(str1, str2) == 0) cout << " (ࠢ��)\n";
    else if (myStrcmp(str1, str2) < 0) cout << " (str1 < str2)\n";
    else cout << " (str1 > str2)\n";

    cout << "   myStrcmp(str1, str1) = " << myStrcmp(str1, str1);
    if (myStrcmp(str1, str1) == 0) cout << " (ࠢ��)\n\n";

    // ����஢���� �����⥭�樨
    cout << "4. �����⥭��� ��ப:\n";
    myStrcpy(str4, str1);  // �����㥬 str1 � str4
    myStrcat(str4, str2);
    cout << "   myStrcat(str4, str2) -> str4 = \"" << str4 << "\"\n";
}

// ����� 3: ������������ ������ 
void demonstrateDynamicMemory() {
    cout << "\n����� 3: ������������ ������\n";

    // �뤥����� �����
    char* str1 = (char*)malloc(100 * sizeof(char));
    char* str2 = (char*)malloc(100 * sizeof(char));
    char* str3 = (char*)malloc(100 * sizeof(char));

    if (str1 == NULL || str2 == NULL || str3 == NULL) {
        cout << "�訡�� �뤥����� �����!\n";
        return;
    }

    // ����஢���� ��ப � ���������� ������
    myStrcpy(str1, "qwerty");
    myStrcpy(str2, "1234567890");

    cout << "��ப� � �������᪮� �����:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n";
    cout << "����� str1 = " << myStrlen1(str1) << endl;

    // �����⥭���
    myStrcpy(str3, str1);
    myStrcat(str3, str2);
    cout << "str1 + str2 = \"" << str3 << "\"\n";

    // �᢮�������� �����
    free(str1);
    free(str2);
    free(str3);

    cout << "������ �ᯥ譮 �᢮�������\n";
}

// ����� 4: ������ �����
void demonstrateStringArray() {
    cout << "\n����� 4: ������ �����\n";

    // ������� ���ᨢ ��ப � �������᪮� �����
    const int NUM_STRINGS = 5;
    char** strings = (char**)malloc(NUM_STRINGS * sizeof(char*));

    // �஢�ઠ �뤥����� �����
    if (strings == NULL) {
        cout << "�訡�� �뤥����� ����� ��� ���ᨢ� ��ப!\n";
        return;
    }

    // �뤥�塞 ������ ��� ������ ��ப�
    for (int i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        if (strings[i] == NULL) {
            cout << "�訡�� �뤥����� ����� ��� ��ப� " << i << "!\n";
            // �᢮������� 㦥 �뤥������ ������
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return;
        }
    }

    // ������塞 ��ப�
    myStrcpy(strings[0], "Hello");
    myStrcpy(strings[1], "World");
    myStrcpy(strings[2], "C++");
    myStrcpy(strings[3], "Programming");
    myStrcpy(strings[4], "Language");

    cout << "��室�� ���ᨢ ��ப:\n";
    for (int i = 0; i < NUM_STRINGS; i++) {
        cout << "strings[" << i << "] = \"" << strings[i]
            << "\", ����� = " << myStrlen1(strings[i]) << endl;
    }

    // �ਬ��塞 ��� �㭪樨 � ���ᨢ� ��ப
    cout << "\n�ਬ������ �㭪権 � ���ᨢ� ��ப:\n";

    // �ࠢ����� ��ப
    cout << "�ࠢ����� strings[0] � strings[1]: ";
    int cmp = myStrcmp(strings[0], strings[1]);
    if (cmp == 0) cout << "ࠢ��\n";
    else if (cmp < 0) cout << "strings[0] < strings[1]\n";
    else cout << "strings[0] > strings[1]\n";

    // �����⥭��� (१���� ��࠭塞 � ����� ��ப�)
    char* temp = (char*)malloc(200 * sizeof(char));
    if (temp != NULL) {
        myStrcpy(temp, strings[2]);
        myStrcat(temp, strings[3]);
        cout << "�����⥭��� strings[2] + strings[3] = \"" << temp << "\"\n";
        free(temp);
    }

    // ���� ᠬ�� ������� ��ப�
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 0; i < NUM_STRINGS; i++) {
        int len = myStrlen1(strings[i]);
        if (len > maxLen) {
            maxLen = len;
            maxIdx = i;
        }
    }
    cout << "����� ������� ��ப�: strings[" << maxIdx
        << "] = \"" << strings[maxIdx] << "\" (����� " << maxLen << ")\n";

    // �᢮������� ������
    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }
    free(strings);
    cout << "������ ���ᨢ� ��ப �᢮�������\n";
}

// ������� ������� 
int main() {
    
    cout << "������������ ������ 4 - ��������� ��������� ������\n";


    // �㭪� 1: ��������� �㭪樨
    demonstrateLibraryFunctions();

    // �㭪� 2: ᢮� �㭪樨
    demonstrateMyFunctions();

    // �㭪� 3: �������᪠� ������
    demonstrateDynamicMemory();

    // �㭪� 4: ���ᨢ ��ப
    demonstrateStringArray();

    cout << "\n�ணࠬ�� �����襭�.\n";
    return 0;
}