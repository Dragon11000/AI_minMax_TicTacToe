#include "bash.hpp"

void bash::changeBash(int index) {
	std::cout << ("\e[" + std::to_string(index) + "m");
}

void bash::bashDefault() {
	changeBash(0);
}

void bash::invert() {
	changeBash(7);
}
void bash::undo() {
	changeBash(27);
}

void bash::changeTextDefault() {
	changeBash(39);
}

void bash::changeTextBlack() {
	changeBash(30);
}

void bash::changeTextRed() {
	changeBash(31);
}

void bash::changeTextGreen() {
	changeBash(32);
}

void bash::changeTextYellow() {
	changeBash(33);
}

void bash::changeTextBlue() {
	changeBash(34);
}

void bash::changeTextMagenta() {
	changeBash(35);
}

void bash::changeTextCyan() {
	changeBash(36);
}

void bash::changeTextLightGray() {
	changeBash(37);
}

void bash::changeTextDarkGray() {
	changeBash(90);
}

void bash::changeTextLightRed() {
	changeBash(91);
}

void bash::changeTextLightGreen() {
	changeBash(92);
}

void bash::changeTextLightYellow() {
	changeBash(93);
}

void bash::changeTextLightBlue() {
	changeBash(94);
}

void bash::changeTextLightMagenta() {
	changeBash(95);
}

void bash::changeTextLightCyan() {
	changeBash(96);
}

void bash::changeTextLightWhite() {
	changeBash(97);
}

//MARK: Background Color
void bash::changeBackgroundDefualt() {
	changeBash(49);
}

void bash::changeBackgroundBlack() {
	changeBash(40);
}

void bash::changeBackgroundRed() {
	changeBash(41);
}

void bash::changeBackgroundGreen() {
	changeBash(42);
}

void bash::changeBackgroundYellow() {
	changeBash(43);
}

void bash::changeBackgroundBlue() {
	changeBash(44);
}

void bash::changeBackgroundMagenta() {
	changeBash(45);
}

void bash::changeBackgroundCyan() {
	changeBash(46);
}

void bash::changeBackgroundLightGray() {
	changeBash(47);
}

void bash::changeBackgroundDarkGray() {
	changeBash(100);
}

void bash::changeBackgroundLightRed() {
	changeBash(101);
}

void bash::changeBackgroundLightGreen() {
	changeBash(102);
}

void bash::changeBackgroundLightYellow() {
	changeBash(103);
}

void bash::changeBackgroundLightBlue() {
	changeBash(104);
}

void bash::changeBackgroundLightMagenta() {
	changeBash(105);
}

void bash::changeBackgroundLightCyan() {
	changeBash(106);
}

void bash::changeBackgroundLightWhite() {
	changeBash(107);
}
