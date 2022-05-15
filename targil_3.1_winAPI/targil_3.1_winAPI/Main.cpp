#include <Windows.h>
#include <iostream>

using namespace std;

#define BUFFER_SIZE 20

int main()
{
    CHAR data[BUFFER_SIZE] = {0};
    DWORD dwBytesRead = NULL;
    LPCSTR pfilename = "C:\\Users\\amirl\\OneDrive\\מסמכים\\בר אילן\\ארגוני טרור - סמינריון\\targil_winapi.txt";
    HANDLE fileHandle = CreateFileA(pfilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        cout << "ERROR: " << GetLastError() << endl;
        return -1;
    }
    BOOL readFileStatus = ReadFile(fileHandle, data, BUFFER_SIZE - 1, &dwBytesRead, NULL);
    if (readFileStatus == FALSE)
    {
        cout << "ERROR: " << GetLastError() << endl;
        return -1;
    }

    CloseHandle(fileHandle);
    // if we read data from the file
    if (dwBytesRead > 0 && dwBytesRead <= BUFFER_SIZE - 1)
    {
        data[dwBytesRead] = '\0';
        cout << "Data from file: " << endl;
        cout << data << endl;
    }
    // there is no data in the file
    else if (dwBytesRead == 0)
        cout << "The file was empty!" << endl;
    // we read more the the space in buffer (unexpected result)
    else
        cout << "dwBytesRead is too large!" << endl;

    return 0;
}