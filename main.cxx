#include <vtkm/io/VTKDataSetReader.h>
#include <vtkm/io/VTKDataSetWriter.h>
#include <vtkm/cont/DataSet.h>
#include <vtkm/cont/Initialize.h>
#include <vtkm/filter/Streamline.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	vtkm::io::VTKDataSetReader reader(argv[1]);
	vtkm::cont::DataSet ds = reader.ReadDataSet();
	
	// Add a composite array to the dataset which is a single velocity field.


	std::vector<vtkm::Vec3f> vel_field;
	float u,v,w;
	for(int i = 0; i < ds.GetNumberOfPoints(); i++)
	{
		u = 0.0;
		v = 0.0;
		w = 0.0;
		vel_field.push_back(vtkm::Vec3f(u, v, w));
	}
	
	ds.AddPointField("velocity", vel_field);
	
	std::cout << " Number of unstructured grid points: " << ds.GetNumberOfPoints() << std::endl;
	std::cout << " Number of fields: " << ds.GetNumberOfFields() << std::endl;

	int numSeeds = atoi(argv[3]);
	float stepSize = atof(argv[4]);
	int numSteps = atoi(argv[5]);
	
  vtkm::Bounds bounds = ds.GetCoordinateSystem().GetBounds();
  std::vector<vtkm::Particle> seeds;

  for (vtkm::Id i = 0; i < numSeeds; i++)
  {
    vtkm::Particle p;
    vtkm::FloatDefault rx = (vtkm::FloatDefault)rand() / (vtkm::FloatDefault)RAND_MAX;
    vtkm::FloatDefault ry = (vtkm::FloatDefault)rand() / (vtkm::FloatDefault)RAND_MAX;
    vtkm::FloatDefault rz = (vtkm::FloatDefault)rand() / (vtkm::FloatDefault)RAND_MAX;
    p.Pos[0] = static_cast<vtkm::FloatDefault>(bounds.X.Min + rx * bounds.X.Length());
    p.Pos[1] = static_cast<vtkm::FloatDefault>(bounds.Y.Min + ry * bounds.Y.Length());
    p.Pos[2] = static_cast<vtkm::FloatDefault>(bounds.Z.Min + rz * bounds.Z.Length());
    p.ID = i;
    seeds.push_back(p);
  }
  auto seedArray = vtkm::cont::make_ArrayHandle(seeds);

  vtkm::filter::Streamline streamline;

  streamline.SetStepSize(stepSize);
  streamline.SetNumberOfSteps(numSteps);
  streamline.SetSeeds(seedArray);

  streamline.SetActiveField(argv[6]);
  auto output = streamline.Execute(ds);

  vtkm::io::VTKDataSetWriter wrt(argv[2]);
  wrt.WriteDataSet(output);

  return 0;
	
}
