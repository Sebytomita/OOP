#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char*[height];
    for (int i = 0; i < height; ++i) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int cx = ray;
    int cy = 0;
    int nr = 3 - 2 * ray;

    while (cx >= cy) {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x + cx, y - cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x - cy, y - cx, ch);

        if (nr > 0) {
            cy++;
            nr = nr + 4 * (cx - cy) + 10;
        } else {
            cx--;
            nr = nr + 4 * cx + 6; 
        }
    }
}


void Canvas::FillCircle(int x, int y, int ray, char ch) {
    int cx = ray;
    int cy = 0;
    int nr = 0;

    while (cx >= cy) {
        DrawLine(x - cx, y + cy, x + cx, y + cy, ch);
        DrawLine(x - cx, y - cy, x + cx, y - cy, ch);
        DrawLine(x - cy, y + cx, x + cy, y + cx, ch);
        DrawLine(x - cy, y - cx, x + cy, y - cx, ch);

        if (nr <= 0) {
            cy++;
            nr += 2 * cy + 1;
        }
        if (nr > 0) {
            cx--;
            nr -= 2 * cx + 1;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(right, bottom, left, bottom, ch);
    DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        DrawLine(left, i, right, i, ch);
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int difx = abs(x2 - x1);
    int dify = abs(y2 - y1);
    int dirx = x1 < x2 ? 1 : -1;
    int diry = y1 < y2 ? 1 : -1;
    int nr = difx - dify;

    while (x1 != x2 || y1 != y2) {
        SetPoint(x1, y1, ch);
        if ( 2 * nr > -dify) {
            nr -= dify;
            x1 += dirx;
        }
        if (2 * nr < difx) {
            nr += difx;
            y1 += diry;
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << matrix[i][j];
        }
        cout << '\n';
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}
