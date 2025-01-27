#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>


constexpr int Default = 7 ;
constexpr int Purple = 13;
constexpr int Green = 2;
constexpr int Grey = 8;
constexpr int Red = 12;


void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

DWORD GetProcessByName(const char* lpProcessName)
{
    char lpCurrentProcessName[255];

    PROCESSENTRY32 ProcList{};
    ProcList.dwSize = sizeof(ProcList);

    const HANDLE hProcList = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcList == INVALID_HANDLE_VALUE)
        return -1;

    if (!Process32First(hProcList, &ProcList))
        return -1;

    wcstombs_s(nullptr, lpCurrentProcessName, ProcList.szExeFile, 255);

    if (lstrcmpA(lpCurrentProcessName, lpProcessName) == 0)
        return ProcList.th32ProcessID;

    while (Process32Next(hProcList, &ProcList))
    {
        wcstombs_s(nullptr, lpCurrentProcessName, ProcList.szExeFile, 255);

        if (lstrcmpA(lpCurrentProcessName, lpProcessName) == 0)
            return ProcList.th32ProcessID;
    }

    return -1;
}


int main() {
    SetConsoleTitle(L"                                                                                                              FEEL THE GAMESENSE ");


    const char* lpDLLName = "skeet.dll";
    const char* lpProcessName = "csgo.exe";
    char lpFullDLLPath[MAX_PATH];
    SetConsoleOutputCP(CP_UTF8);

    SetColor(Green);
    std::cout << "                                                                                                                  \n";
    std::cout << "                                                                                                                  \n";
    std::cout << "                                                                                                                  \n";
    std::cout << "                                                                                                                  \n";
    std::cout << u8"                 ▄████  ▄▄▄       ███▄ ▄███▓▓█████   ██████ ▓█████  ███▄    █   ██████ ▓█████                      \n";
    std::cout << u8"                ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ ▒██    ▒ ▓█   ▀  ██ ▀█   █ ▒██    ▒ ▓█   ▀                      \n";
    std::cout << u8"               ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   ░ ▓██▄   ▒███   ▓██  ▀█ ██▒░ ▓██▄   ▒███                        \n";
    std::cout << u8"               ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄   ▒   ██▒▒▓█  ▄ ▓██▒  ▐▌██▒  ▒   ██▒▒▓█  ▄                      \n";
    std::cout << u8"               ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒▒██████▒▒░▒████▒▒██░   ▓██░▒██████▒▒░▒████▒                     \n";
    std::cout << u8"                ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░▒ ▒▓▒ ▒ ░░░ ▒░ ░░ ▒░   ▒ ▒ ▒ ▒▓▒ ▒ ░░░ ▒░ ░                     \n";
    std::cout << u8"                 ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░░ ░▒  ░ ░ ░ ░  ░░ ░░   ░ ▒░░ ░▒  ░ ░ ░ ░  ░                     \n";
    std::cout << u8"               ░ ░   ░   ░   ▒   ░      ░      ░   ░  ░  ░     ░      ░   ░ ░ ░  ░  ░     ░                        \n";
    std::cout << u8"                     ░       ░  ░       ░      ░  ░      ░     ░  ░         ░       ░     ░  ░                     \n";
    std::cout << u8"                                                                                                                \n";
    std::cout << u8"                                                                                                                \n";
    std::cout << u8"                            ╔════════════════════════════════════════════════════╗                             \n";
    std::cout << u8"                            ║       Version 1.2       -       Refined by Ladro   ║                             \n";
    std::cout << u8"                            ╚════════════════════════════════════════════════════╝                             \n";
    std::cout << "                                                                                                               \n";
    std::cout << "                                                                                                               \n";

    SetColor(Grey);

    std::cout << "                                     !  Checking for the game process ! \n\n";
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "                                                      .                                                     \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    DWORD dwProcessID = -1;
    while (dwProcessID == (DWORD)-1) {
        dwProcessID = GetProcessByName(lpProcessName);
        if (dwProcessID == (DWORD)-1) {
            SetColor(Grey);
            std::cout << "                                         CSGO not detected. Waiting for game to be launched ...\r";
            SetColor(Default);
        
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    SetColor(Green);
    std::cout << "\n\n\n                                            !  CSGO Detected  !\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));


    if (!GetFullPathNameA(lpDLLName, MAX_PATH, lpFullDLLPath, nullptr)) {
        SetColor(Purple);
        std::cout << "                                        Error(-1): Failed to resolve the full path for the DLL.\n";
        std::cout << "                                          Result: Process Termination.\n\n\n\n\n";
        SetColor(Default);
        return -1;
    }

    DWORD dwAttributes = GetFileAttributesA(lpFullDLLPath);
    if (dwAttributes == INVALID_FILE_ATTRIBUTES || (dwAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        SetColor(Purple);
        std::cout << "                \n\n\n\n                 Error(-1): DLL file \"" << lpDLLName << "\" not found in the same directory as the loader.\n";
        std::cout << "                                        Result: Process Termination.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(10));
        SetColor(Default);

        return -1;
    }


    const HANDLE hTargetProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);
    if (hTargetProcess == nullptr) {
        SetColor(Purple);
        std::cout << "Error: Could not open the target process. Ensure you are running as administrator.\n";
        SetColor(Default);
        return -1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    VirtualAllocEx(hTargetProcess, (LPVOID)0x43310000, 0x2FC000u, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); // for skeet
    VirtualAllocEx(hTargetProcess, 0, 0x1000u, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); // for skeet


    const LPVOID lpPathAddress = VirtualAllocEx(hTargetProcess, nullptr, lstrlenA(lpFullDLLPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (lpPathAddress == nullptr) {
        SetColor(Purple);
        std::cout << "                 Error: Could not allocate memory in the target process.\n";
        SetColor(Default);
        CloseHandle(hTargetProcess);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return -1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    SetColor(Green);
    std::cout << "\n                                        Memory allocated in target process at: " << std::hex << (uintptr_t)lpPathAddress << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));


    if (!WriteProcessMemory(hTargetProcess, lpPathAddress, lpFullDLLPath, lstrlenA(lpFullDLLPath) + 1, nullptr)) {
        SetColor(Red);
        std::cout << "                 Error: Could not write the DLL path to the target process memory.\n";
        SetColor(Default);
        CloseHandle(hTargetProcess);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return -1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "                                        DLL path written successfully.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    const HMODULE hModule = GetModuleHandleA("kernel32.dll");
    if (hModule == INVALID_HANDLE_VALUE || hModule == nullptr)
        return -1;

    const FARPROC lpFunctionAddress = GetProcAddress(hModule, "LoadLibraryA");
    if (lpFunctionAddress == nullptr)
    {
        SetColor(Purple);
        printf("                 An error occurred when trying to get \"LoadLibraryA\" address.\n");
        SetColor(Default);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return -1;
    }

    printf("                                        LoadLibrary address at 0x%X\n", (UINT)(uintptr_t)lpFunctionAddress);
    std::this_thread::sleep_for(std::chrono::seconds(1));


    const HANDLE hThreadCreationResult = CreateRemoteThread(hTargetProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)lpFunctionAddress, lpPathAddress, 0, nullptr);
    if (hThreadCreationResult == INVALID_HANDLE_VALUE)
    {
        SetColor(Red);
        std::cout << "                 Error (-1) : Could not create a remote thread in the target process.\n";
        SetColor(Default);
        CloseHandle(hTargetProcess);
        return -1; \
            std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    SetColor(Green);
    std::cout << "                                        Gamesense Loaded Successfully!\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));

    SetColor(Default);
    return 0;
}