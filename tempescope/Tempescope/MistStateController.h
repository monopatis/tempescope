/*
  MistStateController.h - Mist state controller for a Tempescope
  Released as part of the Tempescope project - http://kenkawakenkenke.github.io/tempescope/
  Copyright (c) 2013 Ken Kawamoto.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef MistStateController_h
#define MistStateController_h
#include <Arduino.h>
#include "StateController.h"
#include "PinController.h"

#define STATE_MIST_OFF 0
#define STATE_MIST_ON_H 1 //ON(high)
#define STATE_MIST_ON_L 2 //OFF(low)
#define ACTION_MIST_ON 0
#define ACTION_MIST_OFF 1

class MistStateController: public StateController{
  public:
    MistStateController(PinController *mistController);
    
  protected:
    void stateChangedTo(int state);
    void transition(int state,int action);
    void stateTimedOut(int state);
  private:
    PinController *mistController;
};

#endif
