struct Flightchar{
	float GSD;
	float Speed;
	int Sensor_width;
	int Sensor_Heigth;
	int Image_Heigthmm;
	int Image_lengthmm;
	int Area_X,Area_y;
	int Front_Overlap;
	int Side_overlap;
	float CameraShutterSpeed;
	float FlightLineSpacing;
	float NumbersOfLienes;
	float NumbersOfImagesPerLine;
	float WidthFootPrint;
	float ImageWidthM;
	float ImageWidrhP;

	float CameraSpeed(float GSD,float Speed);
	float WidthM(float GSD,float ImageWidthP);

};

void CameraSpeed(float GSD,float Speed) {
	CameraShutterSpeed=(GSD*0.01/2)/Speed;
	}
float WidthM(float GSD,float ImageWidthP) {
	ImageWidthM=GSD*ImageWidthP/100;
	return ImageWidthM;
	}
