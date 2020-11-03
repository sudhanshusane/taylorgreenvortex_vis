#!/bin/bash

INPUT=/home/sci/ssane/data/Ensemble/TGV64_1000.vtk
OUTPUT=TGV_Streamlines.vtk
NUMSEEDS=100
STEPSIZE=0.01
NUMSTEPS=100
VARNAME="velocity"

./Construct_Streamlines $INPUT $OUTPUT $NUMSEEDS $STEPSIZE $NUMSTEPS $VARNAME
