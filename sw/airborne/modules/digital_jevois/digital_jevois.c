/*
 * Copyright (C) Amit Ferencz
 *
 * This file is part of paparazzi
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/digital_jevois/digital_jevois.c"
 * @author Amit Ferencz
 * This module interfaces dc.c funtion to work with jevois camera
 */

#include "modules/digital_jevois/digital_jevois.h"
// Include Standard Camera Control Interface
#include "modules/digital_cam/dc.h"
// Telemetry
#include "subsystems/datalink/telemetry.h"
//Jevois functions.
#include "modules/sensors/jevois.h"

#include "state.h"

void digital_Jevois_init(void)
{
  // Call common DC init
  dc_init();
  jevois_init();
 }


void digital_Jevois_periodic(void)
{
  // Common DC Periodic task
  dc_periodic();
}

/* Command The Camera */
void dc_send_command(uint8_t cmd)
{
  switch (cmd) {
    case DC_SHOOT:
      jevois_sendCustomMeassege()
      break;
    case Open:
      jevois_sendCustomMeassege("O,x,x,x,x,x")
      break;
    case Close:
      jevois_sendCustomMeassege("C,x,x,x,x,x")
      break;
    case SET:
      jevois_setmapping(int number)
      break;
    default:
      break;
  }
}
