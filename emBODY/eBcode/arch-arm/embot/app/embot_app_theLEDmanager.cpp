    /*
 * Copyright (C) 2019 iCub Facility - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "embot_app_theLEDmanager.h"

// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stm32hal.h"
#include "embot_hw.h"
#include "embot_hw_gpio.h"
#include "embot_hw_bsp.h"
#include "embot_binary.h"
#include "embot_sys_Timer.h"

#include "embot_sys_theCallbackManager.h"
#include "embot_sys_Timer.h"
#include "embot_sys_Action.h"

#include <vector>
#include <map>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------

namespace embot { namespace app {
    
    using namespace embot::hw;
    
    GPIO_PinState convert(embot::hw::gpio::State s)
    {
        return (s == embot::hw::gpio::State::RESET) ? (GPIO_PIN_RESET) : (GPIO_PIN_SET);
    }
    
    
#if 0
    // correct but we use another one
    class aLED : public LEDhandle
    {
    public:
        LED led;
        GPIO_PinState stateON;
        GPIO_PinState stateOFF;
        bool supp;
        const embot::hw::GPIO *gpio;
    public:
        
        aLED(LED l = LED::none, const embot::hw::GPIO *g = nullptr, GPIO_PinState ON = GPIO_PIN_SET, GPIO_PinState OFF = GPIO_PIN_RESET) : led(l), gpio(g), stateON(ON), stateOFF(OFF)
        {
            supp = embot::hw::bsp::led::getMAP()->supported(led);
        };
            
        ~aLED() {};
            
        virtual bool supported() const
        {
            return supp;
        }
        
        virtual LED id() const
        {
            return led;
        }
        
        virtual void on()
        {
            if(supp)
            {
                HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateON);
            }
        }
        
        virtual void off()
        {
            if(supp)
            {
                HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateOFF);
            }
        }
        
        virtual void toggle()
        {
            if(supp)
            {
                HAL_GPIO_TogglePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin));
            }
        }  

        virtual void pulse(embot::common::relTime period, std::uint32_t times) 
        {
    
        }            
        
    };
    
#endif

#if 0
    // use this class if you know for sure that the led is supported. please check with a call to embot::hw::bsp::led::getMAP()->supported(led) first
    // correct but we use its extension w/ timer
    class aSlimLED : public LEDhandle
    {
    public:
        LED led;
        const embot::hw::GPIO *gpio;
        GPIO_PinState stateON;
        GPIO_PinState stateOFF;
    public:
        
        aSlimLED(LED l = LED::none, const embot::hw::GPIO *g = nullptr, 
                        embot::hw::gpio::State ON = embot::hw::gpio::State::SET, 
                        embot::hw::gpio::State OFF = embot::hw::gpio::State::RESET) 
                        : led(l), gpio(g), stateON(convert(ON)), stateOFF(convert(OFF))
        {
            // assume led is ok.
        };
            
        ~aSlimLED() {};
            
        virtual bool supported() const
        {   // assume it is ok but i give correct result anyway
            return embot::hw::bsp::led::getMAP()->supported(led);
        }
        
        virtual LED id() const
        {
            return led;
        }
        
        virtual void on() const
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateON);
        }
        
        virtual void off() const
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateOFF);
        }
        
        virtual void toggle() const
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_TogglePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin));
        }   

        virtual void pulse(embot::common::relTime period, std::uint32_t times) 
        {

        }            
        
    };
    
#endif

    // use this class if you know for sure that the led is supported. please check with a call to embot::hw::bsp::led::getMAP()->supported(led) first
    class aSlimPulsableLED : public LEDhandle
    {
    public:
        LED led;
        const embot::hw::GPIO *gpio;
        GPIO_PinState stateON;
        GPIO_PinState stateOFF;
        embot::sys::Timer *tmr;
    public:
        
        aSlimPulsableLED(LED l = LED::none, const embot::hw::GPIO *g = nullptr, 
                        embot::hw::gpio::State ON = embot::hw::gpio::State::SET, 
                        embot::hw::gpio::State OFF = embot::hw::gpio::State::RESET) 
                        : led(l), gpio(g), stateON(convert(ON)), stateOFF(convert(OFF))
        {
            // assume led is ok.
            // i defer creation of the timer.
            tmr = nullptr;            
        };
            
        ~aSlimPulsableLED() {};
            
        virtual bool supported() const
        {   // assume it is ok but i give correct result anyway
            return embot::hw::bsp::led::getMAP()->supported(led);
        }
        
        virtual LED id() const
        {
            return led;
        }
        
        virtual void on() 
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateON);
        }
        
        virtual void off() 
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_WritePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin), stateOFF);
        }
        
        virtual void toggle() 
        {   // assume it is ok, hence gpio is not null
            HAL_GPIO_TogglePin(static_cast<GPIO_TypeDef*>(gpio->port), static_cast<uint16_t>(gpio->pin));
        }   

        static void onexpiry(void *p)
        {
            aSlimPulsableLED * l = reinterpret_cast<aSlimPulsableLED*>(p);
            l->toggle();            
        }
        
        virtual void pulse(embot::common::relTime period, std::uint32_t times) 
        {            
            if(nullptr == tmr)
            {
                tmr = new embot::sys::Timer;
            }
            
            if(0 == period)
            {
                tmr->stop();
            }
            else
            {
                embot::sys::Timer::Mode mode = (0 == times) ? (embot::sys::Timer::Mode::forever) : (embot::sys::Timer::Mode::someshots);
                embot::sys::Action act(embot::sys::CallbackToTask(onexpiry, this, embot::sys::theCallbackManager::getInstance().task()));
                embot::sys::Timer::Config cfg(period/2, act, mode, times);
                tmr->start(cfg);
            }
        }
        
    };    
    
    
    class aDummyLED : public LEDhandle
    {
    public:
        LED led;
    public:
        
        aDummyLED(LED le = LED::none) : led(le) {};
            
        ~aDummyLED() {};
            
        virtual bool supported() const
        {
            return false;
        }
        
        virtual LED id() const
        {
            return led;
        }
        
        virtual void on() {}        
        virtual void off() {}        
        virtual void toggle() {}  
        virtual void pulse(embot::common::relTime period, std::uint32_t times) {}          
    };
    
}}

namespace embot { namespace app {
    
    struct theLEDmanager::Impl
    {    
        bool started;
        
        const embot::hw::bsp::led::MAP * thebspmap;
        
        std::uint32_t initialisedmask = 0;
        
        //std::map<LED, aSlimLED> mapofleds;
        std::map<LED, aSlimPulsableLED> mapofleds;
        aDummyLED lednone{LED::none};
        //aSlimLED lednone{LED::none};
                     
        Impl() 
        {              
            started = false;
            initialisedmask = 0;
            thebspmap = embot::hw::bsp::led::getMAP();
        }
        
        ~Impl() 
        {              
            started = false;
            initialisedmask = 0;
            thebspmap = nullptr;
        }
        
        
        bool initialised(LED led) const
        {
            return embot::binary::bit::check(initialisedmask, embot::hw::bsp::led::MAP::toindex(led));
        }
           

        bool init(LED led)
        {
            if(!thebspmap->supported(led))
            {
                return false;
            }  
            
            if(!thebspmap->isvalid(led))
            {
                return false;
            }
            
            if(initialised(led))
            {   // dont need to re-init
                return true;
            }
            
            // every led initalisation is done in the bsp ...
            
            if(!embot::hw::bsp::initialised())
            {   // requires embot::hw::bsp::init()
                return false;
            }
                    
            embot::binary::bit::set(initialisedmask, embot::hw::bsp::led::MAP::toindex(led));
            
            // i am sure that thebspmap->getgpio(led) is ok 
//            aSlimLED a{led, thebspmap->getgpio(led), thebspmap->on, thebspmap->off};
//            a.off();            
//            mapofleds.insert(std::pair<LED, aSlimLED>(led, a));
            
            aSlimPulsableLED a{led, thebspmap->getgpio(led), thebspmap->on, thebspmap->off};
            a.off();            
            mapofleds.insert(std::pair<LED, aSlimPulsableLED>(led, a));
                       
            return true;        
        }
        
        bool deinit()
        {           
            initialisedmask = 0;
            mapofleds.clear();                                   
            return true;        
        }
        
        bool deinit(LED led)
        { 
            if(initialised(led))
            {
                mapofleds.erase(led);            
                embot::binary::bit::clear(initialisedmask, embot::hw::bsp::led::MAP::toindex(led));
            }
            return true;
        }

    };
    
    theLEDmanager& theLEDmanager::getInstance()
    {
        static theLEDmanager* p = new theLEDmanager();
        return *p;
    }
    
    theLEDmanager::theLEDmanager()
//    : pImpl(new Impl)
    {
        pImpl = std::make_unique<Impl>();
    }  
    
    
    theLEDmanager::~theLEDmanager() { }
   

    bool theLEDmanager::init(const std::initializer_list<LED> &leds)
    {
        for(auto a : leds)
        {
            pImpl->init(a);
        }
        
        return true;
    } 

    bool theLEDmanager::deinit()
    {
        pImpl->deinit();
        return true;
    }  

    bool theLEDmanager::deinit(const std::initializer_list<LED> &leds)
    {
        for(auto a : leds)
        {
            pImpl->deinit(a);
        }
        return true;
    }     

    bool theLEDmanager::initialised(LED led) const
    {
        return pImpl->initialised(led);     
    }    
    
    LEDhandle & theLEDmanager::get(LED led) const
    {
        auto a = pImpl->mapofleds.find(led);
        if(a != pImpl->mapofleds.end())
        {
            return a->second;
        }
        else
        {
            return pImpl->lednone;
        }        
    }
    
    
//    LEDhandle * theLEDmanager::obtain(LED led) const
//    {
//        auto a = pImpl->mapofleds.find(led);
//        if(a != pImpl->mapofleds.end())
//        {
//            return &a->second;
//        }
//        else
//        {
//            return &pImpl->lednone;
//        }        
//    }
    
//    LEDhandle * theLEDmanager::release(const LEDhandle *handle) const
//    {
//        //handle = &pImpl->lednone;
//        return &pImpl->lednone;
//    }
//    
//    LEDhandle & theLEDmanager::none() const
//    {
//        return pImpl->lednone;
//    }

}} // namespace embot { namespace app {

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------

