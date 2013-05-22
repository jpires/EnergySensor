//Basic energy monitoring sketch - by Trystan Lea
//Licenced under GNU General Public Licence more details here
// openenergymonitor.org

//Sketch measures current only. 
//and then calculates useful values like
//apparent power and Irms.
//Apparent power is calculated from set Vrms.
double Vrms = 230.0;

//Setup variables
int numberOfSamples = 3000;

//Set current input pin
int inPinI = 0; 

//Current calibration coeficient
double ICAL = 0.1;

//Sample variables
int lastSampleI, sampleI;

//Filter variables
double lastFilteredI, filteredI;

//Power calculation variables
double sqI, sumI;

//Useful value variables
double apparentPower, Irms;

void powerMeter(double* power, double* energy){ 

	for (int n=0; n<numberOfSamples; n++){

		//Used for offset removal
		lastSampleI=sampleI;
   
		//Read in current samples.   
		sampleI = analogRead(inPinI);
   
		//Used for offset removal
		lastFilteredI = filteredI;
  
		//Digital high pass filters to remove 2.5V DC offset.
		filteredI = 0.996*(lastFilteredI + sampleI - lastSampleI);
      
		//Root-mean-square method current
		//1) square current values
		sqI = filteredI * filteredI;
		//2) sum 
		sumI += sqI;
	}

	//Calculation of the root of the mean of the current squared (rms)
	//Calibration coeficients applied. 
	Irms = ICAL * sqrt(sumI / numberOfSamples); 

	//Calculation power values
	apparentPower = Vrms * Irms;

	//Output to serial
	*power = apparentPower;
	*energy = Irms;

	//Reset current accumulator
	sumI = 0;
}

