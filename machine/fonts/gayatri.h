

/*
 *
 * new Font
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : gayatri
 * Date                : 26.08.2022
 * Font size in bytes  : 14059
 * Font width          : 10
 * Font height         : 17
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef NEW_FONT_H
#define NEW_FONT_H

#define NEW_FONT_WIDTH 10
#define NEW_FONT_HEIGHT 17

static uint8_t Gayatri[] PROGMEM = {
    0x36, 0xEB, // size
    0x0A, // width
    0x11, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x10, 0x02, 0x0E, 0x0F, 0x0F, 0x0B, 0x0A, 0x05, 0x05, 
    0x00, 0x00, 0x0B, 0x0E, 0x07, 0x0D, 0x05, 0x04, 0x04, 0x04, 
    0x05, 0x04, 0x05, 0x05, 0x05, 0x04, 0x03, 0x02, 0x0B, 0x02, 
    0x0D, 0x0D, 0x11, 0x06, 0x0D, 0x0B, 0x0C, 0x0B, 0x09, 0x08, 
    0x0C, 0x08, 0x02, 0x08, 0x0F, 0x07, 0x0C, 0x05, 0x0A, 0x08, 
    0x0B, 0x08, 0x0C, 0x03, 0x0E, 0x0B, 0x0F, 0x03, 0x0E, 0x0E, 
    0x03, 0x10, 0x11, 0x04, 0x0C, 0x07, 0x0B, 0x0D, 0x0B, 0x08, 
    0x0A, 0x08, 0x08, 0x09, 0x03, 0x04, 0x05, 0x07, 0x0C, 0x05, 
    0x08, 0x0A, 0x0A, 0x09, 0x0E, 0x0B, 0x0A, 0x08, 0x08, 0x07, 
    0x0B, 0x03, 0x08, 0x07, 0x08, 0x0A, 
    
    // font data
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x07, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 33
    0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, // 34
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0xE0, 0x20, 0x20, 0xA0, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0B, 0x09, 0x0F, 0x0F, 0x0F, 0x09, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 36
    0xC0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xA0, 0xA0, 0xE0, 0xE0, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x0B, 0x0B, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
    0xC0, 0xE0, 0x20, 0xE0, 0xE0, 0xE4, 0xFC, 0x3C, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 39
    0xFC, 0xFC, 0x04, 0x04, 0x04, 0x3F, 0x3F, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // 40
    0x04, 0x04, 0x04, 0xFC, 0xFC, 0x20, 0x20, 0x20, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, // 41
    0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0x80, 0x80, 0xE0, 0xE0, 0x0E, 0x0E, 0x02, 0x0E, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0xE8, 0x08, 0xF8, 0xF8, 0x0F, 0x0F, 0x01, 0x09, 0x0F, 0x08, 0x08, 0x3F, 0x3F, 0x28, 0x3F, 0x21, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0xE0, 0xE0, 0x20, 0xA0, 0xA0, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0B, 0x0B, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 46
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xC0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xE0, 0xF8, 0x08, 0xF8, 0xE0, 0x03, 0x0F, 0x08, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // 48
    0x20, 0xE0, 0xF8, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00, // 49
    0x30, 0x08, 0xF8, 0xF0, 0x0C, 0x0B, 0x09, 0x0E, 0x00, 0x00, 0x00, 0x00, // 50
    0x18, 0x88, 0xF8, 0x70, 0x06, 0x0A, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, // 51
    0x00, 0xC0, 0xF0, 0xF8, 0x00, 0x02, 0x03, 0x0F, 0x0F, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
    0xF0, 0x50, 0xD0, 0x88, 0x0D, 0x0C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, // 53
    0xF0, 0x88, 0xB8, 0xB8, 0x00, 0x03, 0x0F, 0x08, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 54
    0x30, 0x10, 0x10, 0xD0, 0x70, 0x00, 0x0C, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x70, 0xF8, 0x88, 0x48, 0x70, 0x0F, 0x08, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 56
    0xF0, 0xF8, 0x18, 0xF8, 0x0E, 0x0F, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, // 57
    0xE0, 0xA0, 0xE0, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 0x00, // 58
    0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, // 59
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x1E, 0x1E, 0x02, 0x0E, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, // 61
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0xA0, 0xE0, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x07, 0x0F, 0x08, 0x09, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0xE0, 0xE0, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0x20, 0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xA0, 0xE0, 0x80, 0x80, 0x0F, 0x0F, 0x0F, 0x0F, 0x09, 0x09, 0x0E, 0x00, 0x0F, 0x0F, 0x0F, 0x2F, 0x29, 0x2F, 0x2F, 0x20, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 64
    0xC0, 0xC0, 0x40, 0x40, 0xC0, 0xC0, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
    0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x09, 0x0F, 0x00, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 66
    0xC0, 0xE0, 0x20, 0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xA0, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
    0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0E, 0x0E, 0x02, 0x0E, 0x0E, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 69
    0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xE0, 0xE0, 0x24, 0xEC, 0xFC, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE4, 0xFC, 0xF8, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 73
    0xFF, 0xFF, 0x0F, 0x0F, 0x00, 0x00, // 74
    0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0xE0, 0x00, 0x3D, 0x3D, 0x25, 0x25, 0x25, 0x27, 0x27, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 75
    0xE0, 0x60, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0x20, 0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xA0, 0xE0, 0x0F, 0x0C, 0x0F, 0x0F, 0x09, 0x09, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 76
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x7F, 0x7F, 0x20, 0x20, 0x20, 0x6F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
    0xE0, 0x20, 0xE0, 0x20, 0xE0, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
    0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE4, 0xFC, 0xFC, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xA0, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x0E, 0x0E, 0x0A, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 83
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x3F, 0x3F, 0x2D, 0x2F, 0x2F, 0x28, 0x2F, 0x2F, 0x28, 0x28, 0x2F, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0x00, 0x00, 0xE0, 0xE0, 0x80, 0xFF, 0x00, 0x00, 0x00, // 85
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x08, 0x08, 0x0B, 0x0B, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0xE0, 0xE0, 0xA0, 0xA0, 0xE0, 0xE0, 0xE0, 0xE0, 0xA0, 0xA0, 0xE0, 0x0F, 0x0F, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
    0xC0, 0xE0, 0x20, 0x20, 0xE0, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x0B, 0x0B, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
    0xE0, 0xE0, 0x00, 0x7F, 0x7F, 0x40, 0x00, 0x00, 0x00, // 89
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xE0, 0xE0, 0x0F, 0x09, 0x01, 0x0F, 0x0F, 0x08, 0x3F, 0x3F, 0x28, 0x2F, 0x2F, 0x20, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 90
    0x80, 0x80, 0x80, 0xE0, 0xE0, 0xA0, 0xA0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x0F, 0x0F, 0x08, 0x06, 0x08, 0x08, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 91
    0x10, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 92
    0x00, 0x00, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0x00, 0x40, 0xA0, 0xE0, 0xE0, 0xC0, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x07, 0x09, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 93
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x20, 0xC0, 0xE0, 0x20, 0xE0, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x30, 0x30, 0xF0, 0xF0, 0x00, 0x2E, 0x2F, 0x03, 0x00, 0x00, 0x00, 0x00, // 95
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0xFF, 0x5F, 0xDF, 0xF0, 0x1F, 0xFF, 0x10, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, // 96
    0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xE0, 0xE0, 0x0F, 0x0F, 0x0C, 0x0B, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 97
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xC0, 0x60, 0x20, 0xE0, 0xE0, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x08, 0x09, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 98
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x1F, 0x00, 0x00, 0x0F, 0x07, 0x00, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 99
    0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x09, 0x07, 0x0F, 0x0F, 0x0F, 0x09, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 100
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x0E, 0x0E, 0x0A, 0x0E, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 101
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 102
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 103
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x09, 0x09, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 104
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 105
    0x01, 0xFF, 0xFF, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, // 106
    0x20, 0xE0, 0x80, 0x00, 0xE0, 0xFF, 0xE7, 0xE0, 0x00, 0x00, 0x00, 0x00, // 107
    0x60, 0x60, 0x20, 0xE0, 0xC0, 0x0E, 0x0E, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, // 108
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0x60, 0x0F, 0x0F, 0x09, 0x09, 0x09, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 110
    0x20, 0xE0, 0x80, 0x00, 0x00, 0xF0, 0xFF, 0xF7, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, // 111
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x00, 0x09, 0x09, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 112
    0x00, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x08, 0x0B, 0x0B, 0x0A, 0x0F, 0x0F, 0x06, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 113
    0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x09, 0x0B, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 115
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0xE8, 0xE8, 0xF8, 0xF8, 0x0F, 0x0F, 0x01, 0x09, 0x0F, 0x0F, 0x08, 0x3F, 0x3F, 0x28, 0x3F, 0x3F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 116
    0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 117
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x08, 0x08, 0x0B, 0x0B, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 118
    0xE0, 0xE0, 0xA0, 0xE0, 0xC0, 0x20, 0x20, 0xE0, 0x0E, 0x0F, 0x0A, 0x0B, 0x0F, 0x0A, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
    0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0x60, 0x00, 0x3D, 0x3D, 0x25, 0x25, 0x24, 0x27, 0x27, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 120
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 121
    0xC0, 0xE0, 0x20, 0x00, 0xE0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 122
    0x00, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, // 123
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0xE0, 0xE0, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 124
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0x60, 0x60, 0x0F, 0x4F, 0x49, 0x49, 0x49, 0x4F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x0E, 0x8E, 0xCA, 0xCE, 0xC8, 0x88, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 127
    
};

#endif
