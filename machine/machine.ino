#include <SPI.h>
#include <DMD2.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <fonts/Arial_Black_16.h>
#include <fonts/Arial14.h>
// #include "fonts/gayatri.h"
#define pin_A 16
#define pin_B 12
#define pin_sclk 0
#define pin_clk 14
#define pin_r 13
#define pin_noe 15

#define DISPLAYS_WIDE 4
#define DISPLAYS_HIGH 1
#define SCROLL_SPEED 50
#define DEBUG
// WIFI Settings

String ssid = "Flamingo";
String password = "123456789";

// DMD Settings

SPIDMD dmd(DISPLAYS_WIDE, DISPLAYS_HIGH, pin_noe, pin_A, pin_B, pin_sclk);
DMD_TextBox box(dmd);
// String toDisplay = "Why timer 0 ? Because the ESP8266 has no hardware PWM, so the ESP8266/Arduino project is using timer1 for software PWM, a.k.a analogWrite. The only other ESP8266 library that currently uses timer0 is for Servo control, the likelihood that someone will use servos with a DMD is low compared to wanting to be able to adjust DMD brightness. How to connect: You'll probably want to use a level shifter, I used a TXS0108E that worked quite well. I imagine some 7400 and 4000 series chips that have been used in such a way before could also be substituted";
// String malText = "AXv ]co£n¨pt\\m¡p¶Xn\\v, NphsS \\n§fpsS `mjbpw Fgp¯v D]IcW§fpw XncsªSp¯v ssS¸psN¿m³ Bcw`n¡pI.";

void setup()
{

#ifdef DEBUG
    Serial.begin(115200);
    Serial.print("Connecting");
#endif
    WiFi.begin(ssid, password);
    // directPrintOnDisplay("Connecting to WiFi ", Arial14);
#ifdef DEBUG
    Serial.print("Connecting");
#endif
    while (WiFi.status() != WL_CONNECTED)
    {
#ifdef DEBUG
        Serial.print(".");
#endif
        delay(500);
        // directPrintOnDisplay(".", Arial14);
    }
    Serial.println("Wifi Connected");
    delay(400);

    dmd.setBrightness(255);
    dmd.begin();
    dmd.selectFont(Arial_Black_16);
}

boolean isCharPrinted = false;
uint16_t charPointer = 0;
uint16_t marqueePointer = 0;
ulong lastRunTime = 0;

// void printOnDisplay(const String &data, const uint8_t *font)
// {
//     if (!isCharPrinted)
//     {
//         if (data.length() < charPointer)
//             charPointer = 0;
//         uint16_t charWidth = dmd.charWidth(data.charAt(charPointer - 1), font);
//         dmd.drawFilledBox(charWidth, 0, charWidth + dmd.charWidth(data.charAt(charPointer), font), 16, GRAPHICS_OFF);
//         dmd.drawChar(charWidth + 1, 0, data.charAt(charPointer), GRAPHICS_OFF);
//         charPointer++;
//         isCharPrinted = true;
//         // return;
//     }

//     if (millis() - lastRunTime > SCROLL_SPEED)
//     {
//         if (marqueePointer >= (dmd.charWidth(data.charAt(charPointer - 1), font)))
//         {
//             marqueePointer = 0;
//             isCharPrinted = false;
//         }
//         dmd.marqueeScrollX(-1);
//         marqueePointer++;
//         lastRunTime = millis();
//     }
// }

void directPrintOnDisplay(const String &data, const uint8_t *font)
{
    Serial.println("Printing ....");
    for (uint32_t i = 0; i <= data.length(); i++)
    {
        Serial.print(data.charAt(i));
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

boolean httpGetToJson(const String &url, JsonDocument &WebResponse)
{

    WiFiClientSecure client; // or WiFiClientSecure for HTTPS
    client.setInsecure();
    HTTPClient http;
    http.useHTTP10(true);
    uint8_t retryCount = 0;
    uint16_t res = 0;
    Serial.println("Making HTTP Req");

    http.begin(client, url);
    http.setFollowRedirects(HTTPC_FORCE_FOLLOW_REDIRECTS);
    res = http.GET();
    Serial.println("Made req");
    if (res != HTTP_CODE_OK)
        return false;

    if (res != t_http_codes::HTTP_CODE_OK)
    {
        http.end();
        return false;
    }

    DeserializationError error = deserializeJson(WebResponse, http.getStream());
    http.end();
    Serial.println("HTTP End");
#ifdef DEBUG
    serializeJsonPretty(WebResponse, Serial);
    Serial.println("");
#endif
    if (error)
    {
#ifdef DEBUG
        Serial.println("Deserialization failed: " + String(error.c_str()));
#endif
        return false;
    }
    return true;
}

StaticJsonDocument<2024> Response;

void loop()
{

    // printOnDisplay(toDisplay, Arial_Black_16);
#ifdef DEBUG
    Serial.println("Helo");
#endif

    boolean res = httpGetToJson("https://fj13tq.deta.dev/random", Response);
    if (!res)
        return;
#ifdef DEBUG
    Serial.println(Response["headline"].as<String>());
#endif
    directPrintOnDisplay(Response["headline"].as<String>(), Arial_Black_16);
    directPrintOnDisplay(Response["summary"].as<String>(), Arial_Black_16);
    Response.clear();
    delay(500);
}