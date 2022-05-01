#include "a.h"

//keyboard input
int getKeyDown() {  // 키보드가 눌려있을 경우에만 _getch()를 통해 입력을 받고 그렇지 않을 경우 -1를 리턴
    if (_kbhit()) return _getch();  // _kbhit() --> 현재 키보드가 입력된 상태인지 조사.
                                    // _getch() --> 키보드의 입력을 받으며, 입력한 내용은 화면에 보이지 않는다.
    return -1;
}