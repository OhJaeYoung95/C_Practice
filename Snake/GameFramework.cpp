    #include "GameFramework.h"


    GameFramework::GameFramework(int w, int h) :width(w), height(h)
        ,screenIndex(0)
    {
    }

    GameFramework::~GameFramework()
    {
    }

    void GameFramework::UpdateInput()
    {
        memcpy(prevKeyStates, currentKeyStates, sizeof(prevKeyStates));

        for (int keyCode = 0; keyCode < 256; keyCode++) {
            currentKeyStates[keyCode] = IsKeyDown(keyCode);
        }
    }

    bool GameFramework::IsKeyDown(int keyCode)
    {
        return 0x8000 & GetAsyncKeyState(keyCode);
    }

    bool GameFramework::GetKeyDown(KeyCode keyCode)
    {
        int code = (int)keyCode;

        return false == prevKeyStates[code] && currentKeyStates[code];
    }

    bool GameFramework::GetKeyUp(KeyCode keyCode)
    {
        int code = (int)keyCode;

        return prevKeyStates[code] && false == currentKeyStates[code];
    }

    bool GameFramework::GetKey(KeyCode keyCode)
    {
        int code = (int)keyCode;

        return prevKeyStates[code] && currentKeyStates[code];
    }

    void GameFramework::ScreenInit()
    {
        screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        CONSOLE_CURSOR_INFO cci = { 1, FALSE };
        SetConsoleCursorInfo(screens[0], &cci);
        SetConsoleCursorInfo(screens[1], &cci);

        COORD dw = { (SHORT)width, (SHORT)height };
        SetConsoleScreenBufferSize(screens[0], dw);
        SetConsoleScreenBufferSize(screens[1], dw);
    }

    void GameFramework::ScreenFlipping()
    {
        SetConsoleActiveScreenBuffer(screens[screenIndex]);
        screenIndex = (screenIndex + 1) % 2;
    }

    void GameFramework::ScreenClear()
    {
        COORD Coor = { 0, 0 };
        DWORD dw;
        // 프레임별로 화면 클리어
        FillConsoleOutputCharacter(screens[screenIndex], ' ', width* height, Coor, &dw);
    }

    void GameFramework::ScreenRelease()
    {
        CloseHandle(screens[0]);
        CloseHandle(screens[1]);
    }

    void GameFramework::ScreenPrint(int x, int y, const char* string)
    {
        DWORD dw;
        COORD CursorPosition = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(screens[screenIndex], CursorPosition);
        WriteFile(screens[screenIndex], string, strlen(string), &dw, NULL);
    }

    // 1 ~ 15 까지 색상 설정 가능
    void GameFramework::SetColor(unsigned short color)
    {
        SetConsoleTextAttribute(screens[screenIndex], color);
    }

    void GameFramework::Do()
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER currentTime;
        LARGE_INTEGER lastTime;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&lastTime);

        while (true)
        {
            QueryPerformanceCounter(&currentTime);
            float dt = (currentTime.QuadPart - lastTime.QuadPart) / static_cast<float>(frequency.QuadPart);

            // 게임 속도를 가변적으로 조절하기 위해 timeScale 변수를 사용한다.
            float timeScale = 0.5f; // 게임 속도를 0.5배로 조절
            dt *= timeScale;

            if (dt >= (1.0f / 60.0f))
            {
                UpdateInput();
                Update(dt);
                ScreenClear();
                Draw();
                ScreenFlipping();

                lastTime = currentTime;
            }
        }
    }


    void GameFramework::Release()
    {
    }
