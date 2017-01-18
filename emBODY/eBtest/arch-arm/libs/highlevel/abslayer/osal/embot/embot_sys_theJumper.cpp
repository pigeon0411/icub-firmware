/*
 * Copyright (C) 2017 iCub Facility - Istituto Italiano di Tecnologia
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

#include "embot_sys_theJumper.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------




// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------

static volatile std::uint32_t s_nzi_ram[8]       __attribute__((at(0x2001FFE0)));

struct embot::sys::theJumper::Impl
{    
    bool initted;
    Config config;
    
    Impl() 
    {              
        initted = false;
        config.restart = nullptr;
        config.jump2 = nullptr;
    }
};


// --------------------------------------------------------------------------------------------------------------------
// - all the rest
// --------------------------------------------------------------------------------------------------------------------


embot::sys::theJumper::theJumper()
: pImpl(new Impl)
{   

}


bool embot::sys::theJumper::init(Config &config)
{   

    pImpl->config = config;
    
    pImpl->initted = true;
    
    return true;    
}

        
bool embot::sys::theJumper::eval(std::uint32_t &address, bool jumpnow)
{
    if(false == pImpl->initted)
    {
        return false;
    }
    
    bool ret = true;
    
    if((0x12345678 == s_nzi_ram[0]) && (0 != s_nzi_ram[1]))
    {
        address = s_nzi_ram[1];
        ret = true;
    }
    
    s_nzi_ram[0] = 0;
    s_nzi_ram[1] = 0;
    
    if(ret && jumpnow)
    {
        jump(address);        
        ret = false;
    }
           
    return ret;
};
        
        
bool embot::sys::theJumper::jump(std::uint32_t address)
{
    if(false == pImpl->initted)
    {
        return false;
    }
    
    bool ret = false;    
    // it jumps to the specified address. returns false only if it cannot jump.
    
    if(nullptr != pImpl->config.jump2)
    {
        pImpl->config.jump2(address);
    }
    
    return ret;    
}      
  

bool embot::sys::theJumper::set(std::uint32_t address)
{
    if(false == pImpl->initted)
    {
        return false;
    }
    
    bool ret = false;    
    // it sets in permanent memory an address where to start
    
    s_nzi_ram[0] = 0;
    s_nzi_ram[1] = 0;
    
    if(0 == address)
    {
        return false;
    }
    
    s_nzi_ram[0] = 0x12345678;
    s_nzi_ram[1] = address;
    
    return ret;    

}   

        
bool embot::sys::theJumper::restart()
{       
    if(false == pImpl->initted)
    {
        return false;
    }
    
    // restart the micro by calling hal_sys_restart
    if(nullptr != pImpl->config.restart)
    {
        pImpl->config.restart();
    }
    
    return false;   
}

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


