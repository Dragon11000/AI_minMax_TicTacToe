#ifndef bash_hpp
#define bash_hpp

#include <iostream>

//Colors

namespace bash {
    //void changeBash(int index);
    void changeBash(int index);
    void bashDefault();

    //MARK: Other
    void invert();
    void undo();

    //MARK: Text Color
    void changeTextDefault();
    void changeTextBlack();
    void changeTextRed();
    void changeTextGreen();
    void changeTextYellow();
    void changeTextBlue();
    void changeTextMagenta();
    void changeTextCyan();
    void changeTextLightGray();
    void changeTextDarkGray();
    void changeTextLightRed();
    void changeTextLightGreen();
    void changeTextLightYellow();
    void changeTextLightBlue();
    void changeTextLightMagenta();
    void changeTextLightCyan();
    void changeTextLightWhite();

    //MARK: Background Color
    void changeBackgroundDefualt();
    void changeBackgroundBlack();
    void changeBackgroundRed();
    void changeBackgroundGreen();
    void changeBackgroundYellow();
    void changeBackgroundBlue();
    void changeBackgroundMagenta();
    void changeBackgroundCyan();
    void changeBackgroundLightGray();
    void changeBackgroundDarkGray();
    void changeBackgroundLightRed();
    void changeBackgroundLightGreen();
    void changeBackgroundLightYellow();
    void changeBackgroundLightBlue();
    void changeBackgroundLightMagenta();
    void changeBackgroundLightCyan();
    void changeBackgroundLightWhite();
}

#endif /* bash_hpp */
