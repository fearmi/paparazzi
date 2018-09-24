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
 * @file "modules/photogrammetryparam/photogrammetryparam.h"
 * @author Amit Ferencz
 * Generates Photogrammetry parrameters
 */

#ifndef PHOTOGRAMMETRYPARAM_H
#define PHOTOGRAMMETRYPARAM_H
#include <math.h>


float ImageWidthM;
float ImageWidrhP;
float GSD;
float Speed;
int Sensor_width;
int Sensor_Heigth;
int Image_Heigthmm;
int Image_lengthmm;
int Area_X,Area_y;
int Front_Overlap;
int Side_overlap;
float ImageWM;
float ImageHm;
float numberOfImage;
float SpaceBLines;
double  numberOfLines;
float Distance_Between_Photos;
float Photos;
float altitud;
float Flength;
float sensor_width;
float Cspeed;


struct Flightchar{
	
	float CameraShutterSpeed;
	float FlightLineSpacing;
	float NumbersOfLienes;
	float NumbersOfImagesPerLine;
	float WImageFootprint;
	float HImageFootprint;
	float DistanceBetweenPhotos;
	float FlightAltite;
};

float CameraSpeed(float GSD,float Speed);
float WidthM(float GSD,float ImageWidthP); 
float HeigthM(float GSD,float ImageHeigthP);
float Linespacing (float SideOverlap);
float DistanceBetweeImages(float FrontOverlap);
float NumberLines(float Area_Y);
float DistancePhotos(float FrontOverlap);
float NumbersOfPhotos(float Area_X);
float Altitud(float GSD,float Flength,int ImageWidthP,float sensor_width);
void photogrammetry(float GSD,float Speed,float ImageWidthP,float ImageHeigthP,float SideOverlap,float Area_Y,float FrontOverlap,float Area_X,float Flength,float sensor_width);


void photogrammetry(float GSD,float Speed,float ImageWidthP,float ImageHeigthP,float SideOverlap,float Area_Y,float FrontOverlap,float Area_X,float Flength,float sensor_width){
	Cspeed = (GSD*0.01/2)/Speed;
	ImageWM = GSD*ImageWidthP/100;
	ImageHm = GSD*ImageHeigthP/100;
	SpaceBLines = ImageWM*(100-SideOverlap)/100;
	numberOfLines =Area_Y/SpaceBLines;
	Distance_Between_Photos =ImageHm*(100-FrontOverlap)/100 ;
	Photos =Area_X/Distance_Between_Photos;
	altitud = (GSD*Flength*ImageWidthP)/(sensor_width*100);

	printf("%s,%f \n","Camera shutter sppe: ",Cspeed);
	printf("%s,%f \n","Foot print Width ",ImageWM);
	printf("%s,%f \n","Foot print Height ",ImageHm);
	printf("%s,%f \n","Space Between lines ",SpaceBLines);
	printf("%s,%f \n","Numbers of lines ",numberOfLines);
	printf("%s,%f \n","Distance Between photos " ,Distance_Between_Photos);
	printf("%s,%f \n","Number of photos per line" ,Photos);
	printf("%s,%f \n","Altitud" ,altitud);

}

#endif

