#!/bin/bash

FILE=380
INPUT="/home/sci/ssane/data/Ensemble/TrainingSet1/TGV_"$FILE".vtk"
OUTPUT="TGV_Streamlines_"$FILE".vtk"
NUMSEEDS=4096
STEPSIZE=0.5
NUMSTEPS=100
VARNAME="velocity"
SEED="TGV_Seeds.txt"

./Construct_Streamlines $INPUT $OUTPUT $NUMSEEDS $STEPSIZE $NUMSTEPS $VARNAME $SEED
