#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>

int main(int argc, char *argv[])
{
    LGFX lcd{240, 320};
    lcd.init();
    lcd.setColorDepth(16);
    lcd.fillScreen(0);
    lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    int fd{open("/dev/input/by-path/platform-fe205000.i2c-event", O_RDONLY)};
    if (fd >= 0) {
        int x{0}, y{0};
        while (true) {
            input_event e;
            auto n{read(fd, &e, sizeof e)};
            if (n == sizeof e) {
                if (e.type == EV_KEY && e.code == KEY_LEFTMETA && e.value == 1) {
                    lcd.fillScreen(0);
                } else if (e.type == EV_ABS && e.code == ABS_MT_POSITION_X) {
                    x = e.value;
                } else if (e.type == EV_ABS && e.code == ABS_MT_POSITION_Y) {
                    y = e.value;
                    lcd.setColor(0xff0000U);
                    lcd.fillCircle (x, y, 10);
                }
            }
        }
        close(fd);
    }
    return 0;
}
