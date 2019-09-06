/*
 * Console Color
 *
 * Copyright (c) 2005 Joergen Ibsen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <stdio.h>

void con_set_color(unsigned int fg_color, unsigned int bg_color)
{
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	SetConsoleTextAttribute(hStdOut, (bg_color << 4) | fg_color);
}

void con_def_color(void)
{
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	/* set default gray on black attributes */
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void con_set_pos(unsigned int x, unsigned int y)
{
	COORD c;
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	c.X = (SHORT) x;
	c.Y = (SHORT) y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void con_clear(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD c = { 0, 0 };
	HANDLE hStdOut;
	DWORD dwNumWritten;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		return;
	}

	/* fill console buffer with spaces */
	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, c, &dwNumWritten);

	/* set cursor to position 0,0 */
	SetConsoleCursorPosition(hStdOut, c);
}

void con_fill(unsigned int fg_color, unsigned int bg_color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD c = { 0, 0 };
	HANDLE hStdOut;
	DWORD dwNumWritten;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		return;
	}

	/* fill console buffer attributes */
	FillConsoleOutputAttribute(hStdOut, (bg_color << 4) | fg_color, csbi.dwSize.X * csbi.dwSize.Y, c, &dwNumWritten);
}

void con_wait_key(void)
{
	INPUT_RECORD ir;
	HANDLE hStdIn;
	DWORD dwNumEvents, dwNumRead;

	hStdIn = GetStdHandle(STD_INPUT_HANDLE);

	if (hStdIn == INVALID_HANDLE_VALUE) {
		return;
	}

	FlushConsoleInputBuffer(hStdIn);

	/* wait loop */
	while (1) {
		WaitForSingleObject(hStdIn, INFINITE);

		if (GetNumberOfConsoleInputEvents(hStdIn, &dwNumEvents) && dwNumEvents) {
			while (dwNumEvents--) {
				if (ReadConsoleInput(hStdIn, &ir, 1, &dwNumRead) && dwNumRead) {
					/* if it's a key being released, return */
					if (ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown == 0) {
						return;
					}
				}
			}
		}
	}
}

int main()
{
	con_clear();

	con_set_color(0, 0);
	printf("color 0\n");
	con_set_color(1, 0);
	printf("color 1\n");
	con_set_color(2, 0);
	printf("color 2\n");
	con_set_color(3, 0);
	printf("color 3\n");
	con_set_color(4, 0);
	printf("color 4\n");
	con_set_color(5, 0);
	printf("color 5\n");
	con_set_color(6, 0);
	printf("color 6\n");
	con_set_color(7, 0);
	printf("color 7\n");
	con_set_color(8, 0);
	printf("color 8\n");
	con_set_color(9, 0);
	printf("color 9\n");
	con_set_color(10, 0);
	printf("color 10\n");
	con_set_color(11, 0);
	printf("color 11\n");
	con_set_color(12, 0);
	printf("color 12\n");
	con_set_color(13, 0);
	printf("color 13\n");
	con_set_color(14, 0);
	printf("color 14\n");
	con_set_color(15, 0);
	printf("color 15\n");

	con_wait_key();

	con_def_color();

	return 0;
}
