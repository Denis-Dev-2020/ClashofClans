#define TEXT_SIZE 16
#include <iostream>
#include <Windows.h>

using namespace std;

const LPCTSTR window_title = "BlueStacks";
const HWND hWND = FindWindow(NULL, window_title);
int CoordNum = 0;
int dummy;

void openingMenu () {
    cout << "#############################################" << endl;
    cout << "####### WELCOME TO CASH OF CLANS BOT ########" << endl;
    cout << "#############################################" << endl;
    cout << "#  INVITE CLAN MEMBERS            - 1       #" << endl;
    cout << "#  ADMIN MODE - GET MOUSE COORDS  - 2       #" << endl;
    cout << "#  LOWER BUILDER VILLAGE TROPHIES - 3       #" << endl;
    cout << "#############################################" << endl;    
}
void LeftClick () {
  INPUT iNPUT = { 0 };
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &iNPUT, sizeof(iNPUT));
        ZeroMemory(&iNPUT, sizeof(iNPUT));
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &iNPUT, sizeof(iNPUT));
}
void LeftClickDown () {
  INPUT iNPUT = { 0 };
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &iNPUT, sizeof(iNPUT));
}
void LeftClickUp () {
  INPUT iNPUT;
        ZeroMemory(&iNPUT, sizeof(iNPUT));
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &iNPUT, sizeof(iNPUT));
}
void MoveMouseTo (int a , int b) {
        int x = a;
        int y = b;
        // Get total screen coordinates
        int screen_x = GetSystemMetrics(SM_CXSCREEN);
        int screen_y = GetSystemMetrics(SM_CYSCREEN);
        WINDOWPLACEMENT wp;
        GetWindowPlacement(hWND, &wp);
        long xConverted = (65535 * (x + wp.rcNormalPosition.left)) / screen_x;
        long yConverted = (65535 * (y + wp.rcNormalPosition.top)) / screen_y;
        INPUT iNPUT = { 0 };
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
        iNPUT.mi.dx = xConverted;
        iNPUT.mi.dy = yConverted;
        SendInput(1, &iNPUT, sizeof(iNPUT));
}
void WriteChar (char a) {
 INPUT Input = { 0 };
        Input.type = INPUT_KEYBOARD;
        Input.ki.wVk = VkKeyScanA(a);
        SendInput(1, &Input, sizeof(Input));
        ZeroMemory(&Input, sizeof(Input));
        Input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &Input, sizeof(Input));
}
void CleanArray (char a[TEXT_SIZE]) {
    for (int i = 0; i < TEXT_SIZE; i++){
        a[i] = ' ';
    }
}
void PrintArray (char a[TEXT_SIZE]) {
    cout << "[";
    for (int i = 0; i < TEXT_SIZE; i++){
        cout << a[i] << ",";
    }
    cout << "]" << endl;
}
void WriteText (string str) {
    cout << str << endl ;
    char Crayy[TEXT_SIZE];
    cout << "Before :";
    PrintArray(Crayy);
    CleanArray(Crayy);
    cout << "After Clean :";
    PrintArray(Crayy);
    strcpy(Crayy,str.c_str());
    cout << "After Adding Text :";
    PrintArray(Crayy);
    Sleep(3000);
    for (int i = 0; i < TEXT_SIZE; i++){
        if (Crayy[i] == 32){
            WriteChar(Crayy[i]);
        }

        if (((Crayy[i] >= 48)||(Crayy[i]< 58 ))&&((Crayy[i] >= 65)||(Crayy[i]< 91 ))){
            WriteChar(Crayy[i]);
        }


    }
}
int getMouseX () {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(hWND, &p);
    return p.x;
}
int getMouseY () {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(hWND, &p);
    return p.y;
}
void ScanAndDestroy () {

    if (GetAsyncKeyState(0x5A)) {//Mouse position press Z
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(hWND, &p);
        cout << "Mouse Position : (" << p.x << "," << p.y << ")" << endl;
    }
    if (GetAsyncKeyState(0x4C)) { // Left Mouse Click press L
        INPUT iNPUT = { 0 };
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &iNPUT, sizeof(iNPUT));
        ZeroMemory(&iNPUT, sizeof(iNPUT));
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &iNPUT, sizeof(iNPUT));
    }
    if (GetAsyncKeyState(0x59)) { //write a  press Y
        INPUT Input = { 0 };
        Input.type = INPUT_KEYBOARD;
        Input.ki.wVk = VkKeyScanA('a');
        SendInput(1, &Input, sizeof(Input));
        ZeroMemory(&Input, sizeof(Input));
        Input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &Input, sizeof(Input));
    }
    if (GetAsyncKeyState(0x53)) { // Set mouse position using SendInput press S
        int x = 100;
        int y = 100;
        // Get total screen coordinates
        int screen_x = GetSystemMetrics(SM_CXSCREEN);
        int screen_y = GetSystemMetrics(SM_CYSCREEN);
        WINDOWPLACEMENT wp;
        GetWindowPlacement(hWND, &wp);
        long xConverted = (65535 * (x + wp.rcNormalPosition.left)) / screen_x;
        long yConverted = (65535 * (y + wp.rcNormalPosition.top)) / screen_y;
        INPUT iNPUT = { 0 };
        iNPUT.type = INPUT_MOUSE;
        iNPUT.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
        iNPUT.mi.dx = xConverted;
        iNPUT.mi.dy = yConverted;
        SendInput(1, &iNPUT, sizeof(iNPUT));
    }
}
void PressF11 () {
    keybd_event(0x7A, 0, 0, 0);
    keybd_event(0x7A, 0, KEYEVENTF_KEYUP, 0);
}
void PressESC () {
    keybd_event(0x1B, 0, 0, 0);
    keybd_event(0x1B, 0, KEYEVENTF_KEYUP, 0);
}
void PressSPACE () {
    keybd_event(0x20, 0, 0, 0);
    keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
}
void PressBackArrowMouse () {
        /// Press Search
        Sleep(1000);
        MoveMouseTo(140,55);
        LeftClick();
}
void GoToStats () {
    //G
    keybd_event(0x47, 0, 0, 0);
    keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);
}
void GoToLayoutEditor () {

    WriteChar('b');
}
void GoToShop () {

    WriteChar('i');
}
void GoToLegue () {

    WriteChar('v');
}
void GoToArmy () {

    WriteChar('e');
}
void GoToClanWars () {

    WriteChar('w');
}
void GoToInbox () {

    WriteChar('z');
}
void GoToChat () {

    WriteChar('c');
}
void GoToSettings () {

    WriteChar('u');
}
void GoToMultiplayer () {

    PressSPACE();
}
void GoToClan () {

    GoToStats();
    Sleep(1000);
    MoveMouseTo(530,35);
    Sleep(200);
    LeftClick();
}
void GoToSeachNewClanMembers () {

    GoToClan();
    Sleep(1000);
    MoveMouseTo(250,520);
    Sleep(200);
    LeftClick();
}
void GoToHomeVillageScreen () {

    Sleep(1000);
    for (int i = 0; i < 6; i++){
        PressESC();
        Sleep(100);
    }
        PressF11();
}
void PrintMousePos () {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(hWND, &p);
        cout << "Mouse Position : (" << p.x << "," << p.y << ")" << endl;
}
void GetPlayers (int x) {

    //GoToHomeVillageScreen();
    Sleep(800);
    GoToSeachNewClanMembers();
    Sleep(1500);
    /////////// Scrolling For different tags   ////////////////////
    for (int i = 0; i < 3; ++i){
        MoveMouseTo(1100,220);
        Sleep(200);
        LeftClickDown();
        MoveMouseTo(1100,220);
        Sleep(200);
        MoveMouseTo(400,220);
        Sleep(200);
        LeftClickUp();
        Sleep(200);
    }
    ///////////////////////////////////////////////////////////////
    // MoveMouseTo(350,220);     /// Select Active Active Doner
        MoveMouseTo(650,220);    /// Select Active Daily
        Sleep(200);
        LeftClick();
    /// Press Search
        MoveMouseTo(1050,290);
        Sleep(200);
        LeftClick();
    for (int i = 1; i < x; i++){
        /// Pressing the first row player
            MoveMouseTo(520,380);
            LeftClick(); 
            Sleep(700);
            LeftClick();  // <----- Invite (is in the same mouse location)
        /// Back 1 Page
            PressBackArrowMouse();
            Sleep(500);
        /// Scrolls 1 member up to the first row
            MoveMouseTo(520,473);
            LeftClickDown();
            MoveMouseTo(520,473);
            Sleep(200);
            MoveMouseTo(520,380);
            Sleep(200);
            LeftClickUp();
            Sleep(200);
            if (i%8 == 0){
                MoveMouseTo(520,380);
                Sleep(500);
                LeftClickDown();
                MoveMouseTo(520,380);
                Sleep(500);
                MoveMouseTo(520,407);
                Sleep(200);
                LeftClickUp();
                Sleep(200);
            }
        }
	MoveMouseTo(1215,50);
        Sleep(2000);
        LeftClick();
}
void GetToGroundZero () {
    MoveMouseTo(520,700);
    LeftClickDown();
    MoveMouseTo(520,700);
    Sleep(200);
    MoveMouseTo(520,100);
    Sleep(200);
    LeftClickUp();
    Sleep(1000);
    MoveMouseTo(520,700);
    LeftClickDown();
    MoveMouseTo(520,700);
    Sleep(200);
    MoveMouseTo(520,100);
    Sleep(200);
    LeftClickUp();
    Sleep(1000);
    MoveMouseTo(400,400);
    LeftClickDown();
    MoveMouseTo(400,400);
    Sleep(200);
    MoveMouseTo(1000,400);
    Sleep(200);
    LeftClickUp();
    Sleep(1000);
    MoveMouseTo(400,400);
    LeftClickDown();
    MoveMouseTo(400,400);
    Sleep(200);
    MoveMouseTo(1000,400);
    Sleep(200);
    LeftClickUp();
    Sleep(200);
}
void GetToBuilderVillage () {
    GetToGroundZero();
    MoveMouseTo(430,430);
    LeftClick();
}
void BuilderVillageAttack () {
    Sleep(1000);
    MoveMouseTo(90,680);
    LeftClick();
}
void Lose10Battles () {
    GetToBuilderVillage ();

for (int i = 0 ; i < 10 ; i++){

    BuilderVillageAttack ();
    Sleep(1000);
    MoveMouseTo(900,300);
    LeftClick();
    Sleep(5000);
    MoveMouseTo(210,680);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(270,350);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(100,570);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(815,500);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(680,650);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(1030,540);
    LeftClick();
    Sleep(2000);
    MoveMouseTo(1030,630);
    LeftClick();
    Sleep(240000);

  }
}


int main (void){


    string Sentence = "CASH OF CLANS";

    openingMenu();


    int Option = 0;

    cin >> Option;


    switch (Option) {

        case 1:
        ///////////////////////////////// GET NEW CLAN MEMBERS /////////////////////////////////////
	for (int i = 0 ; i < 30 ; i++){
        	Sleep(3000);
		GetPlayers(20);
	}
        ////////////////////////////////////////////////////////////////////////////////////////////
        return 0;
        case 2:
        //////////////////////////////// GET MOUSE COORDINATES /////////////////////////////////////
        dummy = 1;

        while (dummy) {

            if (GetAsyncKeyState(0x4E)) {//Mouse position press Z print coordinates
                POINT p;
                CoordNum++;
                GetCursorPos(&p);
                ScreenToClient(hWND, &p);
                cout << "CoordNum #" << CoordNum << "  (" << getMouseX() << "," << getMouseY() << ")" << endl;
                }
            if (GetAsyncKeyState(0x51)) {//Mouse position press Q quit
                POINT p;
                GetCursorPos(&p);
                ScreenToClient(hWND, &p);
                dummy = 0;
                }
            if (GetAsyncKeyState(0x4D)) {//Mouse position press M clear screen
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl ;
                }
            if (GetAsyncKeyState(0x4F)) {//Mouse position press M clear screen
                GetToBuilderVillage ();
                }

        }





        ////////////////////////////////////////////////////////////////////////////////////////////
        return 0;

        case 3:
	Sleep(4000);
	Lose10Battles ();

        return 0;

        default:
        return 0;


    }




}
