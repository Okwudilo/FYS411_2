#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
// output file as global variable
ofstream ofile;

// Begin of main program

int main(int argc, char *argv[])
{
  char *outfilename;
  // Read in output file, abort if there are too few command-line arguments
  if( argc <= 3 ){
    cout << "Bad Usage: " << argv[0] <<
      " read also output file, number of integration points and the final x values  on same line, four variables in total" << std::endl;
    exit(1);
  }
  else{
    outfilename=argv[1];
  }
  //  opening a file for the program
  ofile.open(outfilename);
  // extracting number of mesh points
  int i = atoi(argv[2]);
  double x = atof(argv[3]);  // reading x-value
  double h = 1.0/((double) i); // setting up step size
  double Derivative = (exp(x+h)-2.*exp(x)+exp(x-h))/(h*h);
  double RelativeError = log10(fabs(Derivative-exp(x))/exp(x));
  ofile <<  setw(15) << setprecision(8) << "relative error=" << RelativeError << endl;
  ofile.close();  // close output file
  return 0;
}