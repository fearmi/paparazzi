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
 * @file "modules/digital_jevois/digital_jevois.h"
 * @author Amit Ferencz
 * This module interfaces dc.c funtion to work with jevois camera
 */

#ifndef DIGITAL_JEVOIS_H
#define DIGITAL_JEVOIS_H

extern void digital_jevois_init(void);
extern void digital_Jevois_periodic(void);
extern void digital_Jevois_event(void);



#endif

