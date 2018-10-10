#include "embot_hw_usb.h"
using namespace std;
void getMessage(uint8_t **ptr, uint16_t *size)
{
    embot::hw::usb::Message msg;
    std::uint8_t numofmsg;
    embot::hw::result_t res = embot::hw::usb::get(embot::hw::usb::Port::one, msg, numofmsg);
    
    if(res == embot::hw::resNOK)
    {
        *ptr = NULL;
        *size = 0;
        return;
    }
    *ptr = msg.data;
    *size = msg.size;
    return;
    
}