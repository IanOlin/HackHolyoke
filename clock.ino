

    clock.ino 

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"
/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to 
 * hook up your pixels and all of the pixel types that are supported.
 *
 */
#include "application.h"
#include <time.h>
SYSTEM_MODE(AUTOMATIC);
// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D7
#define PIXEL_COUNT 16
#define PIXEL_TYPE WS2812B
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
void setup() 
{
  Time.zone(-4);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
uint32_t colors[12];
uint16_t i;
uint8_t w, h, m, s;
uint32_t green = strip.Color(0, 255, 0);
uint32_t white = strip.Color(255, 255, 255);
uint32_t blue = strip.Color(0, 0, 255);
void loop() 
{
    h = Time.hourFormat12() - 1;
    m = Time.minute() / 5;
    s = Time.second() / 5;
    w = 100;
    //set the colors all to dark
    for (int i = 0; i < 12; i++) {
        colors[i] = 0;
    }
    //update colors
    colors[h] = blue;
    colors[m] = green;
    colors[s] = white;
    //update the pixels
    for (uint16_t i = 0; i < 12; i++){
        setPixel(i, colors[i]);
Ready.

