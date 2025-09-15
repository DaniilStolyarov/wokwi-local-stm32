#include "Include/ZebraController.h"
#include "Adafruit_SPITFT.h"
const unsigned char green_dude [] PROGMEM = {
	0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x00, 0x03, 0x80, 0x07, 0xc0, 0x1f, 0x60, 
	0x33, 0x20, 0x63, 0x20, 0x0f, 0xa0, 0x1d, 0x80, 0x18, 0xc0, 0x30, 0xc0, 0x30, 0xe0, 0x60, 0x60
};
const unsigned char red_dude [] PROGMEM = {
	0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x3f, 0xc0, 0x3f, 0xc0, 0x2f, 0x40, 0x2f, 0x40, 0x2f, 0x40, 
	0x2f, 0x40, 0x0f, 0x00, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 0x30, 0xc0
};

const unsigned char green_dude_anim [] PROGMEM = {
	0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x07, 0x80, 0x07, 0x80, 
	0x0f, 0x80, 0x1b, 0xc0, 0x13, 0x60, 0x07, 0x00, 0x05, 0x80, 0x04, 0x80, 0x04, 0x80, 0x0d, 0x80
};
ZebraController::ZebraController()
{
	state = ZebraControllerState::RED;
	tft.begin();
}

void ZebraController::setState(ZebraControllerState _state)
{
	if (_state == ZebraControllerState::RED)
	{
		image = red_dude;
		imageColor = ILI9341_RED;
	}
	else if (_state == ZebraControllerState::GREEN)
	{
		if (image == green_dude)
		{
			image = green_dude_anim;
		}
		else
		{
			image = green_dude;
		}
		imageColor = ILI9341_GREEN;
	}
	state = _state;
}

void ZebraController::apply()
{
    
    uint8_t bytesPerRow = (IMAGE_WIDTH + 7) / 8;

    // Вычисляем смещение для центрирования изображения
    uint16_t xOffset = (tft.width() - IMAGE_WIDTH * SCALE) / 2;
    uint16_t yOffset = (tft.height() - IMAGE_HEIGHT * SCALE) / 2;

    for (int16_t srcY = 0; srcY < IMAGE_HEIGHT; srcY++) {
        for (int16_t srcX = 0; srcX < IMAGE_WIDTH; srcX++) {
            // Определяем позицию байта и бита в изображении
            uint16_t byteIndex = srcY * bytesPerRow + srcX / 8;
            uint8_t bitIndex = 7 - (srcX % 8);
            uint8_t byte = pgm_read_byte(&image[byteIndex]);

            // Определяем цвет пикселя
            if (byte & (1 << bitIndex)) {
                // Рисуем масштабированный прямоугольник вместо пикселя
                tft.fillRect(
                    xOffset + srcX * SCALE, 
                    yOffset + srcY * SCALE, 
                    SCALE, 
                    SCALE, 
                    imageColor
                );
            }
			else
			{
				tft.fillRect(
                    xOffset + srcX * SCALE, 
                    yOffset + srcY * SCALE, 
                    SCALE, 
                    SCALE, 
                    ILI9341_BLACK
                );
			}
        }
    }
	
}


