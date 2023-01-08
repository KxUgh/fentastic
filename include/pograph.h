#ifndef POGRAPH_H
#define POGRAPH_H
#include<vector>
#include<cstdint>
#include<cstdio>
#include<string>
#include<fstream>
#include<array>
#include<variant>

namespace pograph{

enum MagicNumber{
    P3,
    P6
};


class Color{
    public:
    Color(uint8_t r,uint8_t g, uint8_t b);
    Color& operator=(const Color& other);
    bool operator==(Color other);
    bool operator!=(Color other);
    uint8_t r,g,b;
};

typedef std::vector<std::vector<Color>> colorMatrix;

class Point{
    public:
    Point(int x,int y);
    double distance(Point& other);
    int x,y;
};

class Rect{
    public:
    Rect(Point corner, int w, int h, Color color);
    Point corner;
    int w,h;
    Color color;
};
class Circle{
    public:
    Circle(Point center, int r, Color color);
    Point center;
    int r;
    Color color;
};

class Pixel{
    public:
    Pixel(Color color);
    Pixel();
    bool isTransparent();
    Color color();
    private:
    std::variant<std::monostate, Color> value;
};

typedef std::vector<std::vector<Pixel>> pixelMatrix;

class Sprite{
    public:
    Sprite();
    Sprite(std::string input, Pixel transparencyColor = Pixel());
    Pixel transparencyColor;
    pixelMatrix getPixels();
    int width();
    int height();
    private:
    pixelMatrix pixels;
};

class Canvas{
    public:
    Canvas(int width,int height);
    Canvas(colorMatrix colors);

    colorMatrix getColors();
    void setColor(int x,int y,Color color);

    void fillBackground(Color color);
    void drawRect(Rect& rect);
    void drawCircle(Circle& circle);
    void drawSprite(Sprite& sprite, int x,int y);
    int width();
    int height();
    private:
    colorMatrix colors;
    int w,h;
};

void generatePPM(std::string output, Canvas& canvas, MagicNumber mn = P6);
}
#endif