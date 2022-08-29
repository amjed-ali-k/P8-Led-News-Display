#include <SPI.h>
#include <DMD2.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <fonts/Arial_Black_16.h>
#include <fonts/Arial14.h>
#include "fonts/gayatri.h"
#define pin_A 16
#define pin_B 12
#define pin_sclk 0
#define pin_clk 14
#define pin_r 13
#define pin_noe 15

#define DISPLAYS_WIDE 4
#define DISPLAYS_HIGH 1
#define SCROLL_SPEED 50

// WIFI Settings

String ssid = "Flamingo";
String password = "123456789";
String serverName = "https://cc.app.squir.xyz/api/";

// DMD Settings

SPIDMD dmd(DISPLAYS_WIDE, DISPLAYS_HIGH, pin_noe, pin_A, pin_B, pin_sclk);
DMD_TextBox box(dmd);
String toDisplay = "Why timer 0 ? Because the ESP8266 has no hardware PWM, so the ESP8266/Arduino project is using timer1 for software PWM, a.k.a analogWrite. The only other ESP8266 library that currently uses timer0 is for Servo control, the likelihood that someone will use servos with a DMD is low compared to wanting to be able to adjust DMD brightness. How to connect: You'll probably want to use a level shifter, I used a TXS0108E that worked quite well. I imagine some 7400 and 4000 series chips that have been used in such a way before could also be substituted";
String malText = "AXv ]co£n¨pt\\m¡p¶Xn\\v, NphsS \\n§fpsS `mjbpw Fgp¯v D]IcW§fpw XncsªSp¯v ssS¸psN¿m³ Bcw`n¡pI.";

void setup()
{
    // Serial.begin(115200);
    dmd.setBrightness(255);
    dmd.begin();
    dmd.selectFont(Gayatri);

    WiFi.begin(ssid.c_str(), password.c_str());
    directPrintOnDisplay("Connecting to WiFi ", Arial14);
    while (WiFi.status() != WL_CONNECTED)
        directPrintOnDisplay(".", Arial14);
}

boolean isCharPrinted = false;
uint16_t charPointer = 0;
uint16_t marqueePointer = 0;
ulong lastRunTime = 0;

void printOnDisplay(const String &data, const uint8_t *font)
{
    if (!isCharPrinted)
    {
        if (data.length() < charPointer)
            charPointer = 0;
        uint16_t charWidth = dmd.charWidth(data.charAt(charPointer - 1), font);
        dmd.drawFilledBox(charWidth, 0, charWidth + dmd.charWidth(data.charAt(charPointer), font), 16, GRAPHICS_OFF);
        dmd.drawChar(charWidth + 1, 0, data.charAt(charPointer), GRAPHICS_OFF);
        charPointer++;
        isCharPrinted = true;
        // return;
    }

    if (millis() - lastRunTime > SCROLL_SPEED)
    {
        if (marqueePointer >= (dmd.charWidth(data.charAt(charPointer - 1), font)))
        {
            marqueePointer = 0;
            isCharPrinted = false;
        }
        dmd.marqueeScrollX(-1);
        marqueePointer++;
        lastRunTime = millis();
    }
}

void directPrintOnDisplay(const String &data, const uint8_t *font)
{
    for (int i = 0; i < data.length(); i++)
    {
        int width = dmd.charWidth(data.charAt(i - 1), font);
        dmd.drawFilledBox(width, 0, width + dmd.charWidth(data.charAt(i), font), 16, GRAPHICS_OFF); // Clear the buffer
        dmd.drawChar(width + 1, 0, data.charAt(i), GRAPHICS_OFF);
        for (int j = 0; j <= (width); j++)
        {
            dmd.marqueeScrollX(-1);
            delay(20);
        }
    }
}

void loop()
{

    // printOnDisplay(toDisplay, Arial_Black_16);
    directPrintOnDisplay(malText, Gayatri);
}