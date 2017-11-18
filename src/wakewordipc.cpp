/*
   Copyright (C) 2017 - 2018 this.mutzii@gmail.com

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "include/wakewordipc.h"

using namespace WakeWord;

const char * WakeWordIPC::IPCCommandNames[] = { "NONE" ,"IPC_DISCONNECT" , "IPC_WAKE_WORD_DETECTED" , "IPC_PAUSE_WAKE_WORD_ENGINE" , "IPC_RESUME_WAKE_WORD_ENGINE" , "IPC_CONFIRM" };

WakeWordIPC::WakeWordIPC(WakeWordDetectedHandler * handler)
{
    m_wakeword_handler = handler;
}

void WakeWordIPC::wakeWordDetected()
{
    if( m_wakeword_handler != nullptr )
             m_wakeword_handler->onWakeWordDetected();
}
