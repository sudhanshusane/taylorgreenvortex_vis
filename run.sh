#!/bin/bash

INPUT="/home/sci/ssane/data/Ensemble/TGV64_1600.vtk"
OUTPUT="TGV_Streamlines.vtk"
NUMSEEDS=100
STEPSIZE=0.1
NUMSTEPS=400
VARNAME="velocity"
SEED="TGV_Seeds.txt"

./Construct_Streamlines $INPUT $OUTPUT $NUMSEEDS $STEPSIZE $NUMSTEPS $VARNAME $SEED
