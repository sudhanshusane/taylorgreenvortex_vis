#include <vtkm/io/reader/VTKDataSetReader.h>
#include <vtkm/io/reader/VTKUnstructuredGridReader.h>
#include <vtkm/io/writer/VTKDataSetWriter.h>
// /home/sci/ssane/data/Ensemble
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkSmartPointer.h>

#include <omp.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

  vtkSmartPointer<vtkXMLUnstructuredGridReader> reader =
    vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader->SetFileName(filename.c_str());
  reader->Update();


}
