#include "qrcode.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    /* Create the QR code */
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)] = {0};
    qrcode_initText(&qrcode, qrcodeData, 3, 0, "http://weixin.qq.com/r/p0xudjXEUmgtrXEV9xm1");

    QString result;
    for (uint8_t y = 0; y < qrcode.size; y++) {
        /* Each horizontal module */
        for (uint8_t x = 0; x < qrcode.size; x++) {
            /* Print each module (UTF-8 \u2588 is a solid block) */
            result += qrcode_getModule(&qrcode, x, y) ? QString("\u2588\u2588") : QString("  ");
        }

        result.append(QString("\r\n"));
    }

    qDebug().noquote()<<result;

    return 0;
}
